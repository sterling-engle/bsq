/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:37:45 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 23:01:45 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq(int argc, char **argv)
{
	t_uns	 i;

	i = 0;
	if (argc > 1)
		while (++i < argc)
		{
			if (read_file(argv[i]) == 1)
				write(1, "map error\n", 10);
		}
	else
		read_stdin();
}
