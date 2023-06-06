#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *dupliquer(const char *s);
int min();
int ordrealpha(const char *s1, const char *s2);
char *multiplier(const char *s, unsigned int n);

int main()
{
    char c[7] = "abcdef";
    char c2[7] = "abcjef";
    char *test = dupliquer(c);
    char *test2 = multiplier(c, 4);
    printf("%s\n", test);
    printf("%s\n", test2);
    printf("%d\n", ordrealpha(test, c));
    printf("%d\n", ordrealpha(test, test2));
    printf("%d\n", ordrealpha(c, c2));
    printf("%d\n", ordrealpha(c2, c));
    printf("%d\n", strlen(c + strlen(c)));
    printf("%s", c + 1);
    free(test);
    free(test2);
    return 0;
}

char *dupliquer(const char *s)
{
    unsigned lens = strlen(s);
    char *res = malloc(lens * sizeof(char) + 1);

    for (unsigned i = 0; i < lens; ++i)
    {
        *(res + i) = *(s + i);
    }
    *(res + lens) = '\0';

    return res;
}

int min(int n1, int n2)
{
    if (n1 < n2)
    {
        return n1;
    }
    return n2;
}

int ordrealpha(const char *s1, const char *s2)
{
    unsigned minlen = min(strlen(s1), strlen(s2));

    for (unsigned i = 0; i < minlen; ++i)
    {
        if (*(s1 + i) < *(s2 + i))
        {
            return -1;
        }
        else if (*(s1 + i) > *(s2 + i))
        {
            return 1;
        }
    }

    if (strlen(s1) < strlen(s2))
    {
        return -1;
    }

    if (strlen(s1) > strlen(s2))
    {
        return 1;
    }
    return 0;
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