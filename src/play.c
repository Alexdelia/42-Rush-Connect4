/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:15:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 00:14:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

int	play(t_env *e)
{
	bool	legal;
	bool	full;

	full = false;
	while (!full && !is_connect(&e->b, AI))	// first to play need to be randomly choosen
	{
		print_board(e);
		legal = false;
		while (!legal)
			legal = prompt_user(e);
		print_board(e);
		//sleep(5);
		full = is_board_full(&e->b);
		if (full || is_connect(&e->b, USER))
			return (!full * USER);
		ai(e);
		full = is_board_full(&e->b);
	}
	return (!full * AI); //
}
