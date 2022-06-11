/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_col_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:43:02 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/11 12:46:28 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

t_index	get_col_height(const t_board *board, t_index col)
{
	t_index	i;

	i = 0;
	while (board->board[col][i] != 0)
		i++;
	return (i);
}