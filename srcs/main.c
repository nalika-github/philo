/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:35:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/21 15:45:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rule	*rule;
	t_philo	*philo;
	t_time	*time;
	int		i;

	if (argc != 5 || argc != 6)
		return (0);
	rule = malloc(sizeof(t_rule));
	time = malloc(sizeof(t_time));
	philo = philo_init(rule, time, argc, argv);
	if(!philo)
	{
		// free_philo(&rule, &philo);
		return (0);
	}
	i = 0;
	while(i < rule->n_philo)
	{
		pthread_join(philo[i].phi, NULL);
		i++;
	}
	// free_philo(&rule, &philo);
	return(0);
}
