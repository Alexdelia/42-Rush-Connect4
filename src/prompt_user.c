/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:58:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 21:37:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool	is_index_in_range(const t_index index, const t_index size)
{
	if (index >= size)
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

bool	prompt_user(t_env *e)
{
	char	*buffer;
	size_t	r;
	t_index	index;

	if (is_board_empty(&e->b))
		ft_psc("\nEnter index of your coin ", C_BOLD);
	//r = read(STDIN_FILENO, buffer, r);	// buggy
	buffer = gnl(&r, false);
	/*if (r == 0)
	{
		free(buffer);
		ft_pserc("r == 0\n", C_RED);
		return (false);
	}*/
	if (!is_num(buffer))
	{
		ft_pserc("\"", C_RED);
		ft_pserc(buffer, C_MAGENTA);
		ft_pserc("\" is not a valid index\n", C_RED);
	}
	index = atoi(buffer);
	free(buffer);
	if (!is_index_in_range(index, e->b.col))
		return (false);
	return (add_coin(&e->b, index, USER)); //
}
