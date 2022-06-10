/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:27:08 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 21:55:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

bool	init(t_env *e, const int ac, char **av)
{
	(void)ac;
	(void)av;
	// board from arg
	// else ask
	e->b.col = DEFAULT_COL;
	e->b.row = DEFAULT_ROW;
	if (!init_board(e))
		return (false);
	e->b.n_move = 0;
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
	print_win_msg(&e, play(&e));
	free_board(e.b.board, e.b.col);
	return (0);
}
