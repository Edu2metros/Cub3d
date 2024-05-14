/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 08:44:13 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define VALID_CHARS "01 \nNSEW"
# define PLAYER_CHARS "NSEW"
# define MSG_ERROR "\x1b[31mError\n\x1b[0m"

# define WIDTH 640
# define HEIGHT 480

enum					e_directions
{
	NO = 0,
	SO,
	WE,
	EA
};

enum					e_flags
{
	FALSE = 0,
	TRUE,
	ERROR,
	TOTAL_INFOS = 6
};

enum					e_types
{
	FLOOR = 1,
	WALL,
	PLAYER,
	SPACE
};

typedef struct s_math
{
	double				tex_x;
	double				tex_pos;
	double				step_line;
	int					side_ray_hit;
	int					mapx;
	int					mapy;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;

	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;

	double				delta_dist_x;
	double				delta_dist_y;

	double				side_dist_x;
	double				side_dist_y;

	int					step_x;
	int					step_y;
	double				surface_x;
	double				wall_dist;
	double				time;
	double				old_time;
	int					line_height;
	double				x;
	double				step;
	int					side;
}						t_math;

typedef struct s_info
{
	char				**map;
	mlx_texture_t		*no;
	mlx_texture_t		*so;
	mlx_texture_t		*we;
	mlx_texture_t		*ea;
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
	int					loop;
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
void					key(void *arg);
void					running2(t_cub *cub);
int						wall_hit(t_cub *cub, t_math *m);
void					finish_mlx(t_cub *cub);
void					ft_mlx_init(t_cub *cub);
void					update_side_hit(t_math *m, char type);
void					init_variables_paint(t_math *m, int x);
mlx_texture_t			*get_texture(t_math *m, t_cub *cub);
uint32_t				get_pixel(mlx_texture_t *texture, int texx, int texy);
void					remove_char_color(char *line);
int						is_error(t_cub *cub, char **info, int i);

// VALIDATION

void					validation(int argc, char **argv, t_cub *cub);
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
void					*calloc_gc(t_garbage **garbage_collector, size_t count,
							size_t size);
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
void					draw_frame(t_cub *cub);

// Math
void					calculate_distance(t_math *m);
void					determinate_side_distance(t_math *m);
void					calculate_dda(t_cub *cub, t_math *m);
int						calculate_line_start(t_math *m);
int						calculate_line_end(t_math *m);

// UTILS MLX
int32_t					ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void					update_time(t_math *m);

// KEYS
void					keys(void *arg);

#endif