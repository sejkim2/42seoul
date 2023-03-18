#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *p;
    t_list *new;
    t_list *head;

    p = lst;
    while (p->next)
    {
        f(p->content);
        new = ft_lstnew(p->content);
        ft_lstadd_back(&head, new);
        p = p->next;
    }
    f(p->content);
    new = ft_lstnew(p->content);
    ft_lstadd_back(&head, new);

    return (head);
}