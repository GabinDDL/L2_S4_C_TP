#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nbr;
    char **words;
} w_index;

void free_index(w_index *pi);
void print_index(w_index *pi);
int size_words(w_index *pi);
char *concat_words(w_index *pi);
int size_words(w_index *pi);
w_index *cons_index(const char *s);

int main()
{
}

void free_index(w_index *pi)
{
    if (pi == NULL)
    {
        return;
    }

    if (pi->words != NULL)
    {
        for (size_t i = 0; i < pi->nbr; ++i)
        {
            free(pi->words[i]);
        }

        free(pi->words);
    }
    free(pi);
}

void print_index(w_index *pi)
{
    if (pi == NULL || pi->words == NULL)
    {
        return;
    }

    for (size_t i = 0; i < pi->nbr; ++i)
    {
        printf("%s\n", pi->words[i]);
    }
}

int size_words(w_index *pi)
{
    if (pi == NULL || pi->words == NULL)
    {
        return 0;
    }

    unsigned nb = 0;

    for (size_t i = 0; i < pi->nbr; ++i)
    {
        nb += strlen(pi->words[i]);
    }

    return nb;
}

char *concat_words(w_index *pi)
{
    if (pi == NULL || pi->words == NULL)
    {
        return NULL;
    }
    char *res = malloc(sizeof(char) * size_words(pi) + pi->nbr);
    unsigned nb_size = 0;

    for (size_t i = 0; i < pi->nbr - 1; ++i)
    {
        memmove(res + nb_size + i, pi->words[i], strlen(pi->words[i]));
        nb_size += strlen(pi->words[i]);
        res[nb_size + i] = ' ';
    }
    memmove(res + nb_size + pi->nbr - 1, pi->words[pi->nbr - 1], strlen(pi->words[pi->nbr - 1]));
    nb_size += strlen(pi->words[pi->nbr - 1]);
    res[nb_size + pi->nbr - 1] = '/0';
}

w_index *cons_index(const char *s)
{
}