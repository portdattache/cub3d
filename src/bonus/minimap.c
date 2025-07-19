/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaumont <bcaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 00:31:44 by bcaumont          #+#    #+#             */
/*   Updated: 2025/07/20 00:33:15 by bcaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_square(t_image *img, int x, int y, int size, int color)
{
	int i, j;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	color;
	int	scale;
	int	px;
	int	py;
	int	dir_x;
	int	dir_y;

	int x, y;
	scale = MINIMAP_SCALE;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				color = 0xAAAAAA; // mur
			else if (game->map[y][x] == '0')
				color = 0x000000; // vide
			else
				color = 0x333333; // autres (portes, etc.)
			draw_square(&game->screen, MINIMAP_MARGIN + x * scale,
				MINIMAP_MARGIN + y * scale, scale, color);
			x++;
		}
		y++;
	}
	// Dessiner le joueur
	px = MINIMAP_MARGIN + game->player.pos_x * scale;
	py = MINIMAP_MARGIN + game->player.pos_y * scale;
	draw_square(&game->screen, px - 2, py - 2, 4, 0xFF0000);
	// Dessiner une ligne pour la direction
	dir_x = (int)(px + cos(game->player.dir) * 10);
	dir_y = (int)(py + sin(game->player.dir) * 10);
	draw_line(&game->screen, px, py, dir_x, dir_y, 0xFF0000);
}

void	draw_line(t_image *img, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		put_pixel(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
