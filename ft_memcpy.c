/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:18 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 17:57:19 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    
    i = 0;
    if (dest == 0 && src == 0)
        return (dest);
    while (i < n)
    {
        *((unsigned char *)dest + i) = *((unsigned char *)src + i);
        i++;
    }
    return (dest);
}