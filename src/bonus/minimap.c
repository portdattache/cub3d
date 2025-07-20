/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broboeuf <broboeuf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 00:31:44 by bcaumont          #+#    #+#             */
/*   Updated: 2025/07/21 01:44:58 by broboeuf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	draw_square(t_image *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

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

static void	draw_minimap_tiles(t_game *game, int scale)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				color = 0xAAAAAA;
			else if (game->map[y][x] == '0')
				color = 0x000000;
			else
				color = 0x333333;
			draw_square(&game->screen, MINIMAP_MARGIN + x * scale,
				MINIMAP_MARGIN + y * scale, scale, color);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *game, int scale)
{
	t_point	p1;
	t_point	p2;
	int		px;
	int		py;

	px = MINIMAP_MARGIN + (game->player.pos_x / CUBE_SIZE) * scale;
	py = MINIMAP_MARGIN + (game->player.pos_y / CUBE_SIZE) * scale;
	draw_square(&game->screen, px - 2, py - 2, 4, 0xFF0000);
	p1.x = px;
	p1.y = py;
	p2.x = px + cos(game->player.dir) * 10;
	p2.y = py + sin(game->player.dir) * 10;
	ft_draw_line(&game->screen, p1, p2, 0xFF0000);
}

void	draw_minimap(t_game *game)
{
	int	scale;

	scale = MINIMAP_SCALE;
	draw_minimap_tiles(game, scale);
	draw_player(game, scale);
}
