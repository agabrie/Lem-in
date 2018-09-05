/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:01:26 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/05 10:45:52 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*new_node(char *str)
{
	t_link *link;

	link = (t_link*)malloc(sizeof(t_link));
	link->str = ft_strdup(str);
	link->next = NULL;
	return (link);
}
t_qu		*create_q()
{
	t_qu *q = (t_qu*)malloc(sizeof(t_qu));
    q->front = q->back = NULL;
    return (q);
}

void pushq(t_qu *link, char *str)
{
    // Create a new LL node
    t_link *temp = new_node(str);
	//col_endl_fd(FBLU, temp->str, 2);
	t_link *f;
	t_link *b;
 
	f = link->front;
	b = link->back;
    // If queue is empty, then new node is front and rear both
    if (f == NULL)
    {
       f = b = temp;
	   col_endl_fd(FBLU, f->str, 2);
       return;
    }
	/*if (farm->format->back == NULL)
    {
       farm->format->back = temp;
	   col_endl_fd(FBLU, farm->format->front->str, 2);
       return;
    }*/
    // Add the new node at the end of queue and change rear
    b->next = temp;
    b = temp;
	//farm->format->front->next = farm->format->back;
}

void		push(t_farm *farm, char *str)
{
	t_link	*link;
	t_link	*head;
	
	link = new_node(str);
	head = farm->format;
	
	if (farm->format)
	{
		while(head->next)
		{
			head = head->next;
		}
		head->next = link;
	}
	else
	{
		farm->format = link;
	}
}

void	init(t_farm *farm)
{
	farm->format = NULL;
	farm->rooms = NULL;
	char *line;
	while (g_n_l(0, &line))
	{
		push(farm, line);
		ft_strdel(&line);
	}
}

int find_ants(t_farm *farm)
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

int arrlen(char **arr)
{
	//char **lment = (char **)arr;
	int len = 0;
	//ft_putarr(arr);
	while(arr[len])
	{
		//col_endl_fd(FMAG, arr[len], 2);
		len++;
	}
	//ft_nbrendl_fd(len, 2);
	return(len);
}

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
		{
			//col_endl_fd(FYEL, str, 2);
			head = head->next;
		}
		head->next = link;
	}
	else
	{
		farm->rooms = link;
	}
}

int ft_islink(char *str)
{
	char **form;
	form=ft_strsplit(str, '-');
	if(arrlen(form) != 2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int	ft_isroom(char *str)
{
	char **form;
	if(ft_islink(str))
	{
		//col_endl_fd(FBLU, "is link", 2);
			return 0;
	}
	form = ft_strsplit(str, ' ');
	if(arrlen(form) != 3)
	{
		//freearray(form);
		//col_endl_fd(FYEL, str, 2);
		//ft_nbrendl_fd(arrlen(form), 2);
		
		col_endl_fd(FRED, "Incorrect room format", 2);
		return(0);
	}
	if(ft_isnum(form[1]) && ft_isnum(form[2]))
	{
		//freearray(form);
		//col_endl_fd(FYEL, form[1], 2);
		//col_endl_fd(FYEL, form[2], 2);
		return(1);
	}
	else
	{
		col_endl_fd(FRED, "Incorrect room format - coordinates", 2);
		//freearray(form);
		return(0);
	}
}

int find_rooms(t_farm *farm)
{
	t_link *head;
	head = farm->format;
	int type;
	int num_rooms;

	num_rooms = 0;
	type = REG;
	while(head)
	{
		if(ft_strnequ("##", head->str, 2))
		{
			if(ft_strequ("##start", head->str))
			{
				if(type != REG)
				{
					col_endl_fd(FRED, "Invalid room - start", 2);
					return(0);
				}
				type = START;	
			}
			if(ft_strequ("##end", head->str))
			{
				if(type != REG)
				{
					col_endl_fd(FRED, "Invalid room - end", 2);
					return(0);
				}
				type = END;
			}
			head = head->next;
			continue ;
		}
		else if(ft_strnequ("#", head->str, 1))
		{
			col_endl_fd(FCYN, head->str, 2);
			head = head->next;
			continue ;
		}
		else if(ft_isroom(head->str))
		{
			create_room(farm, type, head->str, num_rooms);
			num_rooms++;
			type = REG;
			head = head->next;
			continue;
		}
		else if(ft_islink(head->str))
		{
			col_endl_fd(FBLU, "link", 2);
			break ;
		}
		head = head->next;
	}
	if(num_rooms)
		return(1);
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
	{
		ft_nbrendl_fd(farm.ants, 2);
		while(farm.format && !ft_isnum(farm.format->str))
		{
			col_endl_fd(FCYN, farm.format->str, 2);
			farm.format = farm.format->next;
		}
		farm.format = farm.format->next;
	}
	if(!find_rooms(&farm))
	{
		col_endl_fd(FRED, "Error!\nNo Rooms", 2);
	}
}