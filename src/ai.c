/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 23:40:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

void	ai(t_env *e)
{
	size_t	index;

	srand(time(NULL));
	index = rand() % e->b.col;
	while (is_col_full(&e->b, index))
		index = rand() % e->b.col;

	if (!add_coin(&e->b, index, AI))
	{
		ft_pser(C_BOLD);
		ft_pserc("AI tried to insert coin on full col\n", RED);
		exit(1);	// tmp
	}
}
