/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/24 20:27:17 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1
# define ERROR 2

typedef struct s_colors
{
	char **cel;
	char **flo;
	char *no;
	char *so;
	char *we;
	char *ea;
}		t_colors;

typedef struct s_cub
{
	int	fd;
	int	clr_flag;
	char **file;
	t_colors *colors;
}		t_cub;

t_cub	*init(t_cub *cub);
void	*ft_safe_malloc(size_t size);
t_cub	*get_struct(void);
void	validation(int argc, char **argv, t_cub *cub);

#endif