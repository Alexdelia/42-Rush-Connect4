/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:27:08 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 13:59:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

bool	init(t_env *e, int ac, char **av)
{
	(void)ac;
	(void)av;
	// board from arg
	// else ask
	e->col = DEFAULT_COL;
	e->row = DEFAULT_ROW;
	if (!init_board(e))
		return (false);
	// choose color
	e->c_user = C_RED;
	e->c_ai = C_YELLOW;
	return (true);
}

int	main(int ac, char **av)
{
	t_env	e;

	if (!init(&e, ac, av))
		return (1);

	play(&e);	// might get return if win or lose or full board

	// test
	e.board[2][0] = USER;
	e.board[2][1] = AI;
	e.board[3][0] = USER;
	e.board[4][0] = AI;
	//e.board[4][1] = USER;
	print_board(&e);

	free_board(e.board, e.col);
	return (0);
}
