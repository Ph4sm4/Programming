#include <stdio.h>

int powerRecursive(int N)
{
    if (N == 0)
        return 1;

    return powerRecursive(N - 1) * 2;
}

int powerIterative(int N)
{
    int valueIteration = 1;
    printf("\nour base: %d", 2);
    printf("\nour exponent: %d", N);

    for (int i = 0; i < N; i++)
    {
        valueIteration *= 2;
        printf("\nintermediate product: %d", valueIteration);
    }

    return valueIteration;
}

int main(int argc, char *argv[])
{
    int N;
    if (argc < 2)
        return -1;

    sscanf(argv[1], "%d", &N);

    printf("\nour base: %d", 2);
    printf("\nour exponent: %d", N);
    int valueRecursive = powerRecursive(N);
    printf("\npower recursive: %d", valueRecursive);

    printf("\n\n");

    int valueIterative = powerIterative(N);
    printf("\npower iterative: %d", valueIterative);

    return 0;
}