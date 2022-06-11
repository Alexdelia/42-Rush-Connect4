/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wrong_size_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:56:18 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 12:57:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/connect4.h"

bool	print_wrong_size(void)
{
	ft_ps(C_BOLD);
	ft_pserc("invalid size given\n", C_RED);
	ft_pserc("./connect4 <col> <row>\n\t", C_BOLD);
	ft_pnerc(DEFAULT_COL, BIMAG);
	ft_pserc(" <= col < ", C_ITALIC);
	ft_pnerc(MAX_SIZE, BIMAG);
	ft_ps("\n\t");
	ft_pnerc(DEFAULT_ROW, BIMAG);
	ft_pserc(" <= row < ", C_ITALIC);
	ft_pnerc(MAX_SIZE, BIMAG);
	ft_ps("\n");
	return (false);
}

bool	print_wrong_index(const char *buffer)
{
	ft_pserc("\"", C_RED);
	ft_pserc(buffer, C_MAGENTA);
	ft_pserc("\" is not a valid index\n", C_RED);
	return (false);
}
