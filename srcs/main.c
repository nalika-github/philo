/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:35:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/07/08 13:56:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rule	*rule;
	int		status;

	status = 0;
	status = arg_consideration(argc, argv);
	if (status == 0)
	{
		rule = malloc(sizeof(t_rule));
		if (!rule)
			return (1);
	}
	if (status == 0)
		status = var_init(rule, argc, argv);
	if (status == 0)
		status = thread_init(rule);
	if (status == 0)
		status = check_end_loop(rule);
	if (status != 1)
		clear_mem(rule);
	return (0);
}

int	clear_mem(t_rule *rule)
{
	free(rule->philo);
	free(rule);
	return (0);
}
