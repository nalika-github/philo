/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:55:33 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/21 17:57:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_mutex(t_rule *rule, t_philo *philo)
{
	int		i;

	pthread_mutex_init(&(rule->util_mutex), NULL);
	i = 0;
	while(i < rule->n_philo)
	{
		pthread_mutex_init(&(philo[i].r_fork), NULL);
		i++;
	}
}

t_philo *give_birth_to_philo(t_rule *rule, t_time *time)
{
	int		i;
	t_philo *philo;

	philo = malloc(sizeof(t_philo) * (rule->n_philo));
	if (!philo)
		return(NULL);
	init_mutex(rule, philo);
	time->t_start = get_time();
	i = 0;
	while(i < rule->n_philo)
	{
		if(i == rule->n_philo - 1)
			philo[i].l_fork = &(philo[0].r_fork);
		else
			philo[i].l_fork = &(philo[i + 1].r_fork);
		philo[i].tag = i + 1;
		philo[i].rule_book = rule;
		philo[i].clock = time;
		pthread_mutex_lock(&(rule->util_mutex))
		if(pthread_create(&(philo[i].phi), NULL, &philo_rotine, &philo[i]) != 0)
			return(NULL);
		i++;
	}
	return(philo);
}

t_philo	*philo_init(t_rule *rule, t_time *time, char **argv)
{
	rule->n_philo = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	rule->n_eat = ft_atoi(argv[5]);
	return(give_birth_to_philo(rule, time));
}
