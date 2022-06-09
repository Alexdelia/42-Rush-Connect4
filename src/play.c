/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:15:46 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 13:59:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

int	play(t_env *e)
{
	bool	legal;

	// while (!win && !lose && board full)
	print_board(e);
	legal = false;
	while (!legal)
	{
		// ask user to play
		// if (prompt_user(e, &index))
		//  legal = add_coin(&e, index, USER)
	}
	//	if (win || board full)
	//		exit / break
	//	ai play

	return (true); //
}