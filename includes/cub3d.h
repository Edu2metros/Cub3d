/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/03 15:38:28 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define VALID_CHARS "01 \nNSEW"
# define PLAYER_CHARS "NSEW"

# define WIDTH 800
# define HEIGHT 600

enum					e_flags
{
	FALSE = 0,
	TRUE,
	ERROR,
	TOTAL_INFOS = 6
};

enum					types
{
	FLOOR = 0,
	WALL,
	PLAYER,
	SPACE
};

typedef struct s_math
{
	int side;
	int mapx;
	int mapy;
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;

	double camera_x;
	double ray_dir_x;
	double ray_dir_y;
	
	double delta_dist_x;
	double delta_dist_y;

	double side_dist_x;
	double side_dist_y;
	
	int step_x;
	int step_y;

	double wall_dist;
	
}					t_math;

typedef struct s_info
{
	char				**map;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	int					*cel;
	int					*flo;
}						t_info;

typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_vectors
{
	int					x;
	int					y;
	int					type;
}						t_vectors;

typedef struct s_cub
{
	int					fd;
	int					err_flag;
	char				**file;
	mlx_image_t			*img;
	mlx_t				*mlx;
	t_math				*math;
	t_vectors			**vectors;
	t_info				*info;
	t_garbage			*garbage;
}						t_cub;

t_cub					*get_struct(void);
t_cub					*init(void);
void					print_lines(t_cub *cub);
void					exit_program(t_cub *cub, char *str);

// VALIDATION

t_cub					*validation(int argc, char **argv);
void					validate_map(t_cub *cub, char **map_start);
int						validate_info(char *line, char **info, t_cub *cub);

// Validate Utils
char					**fill_info(void);
int						find_first_char(char *line);
int						find_map_height(char **map_start);
int						is_extremities_closed(char *top_line, char *bot_line);
int						ft_isvalid(char c);
int						ft_isspace_two(char **map_start, int i, int j);
int						is_a_dif_char(char *s, char c);

// Memory
void					*calloc_garbage_collector(t_garbage **garbage_collector, size_t count, size_t size);
void					free_gargabe_collector(t_garbage *list);
void					*ft_safe_malloc(size_t size);
char					*ft_strdup_two(const char *str, t_cub *cub);

// Utils
int						jump_lines(char **file);
void					remove_char(char *str, char c);

// Parser
void					parser(t_cub *cub);

// Draw Map
void					define_vectors(char **map, t_cub *cub);
void					free_vectors(t_vectors **vectors);

// MLX

mlx_t					*init_window(t_vectors **vectors);
void 					running(void *arg);

#endif