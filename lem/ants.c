/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 04:30:16 by zee               #+#    #+#             */
/*   Updated: 2018/09/08 07:46:55 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			find_ants(t_farm *farm)
{
	t_link *head;

	head = farm->format;
	while(head)
	{
		if(ft_strnequ("#", head->str, 1))
		{
			head = head->next;
			continue ;
		}
		else if(ft_isnum(head->str))
		{
			farm->ants = ft_atoi(head->str);
			return(farm->ants);
		}
		else
			return(0);
		head = head->next;
	}
	return (0);
}

void	send_ants(t_farm *farm)
{
	t_room *h1;
	t_room *h2;

	h1 = farm->rooms;
	h2 = farm->rooms;
	while(h1 && h1->type != START)
		h1 = h1->next;
	while(h2 && h2->number != h1->links[0])
		h2 = h2->next;
	if(!h2)
	{
		col_endl_fd(FRED, "Error!\nNo valid Path", 2);
		exit(0);
	}
	ft_putlist(farm);
	col_str_fd(FGRN, "L1-", 1);
	col_endl_fd(FGRN, h2->name, 1);
}