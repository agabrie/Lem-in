/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:02:02 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/08 07:20:00 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
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
	int type;
	t_link	*format;
	t_room *rooms;
	int num_rooms;
}				t_farm;


void	init(t_farm *farm);
int arrlen(char **arr);
void	ft_putlist(t_farm *farm);
int ft_islink(char *str);
int check_qual(t_farm *farm);
int		is_valink(t_farm *farm, char **info);
int	add_link(t_farm *farm, char *str);
int	find_links(t_farm *farm);
void	set_linksizes(t_farm *farm);
t_room	*new_room(char *str, int type, int num_rooms);
void create_room(t_farm *farm, int type, char *str,int num_rooms);
int	ft_isroom(char *str);
int find_rooms(t_farm *farm);
int find_ants(t_farm *farm);
void	send_ants(t_farm *farm);
t_link		*new_node(char *str);
t_qu		*create_q();
void pushq(t_qu *link, char *str);
void		push(t_farm *farm, char *str);
#endif
