#include <stdio.h>
#include <stddef.h>

#define N 10

void somme(int T[], int S[], size_t n);
void afficheTab(int T[], size_t n);
void permute(int T[], size_t n);

int main()
{
    int T[N];
    int S[N];

    for (unsigned i = 0; i < N; ++i)
    {
        T[i] = i + 1;
    }
    afficheTab(T, N);
    somme(T, S, N);
    afficheTab(S, N);
    permute(T, N);
    afficheTab(T, N);
}

void afficheTab(int T[], size_t n)
{
    printf("[");

    for (unsigned i = 0; i < n - 1; ++i)
    {
        printf("%d,", T[i]);
    }
    if (n != 0)
    {
        printf("%d", T[n - 1]);
    }
    printf("]\n");
}

void somme(int T[], int S[], size_t n)
{
    int temp = 0;

    for (unsigned i = 0; i < n; i++)
    {
        temp += T[i];
        S[i] = temp;
    }
}

void permute(int T[], size_t n)
{
    if (n == 0)
    {
        return;
    }

    int temp = T[n - 1];

    for (unsigned i = n - 1; i > 0; i--)
    {
        T[i] = T[i - 1];
    }

    T[0] = temp;
}