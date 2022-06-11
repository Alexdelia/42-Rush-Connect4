/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:27:08 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 19:30:07 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

bool	init(t_env *e, const int ac, char **av)
{
	if (ac == 3)
	{
		if (!is_num(av[1]) || !is_num(av[2]))
			return (print_wrong_size());
		e->b.col = atoi(av[1]);
		e->b.row = atoi(av[2]);
		if (e->b.col < DEFAULT_COL/* || e->b.col >= MAX_SIZE*/
			|| e->b.row < DEFAULT_ROW/* || e->b.row >= MAX_SIZE*/)
			return (print_wrong_size());
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
