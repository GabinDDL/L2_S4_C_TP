#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int t[] = {1, 2, 3};
    int *pt = t;

    printf("%d %d %d\n", *pt, *pt + 1, *pt + 2);
    Fonctionne*/

    /*int t[3] = {1, 2, 3};
    int *pt = t + 1;

    printf("%d %d\n", *pt, *pt + 1);
    Fonctionne
    */

    /*int t[] = {1, 2, 3};
    int *pt;
    pt = t;
    Fonctionne mais dans l'autre sens, t pas modifiable
    */

    /*int t[3];
    int *pt = malloc(5 * sizeof(int));
    pt = t;
    Modifiable mais pas alloué
    */

    /*int *pt = malloc(5 * sizeof(int));
    pt[0] = 10;
    pt[1] = 20;
    pt[12] = 30;

    printf("%d %d", pt[1], pt[12]);*/

    
}
