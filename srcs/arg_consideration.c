/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_consideration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:53:39 by ptungbun          #+#    #+#             */
/*   Updated: 2023/06/26 17:27:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_error(int	error_index)
{
	if (error_index == 1)
		printf("Error: invalid argument (number of argument have to be 4 or 5)\n");
	if (error_index == 2)
		printf("Error: invalid argument (argument can be only positive int)\n");
	if (error_index == 3)
		printf("Error: invalid argument (n_philo can't be zero)\n");
	if (error_index == 4)
		printf("Error: invalid argument (n_eat can't be zero)\n");
}

static int is_all_digi(char **argv)
{
	int	i;
	int	j;
	char c;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (!(c >= '0' && c <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_consideration(int argc, char **argv)
{
	int	error_index;

	error_index = 0;
	if(argc < 5 || argc > 6)
		error_index = 1;
	else if(!is_all_digi(argv))
		error_index = 2;
	else if(ft_atoi(argv[1]) <= 0)
		error_index = 4;
	else if(argc == 6)
	{
		if(ft_atoi(argv[5]) <= 0)
			error_index = 4;
	}
	if (error_index != 0)
	{
		print_error(error_index);
		return (1);
	}
	return (0);
}
