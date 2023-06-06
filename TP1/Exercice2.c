#include <stdlib.h>
#include <stdio.h>

void test1();
void test2();
void test4();

int power(int x, unsigned n);
unsigned sumOfCubed(unsigned n);
unsigned fact(unsigned n);
double averageOfSequence();

int main()
{
    test1();

    test2();

    test4();
}

void test1()
{
    puts("#######################");
    puts("# TEST 1 (sumOfCubed) #");
    puts("#######################");

    unsigned n;
    printf("Donner un nombre n : ");
    scanf("%u", &n);
    printf("sumedOfCubed(%u) = %u\n", n, sumOfCubed(n));
}

void test2()
{
    puts("\n#################");
    puts("# TEST 2 (fact) #");
    puts("#################");

    unsigned n;
    printf("Donner un nombre n : ");
    scanf("%u", &n);
    printf("fact(%u) = %u\n", n, fact(n));
}

void test4()
{
    puts("\n##############################");
    puts("# TEST 4 (averageOfSequence) #");
    puts("##############################");

    printf("%lf\n", averageOfSequence());
}

/*
Return la puissance n d'un entier x
*/
int power(int x, unsigned n)
{
    int res = 1;
    for (unsigned i = 0; i < n; ++i)
    {
        res *= x;
    }
    return res;
}

/*
Return la somme des cubes des nombres naturels <= n
*/
unsigned sumOfCubed(unsigned n)
{
    unsigned res = 0;

    for (unsigned i = 1; i <= n; ++i)
    {
        res += power(i, 3);
    }
    return res;
}

/*
Return le factorielle d'un nombre
*/
unsigned fact(unsigned n)
{
    unsigned res = 1;

    for (unsigned i = 1; i <= n; ++i)
    {
        res *= i;
        printf("%u! = %u\n", i, res);
    }
    return res;
}

/*
Return la moyenne d'une sequence donne par l'utilisateur
*/
double averageOfSequence()
{
    unsigned n = 0;
    double sum = 0;
    unsigned length = 0;

    puts("Entrez un entier:");
    scanf("%u", &n);

    if (n == 0)
    {
        return 0;
    }

    while (n != 0)
    {
        length++;
        sum += n;

        puts("Entrez un entier:");
        scanf("%u", &n);
    }
    return sum / length;
}