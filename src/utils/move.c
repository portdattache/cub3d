/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broboeuf <broboeuf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:51:25 by broboeuf          #+#    #+#             */
/*   Updated: 2025/07/19 00:24:18 by broboeuf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

void	move_player_left(t_game *game)
{
	game->player.pos_x -= sin(game->player.dir) * SPEED;
	game->player.pos_y += cos(game->player.dir) * SPEED;
	draw_frame(game);
}

void	move_player_right(t_game *game)
{
	game->player.pos_x += sin(game->player.dir) * SPEED;
	game->player.pos_y -= cos(game->player.dir) * SPEED;
	draw_frame(game);
}
