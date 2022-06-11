/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_diag_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:48:53 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/11 17:32:20 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "connect4.h"

//static int	score_diag_up_right(const t_board *b, t_index index, t_index height);
//static int	score_diag_up_left(const t_board *b, t_index index, t_index height);

//int	score_diag_up(const t_board *b, t_index index)
//{
//	t_index	height;
//	int		right;
//	int		left;

//	height = get_col_height(b, index);
//	right = score_diag_up_right(b, index, height);
//	left = score_diag_up_left(b, index, height);
//	return (right + left);
//}

//static int	player_type_streak(const t_board *b, t_index index, t_index height,
//							char dir)
//{
//	if ((index == b->col && dir == DIR_R) || (index == 0 && dir == DIR_L)
//	|| (height == b->row))
//		return (OUT_OF_BOUNDS);
//	if (dir == DIR_R)
//		return (b->board[index + 1][height + 1]);
//	return (b->board[index - 1][height + 1]);
//}

//static int	score_diag_up_right(const t_board *b, t_index index, t_index height)
//{
//	int	i;
//	int	ret_val;

//	if (player_type_streak(b, index, height, DIR_R) == OUT_OF_BOUNDS)
//		return (OUT_OF_BOUNDS);
//	i = 0;
//	ret_val = 0;	
//	while (i + index < b->col && i < 4 && height + i < b->row)
//	{
//		if (i == 0 || b->board[index + i][height]
//			== b->board[index + i - 1][height])
//			ret_val++;
//		else
//			break;
//		i++;
//	}
//	ret_val *= ret_val;
//	if (player_type_streak(b, index, height, DIR_R) == USER)
//		return (ret_val - 1);
//	return (ret_val);
//}

//static int	score_diag_up_left(const t_board *b, t_index index, t_index height)
//{
//	int	i;
//	int	ret_val;

//	if (player_type_streak(b, index, height, DIR_L) == OUT_OF_BOUNDS)
//		return (OUT_OF_BOUNDS);
//	i = 0;
//	ret_val = 0;	
//	while (index - i > 0 && i < 4 && height + i < b->row)
//	{
//		if (i == 0 || b->board[index - i][height]
//			== b->board[index - i - 1][height])
//			ret_val++;
//		else
//			break;
//		i++;
//	}
//	ret_val *= ret_val;
//	if (player_type_streak(b, index, height, DIR_L) == USER)
//		return (ret_val - 1);
//	return (ret_val);
//}