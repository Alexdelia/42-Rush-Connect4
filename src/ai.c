/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 00:22:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

void	ai(t_env *e)
{
	size_t	index;

	srand(time(NULL));
	index = rand() % e->col;

	if (!add_coin(e, index, AI))
	{
		ft_pser(C_BOLD);
		ft_pserc("AI tried to insert coin on full col\n", RED);
		exit(1);	// tmp
	}
}
