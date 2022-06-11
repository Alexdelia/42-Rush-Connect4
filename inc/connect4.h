/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:29:00 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 21:17:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include <unistd.h>
# include <stdbool.h>
# include <time.h>

# include "libft.h"

# define DEFAULT_COL	7
# define DEFAULT_ROW	6

# define NONE			0
# define USER			1
# define AI				2

# define COIN_EMPTY		"  "
# define COIN_USER		""/*"● "*//*"⬤"*//*"⚉"*/
# define COIN_AI		""/*"✘ "*//*"⬤"*//*"⚇"*/
# define COIN_SIZE		2

/*# define COIN_RED		C_RED
# define COIN_YELLOW	C_YELLOW*/
# define COIN_RED		"🔴"
# define COIN_YELLOW	"🟡"

# define MAX_SIZE			USHRT_MAX
# define BUFFER_SIZE		800000
# define GNL_BUFFER_SIZE	16

# define C_FRAME		"\033[48;2;100;100;100m"

# define WIN_SCORE		1000000
# define DENY_SCORE		500000

# define DIR_R			1
# define DIR_L			0
# define OUT_OF_BOUNDS	0

typedef unsigned short	t_index;
typedef char			t_coin;

typedef struct s_board
{
	t_coin	**board;
	t_index	col;
	t_index	row;
	size_t	n_move;
}			t_board;

typedef struct s_env
{
	t_board	b;
	char	*c_user;
	char	*c_ai;
	t_coin	first;
}			t_env;

typedef struct s_moves
{
	t_index	best_index;
	int		best_score;	
}			t_moves;

bool	init_board(t_env *e);
bool	init_col_row(t_env *e, char **av);
void	init_first_player(t_env *e);

int		play(t_env *e);
bool	prompt_user(t_env *e);
void	ai(t_env *e);
bool	add_coin(t_board *b, const t_index index, const t_coin player);
void	remove_coin(t_board *b, const t_index index);

void	print_board(t_env *e);
void	print_win_msg(t_env *e, const int who);
bool	print_wrong_size(void);
bool	print_wrong_index(const char *buffer);
int		print_col_full(const t_index index);

void	free_board(t_coin **board, const size_t size);

int		error(const char *str, const int ret);
char	*gnl(size_t *size, const bool f);
char	*ft_strjoin_n_free(char *s1, size_t *size1,
			const char *s2, const size_t size2);
char	*ft_strdup_n(const char *src, const size_t size);

bool	is_connect(const t_board *b, const t_coin player);

bool	is_num(const char *n);
bool	is_board_empty(const t_board *b);
bool	is_board_full(const t_board *b);
bool	is_col_full(const t_board *b, const t_index index);

t_index	get_col_height(const t_board *board, t_index col);
int		get_score(const t_board *b, int index);
int		score_hor(const t_board *b, t_index index);
int		score_diag_up(const t_board *b, t_index index);
int		score_diag_down(const t_board *b, t_index index);
int		score_down(const t_board *b, t_index index);
#endif