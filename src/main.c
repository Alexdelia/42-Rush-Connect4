/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:27:08 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 19:58:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static bool	init_col_row(t_env *e, char **av)
{
	long	col;
	long	row;

	if (!is_num(av[1]) || !is_num(av[2]))
		return (print_wrong_size());
	col = ft_atol(av[1]);
	row = ft_atol(av[2]);
	if (col < DEFAULT_COL || col >= MAX_SIZE
		|| row < DEFAULT_ROW || row >= MAX_SIZE)
		return (print_wrong_size());
	e->b.col = col;
	e->b.row = row;
	return (true);
}

static bool	init(t_env *e, const int ac, char **av)
{
	if (ac == 3)
	{
		if (!init_col_row(e, av))
			return (false);
	}
	else
	{
		ft_psc("No size specified, using default\n", C_BOLD);
		e->b.col = DEFAULT_COL;
		e->b.row = DEFAULT_ROW;
	}
	if (!init_board(e))
		return (false);
	e->b.n_move = 0;
	srand(time(NULL));
	init_first_player(e);
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
