/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:08:53 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/21 18:05:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_rotine(t_philo philo)
{
	int	end_case;

	pthread_mutex_unlock(&(philo.rule->util_mutex));
	end_case = 0;
	while(!end_case)
	{
		if(!end_case)
			end_case = philo_sleep(philo);
		if(!end_case)
			end_case = philo_think(philo);
		if(!end_case)
			end_case = philo_eat(philo);
	}
	// print(end_case);
	return;
}

void	*philo_rotine(void *vp_philo)
{
	t_philo	philo;

	philo = *(t_philo *)vp_philo;
	do_rotine(philo);
}
