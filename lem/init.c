/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:01:26 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/08 04:42:37 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int arrlen(char **arr)
{
	int len = 0;
	while(arr[len])
	{
		len++;
	}
	return(len);
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
