/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:01:26 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/04 13:10:25 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*new_node(char *str)
{
	t_link *link;

	link = (t_link*)malloc(sizeof(t_link));
	link->str = str;
	col_endl_fd(FMAG, link->str, 2);
	link->next = NULL;
	return (link);
}

void		push(t_link *format, char *str)
{
	t_link	*link;

	col_endl_fd(FCYN, str, 2);
	link = new_node(str);
	col_endl_fd(FCYN, link->str, 2);
	link->next = format;
	format = link;
	col_endl_fd(FYEL, format->str, 2);
}

void	init(t_farm *farm)
{
	farm->format = NULL;
	char *line;
	line = malloc(100);
	while (g_n_l(0, &line))
	{
		col_endl_fd(FYEL, line, 2);
		push(farm->format, line);
		col_endl_fd(FYEL, farm->format->str, 2);
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
			continue ;
		}
		else if(ft_isnum(head->str))
		{
			col_endl_fd(FGRN, head->str, 2);
			farm->ants = ft_atoi(head->str);
			return(1);
		}
		else
		{
			return(0);
		}
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
	/*if(!find_rooms(&farm))
	{
		col_endl_fd(FRED, "Error!\nNo Rooms", 2);
	}
	*/
}