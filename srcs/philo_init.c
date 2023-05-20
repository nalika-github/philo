/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:55:33 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/20 19:34:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *give_birth_to_philo(t_rule *rule)
{
	int		i;
	t_philo *philo;

	philo = malloc(sizeof(t_philo) * (rule->n_philo));
	if (!philo)
		return(NULL);
	i = 0;
	while(i < rule->n_philo)
	{
		pthread_mutex_init(&(philo[i].r_fork), NULL);
		i++;
	}
	i = 0;
	while(i < rule->n_philo)
	{
		if(i == rule->n_philo - 1)
			philo[i].l_fork = &(philo[0].r_fork);
		else
			philo[i].l_fork = &(philo[i + 1].r_fork);
		philo[i].tag = i;
		if(pthread_create(&(philo[i].phi), NULL, &philo_rotine, &philo[i]) != 0)
			return(NULL);
		i++;
	}
	return(philo);
}

t_philo	*philo_init(t_rule *rule, char **argv)
{
	rule->n_philo = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	rule->n_eat = ft_atoi(argv[5]);
	return(give_birth_to_philo(rule));
}
