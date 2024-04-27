/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/25 17:35:01 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

enum e_flags
{
	FALSE = 0,
	TRUE,
	ERROR,
	TOTAL_INFOS = 6
};

typedef struct s_colors
{
	char **cel;
	char **flo;
	char *no;
	char *so;
	char *we;
	char *ea;
} t_colors;

typedef struct s_garbage
{
	void *ptr;
	struct s_garbage *next;
} t_garbage;

typedef struct s_cub
{
	int fd;
	int err_flag;
	char **file;
	t_colors *colors;
	t_garbage *garbage;
} t_cub;


t_cub *init(void);
void *ft_safe_malloc(size_t size);
t_cub *get_struct(void);
int find_first_char(char *str);
void exit_program(t_cub *cub, char *str);

// VALUDATION

void validation(int argc, char **argv, t_cub *cub);
int map_validate(t_cub *cub, char *line);
void map_is_valid(t_cub *cub);
void print_lines(t_cub *cub);
void map_is_valid(t_cub *cub);
void pop_string_array(char **directions, char *line);
int has_in_array(char *str, char **array);
char **fill_info(void);


// Memory
void *malloc_garbage_collector(t_garbage **garbage_collector, size_t size);
void free_gargabe_collector(t_garbage *list);

#endif