/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broboeuf <broboeuf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:50:46 by broboeuf          #+#    #+#             */
/*   Updated: 2025/07/18 23:13:58 by broboeuf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * Normalise un angle en radians dans l’intervalle [0 ; 2π)
 *
 * @param angle angle à normaliser (en radians)
 * @return angle normalisé
 */
double	normalize_angle(double angle)
{
	if (angle >= TWO_PI)
		angle -= TWO_PI;
	if (angle < 0.0)
		angle += TWO_PI;
	return (angle);
}
