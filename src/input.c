/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:38:26 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 22:38:28 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_uns	read_file(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (prepare_read(&fd) == 1)
		return (1);
	return (0);
}

t_uns	read_stdin(void)
{
	int		fd;

	fd = 0;
	if (prepare_read(&fd))
		return (1);
	return (0);
}
