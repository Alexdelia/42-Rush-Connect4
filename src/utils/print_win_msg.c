/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_win_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:33:13 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 11:11:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/connect4.h"

static void	user_win(void)
{
	ft_pser("you win\n");
}

static void	ai_win(void)
{
	ft_pser("you lose\n");
}

static void	board_full(void)
{
	ft_pser("board is full\n");
}

void	print_win_msg(t_env *e, const int who)
{
	gnl(NULL, true);
	print_board(e);
	if (who == USER)
		user_win();
	else if (who == AI)
		ai_win();
	else
	{
		if (is_connect(e->board, e->col, e->row, USER))
			user_win();
		else if (is_connect(e->board, e->col, e->row, AI))
			ai_win();
		else
			board_full();
	}
}
