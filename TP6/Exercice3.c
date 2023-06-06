#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct
{
    size_t indice;
    size_t len;
} mutation;

void testNbOc();
void printTestNbOc(const char *s, const char *sc, int va);
void testDif();
void printTestDif(const char *s, const char *t, size_t ia, size_t la);
void testLongest();
void printTestDif(const char *s, const char *t, size_t ia, size_t la);
void testLongestString();

void printMutation(mutation m);
int nboc(const char *s, const char *sub);
unsigned indexFirstDif(const char *s, const char *t);
unsigned lengthMutationAtIndex(const char *s, const char *t, unsigned index);
mutation diff(const char *s, const char *t);
mutation longest(const char *s, const char *t);
char *longest_string(const char *s, const char *t);

int main()
{
    testNbOc();
    testDif();
    testLongest();
    testLongestString();
}

void testNbOc()
{
    printf("#############\n# Test nboc #\n#############\n");
    printTestNbOc("aaacaa", "a", 5);
    printTestNbOc("aaacaa", "aa", 3);
    printTestNbOc("ccacacca", "cca", 2);
    printTestNbOc("", "aa", 0);
    printTestNbOc("bcefg", "a", 0);
}

void printTestNbOc(const char *s, const char *sc, int va)
{
    printf("Chaine s = %s et Sous chaine sc = %s\n", s, sc);
    printf("nboc(s, sc) = %d, valeur attendue : %d\n", nboc(s, sc), va);
}

void testDif()
{
    printf("\n############\n# Test dif #\n############\n");
    printTestDif("aaaa", "aaaa", 0, 0);
    printTestDif("", "", 0, 0);
    printTestDif("aaaa", "acca", 1, 2);
    printTestDif("aaaaaaaaaaa", "aacccaaccaa", 2, 3);
    printTestDif("aaaaa", "bbbbb", 0, 5);
}

void printTestDif(const char *s, const char *t, size_t ia, size_t la)
{
    printf("Chaine s = \"%s\" et chaine t = \"%s\"\n", s, t);
    printf("diff(s,t) = ");
    printMutation(diff(s, t));
    printf("Indice attendue : %u, longueur attendue : %u\n", ia, la);
}

void testLongest()
{
    printf("\n################\n# Test longest #\n################\n");
    printTestLongest("aaaa", "aaaa", 0, 0);
    printTestLongest("", "", 0, 0);
    printTestLongest("aaaa", "acca", 1, 2);
    printTestLongest("aaaaaaaaaaa", "aaccaacccaa", 6, 3);
    printTestLongest("aaaaa", "bbbbb", 0, 5);
    printTestLongest("atcgatatt", "aaagccata", 1, 2);
}

void printTestLongest(const char *s, const char *t, size_t ia, size_t la)
{
    printf("Chaine s = \"%s\" et chaine t = \"%s\"\n", s, t);
    printf("longest(s,t) = ");
    printMutation(longest(s, t));
    printf("Indice attendue : %u, longueur attendue : %u\n", ia, la);
}

void testLongestString()

{
    printf("\n#######################\n# Test longest string #\n#######################\n");
    printTestLongestString("aaaa", "aaaa", "");
    printTestLongestString("", "", "");
    printTestLongestString("aaaa", "acca", "cc");
    printTestLongestString("aaaaaaaaaaaaaa", "aaccaacbcaaccc", "cbc");
    printTestLongestString("aaaaa", "bbbbb", "bbbbb");
    printTestLongestString("atcgatatt", "aaagccata", "aa");
    printTestLongestString("atcgatbtt", "aaagccata", "cca");
}

void printTestLongestString(const char *s, const char *t, const char *sa)
{
    printf("Chaine s = \"%s\" et chaine t = \"%s\"\n", s, t);
    char *res = longest_string(s, t);
    printf("longest_string(s,t) = \"%s\"\n", res);
    printf("Chaine attendu : \"%s\"\n", sa);
    free(res);
}

void printMutation(mutation m)
{
    printf("Mutation d'indice %lu et de longueur %lu\n", m.indice, m.len);
}

int nboc(const char *s, const char *sub)
{

    if (strlen(sub) > strlen(s))
    {
        return 0;
    }

    unsigned occ = 0;

    for (unsigned i = 0; i < strlen(s); ++i)
    {
        bool isSub = true;
        for (unsigned j = 0; j < strlen(sub) && isSub; ++j)
        {
            isSub = *(s + i + j) == *(sub + j);
        }

        if (isSub)
        {
            ++occ;
        }
    }
    return occ;
}

/*
s et t doivent être de même longueur
*/
unsigned indexFirstDif(const char *s, const char *t)
{
    for (unsigned i = 0; i < strlen(t); ++i)
    {
        if (*(s + i) != *(t + i))
        {
            return i;
        }
    }
    return 0;
}

/*
s et t doivent être de même longueur
*/
unsigned lengthMutationAtIndex(const char *s, const char *t, unsigned index)
{
    unsigned len = 0;
    for (; index < strlen(s); ++index)
    {
        if (*(s + index) == *(t + index))
        {
            return len;
        }
        len++;
    }
    return len;
}

mutation diff(const char *s, const char *t)
{
    assert(strlen(s) == strlen(t));

    unsigned index = indexFirstDif(s, t);
    unsigned lenMut = lengthMutationAtIndex(s, t, index);

    mutation res = {.indice = index, .len = lenMut};
    return res;
}

mutation longest(const char *s, const char *t)
{
    mutation res = diff(s, t);

    if (res.len == 0)
    {
        return res;
    }

    mutation temp = res;

    while (temp.len != 0)
    {
        size_t memI = temp.indice + temp.len;
        temp = diff(s + temp.indice + temp.len, t + temp.indice + temp.len);
        temp.indice = temp.indice + memI;

        if (temp.len > res.len)
        {
            res = temp;
        }
    }
    return res;
}

char *longest_string(const char *s, const char *t)
{
    mutation m = longest(s, t);

    char *res = malloc(m.len * sizeof(char) + 1);

    for (size_t i = 0; i < m.len; ++i)
    {
        *(res + i) = *(t + i + m.indice);
    }
    *(res + m.len) = '\0';
    return res;
}