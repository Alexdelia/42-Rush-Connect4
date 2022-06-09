/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:29:00 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 00:20:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include <unistd.h>
# include <stdbool.h>
# include <time.h>	//

# include "../libft/inc/libft.h"

# define DEFAULT_COL	7
# define DEFAULT_ROW	6

# define NONE			0
# define USER			1
# define AI				2

# define COIN_EMPTY		" "
# define COIN_USER		"●"/*"⬤"*//*"⚉"*/
# define COIN_AI		"●"/*"⬤"*//*"⚇"*/

# define MAX_SIZE		256
# define BUFFER_SIZE	800000

# define C_FRAME		"\033[48;2;100;100;100m"

typedef struct s_env
{
	size_t	col;
	size_t	row;
	short	**board;
	char	*c_user;
	char	*c_ai;
}			t_env;

bool	init_board(t_env *e);

int		play(t_env *e);
bool	prompt_user(t_env *e);
void	ai(t_env *e);
bool	add_coin(t_env *e, const size_t index, const short player);

void	print_board(t_env *e);

void	free_board(short **board, const size_t size);

int		error(const char *str, const int ret);
bool	is_num(const char *n);
bool	is_board_empty(short **board, const size_t col);
bool	is_board_full(short **board, const size_t col, const size_t row);
int		is_connect(short **board,
			const size_t col, const size_t row, const short player);

#endif