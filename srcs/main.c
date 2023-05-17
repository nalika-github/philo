/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:35:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/17 15:40:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_rule	rule;

	if (argc != 5)
		return (0);
	if (philo_init(&rule, argv))
	{
		free_philo(rule);
		return (0);
	}
	// philo_life();
	// free_philo();
	return(0);
}
