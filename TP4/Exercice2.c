#include <stdio.h>

#define N 10

void test_occ();
void test_line_occ(int *tab, size_t length, int test);
void test_occ_ptr();
void test_line_occ_ptr(int *tab, size_t length, int test);
void print_tab(int *t, size_t length);

size_t occ(int *t, size_t nbr, int v);
int *occ_ptr(int *t, size_t nbr, int v);

int main()
{
    test_occ();
    printf("\n");
    test_occ_ptr();

    return 0;
}

void test_occ()
{
    printf("############\n# Test occ #\n############\n");

    int t[N];

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = i % 4 + 1;
    }
    test_line_occ(t, N, 1);
    test_line_occ(t, N, 4);
    test_line_occ(t, N, 8);
}

void test_line_occ(int *tab, size_t length, int test)
{
    printf("\nTest de occ sur le tableau t = ");
    print_tab(tab, length);
    printf("occ(t, length_t, %d) = %ld\n", test, occ(tab, length, test));
}

void test_occ_ptr()
{
    printf("################\n# Test occ_ptr #\n################\n");

    int t[N];

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = i % 4 + 1; // t = [1, 2, 3, 4, 1, 2, 3, 4, 1, 2]
    }
    test_line_occ_ptr(t, N, 1);
    test_line_occ_ptr(t, N, 4);
    test_line_occ_ptr(t, N, 8);
}

void test_line_occ_ptr(int *tab, size_t length, int test)
{
    printf("\nTest de occ_ptr sur le tableau t = ");
    print_tab(tab, length);

    int *res = occ_ptr(tab, length, test);

    if (res == NULL)
    {
        printf("occ_ptr(t, length_t, %d) = NULL\n", test);
    }
    else
    {
        printf("*occ_ptr(t, length_t, %d) = %d\n", test, *res);
        printf("occ_ptr(t, length_t, %d) = %p\n", test, res);
        printf("Adresse du premier x tel que t[x] = %d : %p\n", test, tab + occ(tab, length, test));
    }
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
Renvoie l'indice de la premiere occurrence de v
*/
size_t occ(int *t, size_t nbr, int v)
{
    for (size_t i = 0; i < nbr; ++i)
    {
        if (*(t + i) == v)
        {
            return i;
        }
    }
    return nbr;
}

/*
Renvoie l'adresse de la première occurrence de v
*/
int *occ_ptr(int *t, size_t nbr, int v)
{
    for (size_t i = 0; i < nbr; ++i)
    {
        if (*(t + i) == v)
        {
            return t + i;
        }
    }
    return NULL;
}