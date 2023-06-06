#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_in_disk(float x, float y)
{

    printf("%lf", sqrt(x));
    return 1;
}

int main()
{
    printf("%d", is_in_disk(1., 1.));
    printf("%d", is_in_disk(0.5, 0.5));
    printf("%d", is_in_disk(sqrt(3) / 2., 1. / 2.));
    printf("%d", is_in_disk(0, 0));
}