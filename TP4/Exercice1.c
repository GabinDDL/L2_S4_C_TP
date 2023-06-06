#include <stdio.h>

void swap(int *p, int *q);

int main()
{
    int x, y;
    x = 5;
    y = 6;
    printf("(avant) x : %d, y : %d\n", x, y); // => (avant) 5 6
    swap(&x, &y);
    printf("(apres) x : %d, y : %d\n", x, y); // => (apres) 6 5

    int t[3] = {3, 2, 1};
    printf("(avant) x : %d, y : %d\n", t[0], t[2]); // => (avant) 3 1
    swap(t, t + 2);
    printf("(apres) x : %d, y : %d\n", t[0], t[2]); // => (apres) 1 3
    return 0;
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}