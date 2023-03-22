/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:36 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/22 15:50:09 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t  row_size(char const *s, char c)
{
    size_t i;
    size_t count;
    size_t len;

    len = ft_strlen(s);
    i = 0;
    count = 0;
    while (s[i] == c || s[i] == '\0')
        i++;
    while (i <= len)
    {
        if (s[i] == c || s[i] == '\0')
        {
            while (s[i] == c || s[i] == '\0')
                i++;
            count++;
        }
        else
            i++;
    }
    return (count);
}

void    make_split_string(char **table, const char *s, size_t head, size_t tail)
{
    size_t i;

    i = 0;
    *table = (char *)malloc(sizeof(char) * (tail - head + 1));
    while (i < tail - head)
    {
        (*table)[i] = s[i + head];
        i++;
    }
    (*table)[i] = '\0';
    printf("%s\n", *(table));
}

char **ft_split(char const *s, char c)
{
    char **table;
    size_t row;
    size_t i;
    size_t s_len;
    size_t head;
    
    i = 0;
    row = 0;
    s_len = ft_strlen(s);
    table = (char **)malloc(sizeof(char *) * (row_size(s, c) + 1));
    if (table == 0)
        return (0);
    while (s[i] && s[i] == c)
        i++;
    head = i;
    while (i <= s_len)
    {
        if (s[i] == '\0' || s[i] == c)
        {
            make_split_string(&(table[row]), s, head, i);
            while (s[i] == '\0' || s[i] == c)
                i++;
            row++;
            head = i;
        }
        else
            i++;
    }
    if (row > 1)
        table[row] = 0;
    return (table);
}

int main()
{
    char **str = ft_split(",,,,,,,", ',');
    for(size_t i = 0; i < 5; i++)
        printf("%zu:%s\n", i, str[i]);
}