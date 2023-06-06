#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void sort(int *t, size_t start, size_t end);
void sort_ptr(int *start, int *end);
void quick_sort(int *t, size_t start, size_t end);
int choose_pivot(size_t start, size_t end);
int partition(int *t, size_t start, size_t end, int pivot);

void swap(int *p, int *q);
void print_tab(int *t, size_t length);

int main()
{
    int t[N];
    for (size_t i = 0; i < N; ++i)
    {
        t[i] = 2 + i - 5 * (i % 3);
    }
    print_tab(t, N);
    sort(t, 0, N);
    print_tab(t, N);

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = 2 + i - 5 * (i % 3);
    }

    sort(t, 1, N - 1);
    print_tab(t, N);

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = 2 + i - 5 * (i % 3);
    }
    print_tab(t, N);
    sort_ptr(t, t + N);
    print_tab(t, N);

    for (size_t i = 0; i < N; ++i)
    {
        t[i] = 2 + i - 5 * (i % 3);
    }

    sort_ptr(t + 3, t - N - 3);
    print_tab(t, N);

    srand(time(NULL));

    puts("QUICK SORt\n");

    srand(time(NULL));
    for (size_t i = 0; i < N; ++i)
    {
        t[i] = 2 + i - 5 * (i % 3);
    }
    print_tab(t, N);
    printf("a\n");
    quick_sort(t, 0, N - 1);
    printf("b\n");
    print_tab(t, N);
}

void sort(int *t, size_t start, size_t end)
{
    for (size_t n = end - 1; n > start + 1; --n)
    {
        for (size_t i = start; i < n; ++i)
        {
            if (*(t + i) > *(t + i + 1))
            {
                swap(t + i, t + i + 1);
            }
        }
    }
}

void sort_ptr(int *start, int *end)
{
    for (int *n = end - 1; n > start + 1; --n)
    {
        for (int *i = start; i < n; ++i)
        {
            if (*(i) > *(i + 1))
            {
                swap(i, i + 1);
            }
        }
    }
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
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

void quick_sort(int *t, size_t start, size_t end)
{
    if (start < end)
    {
        int pivot = choose_pivot(start, end);
        pivot = partition(t, start, end, pivot);
        quick_sort(t, start, pivot - 1);
        quick_sort(t, pivot + 1, end);
    }
}

int choose_pivot(size_t start, size_t end)
{
    return start + (rand() % (end - start + 1));
}

int partition(int *t, size_t start, size_t end, int pivot)
{
    swap(t + pivot, t + end);
    size_t j = start;
    for (size_t i = start; i <= end - 1; ++i)
    {
        if (t[i] <= t[end])
        {
            swap(t + i, t + j);
            ++j;
        }
    }
    swap(t + end, t + j);
    return j;
}