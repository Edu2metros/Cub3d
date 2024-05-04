/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:22 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/04 11:56:07 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		printf("line:%d string:%s\n", i, file[i]);
		i++;
	}
}

void	print_infos(t_info *info)
{
	printf("NO: %s\n", info->no);
	printf("SO: %s\n", info->so);
	printf("WE: %s\n", info->we);
	printf("EA: %s\n", info->ea);
	printf("F: %d, %d, %d\n", info->flo[0], info->flo[1], info->flo[2]);
	printf("C: %d, %d, %d\n", info->cel[0], info->cel[1], info->cel[2]);
}

/* #define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

double get_player_pos(t_vectors **vectos, char type)
{
  int x;
  int y;

  y = -1;
  while (vectos[++y])
  {
    x = -1;
    while (vectos[++x])
    {
      if (vectos[y][x].type == PLAYER)
      {
        if (type == 'x')
          return (vectos[y][x].x);
        else if (type == 'y')
          return (vectos[y][x].y);
      }
    }
  }
  return (0);
}

void running(void *arg)
{
  t_cub *cub;
  t_math *math;
  cub = (t_cub *)arg;
  math = cub->math;
  //iniciar variaveis
  math->pos_x = get_player_pos(cub->vectors, 'x');
  math->pos_y = get_player_pos(cub->vectors, 'y');

  double posX = 22, posY = 12;
  double dirX = -1, dirY = 0;
  double planeX = 0, planeY = 0.66;
  int w = screenWidth;
  // começar o loop que vai pintar a tela inteira
  for(int x = 0; x < w; x++)
  {
    // iniciar de novo as variaveis
    double cameraX = 2 * x / (double)w - 1;
    double rayDirX = dirX + planeX * cameraX;
    double rayDirY = dirY + planeY * cameraX;
    int mapX = (int)posX;
    int mapY = (int)posY;
    double sideDistX;
    double sideDistY;
    
    double deltaDistX;
    double deltaDistY;
    
    if(rayDirX == 0)
      deltaDistX = 1e30;
    else
      deltaDistX = fabs(1 / rayDirX);
    
    if (rayDirY == 0)
      deltaDistY = 1e30;
    else
      deltaDistY = fabs(1 / rayDirY);
    double perpWallDist;
    int stepX;
    int stepY;
    int hit = 0;
    int side;
    
    if (rayDirX < 0)
    { 
      stepX = -1;
      sideDistX = (posX - mapX) * deltaDistX;
    }
    else
    {
      stepX = 1;
      sideDistX = (mapX + 1.0 - posX) * deltaDistX;
    }
    if (rayDirY < 0)
    {
      stepY = -1;
      sideDistY = (posY - mapY) * deltaDistY;
    }
    else
    {
      stepY = 1;
      sideDistY = (mapY + 1.0 - posY) * deltaDistY;
    }



    // loop para verificar se o raio bateu em uma parede
    while (hit == 0)
    {
      if (sideDistX < sideDistY)
      {
        sideDistX += deltaDistX;
        mapX += stepX;
        side = 0;
      }
      else
      {
        sideDistY += deltaDistY;
        mapY += stepY;
        side = 1;
      }
      printf("%d, %d\n", mapX, mapY);
      if (worldMap[mapX][mapY] > 0)
        hit = 1;
    }
    
    if(side == 0)
      perpWallDist = (sideDistX - deltaDistX);
    else
      perpWallDist = (sideDistY - deltaDistY);
    int lineHeight = (int)(screenHeight / perpWallDist);
    int drawStart = -lineHeight / 2 + screenHeight / 2;
    if(drawStart < 0)
      drawStart = 0;
    int drawEnd = lineHeight / 2 + screenHeight / 2;
    if(drawEnd >= screenHeight)
      drawEnd = screenHeight - 1;
    int color;
    switch(worldMap[mapX][mapY])
{
  case 1:  color = 0xFF0000FF;  break;
  case 2:  color = 0x00FF00FF;  break;
  case 3:  color = 0x0000FFFF;  break;
  case 4:  color = 0xFFFFFFFF;  break;
  default: color = 0xFFFF00FF;  break;
}
if(side == 1)
  color = color / 2;
while(drawStart < drawEnd)
{
  mlx_put_pixel(cub->img, x, drawStart, color);
  drawStart++;
}
  }
  mlx_image_to_window(cub->mlx, cub->img, 0, 0);
} */

// Pegar a função que retorna o player pos X e Y
// Pegar a função que retorna a direção do player
// Pegar a função que retorna a direção da camera (de acordo com o player?)

void	cub3d(t_cub *cub)
{
	parser(cub);
	define_vectors(cub->info->map, cub);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "helloworld",FALSE);
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
  mlx_loop_hook(cub->mlx, running, cub);
	mlx_loop(cub->mlx);
}

// mlx_load_png();


int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = validation(argc, argv);
	cub3d(cub);
	free_gargabe_collector(cub->garbage);
	return (EXIT_SUCCESS);
}
