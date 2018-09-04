/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:02:02 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/04 13:05:44 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef	struct	s_link
{
	char			*str;
	struct s_link *next;
}				t_link;

typedef struct	s_room
{
	char *name;
	t_point coords;
	int		type;
	int		*links; 
}				t_rooms;

typedef struct	s_farm
{
	int ants;
	t_link	*format;
	t_rooms rooms;
}				t_farm;
