#include <stdio.h>
#include <math.h>

double aTanApprox(float x0, int N)
{
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += pow(-1, i) / (2 * i + 1) * pow(x0, 2 * i + 1);
    }

    return sum;
}

float calcError(float atanValue, float atanApproxValue)
{
    return fabs(atanValue - atanApproxValue);
}

int main()
{
    int N;
    float x0;

    printf("Provide N (N > 1): ");
    scanf("%d", &N);

    printf("Provide x0 (must be between -1 and 1 inclusive): ");
    scanf("%f", &x0);

    if (N < 1 || x0 > 1 || x0 < -1)
    {
        return -1;
    }

    double arcTanBuiltIn = atan(x0);
    double arcTanApproximation = aTanApprox(x0, N);
    float error = calcError(arcTanBuiltIn, arcTanApproximation);

    printf("Arctan: %f\n", arcTanBuiltIn);
    printf("Arctan approx: %f\n", arcTanApproximation);
    printf("Approximation error: %e\n", error);

    return 0;
}