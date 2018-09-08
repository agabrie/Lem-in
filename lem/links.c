/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 04:38:07 by zee               #+#    #+#             */
/*   Updated: 2018/09/08 07:42:42 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_islink(char *str)
{
	char **form;

	form = ft_strsplit(str, '-');
	if(arrlen(form) != 2)
		return (0);
	else
		return (1);
}

int			check_qual(t_farm *farm)
{
	int val1;
	int val2;
	t_room *head;

	val1 = 0;
	val2 = 0;
	head = farm->rooms;
	while(head)
	{
		if(head->type == START)
			val1++;
		else if(head->type == END)
			val2++;
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

int			is_valink(t_farm *farm, char **info)
{
	t_room *head;

	head = farm->rooms;
	if(arrlen(info) != 2)
		return (0);
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

int			add_link(t_farm *farm, char *str)
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

int			find_links(t_farm *farm)
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
			head = head->next;
		if(ft_islink(head->str))
		{
			if(!add_link(farm, head->str))
				return(0);
		}
		else if(!ft_islink(head->str))
			return(0);
		head = head->next;
	}
	return(1);
}
