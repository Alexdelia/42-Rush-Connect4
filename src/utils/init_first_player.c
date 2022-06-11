/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_first_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:43:40 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 14:51:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/connect4.h"

void	init_first_player(t_env *e)
{
	if (rand() % 2)
	{
		e->b.first = USER;
		e->c_user = C_YELLOW;
		e->c_ai = C_RED;
	}
	else
	{
		e->b.first = AI;
		e->c_user = C_RED;
		e->c_ai = C_YELLOW;
	}
}
