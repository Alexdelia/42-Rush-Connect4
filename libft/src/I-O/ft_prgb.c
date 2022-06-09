/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:09:31 by adelille          #+#    #+#             */
/*   Updated: 2022/04/20 19:05:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static ssize_t	ft_p256(const int n)
{
	char	str[4];
	size_t	len;
	size_t	n256;

	n256 = n % 256;
	if (n256 == 0)
		return (write(STDOUT, "0", 1));
	str[3] = '\0';
	len = 3;
	while (n256 != 0)
	{
		str[--len] = n256 % 10 + '0';
		n256 /= 10;
	}
	return (ft_ps(&str[len]));
}

ssize_t	ft_prgb(const int r, const int g, const int b)
{
	return (ft_ps("\033[38;2;")
		+ ft_p256(r)
		+ write(STDOUT, ";", 1)
		+ ft_p256(g)
		+ write(STDOUT, ";", 1)
		+ ft_p256(b)
		+ write(STDOUT, "m", 1));
}

ssize_t	ft_prgb_b(const int r, const int g, const int b)
{
	return (ft_ps("\033[48;2;")
		+ ft_p256(r)
		+ write(STDOUT, ";", 1)
		+ ft_p256(g)
		+ write(STDOUT, ";", 1)
		+ ft_p256(b)
		+ write(STDOUT, "m", 1));
}
