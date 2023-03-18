#include "libft.h"

int ft_lstsize(t_list *lst)
{
    t_list *p;
    int count;

    if (lst == 0)
        return (0);
    p = lst;
    count = 1;
    while (p->next)
    {
        count++;
        p = p->next;
    }
    return (count);
}