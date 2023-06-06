#include <stdio.h>

#define N 10

void test_nbr_occ();
void test_line_nbr_occ(int *t, size_t length, int test);
void test_nbr_occ_op();
void test_line_nbr_occ_op(int *t, size_t length, int test, size_t *p);
void test_min_max_op();
void test_line_min_max_op(int *t, size_t length, int *min, int *max);
void print_tab(int *t, size_t length);

size_t nbr_occ(int *t, size_t nbr, int v);
void nbr_occ_op(int *t, size_t nbr, int v, size_t *pnv);
void min_max_op(int *t, size_t nbr, int *pmin, int *pmax);

int main()
{
    test_nbr_occ();
    test_nbr_occ_op();
    test_min_max_op();
}

void test_nbr_occ()
{
    printf("################\n# Test nbr_occ #\n################\n");

    int t[N];

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = i % 4 + 2;
    }

    test_line_nbr_occ(t, N, 5);
    test_line_nbr_occ(t, N, 2);
    test_line_nbr_occ(t, N, 8);
}

void test_line_nbr_occ(int *t, size_t length, int test)
{
    printf("\nTest de nbr_occ sur le tableau t = ");
    print_tab(t, length);
    printf("nbr_occ(t, length_t, %d) = %ld\n", test, nbr_occ(t, length, test));
}

void test_nbr_occ_op()
{
    printf("\n###################\n# Test nbr_occ_op #\n###################\n");

    int t[N];

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = i % 4 + 2;
    }

    size_t x = 0;

    test_line_nbr_occ_op(t, N, 5, &x);
    test_line_nbr_occ_op(t, N, 2, &x);
    test_line_nbr_occ_op(t, N, 8, &x);
}

void test_line_nbr_occ_op(int *t, size_t length, int test, size_t *p)
{
    printf("\nTest de nbr_occ_op sur le tableau t = ");
    print_tab(t, length);
    printf("Valeur initiale du pointeur p : %ld\n", *p);
    nbr_occ_op(t, length, test, p);
    printf("nbr_occ_op(t, length_t, %d, p) : *p = %ld\n", test, *p);
}

void test_min_max_op()
{
    printf("\n#######################\n# Test nbr_min_max_op #\n#######################\n");

    int t[N];
    int min = 0;
    int max = 0;

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = i % 4 + 2;
    }

    test_line_min_max_op(t, N, &min, &max);

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = i % 4 + -3 * i * (i % 2);
    }

    test_line_min_max_op(t, N, &min, &max);

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = 1;
    }

    test_line_min_max_op(t, N, &min, &max);
}

void test_line_min_max_op(int *t, size_t length, int *min, int *max)
{
    printf("\nTest de min_max_op sur le tableau t = ");
    print_tab(t, length);
    if (min != NULL)
    {
        printf("Valeur initiale du pointeur min : %d\n", *min);
    }
    else
    {
        printf("Pointeur du min = NULL");
    }
    if (max != NULL)
    {
        printf("Valeur initiale du pointeur max : %d\n", *max);
    }
    else
    {
        printf("Pointeur du max = NULL");
    }
    min_max_op(t, length, min, max);
    printf("min_max_op(tab, length_tab, min, max) : *min = %d et *max = %d\n", *min, *max);
}

void print_tab(int *t, size_t length)
{
    printf("[");

    for (int i = 0; i < length - 1; ++i)
    {
        printf("%d, ", *(t + i));
    }

    if (length > 0)
    {
        printf("%d", *(t + length - 1));
    }
    printf("]\n");
}

/*
Renvoie le nombre d'occurrence de v dans t
*/
size_t nbr_occ(int *t, size_t nbr, int v)
{
    unsigned compteur = 0;

    for (size_t i = 0; i < nbr; ++i)
    {
        if (*(t + i) == v)
        {
            ++compteur;
        }
    }
    return compteur;
}

/*
Définit la valeur du pointeur pnv comme le nombre d'occurrence de v
*/
void nbr_occ_op(int *t, size_t nbr, int v, size_t *pnv)
{
    *pnv = nbr_occ(t, nbr, v);
}

/*
Définit la valeur des pointeurs min et max respectivement comme la valeur min et la valeur max du tableau t
*/
void min_max_op(int *t, size_t nbr, int *pmin, int *pmax)
{
    int min = *t;
    int max = *t;

    for (size_t i = 0; i < nbr; ++i)
    {
        if (min > *(t + i))
        {
            min = *(t + i);
        }
        if (max < *(t + i))
        {
            max = *(t + i);
        }
    }
    *pmin = min;
    *pmax = max;
}