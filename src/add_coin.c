/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:58:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 13:59:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static void	print_coin_out_of_range(const size_t index, const size_t size)
{
	ft_pnerc(index, C_MAGENTA);
	ft_pserc(" is out of range\t", C_RED);
	ft_pserc("(0 =< ", C_BLUE);
	ft_pserc("index", C_MAGENTA);
	ft_pserc(" < ", C_BLUE);
	ft_pnerc(size, C_BLUE);
	ft_ps(")\n");
}

bool	add_coin(t_env *e, const size_t index, const short player)
{
	size_t	i;

	if (index < 0 || index >= e->col)
	{
		print_coin_out_of_range(index, e->col);
		return (false);
	}
	i = 0;
	while (i < e->row)
	{
		if (e->board[index][i] == NONE)
		{
			e->board[index][i] = player;
			return (true);
		}
		i++;
	}
	ft_pserc("column ", C_RED);
	ft_pnerc(index, C_MAGENTA);
	ft_pserc(" is full\n", C_RED);
	return (false);
}
