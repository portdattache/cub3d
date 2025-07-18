/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charactere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broboeuf <broboeuf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:33:50 by broboeuf          #+#    #+#             */
/*   Updated: 2025/07/19 01:33:05 by broboeuf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * Retourne l’orientation du joueur en radians selon la lettre (N/S/E/W)
 * @param c caractère représentant l’orientation sur la carte
 * @return angle en radians
 */
static double	get_player_orientation(char c)
{
	if (c == 'N')
		return (3 * M_PI_2);
	else if (c == 'S')
		return (M_PI_2);
	else if (c == 'E')
		return (0.0);
	else if (c == 'W')
		return (M_PI);
	return (3 * M_PI_2);
}

/**
 * Initialise la position de départ du joueur dans la structure de jeu
 * - Cherche la lettre N/S/E/W sur la carte
 * - Calcule la position en pixels (centrée dans la case)
 * - Définit la direction en radians
 * @param game structure principale du jeu
 */
void	get_player_start(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->player.pos_x = j;
				game->player.pos_y = i;
				game->player.pos_x = (j + 0.5) * CUBE_SIZE;
				game->player.pos_y = (i + 0.5) * CUBE_SIZE;
				game->player.dir = get_player_orientation(game->map[i][j]);
				game->player.speed = SPEED;
				return ;
			}
			j++;
		}
		i++;
	}
}
