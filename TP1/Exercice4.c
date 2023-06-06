#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void test1();
void test2();
void test3();
void test4();

unsigned retourne(unsigned n);
unsigned sommeChiffre(unsigned n);
bool estNarcissique(unsigned n);
void afficheNarcissique(unsigned n);
unsigned retourne2(unsigned n);

int main()
{
    test1();

    test2();

    test3();

    test4();
}

void test1()
{
    puts("#####################");
    puts("# TEST 1 (retourne) #");
    puts("#####################");
    printf("retourne(%u) = %u\n", 3567, retourne(3567));
    printf("retourne(%u) = %u\n", 0, retourne(0));
    printf("retourne(%u) = %u\n", 123456789, retourne(123456789));
    printf("retourne(%u) = %u\n", 6, retourne(6));
}

void test2()
{
    puts("\n#########################");
    puts("# TEST 2 (sommeChiffre) #");
    puts("#########################");
    printf("sommeChiffre(%u) = %u\n", 123, sommeChiffre(123));
    printf("sommeChiffre(%u) = %u\n", 321, sommeChiffre(321));
    printf("sommeChiffre(%u) = %u\n", 6, sommeChiffre(6));
    printf("sommeChiffre(%u) = %u\n", 666, sommeChiffre(666));
}

/*
 */
void test3()
{
    puts("\n################################################");
    puts("# TEST 3 (estNarcissique + afficheNarcissique) #");
    puts("################################################");
    printf("estNarcissique(%u) = ", 12);
    printf(estNarcissique(12) ? "true\n" : "false\n");
    printf("estNarcissique(%u) = ", 79);
    printf(estNarcissique(79) ? "true\n" : "false\n");
    printf("estNarcissique(%u) = ", 123);
    printf(estNarcissique(153) ? "true\n" : "false\n");
    printf("estNarcissique(%u) = ", 153);
    printf(estNarcissique(407) ? "true\n" : "false\n");
    printf("afficheNarcissique(%u) :\n", 407);
    afficheNarcissique(407);
}

void test4()
{
    puts("\n######################");
    puts("# TEST 4 (retourne2) #");
    puts("######################");
    printf("retourne2(%u) = %u\n", 123, retourne2(123));
    printf("retourne2(%u) = %u\n", 654321, retourne2(654321));
    printf("retourne2(%u) = %u\n", 212, retourne2(212));
    printf("retourne2(%u) = %u\n", 1212, retourne2(1212));
}

/*
Return le nombre de chiffre d'un naturel n
*/
unsigned retourne(unsigned n)
{
    unsigned length = 0;

    if (n == 0)
    {
        return 1;
    }

    while (n > 0)
    {
        n /= 10;
        ++length;
    }
    return length;
}

/*
Return la somme des chiffres d'un naturel n
*/
unsigned sommeChiffre(unsigned n)
{
    unsigned sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

/*
Return true si n est narcissique (cad que la somme des cubes de ses chiffres est égal a lui meme)
*/
bool estNarcissique(unsigned n)
{
    unsigned sum_narcisse = 0;
    unsigned temp = n;

    while (temp > 0)
    {
        sum_narcisse += (temp % 10) * (temp % 10) * (temp % 10);
        temp /= 10;
    }
    return sum_narcisse == n;
}

/*
Affiche tout les nombres narcissique inférieur ou égaux a n
*/
void afficheNarcissique(unsigned n)
{
    for (unsigned i = 0; i <= n; i++)
    {
        if (estNarcissique(i))
        {
            printf("%u\n", i);
        }
    }
}

/*
Return n a l'envers
*/
unsigned retourne2(unsigned n)
{
    unsigned sum_reverse = 0;

    while (n > 0)
    {
        sum_reverse *= 10;
        sum_reverse += n % 10;
        n /= 10;
    }
    return sum_reverse;
}