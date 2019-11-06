
#include "fillit.h"

void	*ft_memset(void *b, int c, size_t len)
{
    size_t			i;
    unsigned char	*str;

    i = 0;
    str = (unsigned char*)b;
    while (i < len)
    {
        str[i] = (unsigned char)c;
        i++;
    }
    return (b);
}

int     map_size(int reader)
{
    int size;
    int quantity_tetr;

//    if (reader % 21 != 0)
//        quantity_tetr = reader / 21 + 1;
//    else
//        quantity_tetr = reader / 21;
    size = 2;
    while (size * size < quantity_tetr)
        size++;
//    printf("%d\n", quantity_tetr);
//    printf("%d\n", size);
    return (size);
}

int     count_list(t_flist *list)
{
    int i;

    i = 0;
    while (list)
    {
        list = list->next;
        i++;
    }
    return (i);
}

t_map  *new_map(int size)
{
    t_map *ptr;
    int i;

    ptr = (t_map*)malloc(sizeof(t_map));
    ptr->map = (char**)malloc(sizeof(char*) * size);
    i = 0;
    while (i < size)
    {
        ptr->map[i] = (char*)malloc(sizeof(char) * size + 1);
        ft_memset(ptr->map[i], '.', size);
//        printf("%s\n", ptr->map[i]);
        i++;
    }
    return (ptr);
}





