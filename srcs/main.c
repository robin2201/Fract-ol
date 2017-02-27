/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:33:30 by rberthie          #+#    #+#             */
/*   Updated: 2016/05/31 18:12:09 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		color2(t_e *e, int i)
{
	if (i == 1)
	{
		WHITE;
	}
	else if (i == 2)
	{
		BLACK;
	}
	else if (i == 3)
	{
		C1BR;
	}
	else if (i == 4)
	{
		C1BG;
	}
	else if (i == 5)
	{
		C1RG;
	}
}

void		color1(t_e *e, int i)
{
	if (i == 1)
	{
		CRAD;
	}
	else if (i == 2)
	{
		CRAD1;
	}
	else if (i == 3)
	{
		CRAD2;
	}
	else if (i == 4)
	{
		CRAD3;
	}
	else if (i == 5)
	{
		C1BR1;
	}
}

void		check_fractale(t_e *e, char *av)
{
	if (ft_strcmp("mandelbrot", av) == 0)
		choice(e, 1);
	else if (ft_strcmp("julia", av) == 0)
		choice(e, 2);
	else if (ft_strcmp("tricorn", av) == 0)
		choice(e, 3);
	else if (ft_strcmp("burning", av) == 0)
		choice(e, 4);
	else if (ft_strcmp("mandel1", av) == 0)
		choice(e, 5);
	else if (ft_strcmp("julia1", av) == 0)
		choice(e, 6);
	else if (ft_strcmp("julia2", av) == 0)
		choice(e, 7);
	else if (ft_strcmp("-h", av) == 0)
	{
		help();
		exit(0);
	}
	else
		USAGE_ERROR;
}

void		mlx(t_e *e, int i)
{
	if ((e->fr == 2 || e->fr == 4 || e->fr == 6 || e->fr == 7) && i != 0)
	{
		mlx_hook(e->win, 6, 1L << 6, motion, e);
		mlx_hook(e->win, 2, 3, key, e);
		mlx_mouse_hook(e->win, keym, e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	else if ((e->fr == 1 || e->fr == 3 || e->fr == 5) && i != 0)
	{
		mlx_hook(e->win, 2, 3, key, e);
		mlx_mouse_hook(e->win, keym, e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	else
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
}

int			main(int ac, char **av)
{
	t_e		e;

	if (ac == 2 && av[1] && ft_memset(&e, 0, sizeof(e)))
	{
		create_img(&e);
		check_fractale(&e, av[1]);
		mlx_loop(e.mlx);
	}
	else
		USAGE_ERROR;
}
