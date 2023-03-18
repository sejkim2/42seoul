#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *p;

    p = *lst;
    lst = 0;
    while (p->next)
    {
        t_list *del_node;
        
        del_node = p;
        p = p->next;
        ft_lstdelone(del_node, del);
    }
    ft_lstdelone(p, del);
}