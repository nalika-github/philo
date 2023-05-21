/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:34 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/21 17:39:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


// ---Standard Header---

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

// Define Constant

# define TRUE 1
# define FALSE 0

// Define Structure

typedef struct s_rule
{
	pthread_mutex_t	util_mutex;
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
}	t_rule;

typedef struct s_philo
{
	int				tag;
	int				last_eat;
	int				is_die;
	t_rule			*rule_book;
	t_time			*clock;
	pthread_t		phi;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_time
{
	long long	t_start;
	long long	t_current;
	long long	philo_time;
}	t_time;

// Define Function

t_philo	*philo_init(t_rule *rule, char **argv);
void	*philo_rotine();

#endif
