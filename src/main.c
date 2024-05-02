/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:22 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/02 16:22:48 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		printf("%s\n", file[i]);
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

// void

void running(t_cub *cub)
{
  double posX = 22, posY = 12;  //x and y start position
  double dirX = -1, dirY = 0; //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

//   double time = 0; //time of current frame
//   double oldTime = 0; //time of previous frame

  while(1)
  {
    for(int x = 0; x < WIDTH; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
      //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
      //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
      //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
      //unlike (dirX, dirY) is not 1, however this does not matter, only the
      //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
      //stepping further below works. So the values can be computed as below.
      // Division through zero is prevented, even though technically that's not
      // needed in C++ with IEEE 754 floating point values.
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
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
        //Check if ray has hit a wall
        // if(cub->info->map[mapX][mapY] > 0) hit = 1;
      }
      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;
      //draw the pixels of the stripe as a vertical line
      mlx_put_pixel(cub->img, drawStart, drawEnd, 0XFFFFFF);
    }
    mlx_image_to_window(cub->mlx, cub->img, 0, 0);
  }
}

void	cub3d(t_cub *cub)
{
	parser(cub);
	define_vectors(cub->info->map, cub);
	// mlx_init(cub);
	// printf("cub_vecs: %p\n", cub->vectors);
	// print_infos(cub->info);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "helloworld",FALSE);
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	running(cub);
	print_map(cub->info->map);
	// init_window(cub->vectors);

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
