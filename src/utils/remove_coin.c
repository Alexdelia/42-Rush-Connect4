/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:24:08 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 19:27:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	remove_coin(t_board *b, const t_index index)
{
	t_index	r;

	r = b->row - 1;
	while (r > 0 && b->board[index][r] == NONE)
		r--;
	b->board[index][r] = NONE;
}
