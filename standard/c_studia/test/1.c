#include <stdio.h>

int main()
{
    int x = 1;
    char slowo[] = "Siema";

    strcat(slowo, " wartosc: %i", x);
    printf(slowo);

    return 0;
}