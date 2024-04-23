# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 16:56:58 by eddos-sa          #+#    #+#              #
#    Updated: 2024/04/18 12:24:01 by eddos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                COMPILATION                                   #
#******************************************************************************#

CC      = cc -Wall -Wextra -Werror
FLAGS   = -g3 -O0

#******************************************************************************#
#                                  PATH                                       #
#******************************************************************************#

OBJ_DIR         := obj
SRC_DIR         := .

NAME = libft

src += $(addprefix handle_string/, ft_array_len.c \
                                    ft_split.c \
                                    ft_strchr.c \
                                    ft_strcmp_len.c \
                                    ft_strcmp.c \
                                    ft_strdup.c \
                                    ft_striteri.c \
                                    ft_strjoin_char.c \
                                    ft_strjoin.c \
                                    ft_strlcat.c \
                                    ft_strlcpy.c \
                                    ft_strlen.c \
                                    ft_strmapi.c \
                                    ft_strncmp.c \
                                    ft_strnstr.c \
                                    ft_strrchr.c \
                                    ft_strtrim.c \
                                    ft_substr.c)

src += $(addprefix handle_standard/, close_fd.c \
                                     ft_putchar_fd.c \
                                     ft_putendl_fd.c \
                                     ft_putstr_fd.c \
                                     ft_putstring_fd.c)

src += $(addprefix handle_memory/, ft_bzero.c \
                                    free_array.c \
                                    ft_calloc.c \
                                    ft_lstclear_bonus.c \
                                    ft_lstdelone_bonus.c \
                                    ft_memchr.c \
                                    ft_memcmp.c \
                                    ft_memcpy.c \
                                    ft_memmove.c \
                                    ft_memset.c \
                                    ft_shift_args.c)

src += $(addprefix handle_math/, ft_atof.c \
                                 ft_atoi.c \
                                 ft_atol.c \
                                 ft_itoa.c)
src += $(addprefix handle_list/, ft_lstadd_back_bonus.c \
                                 ft_lstadd_front_bonus.c \
                                 ft_lstiter_bonus.c \
                                 ft_lstlast_bonus.c \
                                 ft_lstnew_bonus.c \
                                 ft_lstsize_bonus.c)
src += $(addprefix handle_files/, ft_file_exist.c \
                                  ft_is_file_executable.c \
                                  ft_is_file_readable.c \
                                  ft_is_file_writable.c)

src += $(addprefix handle_char/, ft_isalnum.c \
                                 ft_isalpha.c \
                                 ft_isascii.c \
                                 ft_isdigit.c \
                                 ft_isprint.c \
                                 ft_tolower.c \
                                 ft_isspace.c \
                                 ft_toupper.c \
                                 ft_count_equals_chr.c \
                                 ft_isalldigit.c \
                                 ft_ismetachar.c)

src += $(addprefix get_next_line/, get_next_line.c)

src += $(addprefix ft_printf_fd/, ft_printf_fd.c)

SRC_OBJ = $(addprefix $(OBJ_DIR)/, $(src:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

libft: $(SRC_OBJ)
	@$(CC) $(FLAGS) -o libft $(SRC_OBJ)

clean: 
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
