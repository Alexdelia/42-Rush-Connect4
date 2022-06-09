/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:41:47 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 13:07:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static void	print_frame_line(t_env *e, char *buffer, size_t *i, const bool n)
{
	size_t	col;

	*i += ft_strcpy(&buffer[*i], C_FRAME);
	col = -1;
	while (++col < e->col + 4)
	{
		if (n && col >= 2 && col < e->col + 2 && col < 15)
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

static void	print_coin(t_env *e, const short coin, char *buffer, size_t *i)
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
	size_t	col;
	size_t	row;
	size_t	i;

	i = ft_strcpy(buffer, C_CLEAR);
	print_frame_line(e, buffer, &i, false);
	row = e->row;
	while (--row + 1 > 0)
	{
		i += ft_strcpy(&buffer[i], C_FRAME);
		i += ft_strcpy(&buffer[i], "  ");
		col = -1;
		while (++col < e->col)
			print_coin(e, e->board[col][row], buffer, &i);
		i += ft_strcpy(&buffer[i], C_FRAME);
		i += ft_strcpy(&buffer[i], "  \033[0m\033[K");
		buffer[i++] = '\n';
	}
	print_frame_line(e, buffer, &i, true);
	buffer[i] = '\0';
	if (write(STDOUT, buffer, i) == -1)
		error("write\t(can't print board)", 0);
}
