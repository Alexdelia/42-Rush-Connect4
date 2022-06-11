/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 17:31:48 by nguiard          ###   ########.fr       */
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

	//Si on est au debut du jeu, pion random random
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
		ft_putnbr_fd(i, 2);
		i++;
	}
	ft_putstr_fd("\n--------------------", 2);
	if (moves.best_score <= 0)
	{
		ft_putstr_fd("\nmoves.best_score <= 0: random\n", 2);
		add_coin(&e->b, rand() % e->b.col, AI);
		return ;
	}
	add_coin(&e->b, moves.best_index, AI);
}

//void	score_tab(int *tab)
//{
//	int	max;
//	int i;

//	i = 4;
//	max = 0;
//	while (i < 4)
//	{
//		if (tab[i] > max)
//			max = tab[i];
//		i++;
//	}
//	i = 0;
//	while ()
//}

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
	//score_tab[2] += score_diag_down(b, index);
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