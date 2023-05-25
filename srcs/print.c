/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:05:17 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/25 16:00:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *ac_str)
{
	long long	timestamp;

	timestamp = phlio->clock.t_start - getnupdate_time(philo->clock);
	printf("%ld %d %s", timestamp, philo->tag, ac_str);
}
