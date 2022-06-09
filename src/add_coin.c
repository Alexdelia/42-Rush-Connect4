/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:58:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 13:06:49 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

bool	add_coin(t_env *e, const size_t index, const short player)
{
	size_t	i;

	if (index < 0 || index >= e->col)
		return (false);
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
	return (false);
}
