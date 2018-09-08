/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 04:41:22 by zee               #+#    #+#             */
/*   Updated: 2018/09/08 07:45:58 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main()
{
	t_farm farm;

	init(&farm);
    if((find_ants(&farm) <= 0))
	{
		col_endl_fd(FRED, "Error!\nNo Ants", 1);
		exit(0);
	}
	if(!find_rooms(&farm))
	{
		col_endl_fd(FRED, "Error!\nNo Rooms", 1);
		exit(0);
	}
	set_linksizes(&farm);
	if(!find_links(&farm))
	{
		col_endl_fd(FRED, "Error!\nNo Links", 1);
		exit(0);
	}
	send_ants(&farm);
}