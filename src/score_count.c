/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:31:34 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/11 12:50:06 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "connect4.h"

int	score_hor(const t_board *b, t_index index, char direction)
{
	t_index	height;

	height = get_col_height(b, index);
	if (direction == SC_RIGHT)
	{
		
	}
}

