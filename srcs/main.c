/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:35:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/25 15:58:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	end(t_psychopompc *psy)
{
	int		i;

	i = 0;
	while(i < psy->rule.n_philo)
	{
		if (pthread_join(&psy->philo[i].phi, NULL) != 0)
			return (1);
		pthread_mutex_destroy(&psy->philo[i].phi, NULL);
		i++;
	}
	if (pthread_join(&psy->dead, NULL) != 0)
		return (1);
	pthread_mutex_destroy(&psy->dead, NULL);
	return(free_all(psy));
}

int	main(int argc, char **argv)
{
	t_psychopomp	*psy;
	int				i;

	if (argc >= 5 && argc <= 6)
		return (0);
	psy = malloc(sizeof(t_psychopomp));
	if (!psy)
		return (0);
	var_init(psy, argc, argv);
	philo_init(psy->lst_philo);
	psychopomp_init(psy);
	return(end(psy));
}
