
#include "fillit.h"

void      oversize(t_map *map)
{

}

t_map   *place_tetramino(t_flist *list_tetramino, t_map *map, char c)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    while (i <= 6)
    {
        x = list_tetramino->coordinate[i] + list_tetramino->x_start;
        y = list_tetramino->coordinate[i + 1] + list_tetramino->y_start;
        printf("x = %d y = %d\n", x, y);
        map->map[y][x] = c;
        i += 2;
    }

    printf("%s\n", map->map[0]);
    printf("%s\n", map->map[1]);
    printf("%s\n", map->map[2]);
    printf("%s\n", map->map[3]);
    return (NULL);
}

t_map   *filling_map(t_flist *list_tetramino)
{
    t_map *map;
    int i;
    int size;

    size = map_size(count_list(list_tetramino) * 4);
    map = new_map(size);
    i = 0;
    place_tetramino(list_tetramino, map, list_tetramino->c);

    return (NULL);
}
