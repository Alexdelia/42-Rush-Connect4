/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 12:42:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

//void	ai(t_env *e)
//{
//	size_t	index;

//	srand(time(NULL));
//	index = rand() % e->b.col;
//	while (is_col_full(&e->b, index))
//		index = rand() % e->b.col;

//	if (!add_coin(&e->b, index, AI))
//	{
//		ft_pser(C_BOLD);
//		ft_pserc("AI tried to insert coin on full col\n", RED);
//		exit(1);	// tmp
//	}
//}

void	ai(t_env *e)
{
	t_moves	moves;
	int		i;
	int		curr_score;

	i = 0;
	moves.best_index = 0;
	moves.best_score = -1;
	while (i < e->b.col)
	{
		curr_score = get_score(e->b, i);
		if (curr_score == WIN_SCORE)
		{
			moves.best_index = i;
			break ;
		}
		if (curr_score > moves.best_score)
		{	moves.best_index = i;
			moves.best_score = curr_score;
		}
		i++;
	}
	add_coin(&e->b, moves.best_index, AI);
}

int	get_score(t_board b, int index)
{
	int	score;
	int	col_height;

	// check si le pion qu'on met win
	score = 0;
	col_height = get_col_height(b, index);
	score += score_hor(b, index, SC_RIGHT);
	score += score_hor(b, index, SC_LEFT);
	score += score_diag_up(b, index, SC_RIGHT);
	score += score_diag_up(b, index, SC_LEFT);
	score += score_diag_down(b, index, SC_RIGHT);
	score += score_diag_down(b, index, SC_LEFT);
	score += score_down(b, index);
	return (score);
}