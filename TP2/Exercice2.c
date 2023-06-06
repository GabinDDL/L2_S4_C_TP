#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define N 100 // Taille du tableau

void initialisation(bool T[], size_t n);

void remplissage(bool T[], size_t n);

void affichNbPremier(bool T[], size_t n);

int main()
{
    printf("###########################\n# Test Crible Eratosthene #\n###########################\n");
    printf("sup = %u\n", N);

    bool T[N];
    initialisation(T, N);
    remplissage(T, N);
    affichNbPremier(T, N);
}

/*
Initialise un tableau de bool de taille n a true (sauf les deux premiers)
*/
void initialisation(bool T[], size_t n)
{
    if (n > 0)
    {
        T[0] = false;
    }

    if (n > 1)
    {
        T[1] = false;
    }

    for (unsigned i = 2; i < n; ++i)
    {
        T[i] = true;
    }
}

/*
Remplis un tableau de taille n selon le crible d'Eratosthene
*/
void remplissage(bool T[], size_t n)
{
    for (unsigned i = 2; i < n; ++i)
    {
        if (T[i])
        {
            for (unsigned j = 2 * i; j < n; j += i)
            {
                T[j] = false;
            }
        }
    }
}

/*
Affiche les indices d'un tableau de taille n si la valeur de T en cet indice est true
*/
void affichNbPremier(bool T[], size_t n)
{
    for (unsigned i = 0; i < n; ++i)
    {
        if (T[i])
        {
            printf("%u ", i);
        }
    }
    printf("\n");
}