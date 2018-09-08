/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 04:26:59 by zee               #+#    #+#             */
/*   Updated: 2018/09/08 07:45:38 by zee              ###   ########.fr       */
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

void		pushq(t_qu *link, char *str)
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
