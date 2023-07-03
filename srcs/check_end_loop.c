/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:08:23 by ptungbun          #+#    #+#             */
/*   Updated: 2023/07/03 14:05:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int destroy_fork(t_rule *rule)
{
	int	i;

	pthread_mutex_lock(&rule->m_all);
	i = 0;
	while (i < rule->n_philo)
	{
		if (pthread_mutex_destroy(&rule->philo[i].r_fork) != 0)
		{
			pthread_mutex_unlock(&rule->m_all);
			return (4);
		}
		i++;
	}
	pthread_mutex_unlock(&rule->m_all);
	return (0);
}

int	check_end_loop(t_rule *rule)
{
	int		i;
	t_philo	*philo;

	philo = rule->philo;
	i = 0;
	while (rule->is_end == 0 && rule->full_count < rule->n_philo)
	{
		if (i > rule->n_philo)
		{
			usleep(5000);
			i = 0;
		}
		if (rule->t_die < get_time() - philo[i].last_eat && \
		philo[i].eat_count < rule->n_eat)
		{
			rule->is_end = 1;
			philo_print_die(REDB ,ADE, philo[i], rule);
		}
	}
	usleep(200);
	return (destroy_fork(rule));
}
