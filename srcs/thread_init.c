/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:55:33 by ptungbun          #+#    #+#             */
/*   Updated: 2023/06/28 10:38:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_fork(t_rule *rule, int i, t_philo *philo)
{
	if (rule->is_end || pthread_mutex_lock(&philo[i].r_fork))
		return (0);
	philo_print(GRNB, ATF, philo[i], rule);
	if (rule->is_end || pthread_mutex_lock(philo[i].l_fork))
		return (0);
	philo_print(GRNB, ATF, philo[i], rule);
	philo[i].last_eat = get_time();
	return (1);
}

static int	wait_n_check(t_rule *rule, long t_wait)
{
	long	t_chk;

	t_chk =  get_time();
	while(!rule->is_end && get_time() - t_chk < t_wait)
		usleep(200);
	return (rule->is_end);
}

static void	rotine_loop(t_rule *rule, int i, t_philo *philo)
{
	while (!rule->is_end && (philo[i].eat_count < rule->n_eat))
	{
		philo_print(YELB, ATK, philo[i], rule);
		if (!take_fork(rule, i, philo))
			return;
		philo_print(CYNB, AET, philo[i], rule);
		if(rule->n_eat > 0)
			philo[i].eat_count = philo[i].eat_count + 1;
		if(wait_n_check(rule, rule->t_eat))
			return;
		if (rule->is_end == 1 || pthread_mutex_unlock(&philo[i].r_fork) != 0)
			return;
		philo_print(GRN, ADF, philo[i], rule);
		if (rule->is_end == 1 || pthread_mutex_unlock(philo[i].l_fork) != 0)
			return;
		philo_print(GRN, ADF, philo[i], rule);
		philo_print(WHTB, ASP, philo[i], rule);
		if(wait_n_check(rule, rule->t_sleep))
			return;
	}
	return;
}

static void	*rotine(void *vp_rule)
{
	t_rule	*rule;
	int		i;
	t_philo	*philo;

	rule = (t_rule *)vp_rule;
	i = rule->arg_id;
	philo = rule->philo;
	philo[i].last_eat = get_time();
	rotine_loop(rule, i, philo);
	rule->full_count++;
	return (NULL);
}

int	thread_init(t_rule *rule)
{
	int		i;

	i = 0;
	while(i < rule->n_philo)
	{
		if (i == 0)
			rule->t_start = get_time();
		rule->arg_id = i;
		if(pthread_create(&(rule->philo[i].phi), NULL, &rotine, rule))
			return (3);
		pthread_detach(rule->philo[i].phi);
		i = i + 2;
		if (i >= rule->n_philo && i % 2 == 0)
			i = 1;
		usleep(10);
	}
	usleep(1000);
	return (0);
}
