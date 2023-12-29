#include "fdf.h"


void print_tab(char *av, int **tab)
{
    int y;
	int x;
    int i = 0;
	int j;

    x = count_x(av);
	y = count_y(av);
    while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%d ", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int main(int ac, char **av)
{
    int **tab;
	int k = -1;
    int y;  
    y = count_y(av[1]);


	tab = init_map(av[1]);
    print_tab(av[1], tab);

    
    while (++k < y)
		free(tab[k]);
	free(tab);
}