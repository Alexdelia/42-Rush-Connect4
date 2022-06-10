/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 16:27:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static size_t	solve(t_env *e, size_t *node_count)
{
	unsigned short	index;

	*node_count += 1;
	if (is_board_full(e->board, e->col, e->row))
		return (0);
	index = -1;
	while (++index < e->col)
		if (
}

void	ai(t_env *e)
{
	unsigned short	index;
	size_t	node_count;

	/*
	srand(time(NULL));
	index = rand() % e->col;
	*/
	index = solve(e, &node_count);
	ft_pnerc(node_count, C_RED);	// tmp

	if (!add_coin(e, index, AI))
	{
		ft_pser(C_BOLD);
		ft_pserc("AI tried to insert coin on full col\n", RED);
		exit(1);	// tmp
	}
}
