/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:37:05 by sengle            #+#    #+#             */
/*   Updated: 2019/08/01 10:11:15 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void		bsq_adjust_list_mine(t_uns *y, t_coord **list)
{
	while (((*list) && (*list)->y < *y))
		(*list) = (*list)->next;
}

static short	bsq_bomb_check(t_uns *x, t_uns *y, t_uns length, t_coord **list)
{
	t_coord		*mine;
	short		result;

	result = -1;
	mine = *list;
	while (mine && mine->y < (*y + length ))
	{
		if ((mine->x >= *x && mine->x < (*x + length))
		&& (mine->y >= *y ) && (mine->y < (*y + length)))
		{
			result = (mine->x);
		}
		mine = mine->next;
	}
	return (result);
}

t_square		*bsq_algo(t_coord **list, t_grid *grid)
{
	t_uns			currentx;
	t_uns			currenty;
	t_square		*max;
	t_square		*temp;
	short			opti;

	temp = new_square();
	max = new_square();
	currenty = 0;
	while (currenty < (grid->y - max->length))
	{
		currentx = 0;
		while (currentx < (grid->x - max->length))
		{
			bsq_adjust_list_mine(&currenty, list);
			temp->start->x = currentx;
			temp->start->y = currenty;
			temp->length = max->length + 1;
			opti = bsq_bomb_check(&currentx, &currenty, temp->length, list);
			while (temp->length <= (grid->x - currentx)
					&& temp->length <= (grid->y - currenty)
					&& (opti == -1))		
			{
				max->start->x = temp->start->x;
				max->start->y = temp->start->y;
				max->length = temp->length;
				temp->length++;
				opti = bsq_bomb_check(&currentx, &currenty, temp->length, list);
			}
			if (opti != -1 && opti > currentx)
				currentx = opti;
			currentx++;
		}
		currenty++;
	}
	free(temp->start);
	free(temp);
	return (max);
}
