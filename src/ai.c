/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 18:35:00 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static bool	is_winning_move(t_board b, const t_index move, const t_coin player)
{
	add_coin(&b, move, player);
	return (is_connect(&b, player));
}

//static t_index	solve(const t_board *b)
//{
//	t_index	index;

//	index = rand() % b->col;
//	while (is_col_full(b, index))
//		index = rand() % b->col;

//	return (index);
//}

static t_index	forced(const t_board *b)
{
	t_index	index;

	index = -1;
	while (++index < b->col)
		if (!is_col_full(b, index) && is_winning_move(*b, index, AI))
			return (index);
	index = -1;
	while (++index < b->col)
		if (!is_col_full(b, index) && is_winning_move(*b, index, USER))
			return (index);
	if (is_board_empty(b))
		return ((t_index)(b->col / 2));
	return (MAX_SIZE);
}

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

static t_index	nathan_ai(t_env *e);

void	ai(t_env *e)
{
	t_index	index;

	index = forced(&e->b);
	if (index == MAX_SIZE)
		index = nathan_ai(e);

	if (!add_coin(&e->b, index, AI))
		exit(print_col_full(index));// tmp
}

static t_index	nathan_ai(t_env *e)
{
	t_moves	moves;
	int		i;
	int		curr_score;

	i = 0;
	moves.best_index = 0;
	moves.best_score = -1;
	while (i < e->b.col)
	{
		curr_score = get_score(&e->b, i);
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
	ft_putstr_fd("\n--------------------", 2);
	if (moves.best_score <= 0)
	{
		ft_putstr_fd("\nmoves.best_score <= 0: random\n", 2);
		return (rand() % e->b.col);
	}
	return (moves.best_index);
}

int	get_score(const t_board *b, int index)
{
	int	score;
	int	col_height;
	int	score_tab[4];

	// check si le pion qu'on met win
	score = 0;
	ft_putstr_fd("\ncolone:", 2);
	ft_putnbr_fd(index, 2);
	ft_memset(score_tab, 0, 16);


	col_height = get_col_height(b, index);
	score_tab[0] += score_hor(b, index);
	score_tab[1] += score_diag_up(b, index);
	score_tab[2] += score_diag_down(b, index);
	//ajust_tab(score_tab);
	
	
	for (int i = 0; i < 4; i++)
	{
		ft_putstr_fd("\t\t", 2);
		ft_putnbr_fd(score_tab[i], 2);
	}
	score = score_tab[0] + score_tab[1] + score_tab[2] + score_tab[3];
	//score += score_down(b, index);
	ft_putstr_fd("\nscore:", 2);
	ft_putnbr_fd(score, 2);
	ft_putstr_fd("\n", 2);
	return (score);
}