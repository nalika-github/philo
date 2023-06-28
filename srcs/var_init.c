/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:53 by ptungbun          #+#    #+#             */
/*   Updated: 2023/06/28 10:39:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	rule_set(t_rule *rule, int argc, char **argv)
{
	if(pthread_mutex_init(&(rule->m_all), NULL) != 0)
		return (0);
	rule->n_philo = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	rule->full_count = 0;
	if(argc == 5)
		rule->n_eat = -1;
	else
		rule->n_eat = ft_atoi(argv[5]);
	rule->is_end = 0;
	return (1);
}

static int	philo_set(t_rule *rule)
{
	int		i;
	t_philo	*philo;

	philo = rule->philo;
	i = 0;
	while(i < rule->n_philo)
	{
		if (pthread_mutex_init(&(philo[i].r_fork), NULL) != 0)
			return (0);
		if(i == rule->n_philo - 1)
			philo[i].l_fork = &philo[0].r_fork;
		else
			philo[i].l_fork = &philo[i + 1].r_fork;
		philo[i].id = i + 1;
		if (rule->n_eat == -1)
			philo[i].eat_count = -2;
		else
			philo[i].eat_count = 0;
		i++;
	}
	return (1);
}

int	var_init(t_rule *rule, int argc, char **argv)
{
	if(!rule_set(rule, argc, argv))
		return (2);
	rule->philo = malloc(sizeof(t_philo) * (rule->n_philo));
	if(!rule->philo)
	{
		free(rule);
		return(2);
	}
	if(!philo_set(rule))
	{
		free(rule);
		return(2);
	}
	return (0);
}
