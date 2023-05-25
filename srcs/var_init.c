/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:53 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/25 15:39:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mem_alloc(t_psychopomp *psy)
{
	psy->rule_book = malloc(sizeof(t_rule));
	if(!psy->rule_book)
		return (0);
	psy->clock = malloc(sizeof(t_time));
	if(!psy->clock)
	{
		free(psy->rule_book);
		return(0);
	}
	psy->lst_philo = malloc(sizeof(t_philo) * (rule->n_philo));
	if(!psy->lst_philo)
	{
		free(psy->rule_book);
		free(psy->lst_philo);
		return(0);
	}
	return (1);
}

static void	rule_set(t_rule *rule, int argc, char **argv)
{
	pthread_mutex_init(&(rule.m_all), NULL);
	rule->n_philo = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	if(argc == 5)
		rule->n_eat = -1;
	else
		rule->n_eat = ft_atoi(argv[5]);
	rule->is_end = 0;
}

static void	philo_set(t_philo *philo, t_rule *rule, t_time *time)
{
	int	i;

	i = 0;
	while(i < rule->n_philo)
	{
		pthread_mutex_init(&(philo[i].r_fork), NULL);
		if(i == rule->n_philo - 1)
			philo[i].l_fork = philo[0].r_fork;
		else
			philo[i].l_fork = philo[i + 1].r_fork;
		philo[i].tag = i + 1;
		philo[i].last_eat = 0;
		philo[i].rule_book = rule;
		philo[i].clock = time;
		i++;
	}
}

static void	time_set(t_time *time)
{
	time->t_start = get_time();
	getnupdate_time(time);
}

void	var_init(t_psychopomp *psy, int argc, char **argv)
{
	if (mem_alloc(psy))
		return;
	rule_set(psy->rule_book, argc, argv);
	time_set(psy->clock);
	philo_set(psy->lst_philo, psy->rule_book, psy->clock);
}
