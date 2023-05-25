/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:34 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/25 15:26:29 by marvin           ###   ########.fr       */
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

// Define Structure

typedef struct s_rule
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				is_end;
	pthread_mutex_t	m_all;
}	t_rule;

typedef struct s_psychopomp
{
	t_philo			*lst_philo;
	t_rule			*rule_book;
	t_time			*clock;
	pthread_t		dead;
}	t_psychopomp;

typedef struct s_philo
{
	int				tag;
	long long		last_eat;
	t_rule			*rule_book;
	t_time			*clock;
	pthread_t		phi;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_time
{
	long long	t_start;
	long long	t;
}	t_time;

// fuction in philo_init.c file

t_philo	*philo_init(t_rule *rule, t_time *time, int argc, char **argv)

// fuction in philo_action.c file

int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
int		philo_eat(t_philo *philo);

// fuction in philo_rotine.c file

int	var_init(t_psychopomp *psy, int argc, char **argv)

// fuction in philo_rotine.c file

void	*philo_rotine(void *vp_philo);

#endif
