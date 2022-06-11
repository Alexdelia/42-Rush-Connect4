/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:44:16 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/11 18:52:18 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	score_down(const t_board *b, t_index index)
{
	t_index	height;
	int	i;

	height = get_col_height(b, index);
	i = 1;
	if (height - 1 == 0 || height == 0)
		return (0);
	if (!(b->board[index][height - 1] == b->board[index][height - 2]))
		return (0);	
	if (b->board[index][height - 1] == AI)
		return (20);
	else if (b->board[index][height - 1] == USER)
		return (15);
	return (0);
}