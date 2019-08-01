/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:36:45 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 23:01:09 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

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

void					bsq(int argc, char **argv);
t_uns					read_file(char *file);
t_uns					read_stdin(void);
t_uns					prepare_read(int *fd);
t_uns					ft_read(int *fd, char *buffer, t_grid *grid,
								t_coord *xy);
t_uns					ft_read_char(t_coord *xy, char *buffer, t_grid *grid,
								t_coord **begin);
t_grid					create_struct_grid();
t_uns					first_line(char *buffer, t_grid *grid);
t_uns					check_first_line(t_grid *grid);
short					check_bomb(t_uns *x, t_uns *y, t_uns l,
								t_coord **list);
t_square				*algo_bsq(t_coord **list, t_grid *grid);
t_coord					*create_mine(t_coord *xy);
void					push_back(t_coord **begin, t_coord *xy);
void					init_those(t_square **temp, t_square **max);
t_square				*square_init();
void					display(t_square *square, t_grid *grid,
								t_coord **begin);
t_uns					ft_after_read(t_coord *xy, t_grid *grid,
								t_coord **begin);

#endif
