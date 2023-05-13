/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <ptungbun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:35:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/13 14:57:31 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	if (argc != 5)
		return (0);
	if (data_init(&data, av) == 1)
	{
		free();
		return (0);
	}
	philo();
	free_philo();
	return(0);
}