/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:08:53 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/20 19:31:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep()
{
	usleep();
	if(!is_die())
		print();
}

static void	philo_think()
{
	usleep();
	if(!is_die())
		print();
}

static void	philo_eat()
{
	pthread_mutex_lock(&philo.r_fork);
	pthread_mutex_lock(philo.l_fork);
	printf("philo.tag = %d eatting\n", philo.tag);
	pthread_mutex_unlock(&philo.r_fork);
	pthread_mutex_unlock(philo.l_fork);
	if(!is_die())
		print();

void	*philo_rotine(void *vp_philo)
{
	t_philo	philo;

	philo = *(t_philo *)vp_philo;
	philo_sleep();
	philo_thinking();
	philo_eat();
	return(NULL);
}
