/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:55:33 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/25 16:12:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	do_rotine(t_philo *philo)
{
	int	end_case;

	end_case = 0;
	while(philo.rule_book->is_end == 0)
	{
		if(!end_case)
			end_case = philo_sleep(philo);
		if(!end_case)
			end_case = philo_think(philo);
		if(!end_case)
			end_case = philo_eat(philo);
	}
	return;
}

static void	*philo_rotine(void *vp_philo)
{
	t_philo	philo;

	philo = *(t_philo *)vp_philo;
	philo.last_eat = getnupdate_time(philo.clock);
	do_rotine(philo);
	return (NULL);
}

int	philo_init(t_philo *philo)
{
	int	i;

	i = 0;
	while(i < rule->n_philo)
	{
		if(pthread_create(&(philo[i].phi), NULL, &philo_rotine, &philo[i]) != 0)
			return(2);
		i++;
	}
}
