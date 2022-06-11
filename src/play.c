/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:15:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 16:21:49 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

int	play(t_env *e)
{
	bool	legal;

	while (!is_board_full(&e->b)
		&& !is_connect(&e->b, AI) && !is_connect(&e->b, USER))
	{
		print_board(e);
		if (e->b.n_move % 2 + 1 != e->first)
		{
			legal = false;
			while (!legal)
				legal = prompt_user(e);
		}
		else
			ai(e);
	}
	if (is_connect(&e->b, AI))
		return (AI);
	else if (is_connect(&e->b, USER))
		return (USER);
	return (NONE);
}
