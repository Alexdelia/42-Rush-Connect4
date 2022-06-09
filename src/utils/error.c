/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:34:30 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 11:16:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/connect4.h"

int	error(const char *str, const int ret)
{
	ft_pser(C_BOLD);
	ft_pserc("Error:\t", C_RED);
	ft_pserc(str, C_RED);
	ft_pser("\n");
	return (ret);
}