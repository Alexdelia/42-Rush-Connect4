/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_win_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:33:13 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 21:26:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void	user_win(void)
{
	ft_ps("\n  \033[1;32mYou won!\n");
}

static void	ai_win(void)
{
	ft_ps("\n  \033[1;31mYou lost\n");
}

static void	board_full(void)
{
	ft_ps("\n  \033[1;90mboard is full: draw\n");
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
