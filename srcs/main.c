/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:35:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/06/26 15:11:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if(!rule)
			return (1);
	}
	if (status == 0)
		status = var_init(rule, argc, argv);
	if (status == 0)
		status = thread_init(rule);
	if (status == 0)
		status = check_end_loop(rule);
	if (status != 0)
		return (ft_status(status));
	if (status > 1)
		clear_mem(rule);
	return (0);
}

int	ft_status(int status)
{
	if (status == 2)
		printf("Error: There're something worng in var_init\n");
	if (status == 3)
		printf("Error: There're something worng in thread_init\n");
	if (status == 4)
		printf("Error: There're something worng in check_end_loop\n");
	return (1);
}

int	clear_mem(t_rule *rule)
{
	free(rule->philo);
	free(rule);
	return(0);
}


