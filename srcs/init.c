/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 17:20:17 by robin             #+#    #+#             */
/*   Updated: 2016/05/31 18:15:10 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void				help(void)
{
	ft_putendl("Usage : ./fractol fractale");
	ft_putendl("fractales : ");
	ft_putendl("1. mandelbrot");
	ft_putendl("2. julia");
	ft_putendl("3. tricorn");
	ft_putendl("4. burning");
	ft_putendl("5. mandel1");
	ft_putendl("6. julia1");
	ft_putendl("7. julia2");
}

static	void		i_m2(t_e *e)
{
	e->x1 = -1.6;
	e->x2 = 2.4;
	e->y1 = -1.1;
	e->y2 = 2.4;
	e->c_r = -0.11;
	e->c_i = -0.24;
	e->zoom = 290;
}

static	void		i_m(t_e *e, int i)
{
	if (i == 1 || i == 5)
	{
		e->x1 = -2.5;
		e->x2 = 1.0;
		e->y1 = -1.6;
		e->y2 = 1.9;
	}
	else if (i == 4)
	{
		e->x1 = -2.2;
		e->x2 = 2.5;
		e->y1 = -2.2;
		e->y2 = 3;
		e->zoom = 259.37;
		e->im = 350;
	}
	else
	{
		e->x1 = -2.1;
		e->x2 = 2.5;
		e->y1 = -1.8;
		e->y2 = 3;
		e->zoom = 220.12;
		e->im = 250;
	}
}

static	void		i_m1(t_e *e, int i)
{
	if (i == 2)
	{
		e->x1 = -1.6;
		e->x2 = 2.4;
		e->y1 = -1.1;
		e->y2 = 2.4;
		e->c_r = -0.64;
		e->c_i = -0.38;
		e->zoom = 290;
	}
	else if (i == 7)
	{
		e->x1 = -2;
		e->x2 = 2.5;
		e->y1 = -1.5;
		e->y2 = 3;
		e->c_r = 0.286;
		e->c_i = 0.01;
		e->zoom = 223.23;
	}
	else
		i_m2(e);
}

void				init(t_e *e)
{
	e->r = 5;
	e->g = 5;
	e->zoom = 220;
	e->b = 5;
	e->col1 = 1;
	e->motion = 0;
	e->im = 100;
	if (e->fr == 1 || e->fr == 5 || e->fr == 3 || e->fr == 4)
		i_m(e, e->fr);
	else if (e->fr == 2 || e->fr == 6 || e->fr == 7)
		i_m1(e, e->fr);
}
