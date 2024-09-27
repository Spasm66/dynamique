#include <stdio.h>
#include <stdlib.h>

void    range(int n)
{
    int *lst;

    lst = malloc(sizeof(int) * n);
    for (int i = 1; i <= n; i++)
        lst[i - 1] = i;
    printf("%d\n", lst[n / 2]);
    free(lst); 
}

int     main(int argc, char **argv)
{
    (void)argc;
    range(atoi(argv[1]));
}
