#include <stdio.h>

#define N 10

void print_tab(int *t, size_t start, size_t end);
void print_tab_ptr(int *pstart, int *pend);

void test_print_tab();
void test_line_print_tab(int *t, size_t length, size_t start, size_t end);
void print_tab_of_test(int *t, size_t length);

int main()
{
    test_print_tab();
    test_print_tab_ptr();

    // print_tab_ptr(t, t + N);

    // print_tab_ptr(t + 3, t + N - 2);
}

void test_print_tab()
{
    printf("##################\n# Test print_tab #\n##################\n");

    int t[N];

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = 2 + i - (i % 3);
    }

    test_line_print_tab(t, N, 0, N);
    test_line_print_tab(t, N, 3, N - 3);

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = i;
    }

    test_line_print_tab(t, N, N / 2, N / 2);
    test_line_print_tab(t, N, N / 2, N);
}

void test_line_print_tab(int *t, size_t length, size_t start, size_t end)
{
    printf("\nTest de print_tab sur le tableau t = ");
    print_tab_of_test(t, length);
    printf("print_tab(t, %lu, %lu) :\n", start, end);
    print_tab(t, start, end);
}

void test_print_tab_ptr()
{
    printf("\n######################\n# Test print_tab_ptr #\n######################\n");

    int t[N];

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = 2 + i - (i % 3);
    }

    test_line_print_tab_ptr(t, N, 0, N);
    test_line_print_tab_ptr(t, N, 3, N - 3);

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = i;
    }

    test_line_print_tab_ptr(t, N, N / 2, N / 2);
    test_line_print_tab_ptr(t, N, N / 2, N);
}

void test_line_print_tab_ptr(int *t, size_t length, size_t start, size_t end)
{
    if (!(start >= 0 && start <= length - 1 && end >= 0 && end <= length))
    {
        return;
    }
    printf("\nTest de print_tab_ptr sur le tableau t = ");
    print_tab_of_test(t, length);
    printf("print_tab_ptr(t + %lu, t + %lu) :\n", start, end);
    print_tab_ptr(t + start, t + end);
}

void print_tab_of_test(int *t, size_t length)
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
Print le tableau sous la forme suivante:
"Adresse de la case d'indice start" : "Valeur case d'indice start"
...
"Adresse de la case d'indice end-1" : "Valeur case d'indice end-1"
*/
void print_tab(int *t, size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i)
    {
        printf("%p : %d\n", t + i, *(t + i));
    }
}

/*
Print le tableau sous la forme suivante:
"Adresse de la case start" : "Valeur case start"
...
"Adresse de la case end-1" : "Valeur case end-1"
*/
void print_tab_ptr(int *pstart, int *pend)
{
    for (int *i = pstart; i < pend; ++i)
    {
        printf("%p : %d\n", i, *i);
    }
}