/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:30:52 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/24 17:14:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	print_action(&philo, "is sleeping\n");
	usleep(philo.rule_book->t_sleep);
}

void	philo_think(t_philo *philo)
{
	print_action(&philo, "is thinking\n");
	usleep(philo.rule_book->t_think);
}

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo.r_fork);
	print_action(&philo, "has taken a fork\n");
	pthread_mutex_lock(philo.l_fork);
	print_action(&philo, "has taken a fork\n");
}

void	philo_eat(t_philo *philo)
{
	take_fork(&philo);
	print_action(&philo, "is eating\n");
	philo.clock->t = getnupdate_time(t_time *time)
	usleep(philo.rule_book->t_eat);
	pthread_mutex_unlock(&philo.r_fork);
	pthread_mutex_unlock(philo.l_fork);
}
