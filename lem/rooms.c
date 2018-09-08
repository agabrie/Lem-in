/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 04:32:51 by zee               #+#    #+#             */
/*   Updated: 2018/09/08 07:39:06 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(char *str, int type, int num_rooms)
{
	char **info;
	t_room *room;
	info = ft_strsplit(str, ' ');
	room = (t_room *)malloc(sizeof(t_room));
	room->name = info[0];
	room->number = num_rooms;
	room->coords = set_point(ft_atoi(info[2]), ft_atoi(info[1]));
	room->type = type;
	room->doors = 0;
	room->next = NULL;
	return(room);
}

void create_room(t_farm *farm, int type, char *str,int num_rooms)
{
	t_room	*link;
	t_room	*head;
	
	link = new_room(str, type, num_rooms);	
	head = farm->rooms;
	if (farm->rooms)
	{
		while(head->next)
			head = head->next;
		head->next = link;
	}
	else
		farm->rooms = link;
}

int	ft_isroom(char *str)
{
	char **form;
	if(ft_islink(str))
		return 0;
	form = ft_strsplit(str, ' ');
	if(arrlen(form) != 3)
		return(0);
	if(ft_isnum(form[1]) && ft_isnum(form[2]))
		return(1);
	else
	{
		col_endl_fd(FRED, "Incorrect room format - coordinates", 2);
		return(0);
	}
}

int find_rooms(t_farm *farm)
{
	t_link *head;

	head = farm->format;
	while(head->next && !ft_isnum(head->str))
		head = head->next;
	while(head)
	{
		if(ft_strnequ("#", head->str, 1))
		{
			if(ft_strequ("##start", head->str))
				farm->type = START;	
			if(ft_strequ("##end", head->str))
				farm->type = END;
		}
		if(ft_isroom(head->str))
		{
			farm->num_rooms++;
			create_room(farm, farm->type, head->str, farm->num_rooms);
			farm->type = REG;	
		}
		if(ft_islink(head->str))
			break ;
		head = head->next;
	}
	return(farm->num_rooms);
}