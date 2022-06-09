/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:15:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 00:06:10 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

int	play(t_env *e)
{
	bool	legal;
	bool	full;

	full = false;
	while (!full && !is_connect(e->board, e->col, e->row, AI))
	{
		print_board(e);
		legal = false;
		while (!legal)
			legal = prompt_user(e);
		full = is_board_full(e->board, e->col, e->row);
		if (full || is_connect(e->board, e->col, e->row, USER))
			return (!full * USER);
		//	ai play
		full = is_board_full(e->board, e->col, e->row);
	}
	return (!full * AI); //
}
