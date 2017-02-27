/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:58:51 by rberthie          #+#    #+#             */
/*   Updated: 2016/05/31 17:29:43 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			choice(t_e *e, int i)
{
	e->fr = i;
	init(e);
	if (i == 1)
		mandelbrot(e);
	else if (i == 2)
		julia(e);
	else if (i == 3)
		tricorn(e);
	else if (i == 4)
		burning(e);
	else if (i == 5)
		mandelbrot1(e);
	else if (i == 6)
		julia1(e);
	else if (i == 7)
		julia2(e);
	mlx(e, 1);
}

int				keym(int key, int x, int y, t_e *e)
{
	double		xt;
	double		yt;

	if (y > 0)
	{
		xt = (x / e->zoom) + e->x1;
		yt = (y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = xt - (x / e->zoom);
			e->y1 = yt - (y / e->zoom);
		}
		else if (key == 5)
		{
			e->zoom *= 0.9;
			e->x1 = xt - (x / e->zoom);
			e->y1 = yt - (y / e->zoom);
		}
		re_draw(e, 1);
	}
	return (0);
}

void			create_img(t_e *e)
{
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, HEIGTH, WIDTH);
	e->win = mlx_new_window(e->mlx, HEIGTH, WIDTH, "Fractol");
	e->s = mlx_get_data_addr(e->img, &(e->bpp), &(e->si), &(e->endian));
}

void			color(t_e *e)
{
	if (e->i == e->im && e->col == 0)
		color2(e, 1);
	else if (e->i == e->im && e->col == 1)
		color2(e, 2);
	else if (e->i != e->im && e->col1 == 1)
		color2(e, 3);
	else if (e->i != e->im && e->col1 == 2)
		color2(e, 4);
	else if (e->i != e->im && e->col1 == 3)
		color2(e, 5);
	else if (e->i != e->im && e->col1 == 4)
		color1(e, 1);
	else if (e->i != e->im && e->col1 == 5)
		color1(e, 2);
	else if (e->i != e->im && e->col1 == 6)
		color1(e, 3);
	else if (e->i != e->im && e->col1 == 7)
		color1(e, 4);
	else if (e->i != e->im && e->col1 == 8)
		color1(e, 5);
	else if (e->i != e->im && e->col1 == 9)
	{
		CDBR;
	}
}

void			re_draw(t_e *e, int i)
{
	if (i != 3)
	{
		if (e->fr == 1)
			mandelbrot(e);
		else if (e->fr == 2)
			julia(e);
		else if (e->fr == 3)
			tricorn(e);
		else if (e->fr == 4)
			burning(e);
		else if (e->fr == 5)
			mandelbrot1(e);
		else if (e->fr == 6)
			julia1(e);
		else if (e->fr == 7)
			julia2(e);
		mlx(e, 1);
	}
	else
		choice(e, e->fr);
}
