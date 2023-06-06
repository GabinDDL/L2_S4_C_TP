#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

#define N 7
struct fraction
{
    long int num;
    long int dem;
};

typedef struct fraction fraction;

void test_eq_fraction(fraction T[], size_t n);
void test_is_int(fraction T[], size_t n);
void test_sum(fraction T[], size_t n);
void test_sub(fraction T[], size_t n);
void test_mul(fraction T[], size_t n);
void test_reduce(fraction T[], size_t n);

fraction build(long int num, long int dem);
bool eq_fraction(fraction f, fraction g);
bool is_int(fraction f);
fraction sum(fraction f, fraction g);
fraction sub(fraction f, fraction g);
fraction mul(fraction f, fraction g);
fraction reduce(fraction f);
long pgcd(long a, long b);

int main()
{
    fraction ex_fraction[N] = {build(1, 1), build(1, 2), build(2, 4), build(-9, 3), build(8, -20), build(-5, -1), build(1, -3)};

    test_eq_fraction(ex_fraction, N);
    printf("\n");
    test_is_int(ex_fraction, N);
    printf("\n");
    test_sum(ex_fraction, N);
    printf("\n");
    test_sub(ex_fraction, N);
    printf("\n");
    test_mul(ex_fraction, N);
    printf("\n");
    test_reduce(ex_fraction, N);
}

void test_eq_fraction(fraction T[], size_t n)
{
    printf("####################\n# Test eq_fraction #\n####################\n");

    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = i + 1; j < n; ++j)
        {
            printf("%ld/%ld == %ld/%ld : ", T[i].num, T[i].dem, T[j].num, T[j].dem);
            printf(eq_fraction(T[i], T[j]) ? "true\n" : "false\n");
        }
    }
}

void test_is_int(fraction T[], size_t n)
{
    printf("###############\n# Test is_int #\n###############\n");

    for (unsigned i = 0; i < n; i++)
    {
        printf("is_int(%ld/%ld) = ", T[i].num, T[i].dem);
        printf(is_int(T[i]) ? "true\n" : "false\n");
    }
}

void test_sum(fraction T[], size_t n)
{
    printf("############\n# Test sum #\n############\n");

    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = i + 1; j < n; ++j)
        {
            fraction s = sum(T[i], T[j]);
            printf("%ld/%ld + %ld/%ld = %ld/%ld\n", T[i].num, T[i].dem, T[j].num, T[j].dem, s.num, s.dem);
        }
    }
}

void test_sub(fraction T[], size_t n)
{
    printf("############\n# Test sub #\n############\n");

    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = i + 1; j < n; ++j)
        {
            fraction s = sub(T[i], T[j]);
            printf("%ld/%ld - %ld/%ld = %ld/%ld\n", T[i].num, T[i].dem, T[j].num, T[j].dem, s.num, s.dem);
        }
    }
}

void test_mul(fraction T[], size_t n)
{
    printf("############\n# Test mul #\n############\n");

    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = i + 1; j < n; ++j)
        {
            fraction s = mul(T[i], T[j]);
            printf("%ld/%ld * %ld/%ld = %ld/%ld\n", T[i].num, T[i].dem, T[j].num, T[j].dem, s.num, s.dem);
        }
    }
}

void test_reduce(fraction T[], size_t n)
{
    printf("###############\n# Test reduce #\n###############\n");

    for (unsigned i = 0; i < n; ++i)
    {
        fraction s = reduce(T[i]);
        printf("reduce(%ld/%ld) = %ld/%ld\n", T[i].num, T[i].dem, s.num, s.dem);
    }
}

/*
Construit une fraction avec un numérateur et un dénominateur
*/
fraction build(long int num, long int dem)
{
    assert(dem != 0 /* Division par zéro*/);
    fraction res = {.num = num,
                    .dem = dem};
    return res;
}

/*
Return true si f est égale à g (avec les normes des fractions)
*/
bool eq_fraction(fraction f, fraction g)
{
    return f.num * g.dem == f.dem * g.num;
}

/*
Return true si la fraction f est un entier
*/
bool is_int(fraction f)
{
    return f.num % f.dem == 0;
}

/*
Return la fraction de l'addition entre f et g
*/
fraction sum(fraction f, fraction g)
{
    if (f.dem == g.dem)
    {
        fraction res = {.num = f.num + g.num, .dem = f.dem};
        return res;
    }

    fraction res = {.num = f.num * g.dem + g.num * f.dem, .dem = f.dem * g.dem};
    return res;
}

/*
Return la fraction de la soustraction entre f et g
*/
fraction sub(fraction f, fraction g)
{
    if (f.dem == g.dem)
    {
        fraction res = {.num = f.num - g.num, .dem = f.dem};
        return res;
    }

    fraction res = {.num = f.num * g.dem - g.num * f.dem, .dem = f.dem * g.dem};
    return res;
}

/*
Return la fraction de la multiplication de la fraction f avec la fraction gS
*/
fraction mul(fraction f, fraction g)
{
    fraction res = {.num = f.num * g.num, .dem = f.dem * g.dem};
    return res;
}

/*
Return la fraction f réduite
*/
fraction reduce(fraction f)
{
    if (f.num == 0) // Cannot be reduced
    {
        return f;
    }

    if (f.dem < 0) // Si les deux sont négatifs, s'annule, sinon le signe est echangés
    {
        f.num = -f.num;
        f.dem = -f.dem;
    }

    long p;

    if (f.num < 0)
    {
        p = pgcd(-f.num, f.dem);
    }
    else
    {
        p = pgcd(f.num, f.dem);
    }

    f.num = f.num / p;
    f.dem = f.dem / p;

    return f;
}

long pgcd(long a, long b)
{
    long x = a;
    long y = b;
    long r;

    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}