/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:15:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 22:37:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool	prompt_user(t_env *e)
{
	char	buffer[4];
	ssize_t	r;

	if (is_board_empty(e->board, e->col))
		ft_psc("\nEnter index of your coin ", C_BOLD);
	if (e->col < 10)
		r = 1;
	else
		r = 3;
	r = read(STDIN_FILENO, buffer, r);
	if (r < 1)
		return (false);
	buffer[r] = '\0';
	if (!is_num(buffer))
	{
		ft_pserc("\"", C_RED);
		ft_pserc(buffer, C_MAGENTA);
		ft_pserc("\" is not a valid index\n", C_RED);
	}
	return (add_coin(e, atoi(buffer), USER)); //
}

int	play(t_env *e)
{
	bool	legal;

	// while (!lose && !board_full)
	print_board(e);
	legal = false;
	while (!legal)
		legal = prompt_user(e);
	//	if (win || board_full)
	//		exit / break
	//	ai play

	return (true); //
}
