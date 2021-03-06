/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:37:21 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/19 11:31:45 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_a(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "Mandatory/assets/hero_left.xpm",
			&game->img_w, &game->img_h);
	move_player(game, 0, -1);
}

void	move_d(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "Mandatory/assets/hero_right.xpm",
			&game->img_w, &game->img_h);
	move_player(game, 0, 1);
}

void	move_w(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "Mandatory/assets/hero_up.xpm",
			&game->img_w, &game->img_h);
	move_player(game, -1, 0);
}

void	move_s(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "Mandatory/assets/hero_down.xpm",
			&game->img_w, &game->img_h);
	move_player(game, 1, 0);
}
