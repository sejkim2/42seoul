/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:58:06 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 17:58:06 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dest;
    size_t s_len;
    size_t i;

    s_len = ft_strlen(s);
    i = 0;
    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (dest == 0)
        return (0);
    if (start >= s_len)
    {
        dest[0] = '\0';
        return (dest);
    }
    ft_strlcpy(dest, s + start, len + 1);
    return (dest);
}