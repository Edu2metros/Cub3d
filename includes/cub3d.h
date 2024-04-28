/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/28 01:15:32 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define VALID_CHARS "01 \nNSEW"
# define PLAYER_CHARS "NSEW"

enum					e_flags
{
	FALSE = 0,
	TRUE,
	ERROR,
	TOTAL_INFOS = 6
};

typedef struct s_colors
{
	char				**cel;
	char				**flo;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
}						t_colors;

typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_cub
{
	int					fd;
	int					err_flag;
	char				**file;
	t_colors			*colors;
	t_garbage			*garbage;
}						t_cub;

t_cub					*get_struct(void);
t_cub					*init(void);
void					print_lines(t_cub *cub);
void					exit_program(t_cub *cub, char *str);

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
void					*malloc_garbage_collector(t_garbage **garbage_collector,
							size_t size);
void					free_gargabe_collector(t_garbage *list);
void					*ft_safe_malloc(size_t size);

#endif