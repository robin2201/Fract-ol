/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:50:44 by rberthie          #+#    #+#             */
/*   Updated: 2016/05/31 18:12:17 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int					motion(int x, int y, t_e *e)
{
	float		i;

	i = 0.03;
	if (e->motion % 2)
		if (x > 0 && x <= WIDTH && y > 0 && y <= HEIGTH)
		{
			if (e->mot_i == 0)
			{
				if (x < WIDTH / 2 && y < HEIGTH / 2)
					e->c_r += i;
				else if (x > WIDTH / 2 && y < HEIGTH / 2)
					e->c_r -= i;
				else if (x < WIDTH / 2 && y > HEIGTH / 2)
					e->c_i += i;
				else if (x > WIDTH / 2 && y > HEIGTH / 2)
					e->c_i -= i;
			}
		}
	re_draw(e, 1);
	return (0);
}

void				julia(t_e *e)
{
	e->i_x = HEIGTH;
	e->i_y = WIDTH;
	e->x = 0;
	while (e->x < e->i_x)
	{
		e->y = 0;
		while (e->y < e->i_y)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->im)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			color(e);
			e->y++;
		}
		e->x++;
	}
}

void				julia1(t_e *e)
{
	e->i_x = HEIGTH;
	e->i_y = WIDTH;
	e->x = 0;
	while (e->x < e->i_x)
	{
		e->y = 0;
		while (e->y < e->i_y)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->im)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = -2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			color(e);
			e->y++;
		}
		e->x++;
	}
}
