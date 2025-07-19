/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaumont <bcaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:15:33 by bcaumont          #+#    #+#             */
/*   Updated: 2025/07/19 22:53:02 by bcaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	mouse_move_hook(int x, int y, t_game *game)
{
	static int	last_x = WIDTH / 2;
	int			delta_x;
	double		angle;
	double		rot_speed;

	(void)y;
	rot_speed = 0.003;
	delta_x = x - last_x;
	if (delta_x != 0)
	{
		angle = delta_x * rot_speed;
		game->player.dir += angle;
		if (game->player.dir < 0)
			game->player.dir += 2 * M_PI;
		else if (game->player.dir >= 2 * M_PI)
			game->player.dir -= 2 * M_PI;
		last_x = x;
	}
	if (x <= 5 || x >= WIDTH - 5)
		mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
