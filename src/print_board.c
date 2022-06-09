/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:41:47 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 11:26:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

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

	ft_strcpy(buffer, C_CLEAR);
	i = ft_strlen(C_CLEAR);
	col = 0;
	while (col < e->col)
	{
		row = e->row - 1;
		while (row + 1 > 0)
		{
			print_coin(e, e->board[col][row], buffer, &i);
			row--;
		}
		buffer[i] = '\n';
		i++;
		col++;
	}
	ft_ps(buffer);
}
