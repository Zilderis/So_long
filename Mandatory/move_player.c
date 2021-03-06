/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:43 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/19 11:32:36 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_game *game)
{
	static int	i;
	static int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->p_x = i;
				game->p_y = j;
			}
			j++;
		}
		i++;
	}
}

int	destroy_window(t_game *game)
{
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	ft_printf("Exit!!");
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	move_player(t_game *game, int i, int j)
{
	if (game->map[game->p_x + i][game->p_y + j] != '1')
	{
		if (game->map[game->p_x + i][game->p_y + j] == 'C')
			game->n_colect--;
		else if (game->map[game->p_x + i][game->p_y + j] == 'E')
		{
			if (game->n_colect == 0)
			{
				win(game);
				free_map(game);
				mlx_destroy_window(game->mlx, game->win);
				free(game->mlx);
				exit(EXIT_SUCCESS);
			}
			return ;
		}
		game->moves++;
		game->map[game->p_x + i][game->p_y + j] = 'P';
		game->map[game->p_x][game->p_y] = '0';
		game->p_x += i;
		game->p_y += j;
		ft_printf("Moves : %d\n", game->moves);
		draw(game);
	}
}

int	m_hook(int key_code, t_game *game)
{
	if (key_code == A)
		move_a(game);
	else if (key_code == D)
		move_d(game);
	else if (key_code == W)
		move_w(game);
	else if (key_code == S)
		move_s(game);
	if (key_code == ESC)
		destroy_window(game);
	return (0);
}
