// void join_philo(t_psychopomp *psy)
// {
// 	int		i;

// 	i = 0;
// 	while(i < psy->rule_book->n_philo)
// 	{
// 		if (pthread_join(psy->lst_philo[i].phi, NULL) != 0)
// 			return;
// 		pthread_mutex_destroy(&psy->lst_philo[i].r_fork);
// 		i++;
// 	}
// 	if (pthread_join(psy->dead, NULL) != 0)
// 		return;
// 	pthread_mutex_destroy(&psy->rule_book->m_all);
// 	free_all(psy);
// }

int	is_die(t_philo *philo)
{
	t_time		*time;

	time = philo->clock;
	if((time->t - philo->last_eat) <= philo->rule_book->t_die)
		return (0);
	philo->rule_book->is_end = 1;
	return (1);
}

// int	is_limit(t_philo philo)
// {
// 	if(philo.count_eat < 0)
// 		return (0);
// 	if(philo.count_eat >= philo.rule_book->n_eat)
// 		return (0);
// 	return (0);
// }

void	*who_die(void *vp_psychopomp)
{
	int				i;
	t_psychopomp	*psy;
	long long		timestamp;

	psy = (t_psychopomp *)vp_psychopomp;
	timestamp = getnupdate_time(psy->clock);
	i = 0;
	while(psy->rule_book->is_end == 0)
	{
		pthread_mutex_lock(&psy->rule_book->m_all);
		if (is_die(&(psy->lst_philo)[i]))
		{
			printf("%lld %d %s", timestamp, (psy->lst_philo)[i].tag, "is die\n");
			return (NULL);
		}
		pthread_mutex_unlock(&psy->rule_book->m_all);
		i++;
		if (i == psy->rule_book->n_philo)
			i = 0;
	}
	return (NULL);
}

void	psychopomp_init(t_psychopomp *psy)
{
	if(pthread_create(&(psy->dead), NULL, &who_die, psy) != 0)
		return;
}

void	print_action(t_philo *philo, char *ac_str)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->rule_book->m_all);
	timestamp = getnupdate_time(philo->clock);
	printf("%lld %d %s", timestamp, philo->tag, ac_str);
	pthread_mutex_unlock(&philo->rule_book->m_all);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping\n");
	usleep(philo->rule_book->t_sleep);
	print_action(philo, "is thinking\n");
}

static void	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->r_fork) != 0)
		return;
	print_action(philo, "has taken a fork\n");
	if (pthread_mutex_unlock(&philo->r_fork) != 0)
		return;
	print_action(philo, "has taken a fork\n");
}

void	philo_eat(t_philo *philo)
{
	take_fork(philo);
	print_action(philo, "is eating\n");
	philo->last_eat = getnupdate_time(philo->clock);
	usleep(philo->rule_book->t_eat);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
