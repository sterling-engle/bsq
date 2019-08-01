/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:38:18 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 22:46:28 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_grid		create_struct_grid(void)
{
	t_grid	grid;

	grid.empty = 0;
	grid.mine = 0;
	grid.square = 0;
	grid.x = 0;
	grid.y = 0;
	return (grid);
}
