#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list *p;

    p = lst;
    while (p->next)
    {
        f(p->content);
        p = p->next;
    }
    f(p->content);
}