/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_col_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:43:02 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/11 23:13:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

t_index	get_col_height(const t_board *board, const t_index col)
{
	t_index	i;

	i = 0;
	while (board->board[col][i] != 0)
		i++;
	return (i);
}
