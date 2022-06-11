/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:58:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 13:02:48 by adelille         ###   ########.fr       */
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
		ft_psc(")\n", C_BLUE);
		return (false);
	}
	return (true);
}

static bool	no_input(char *buffer)
{
	free(buffer);
	buffer = NULL;
	ft_pserc("no input\n", C_YELLOW);
	return (false);
}

bool	prompt_user(t_env *e)
{
	char	*buffer;
	size_t	r;
	t_index	index;

	//if (is_board_empty(&e->b))
	ft_psc("\nEnter index of your coin ", C_BOLD);
	buffer = gnl(&r, false);
	if (!buffer || r == 0)
		return (no_input(buffer));
	if (!is_num(buffer))
	{
		print_wrong_index(buffer);
		free(buffer);
		return (false);
	}
	index = atoi(buffer);
	free(buffer);
	if (!is_index_in_range(index, e->b.col))
		return (false);
	return (add_coin(&e->b, index, USER)); //
}
