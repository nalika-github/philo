/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:55:33 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/17 15:40:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	give_birth_to_philo(t_rule *rule, t_philo *philo)
{
	philo = malloc(sizeof(t_philo));
}

bool	philo_inti(t_rule *rule, t_philo *philo, char **argv)
{
	rule = malloc(sizeof(t_rule));
	if(!rule)
		return(FALSE);
	rule->n_philo = atoi(argv[1]);
	rule->t_die = atoi(argv[2]);
	rule->t_eat = atoi(argv[3]);
	rule->t_sleep = atoi(argv[4]);
	rule->n_eat = atoi(argv[5]);
	return(give_birth_to_philo(rule, philo));
}
