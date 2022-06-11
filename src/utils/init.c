/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:43:40 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 21:16:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	init_first_player(t_env *e)
{
	if (rand() % 2)
	{
		e->first = USER;
		e->c_user = COIN_YELLOW;
		e->c_ai = COIN_RED;
	}
	else
	{
		e->first = AI;
		e->c_user = COIN_RED;
		e->c_ai = COIN_YELLOW;
	}
}

bool	init_col_row(t_env *e, char **av)
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
