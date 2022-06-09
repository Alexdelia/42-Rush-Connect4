/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:27:08 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 00:07:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

bool	init(t_env *e, const int ac, char **av)
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

	free_board(e.board, e.col);
	return (0);
}
