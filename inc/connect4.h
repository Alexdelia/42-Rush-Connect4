/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:29:00 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 10:17:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include "../libft/inc/libft.h"

# define DEFAULT_COL	7
# define DEFAULT_ROW	6

enum e_coin
{
	NONE
	USER
	AI
};

typedef struct s_env
{
	size_t	col;
	size_t	row;
	short	**board;
}			t_env;

bool	init_board(t_env *e);

void	free_board(short **board, size_t size);

#endif