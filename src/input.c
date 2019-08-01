/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:38:26 by sengle            #+#    #+#             */
/*   Updated: 2019/08/01 04:38:05 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_uns	read_bsq_file(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (read_map(&fd) == 1)
		return (1);
	return (0);
}

t_uns	read_bsq_stdin(void)
{
	int		fd;

	fd = 0;
	if (read_map(&fd) == 1)
		return (1);
	return (0);
}
