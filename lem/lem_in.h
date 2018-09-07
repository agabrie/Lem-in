/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:02:02 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/05 09:31:19 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#define START 0
#define REG 1
#define END 2

typedef	struct	s_link
{
	char			*str;
	struct s_link *next;
}				t_link;

typedef struct s_qu
{
	t_link		*front;
	t_link		*back;
}				t_qu;

typedef struct	s_room
{
	char *name;
    int     number;
	t_point coords;
	int		type;
	int		*links;
	int		doors;
	struct s_room *next;
}				t_room;



typedef struct	s_farm
{
	int ants;
	t_link	*format;
	t_room *rooms;
	int num_rooms;
}				t_farm;
