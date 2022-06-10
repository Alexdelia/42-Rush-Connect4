/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:04:40 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 21:05:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

bool	add_coin(t_board *b, const t_index index, const t_coin player)
{
	t_index	i;

	i = 0;
	while (i < b->row)
	{
		if (b->board[index][i] == NONE)
		{
			b->board[index][i] = player;
			return (true);
		}
		i++;
	}
	ft_pserc("column ", C_RED);
	ft_pnerc(index, C_MAGENTA);
	ft_pserc(" is full\n", C_RED);
	return (false);
}