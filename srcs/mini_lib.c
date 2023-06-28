/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:35:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/06/26 17:30:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sign_toint(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	return (1);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' )
		return (1);
	if (c == '\f' || c == '\r' || c == ' ' )
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		sign = sign_toint(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

void philo_print(char *color, char *act ,t_philo philo, t_rule *rule)
{
	pthread_mutex_lock(&rule->m_all);
	printf("%s%ld %d %s%s\n", color, get_time() - rule->t_start\
	, philo.id, act, "\e[0m");
	pthread_mutex_unlock(&rule->m_all);
}
