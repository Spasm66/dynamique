#include <stdio.h>
#include <stdlib.h>

int	int_len(int n)
{
	int	c;

	c = 0;
	while ((n = n / 10) != 0)
		c++;
	return (c + 1);
}

int	*reverse_tab(int *tab, int len_tab)
{
	int	temp;

	for (int i = 0, j = len_tab - 1; i <= j; i++, j--)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
	}
	return (tab);
}

int *int_to_tab(int n)
{
    int *tab = malloc(sizeof(int));
    int c = 0;
    if (!tab)
        return NULL;

    while (n * 10 / 10)
    {
        c++;
        int *temp = realloc(tab, sizeof(int) * c);
        if (!temp)
        {
            free(tab);
            return NULL;
        }
        tab = temp;
        tab[c - 1] = n % 10;
        n /= 10;
    }
    return reverse_tab(tab, c);
}

int	tab_len(int *tab)
{
	int	c;

	c = 0;
	while (tab[c])
		c++;
	return (c);
}

int	tab_to_int(int *tab, int len)
{
	int	res;

	res = 0;
	tab = reverse_tab(tab, len);
	for (int i = 0; i < len; i++)
	{
		res = res * 10 + tab[i];
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	*res;
	int len;
	int	*rev;
	int	nb; 

	(void)argc;
	res = int_to_tab(atoi(argv[1]));
	printf("A la %d position il y a: %d\n", atoi(argv[2]) + 1, res[atoi(argv[2])]); 
	len = int_len(atoi(argv[1]));
	rev = reverse_tab(res, len);
	printf("En renversant le nombre, a la %d position il y a: %d\n", atoi(argv[2]) + 1, rev[atoi(argv[2])]); 
	nb = tab_to_int(res, len);
	printf("Le nombre est: %d\n", nb); 
	free(res);
}