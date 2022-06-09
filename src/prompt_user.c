/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:58:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 00:19:08 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool	is_index_in_range(const size_t index, const size_t size)
{
	if (index < 0 || index >= size)
	{
		ft_pnerc(index, C_MAGENTA);
		ft_pserc(" is out of range\t", C_RED);
		ft_pserc("(0 =< ", C_BLUE);
		ft_pserc("index", C_MAGENTA);
		ft_pserc(" < ", C_BLUE);
		ft_pnerc(size, C_BLUE);
		ft_ps(")\n");
		return (false);
	}
	return (true);
}

bool	add_coin(t_env *e, const size_t index, const short player)
{
	size_t	i;

	i = 0;
	while (i < e->row)
	{
		if (e->board[index][i] == NONE)
		{
			e->board[index][i] = player;
			return (true);
		}
		i++;
	}
	ft_pserc("column ", C_RED);
	ft_pnerc(index, C_MAGENTA);
	ft_pserc(" is full\n", C_RED);
	return (false);
}

bool	prompt_user(t_env *e)
{
	char	buffer[4];
	ssize_t	r;
	size_t	index;

	if (is_board_empty(e->board, e->col))
		ft_psc("\nEnter index of your coin ", C_BOLD);
	if (e->col < 10)
		r = 1;
	else
		r = 3;
	r = read(STDIN_FILENO, buffer, r);	// buggy
	if (r < 1)
		return (false);
	buffer[r] = '\0';
	if (!is_num(buffer))
	{
		ft_pserc("\"", C_RED);
		ft_pserc(buffer, C_MAGENTA);
		ft_pserc("\" is not a valid index\n", C_RED);
	}
	index = atoi(buffer);
	if (!is_index_in_range(index, e->col))
		return (false);
	return (add_coin(e, index, USER)); //
}
