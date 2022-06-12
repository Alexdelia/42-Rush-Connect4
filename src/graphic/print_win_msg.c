/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_win_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:33:13 by adelille          #+#    #+#             */
/*   Updated: 2022/06/12 14:12:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void	user_win(void)
{
	ft_psc("\n  You won!\n", "\033[1;32m");
}

static void	ai_win(void)
{
	ft_psc("\n  You lost\n", "\033[1;31m");
}

static void	board_full(void)
{
	ft_psc("\n  board is full: draw\n", "\033[1;90m");
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
		if (is_connect(&e->b, USER))
			user_win();
		else if (is_connect(&e->b, AI))
			ai_win();
		else
			board_full();
	}
}
