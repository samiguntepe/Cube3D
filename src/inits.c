/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:56 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/22 20:55:08 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <unistd.h>

void	inits(t_file *fl)
{
	char	*ptr;

	fl->EA = NULL;
	fl->SO = NULL;
	fl->WE = NULL;
	fl->NO = NULL;
	fl->C = NULL;
	fl->F = NULL;
	fl->map_h = 0;
	fl->map_w = 0;
	fl->control_index[0] = NULL;
	fl->control_index[1] = NULL;
	ptr = fl->verify;
	ft_strcpy(&ptr, "NO ./SO ./WE ./EA ./");
}

void	game_inits(t_game *g)
{
	g->mlx = mlx_init();
	g->w = false;
    g->a = false;
    g->s = false;
    g->d = false;
    g->left = false;
    g->right = false;
	g->speed = 0.100f;
    g->rspeed = 0.05f;
	g->text.texHeight = 64;
	g->text.texWidth = 64;
}

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

void	inits_rgb(t_game *g)
{
	char **ptr_f;
	char **ptr_c;
	ptr_f = ft_split(g->file->F, ',');
	ptr_c = ft_split(g->file->C, ',');
	
	g->text.floor
	= create_trgb(0, ft_atoi(ptr_f[0]), ft_atoi(ptr_f[1]), ft_atoi(ptr_f[2]));
	g->text.ceiling 
	= create_trgb(0, ft_atoi(ptr_c[0]), ft_atoi(ptr_c[1]), ft_atoi(ptr_c[2]));
}

void	texture_init(t_game *g)
{
	g->text.imgNO = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		{
			exit(printf("%s\n", "Error\n"));
		}
	g->text.imgSO = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		{
			exit(printf("%s\n", "Error\n"));
		}
	g->text.imgWE = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		{
			exit(printf("%s\n", "Error\n"));
		}
	g->text.imgEA = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		{
			exit(printf("%s\n", "Error\n"));
		}
}

void	texture_init_next(t_game *g)
{
	int	n;
	int k;
	
	g->text.imgNO->img = mlx_xpm_file_to_image(g->mlx,g->file->NO, &n, &n);
	g->text.imgSO->img = mlx_xpm_file_to_image(g->mlx,g->file->SO, &n, &n);
	g->text.imgEA->img = mlx_xpm_file_to_image(g->mlx,g->file->EA, &n, &n);
	g->text.imgWE->img = mlx_xpm_file_to_image(g->mlx,g->file->WE, &n, &n);
	g->text.imgNO->addr = (int *)mlx_get_data_addr(g->text.imgNO->img, &k, &k, &k);
	g->text.imgSO->addr = (int *)mlx_get_data_addr(g->text.imgSO->img, &k, &k, &k);
	g->text.imgEA->addr = (int *)mlx_get_data_addr(g->text.imgEA->img, &k, &k, &k);
	g->text.imgWE->addr = (int *)mlx_get_data_addr(g->text.imgWE->img, &k, &k, &k);
}