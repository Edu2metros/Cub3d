/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:15:09 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/24 12:46:10 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	int					i;
	const unsigned char	*str_ptr;
	unsigned char		chr;

	str_ptr = (const unsigned char *)str;
	chr = (unsigned char)c;
	if (str_ptr == NULL)
		return (NULL);
	i = 0;
	while (str_ptr[i] != '\0')
	{
		if (chr == str_ptr[i])
			return ((char *)&str_ptr[i]);
		i++;
	}
	if (chr == '\0')
		return ((char *)&str_ptr[i]);
	return (NULL);
}
