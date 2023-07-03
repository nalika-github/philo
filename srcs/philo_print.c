/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:18:32 by ptungbun          #+#    #+#             */
/*   Updated: 2023/06/29 14:19:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_print(char *color, char *act ,t_philo philo, t_rule *rule)
{
	pthread_mutex_lock(&rule->m_all);
	if (!rule->is_end)
		printf("%s%ld %d %s%s\n", color, get_time() - rule->t_start\
		, philo.id, act, "\e[0m");
	pthread_mutex_unlock(&rule->m_all);
}

void philo_print_die(char *color, char *act ,t_philo philo, t_rule *rule)
{
	pthread_mutex_lock(&rule->m_all);
	printf("%s%ld %d %s%s\n", color, get_time() - rule->t_start\
	, philo.id, act, "\e[0m");
	pthread_mutex_unlock(&rule->m_all);
}
