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

int	*int_to_tab(int n)
{
	int	*tab;
	int	c;

	c = 0;
	tab = malloc(sizeof(int));
	if (!tab)
		return (NULL);
	while (n * 10 / 10)
	{
		c++;
		tab = realloc(tab, sizeof(int) * c);
		if (!tab)
			return (NULL);
		tab[c - 1] = n % 10;
		n /= 10;
	}
	return (reverse_tab(tab, c));
}

int	main(int argc, char **argv)
{
	int	*res;
	int len;
	int	*rev;

	(void)argc;
	res = int_to_tab(atoi(argv[1]));
	printf("%d\n", res[atoi(argv[2])]);
	len = int_len(atoi(argv[1]));
	rev = reverse_tab(res, len);
	printf("%d\n", rev[atoi(argv[2])]);
	
	free(res);
}
