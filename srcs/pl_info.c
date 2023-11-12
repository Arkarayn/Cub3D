void	set_plr_pov(t_map *map, char dir)
{
    map->posx = 0;
    map->posy = 0;
    if (dir == 'N')
    {
        map->posy = -1;
        map->posx = 0.66;
    }
    else if (dir == 'S')
    {
        map->posy = 1;
        map->posx = -0.66;
    }
    else if (dir == 'E')
    {
        map->posx = 1;
        map->posy = 0.66;
    }
    else if (dir == 'W')
    {
        map->posx = -1;
        map->posy = -0.66;
    }
}

void	ft_get_player_pos(t_cube *cube)
{
    int	i;
    int	j;

    i = 0;
    while (i < cube->map->y)
    {
        j = 0;
        while (j < cube->map->x)
        {
            if (strchr("NEWS", cube->map->maprix[i][j]))
            {
                cube->map->posx = i + 0.5;
                cube->map->posy = j + 0.5;
                set_plr_pov(cube->map, cube->map->maprix[i][j]);
                cube->map->maprix[i][j] = '0';
                return ;
            }
            j++;
        }
        i++;
    }
}