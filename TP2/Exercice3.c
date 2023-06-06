#include <stdio.h>
#include <stddef.h>

#define N 20

unsigned f(unsigned n);
unsigned g(unsigned n);

int main()
{
    printf("N = %u, f(N) = %u, g(N) = %u\n", N, f(N), g(N));
}

unsigned f(unsigned n)
{
    if (n == 1)
        return 2;
    return 2 * g(n - 1);
}

unsigned g(unsigned n)
{
    if (n == 1)
        return 1;
    return 3 * f(n / 2);
}