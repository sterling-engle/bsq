/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:39:04 by sengle            #+#    #+#             */
/*   Updated: 2019/08/01 10:10:29 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_square		*new_square(void)
{
	t_square	*square;
	t_coord		*start;

	start = (t_coord*)malloc(sizeof(t_coord));
	square = (t_square*)malloc(sizeof(t_square));
	start->x = 0;
	start->y = 0;
	start->next = 0;
	square->length = 0;
	square->start = start;
	return (square);
}

static t_coord	*new_obstacle(t_coord *xy)
{
	t_coord *obstacle;

	obstacle = (t_coord*)malloc(sizeof(t_coord));
	if (obstacle)
	{
		obstacle->x = xy->x - 1;
		obstacle->y = xy->y - 1;
		obstacle->next = 0;
	}
	return (obstacle);
}

void			push_back(t_coord **begin, t_coord *xy)
{
	t_coord *obstacle;
	t_coord *tmp;

	if (*begin == 0)
	{
		*begin = new_obstacle(xy);
		xy->next = *begin;
	}
	else
	{
		tmp = xy->next;
		obstacle = new_obstacle(xy);
		while (tmp->next != 0)
		{
			tmp = tmp->next;
		}
		xy->next = obstacle;
		tmp->next = obstacle;
	}
}
