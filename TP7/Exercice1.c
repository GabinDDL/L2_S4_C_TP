#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

void test_nbr_words();
void print_test_nbr_words();
void test_word_len();
void print_test_nbr_words();
void test_extract_word();
void print_test_extract_word();
void test_next_word();
void print_test_next_word();

int nbr_words(const char *s);
int word_len(const char *w);
char *extract_word(const char *w, int *pl);
bool isLetter(char c);
const char *next_word(const char *w);

int main()
{
    test_nbr_words();
    test_word_len();
    test_extract_word();
    test_next_word();
}

void test_nbr_words()
{
    printf("##################\n# Test nbr_words #\n##################\n");

    print_test_nbr_words("", 0);
    print_test_nbr_words("a", 1);
    print_test_nbr_words("Bonjour tout le monde", 4);
    print_test_nbr_words("    Test espace avant espace arrière    ", 5);
    print_test_nbr_words("    Test    plusieurs    espaces    ", 3);
}

void print_test_nbr_words(const char *s, int va)
{
    printf("chaine s = \"%s\"\n", s);
    printf("nbr_words(s) = %d, valeur attendue : %d\n", nbr_words(s), va);
}

void test_word_len()
{
    printf("\n#################\n# Test word_len #\n#################\n");

    print_test_word_len("", 0);
    print_test_word_len("hello", 5);
    print_test_word_len(" hello", 0);
    print_test_word_len("hello world ", 5);
    print_test_word_len("  hello world  " + 3, 4);
}

void print_test_word_len(const char *s, int va)
{
    printf("chaine s = \"%s\"\n", s);
    printf("word_len(s) = %d, valeur attendue : %d\n", word_len(s), va);
}

void test_extract_word()
{
    printf("\n#####################\n# Test extract_word #\n#####################\n");

    int *p = malloc(sizeof(int));
    *p = 0;
    print_test_extract_word("", p, "", 0);
    print_test_extract_word("hello", p, "hello", 5);
    print_test_extract_word(" hello   " + 2, p, "ello", 4);
    print_test_extract_word("hello world! ", p, "hello", 5);
    print_test_extract_word("  hello world!  " + 8, p, "world!", 6);
    free(p);
}

void print_test_extract_word(const char *s, int *p, const char *ca, int va)
{
    printf("chaine s = \"%s\", valeur initial longueur p = %d\n", s, *(p)); // p supposée non NULL

    char *res = extract_word(s, p);
    printf("extract_word(s) = \"%s\", nouvelle valeur p = %d, chaine attendue : \"%s\", valeur p attendue : %d\n", res, *(p), ca, va);
    free(res);
}

void test_next_word()
{
    printf("\n#####################\n# Test next_word #\n#####################\n");

    char *s_test = "";
    print_test_next_word(s_test, NULL);

    s_test = "         ";
    print_test_next_word(s_test, NULL);

    s_test = "hello";
    print_test_next_word(s_test, s_test);

    s_test = "   hello";
    print_test_next_word(s_test, s_test + 3);

    s_test = "    hello    ";
    print_test_next_word(s_test, s_test + 4);

    s_test = "   hello    world ";
    print_test_next_word(s_test, s_test + 3);
}

void print_test_next_word(const char *s, const char *ca)
{
    printf("chaine s = \"%s\"\n", s);

    char *res = next_word(s);
    if (res == NULL && ca == NULL)
    {
        printf("next_word(s) = %s, chaine attendue : %s\n", res, ca);
    }
    else
    {
        printf("next_word(s) = \"%s\", chaine attendue : \"%s\"\n", res, ca);
    }
}

int nbr_words(const char *s)
{
    bool isInWord = false;
    unsigned acc = 0;

    for (size_t i = 0; i < strlen(s); ++i)
    {
        if (!isInWord && *(s + i) != ' ')
        {
            ++acc;
            isInWord = true;
        }
        if (isInWord && *(s + i) == ' ')
        {
            isInWord = false;
        }
    }
    return acc;
}

int word_len(const char *w)
{
    int acc = 0;

    for (size_t i = 0; i < strlen(w); ++i)
    {
        if (*(w + i) == ' ')
        {
            return acc;
        }
        ++acc;
    }
    return acc;
}

char *extract_word(const char *w, int *pl)
{
    assert(!isspace(*(w)));

    *(pl) = word_len(w);

    char *res = malloc(*(pl) + 1);
    memmove(res, w, *(pl));

    *(res + *(pl)) = '\0';

    return res;
}

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

const char *next_word(const char *w)
{
    for (size_t i = 0; i < strlen(w); ++i)
    {
        if (!isspace(*(w + i)))
        {
            return w + i;
        }
    }
    return NULL;
}