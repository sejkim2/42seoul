#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *newList;

    newList = (t_list *)malloc(sizeof(t_list));
    newList->next = 0;
    newList->content = content;

    return (newList);
}