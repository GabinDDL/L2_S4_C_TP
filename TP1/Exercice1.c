#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("Bonjour et bienvenue !");
    int n1;
    int n2;

    puts("Calcul de la somme d'un nombre n1 et n2");
    printf("Donnez le nombre n1: ");
    scanf("%d", &n1);

    printf("Donnez le nombre n2: ");
    scanf("%d", &n2);

    printf("Somme (%u + %u) = %u\n", n1, n2, n1 + n2);
}