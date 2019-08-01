/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:38:33 by sengle            #+#    #+#             */
/*   Updated: 2019/08/01 04:26:15 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	t_uns	arg;

	arg = 0;
	if (argc > 1)
	{
		while (++arg < argc)
		{
			if (arg > 1)
				write(1, "\n", 1);
			if (read_bsq_file(argv[arg]) == 1)
				write(1, "map error\n", 10);
		}
	}
	else
	{
		read_bsq_stdin();
	}
	return (0);
}
