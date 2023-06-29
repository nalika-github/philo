/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:34 by ptungbun          #+#    #+#             */
/*   Updated: 2023/06/28 11:15:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


/* Standard Header  */

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

/* text color */
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define PUR "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

/* bold text color */

#define REDB "\e[1;31m"
#define GRNB "\e[1;32m"
#define YELB "\e[0;33m"
#define BLUB "\e[1;34m"
#define PURB "\e[1;35m"
#define CYNB "\e[1;36m"
#define WHTB "\e[1;37m"

/* Philo Action */

#define ATF "has taken a fork"
#define AET "is eating"
#define ASP "is sleeping"
#define ATK "is thinking"
#define ADE "is died"

/*  Define Structure  */

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_eat;
	pthread_t		phi;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_rule
{
	int				arg_id;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				is_end;
	int				full_count;
	t_philo			*philo;
	long			t_start;
	pthread_mutex_t	m_all;
}	t_rule;

/*  main.c  */

int			ft_status(int status);
int			clear_mem(t_rule *rule);

/*  var_init.c  */

int			var_init(t_rule *rule, int argc, char **argv);

/*  mini_lib.c  */

int			ft_atoi(const char *str);
long		get_time(void);
void 		philo_print(char *color, char *act ,t_philo philo, t_rule *rule);

/*  arg_consideration.c  */

int			arg_consideration(int argc, char **argv);

/*  thread_init.c  */

int			thread_init(t_rule *rule);

/*  check_end_loop.c  */

int			check_end_loop(t_rule *rule);

#endif
