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
    t_link *temp = new_node(str);
	t_link *f;
	t_link *b;
 
	f = link->front;
	b = link->back;
    if (f == NULL)
    {
       f = b = temp;
	   col_endl_fd(FBLU, f->str, 2);
       return;
    }
    b->next = temp;
    b = temp;
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
	farm->num_rooms = 0;
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
			return(farm->ants);
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
	int len = 0;
	while(arr[len])
	{
		len++;
	}
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
		{
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
			return 0;
	}
	form = ft_strsplit(str, ' ');
	if(arrlen(form) != 3)
	{
		col_endl_fd(FRED, "Incorrect room format", 2);
		return(0);
	}
	if(ft_isnum(form[1]) && ft_isnum(form[2]))
	{
		return(1);
	}
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
	int type;

	type = REG;

	while(head && !ft_isnum(head->str))
		{
			head = head->next;
		}
		head = head->next;

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
		else if (ft_strnequ("#", head->str, 1))
		{
			//col_endl_fd(FCYN, head->str, 2);
			head = head->next;
			continue ;
		}
		else if(ft_isroom(head->str))
		{
			farm->num_rooms++;
			create_room(farm, type, head->str, farm->num_rooms);
			type = REG;
			head = head->next;
			continue;
		}
		else if(ft_islink(head->str))
		{
			//col_endl_fd(FBLU, "link", 2);
			break ;
		}
		else
			return(0);
		head = head->next;
	}
	return(farm->num_rooms);
}

int check_qual(t_farm *farm)
{
	int val1;
	int val2;
	val1 = 0;
	val2 = 0;
	t_room *head;
	head = farm->rooms;

	while(head)
	{
		if(head->type == START)
		{
			val1++;
		}
		else if(head->type == END)
		{
			val2++;
		}
		head = head->next;
	}
	if(val1 != 1 || val2 != 1)
	{
		col_endl_fd(FRED, "No valid Start or END", 2);
		return(0);
	}
	else
		return(1);
}

int		is_valink(t_farm *farm, char **info)
{
	t_room *head;

	head = farm->rooms;
	while(head && !ft_strequ(head->name, info[0]))
		head = head->next;
	if(!head)
		return(0);
	head = farm->rooms;
	while(head && !ft_strequ(head->name, info[1]))
		head = head->next;
	if(!head)
		return(0);
	return(1);
}

int	add_link(t_farm *farm, char *str)
{
	char **info;
	t_room *h1;
	t_room *h2;

	h1 = farm->rooms;
	h2 = farm->rooms;
	info = ft_strsplit(str, '-');
	if(!is_valink(farm, info))
	{
		col_endl_fd(FRED, "not a valid link", 2);
		return(0);
	}
	while(h1 && !ft_strequ(h1->name, info[0]))
		h1 = h1->next;
	while(h2 && !ft_strequ(h2->name, info[1]))
		h2 = h2->next;
	h1->links[h1->doors++] = h2->number; 
	h2->links[h2->doors++] = h1->number;
	return(1);
}

int	find_links(t_farm *farm)
{
	t_link *head;

	head = farm->format;
	if(!check_qual(farm))
		return(0);
	while(head)
	{
		if(ft_islink(head->str))
			break ;
		head = head->next;
	}
	while(head)
	{
		if(ft_strnequ("#", head->str, 1))
		{
			head = head->next;
			continue ;
		}
		else if(ft_islink(head->str))
		{
			if(!add_link(farm, head->str))
				return(0);
		}
		head = head->next;
	}
	return(1);
}

void	set_linksizes(t_farm *farm)
{
	t_room *head;

	head = farm->rooms;
	while(head)
	{
		head->links = malloc(farm->num_rooms * sizeof(int));
		head = head->next;
	}
}

void	ft_putlist(t_farm *farm)
{
	t_link *head;

	head = farm->format;

	while(head)
	{
		col_endl_fd(FCYN, head->str, 1);
		head = head->next;
	}
	ft_putendl_fd("", 1);
}

void	send_ants(t_farm *farm)
{
	t_room *h1;
	t_room *h2;
	h1 = farm->rooms;
	h2 = farm->rooms;
	while(h1 && h1->type != START)
	{
		h1 = h1->next;
	}
	while(h2 && h2->number != h1->links[0])
	{
		h2 = h2->next;
	}
	if(!h2)
	{
		col_endl_fd(FRED, "Error!\nNo valid Path", 2);
		exit(0);
	}
	ft_putlist(farm);
	col_str_fd(FGRN, "L1-", 1);
	col_endl_fd(FGRN, h2->name, 1);
}

int main()
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