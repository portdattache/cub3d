/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaumont <bcaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:51:25 by broboeuf          #+#    #+#             */
/*   Updated: 2025/07/19 22:58:08 by bcaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_player_forward(t_game *game)
{
	game->player.pos_x += cos(game->player.dir) * SPEED;
	game->player.pos_y += sin(game->player.dir) * SPEED;
	draw_frame(game);
}

void	move_player_backward(t_game *game)
{
	game->player.pos_x -= cos(game->player.dir) * SPEED;
	game->player.pos_y -= sin(game->player.dir) * SPEED;
	draw_frame(game);
}

void	move_player_right(t_game *game)
{
	game->player.pos_x -= sin(game->player.dir) * SPEED;
	game->player.pos_y += cos(game->player.dir) * SPEED;
	draw_frame(game);
}

void	move_player_left(t_game *game)
{
	game->player.pos_x += sin(game->player.dir) * SPEED;
	game->player.pos_y -= cos(game->player.dir) * SPEED;
	draw_frame(game);
}
