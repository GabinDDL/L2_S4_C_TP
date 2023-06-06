#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int min(int n1, int n2);
int ordrealpha(const char *s1, const char *s2);
bool assertLenMul(size_t lenArg);
void printMul(const char *s1, const char *s2);

int main(int argc, char *argv[])
{
    if (assertLenMul(argc))
    {
        printMul(argv[1], argv[2]);
    }
}

bool assertLenMul(size_t lenArg)
{
    if (lenArg - 1 != 2)
    {
        printf("Ce programme attend 2 arguments, mais vous ne lui en avez fourni que %lu.\n", lenArg - 1);
        return false;
    }
    return true;
}

char *multiplier(const char *s, unsigned int n)
{
    char *res = malloc(n * strlen(s) * sizeof(char) + 1);

    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < strlen(s); ++j)
        {
            *(res + j + i * strlen(s)) = *(s + j);
        }
    }
    *(res + strlen(s) * n) = '\0';
    return res;
}

void printMul(const char *s1, const char *s2)
{
    int ordre = ordrealpha(s1, s2);

    if (ordre == 0)
    {
        printf("%s = %s\n", s1, s2);
    }
    else if (ordre == -1)
    {
        printf("%s < %s\n", s1, s2);
    }
    else
    {
        printf("%s > %s\n", s1, s2);
    }
}