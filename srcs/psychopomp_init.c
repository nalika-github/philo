/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psychopomp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:08:23 by ptungbun          #+#    #+#             */
/*   Updated: 2023/05/25 15:59:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	who_die(void *vp_psychopomp)
{
	int				i;
	t_psychopomp	*psy;

	psy = (t_psy *)vp_psy;
	i = 0;
	while(i < psy->rule_book->n_philo && pys->rule_book.is_end == 0)
	{
		if (is_die((psy->lst_philo)[i]))
			pys->rule_book.is_end = 1;
		if (is_limit((psy->lst_philo)[i]))
			pys->rule_book.is_end = 2;
		i++;
	}
	if (pys->rule_book.is_end == 1)
		print(&((psy->lst_philo)[i - 1]), "died\n");
}
