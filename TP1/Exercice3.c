#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 27

void test1();
void test2();
void syracuse(unsigned n, bool printSequence);
void syracuseSequence();

int main()
{
    // 1)
    testSyracuse();

    // 3)
    testSyracuseSequence();
}

void testSyracuse()
{
    puts("#####################");
    puts("# TEST 1 (syracuse) #");
    puts("#####################");
    syracuse(N, true);
}

void testSyracuseSequence()
{
    puts("\n#############################");
    puts("# TEST 3 (syracuseSequence) #");
    puts("#############################");
    syracuseSequence(N);
}

/*
Affiche le temps de vol de la suite de syracuse, et la suite si printSequence est true
*/
void syracuse(unsigned n, bool printSequence)
{
    int temp = n;
    unsigned size = 0;

    if (n == 0)
        return;

    while (temp != 1)
    {
        if (printSequence)
        {
            printf("%d ", temp);
        }

        if (temp % 2 == 0)
        {
            temp /= 2;
        }
        else
        {
            temp = temp * 3 + 1;
        }
        size++;
    }

    if (printSequence)
    {
        printf("%d\n", temp);
    }
    printf("%d : %u\n", n, size);
}

/*
Affiche le nombre vol de la suite de Syracuse de tout les nombres inférieurs ou égaux à n
*/
void syracuseSequence(unsigned n)
{
    for (unsigned i = 1; i <= n; i++)
    {
        syracuse(i, false);
    }
}