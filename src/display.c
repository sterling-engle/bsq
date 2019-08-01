/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:38:02 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 22:56:43 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_coord		*display_line(t_coord *xy, t_coord *mine, t_square *square,
				t_grid *grid)
{
	t_coord *tmp;

	while (xy->x < grid->x - 1)
	{
		if (mine && mine->x == xy->x && mine->y == xy->y)
		{
			write(1, &grid->mine, 1);
			if (mine->next)
			{
				tmp = mine;
				mine = mine->next;
				free(tmp);
			}
		}
		else if (square->start->x <= xy->x &&
				square->length + square->start->x > xy->x &&
				square->start->y <= xy->y &&
				square->length + square->start->y > xy->y)
			write(1, &grid->square, 1);
		else
			write(1, &grid->empty, 1);
		xy->x++;
	}
	return (mine);
}

void		display(t_square *square, t_grid *grid, t_coord **begin)
{
	t_coord xy;
	t_coord *mine;

	mine = *begin;
	xy.y = 0;
	xy.x = 0;
	while (xy.y < grid->y)
	{
		xy.x = 0;
		mine = display_line(&xy, mine, square, grid);
		write(1, "\n", 1);
		xy.y++;
	}
}
