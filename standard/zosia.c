#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// int ** mnozenie(int **a, int **b)
int **mnozenie(int **a, int **b, int numRowsA, int numColsB)
{
    int **result;
    result = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        result[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = rand() % 10;
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return result;
}

void mnozenie(int **a, int **b, int numRowsA, int numColsB)
{
    int **result;
}

int main()
{
    srand(time(NULL));

    int n;
    printf("Please provide n: ");
    scanf("%d", &n);

    //  int *tab = malloc(5 * sizeof(int));

    int **tab;

    tab = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        tab[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = rand() % 10;
            printf("%d ", tab[i][j]); // jakbys byla masochistka to prosze bardzo:
            /*
                *(*(tab + i) + j)

            */
        }
        printf("\n");
    }

    return 0;
}