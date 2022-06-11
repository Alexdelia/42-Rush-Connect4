/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:41:47 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 19:43:10 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void	print_frame_line(t_env *e, char *buffer, size_t *i, const bool n)
{
	t_index	col;

	*i += ft_strcpy(&buffer[*i], C_FRAME);
	col = -1;
	while (++col < e->b.col + 4)
	{
		if (n && col >= 2 && col < e->b.col + 2 && col < 15)
		{
			if (col - 2 < 10)
				buffer[*i] = col - 2 + '0';
			else
				buffer[*i] = '.';
		}
		else
			buffer[*i] = ' ';
		*i += 1;
	}
	*i += ft_strcpy(&buffer[*i], "\033[0m\033[K");
	buffer[*i] = '\n';
	*i += 1;
}

static void	print_coin(t_env *e, const t_coin coin, char *buffer, size_t *i)
{
	if (coin == USER)
	{
		*i += ft_strcpy(&buffer[*i], e->c_user);
		*i += ft_strcpy(&buffer[*i], COIN_USER);
	}
	else if (coin == AI)
	{
		*i += ft_strcpy(&buffer[*i], e->c_ai);
		*i += ft_strcpy(&buffer[*i], COIN_AI);
	}
	else
	{
		*i += ft_strcpy(&buffer[*i], C_RESET);
		*i += ft_strcpy(&buffer[*i], COIN_EMPTY);
	}
}

void	print_board(t_env *e)
{
	char	buffer[BUFFER_SIZE];
	t_index	col;
	t_index	row;
	size_t	i;

	i = ft_strcpy(buffer, C_CLEAR);
	print_frame_line(e, buffer, &i, false);
	row = e->b.row;
	while (row-- > 0)
	{
		i += ft_strcpy(&buffer[i], C_FRAME);
		i += ft_strcpy(&buffer[i], "  \033[0m\033[K");
		col = -1;
		while (++col < e->b.col)
			print_coin(e, e->b.board[col][row], buffer, &i);
		i += ft_strcpy(&buffer[i], C_FRAME);
		i += ft_strcpy(&buffer[i], "  \033[0m\033[K");
		buffer[i++] = '\n';
	}
	print_frame_line(e, buffer, &i, true);
	buffer[i] = '\0';
	if (write(STDOUT, buffer, i) == -1)
		error("write\t(can't print board)", 0);
}
