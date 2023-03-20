#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *newList;

    newList = (t_list *)malloc(sizeof(t_list));
    if (newList == 0)
        return (0);
    newList->next = 0;
    newList->content = content;

    return (newList);
}