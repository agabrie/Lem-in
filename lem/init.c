/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:01:26 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/04 15:55:44 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*new_node(char *str)
{
	t_link *link;

	link = (t_link*)malloc(sizeof(t_link));
	link->str = str;
	link->next = NULL;
	return (link);
}

void		push(t_farm *farm, char *str)
{
	t_link	*link;

	link = new_node(str);
	//farm->format = link;
	link->next = farm->format;
	farm->format = link;
}

void	init(t_farm *farm)
{
	farm->format = NULL;
	char *line;
	//line = malloc(100);
	while (g_n_l(0, &line))
	{
		//col_endl_fd(FYEL, line, 2);
		push(farm, line);
		//col_endl_fd(FYEL, farm->format->str, 2);
		ft_strdel(&line);
	}
}

int find_ants(t_farm *farm)
{
	t_link *head;
	head = farm->format;
	while(head)
	{
		col_endl_fd(FGRN, head->str, 2);
		if(ft_strnequ("#", head->str, 1))
		{
			head = head->next;
			continue ;
		}
		else if(ft_isnum(head->str))
		{
			//col_endl_fd(FGRN, head->str, 2);
			farm->ants = ft_atoi(head->str);
			return(1);
		}
		else
		{
			return(0);
		}
		head = head->next;
	}
	return (0);
}

int main()
{
	t_farm farm;
	init(&farm);
    if(!find_ants(&farm))
	{
		col_endl_fd(FRED, "Error!\nNo Ants", 2);
	}
	else
		ft_nbrendl_fd(farm.ants, 2);
	/*if(!find_rooms(&farm))
	{
		col_endl_fd(FRED, "Error!\nNo Rooms", 2);
	}
	*/
}