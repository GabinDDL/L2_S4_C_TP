#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100
#define NBC 5

struct polynome
{
    int de;
    int co[N];
};
typedef struct polynome polynome;

void test_print_poly(polynome t[], size_t n);
void test_eval(polynome t[], size_t n, int e);
void test_derive(polynome t[], size_t n);
void test_add(polynome t[], size_t n);
void test_mul(polynome t[], size_t n);

int eval(polynome p, int x);
void print_poly(polynome p);
polynome derive(polynome p);
polynome add_poly(polynome p1, polynome p2);
polynome mul_poly(polynome p1, polynome p2);

int main()
{
    polynome tp[NBC] = {
        [0] = {.de = 3, .co = {[0] = 1, [1] = 4, [3] = 3}},  // 1 + 4X + 3X³
        [1] = {.de = -1, .co = {}},                          // 0
        [2] = {.de = 1, .co = {[0] = 5, [1] = -3}},          // 5 - 3X
        [3] = {.de = 5, .co = {[1] = 1, [3] = -1, [5] = 1}}, // X - 3X^3 + X^5
        [4] = {.de = 2, .co = {[2] = 1}}};                   // X^2

    test_print_poly(tp, NBC);
    test_eval(tp, NBC, -1);
    test_eval(tp, NBC, 2);
    test_derive(tp, NBC);
    test_add(tp, NBC);
    test_mul(tp, NBC);
    return 0;
}

void test_print_poly(polynome t[], size_t n)
{
    printf("###################\n# Test print_poly #\n###################\n\n");
    for (unsigned i = 0; i < n; ++i)
    {
        printf("P%d[X] = ", i);
        print_poly(t[i]);
    }
}

void test_eval(polynome t[], size_t n, int e)
{
    printf("\n##################\n# Test eval(%d) #\n##################\n\n", e);
    for (unsigned i = 0; i < n; ++i)
    {
        printf("P%d[%d] = %d\n", i, e, eval(t[i], e));
    }
}

void test_derive(polynome t[], size_t n)
{
    printf("\n###############\n# Test derive #\n###############\n\n");
    for (unsigned i = 0; i < n; ++i)
    {
        printf("P%d'[X] = ", i);
        print_poly(derive(t[i]));
    }
}

void test_add(polynome t[], size_t n)
{
    printf("\n############\n# Test add #\n############\n\n");
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = i + 1; j < n; j++)
        {
            printf("P%d[X] + P%d[X] = ", i, j);
            print_poly(add_poly(t[i], t[j]));
        }
    }
}

void test_mul(polynome t[], size_t n)
{
    printf("\n############\n# Test mul #\n############\n\n");
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = i + 1; j < n; j++)
        {
            printf("P%d[X] * P%d[X] = ", i, j);
            print_poly(mul_poly(t[i], t[j]));
        }
    }
}

// Evalue le polynome p en x
int eval(polynome p, int x)
{
    int res = 0;

    for (int i = p.de; i >= 0; --i)
    {
        res *= x;
        res += p.co[i];
    }

    return res;
}

// Print le polynome
void print_poly(polynome p)
{

    int i = 0;

    if (p.de < 0)
    {
        puts("0");
        return;
    }

    for (unsigned j = 0; j < p.de + 1; ++j)
    {
        if (p.co[j] != 0)
        {
            if (j == 0)
            {
                printf("%d", p.co[j]);
            }
            else if (j == 1)
            {
                if (p.co[j] == 1)
                {
                    printf("X");
                }
                else if (p.co[j] == -1)
                {
                    printf("-X");
                }
                else
                {
                    printf("%dX", p.co[j]);
                }
            }
            else
            {
                if (p.co[j] == 1)
                {
                    printf("X^%d", j);
                }
                else if (p.co[j] == -1)
                {
                    printf("-X^%d", j);
                }
                else
                {
                    printf("%dX^%d", p.co[p.de], p.de);
                }
            }
            i = j;
            break;
        }
    }

    if (i == 0 && p.co[1] != 0)
    {
        if (p.co[1] > 0)
        {
            if (p.co[1] == 1)
            {
                printf(" + X");
            }
            else
            {
                printf(" + %dX", p.co[1]);
            }
        }
        else
        {
            if (p.co[1] == -1)
            {
                printf(" - X");
            }
            else
            {
                printf(" - %dX", -p.co[1]);
            }
        }
        ++i;
    }

    for (unsigned k = i + 1; k < p.de + 1; ++k)
    {
        if (p.co[k] > 0)
        {
            if (p.co[k] == 1)
            {
                printf(" + X^%u", k);
            }
            else
            {
                printf(" + %dX^%u", p.co[k], k);
            }
        }
        else if (p.co[k] < 0)
        {
            if (p.co[k] == -1)
            {
                printf(" - X^%u", k);
            }
            else
            {
                printf(" - %dX^%u", -p.co[k], k);
            }
        }
    }
    printf("\n");
}

// Renvoie le polynome dérivé
polynome derive(polynome p)
{
    polynome res = {.de = (p.de > -1 ? p.de - 1 : -1), .co = {}};

    for (int i = p.de - 1; i >= 0; --i)
    {
        res.co[i] = (i + 1) * p.co[i + 1];
    }

    return res;
}

// Renvoie l'addition des deux polynomes
polynome add_poly(polynome p1, polynome p2)
{
    int max_de = p1.de > p2.de ? p1.de : p2.de;
    polynome res = {.de = max_de,
                    .co = {}};
    bool keep_de = false;

    for (int i = max_de; i >= 0; i--)
    {
        res.co[i] = p1.co[i] + p2.co[i];
        if (!keep_de)
        {
            if (res.co[i] == 0)
            {
                res.de--;
            }
            else
            {
                keep_de = true;
            }
        }
    }
    return res;
}

// Renvoie la multiplication des deux polynomes
polynome mul_poly(polynome p1, polynome p2)
{
    if (p1.de <= -1 || p2.de <= -1)
    {
        polynome res = {.de = -1, .co = {}};
        return res;
    }

    polynome res = {.de = p1.de + p2.de, .co = {}};

    for (int i = 0; i < p1.de + 1; i++)
    {
        if (p1.co[i] != 0)
        {
            for (int j = 0; j < p2.de + 1; j++)
            {
                if (p2.co[j] != 0)
                {
                    res.co[i + j] += p1.co[i] * p2.co[j];
                }
            }
        }
    }

    return res;
}
