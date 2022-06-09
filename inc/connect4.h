/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:29:00 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 11:16:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include "../libft/inc/libft.h"

# define DEFAULT_COL	7
# define DEFAULT_ROW	6

# define NONE			0
# define USER			1
# define AI				2

# define COIN_EMPTY		" "
# define COIN_USER		"⬤"/*"⚉"*/
# define COIN_AI		"⬤"/*"⚇"*/

# define MAX_SIZE		255
# define BUFFER_SIZE	800000

typedef struct s_env
{
	size_t	col;
	size_t	row;
	short	**board;
	char	*c_user;
	char	*c_ai;
}			t_env;

bool	init_board(t_env *e);

void	print_board(t_env *e);

int		error(const char *str, const int ret);

void	free_board(short **board, const size_t size);

#endif