/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:36:45 by sengle            #+#    #+#             */
/*   Updated: 2019/08/01 04:52:28 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef unsigned short	t_dim;;
typedef unsigned short	t_uns;

typedef struct			s_grid
{
	t_dim				x;
	t_dim				y;
	unsigned char		empty;
	unsigned char		mine;
	unsigned char		square;
}						t_grid;

typedef struct			s_square
{
	struct s_coord		*start;
	short				length;
}						t_square;

typedef struct			s_coord
{
	t_dim				x;
	t_dim				y;
	struct s_coord		*next;
}						t_coord;

t_uns					read_bsq_file(char *file);
t_uns					read_bsq_stdin(void);
t_uns					read_map(int *fd);
t_grid					create_struct_grid();
t_square				*bsq_algo(t_coord **list, t_grid *grid);
t_coord					*create_mine(t_coord *xy);
void					push_back(t_coord **begin, t_coord *xy);
void					init_those(t_square **temp, t_square **max);
t_square				*square_init();
void					display(t_square *square, t_grid *grid,
								t_coord **begin);

#endif
