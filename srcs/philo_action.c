/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:30:52 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/21 17:59:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_sleep(t_philo philo)
{
	if(!is_die())
	{
		print();
		usleep();
		return(0)
	}
	if(is_limit_n_eat())
		return(2);
	return(1);
}

static int	philo_think(t_philo philo)
{
	if(!is_die())
	{
		print();
		usleep();
		return(0);
	}
	if(is_limit_n_eat())
		return(2);
	return(1);
}

static int	take_fork(t_philo philo)
{
	pthread_mutex_lock(&philo.r_fork);
	pthread_mutex_lock(philo.l_fork);
}

static int	philo_eat(t_philo philo)
{
	if(!is_die())
	{
		take_fork();
		print();
		usleep();
		pthread_mutex_unlock(&philo.r_fork);
		pthread_mutex_unlock(philo.l_fork);
		return(0);
	}
	if(!is_die())
		print();
}
