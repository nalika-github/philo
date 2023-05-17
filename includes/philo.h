/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:34 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/17 14:07:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_rule
{
	int	rule_n_philo;
	int	rule_t_die;
	int	rule_t_eat;
	int	rule_n_eat;
	int	rule_t_sleep;
}	t_rule;

typedef struct s_philo
{
	int				tag;
	pthread_t		philo;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	friend_fork;
}	t_philo;

#endif
