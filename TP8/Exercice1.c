#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

typedef struct polynome
{
    int coef;
    int degre;
    struct polynome *suiv;
} polynome;

bool assertNbArg(int argc);
int getInt(char *s);
polynome *askPolynome(int n);

void test_creer_polynome_vide();
void test_creer_monome();
void test_evaluer_polynome();
void test_ajouter_monome();
void test_copie();
void test_somme();

void print_test_creer_polynome_vide();
void print_test_creer_monome(int c, int d);
void print_test_evaluer_polynome(polynome *p, double x, double va);
void print_test_ajouter_monome(polynome *p, int c, int d);
void print_test_copie(polynome *p);
void print_test_somme(polynome *p1, polynome *p2);

polynome *creer_polynome_vide();
polynome *creer_monome(int c, int d);
void polynome_destroy(polynome *p);
double evaluer_polynome(polynome *p, double x);
void afficher_polynome(polynome *p);
void ajouter_monome(polynome *p, int c, int d);
polynome *copie(polynome *p);
polynome *somme(polynome *p1, polynome *p2);

int main(int argc, char *argv[])
{
    // Test
    // test_creer_polynome_vide();
    // test_creer_monome();
    // test_evaluer_polynome();
    // test_ajouter_monome();
    // test_copie();
    // test_somme();

    // Main demande polynomes
    assert(assertNbArg(argc));
    int nb1 = getInt(argv[1]);
    int nb2 = getInt(argv[2]);

    printf("Choix Polynome 1\n");
    polynome *p1 = askPolynome(nb1);
    printf("\nChoix Polynome 2\n");
    polynome *p2 = askPolynome(nb2);

    printf("\nPolynome 1 :\n");
    afficher_polynome(p1);
    printf("\nPolynome 2 :\n");
    afficher_polynome(p2);

    printf("\nSomme :\n");
    polynome *som = somme(p1, p2);
    afficher_polynome(som);

    polynome_destroy(p1);
    polynome_destroy(p2);
    polynome_destroy(som);
}

void test_creer_polynome_vide()
{
    printf("# Test creer_polynome_vide #\n");

    polynome *p = creer_polynome_vide();
    printf("\np = creer_polynome_vide()\n");
    printf("afficher_polynome(p) : ");
    afficher_polynome(p);

    printf("p->coef = %d\n", p->coef);
    printf("p->degre = %d\n", p->degre);

    polynome_destroy(p);
}

void test_creer_monome()
{
    printf("\n# Test creer_monome #\n");

    print_test_creer_monome(1, 0);
    print_test_creer_monome(-1, 0);
    print_test_creer_monome(4, 5);
    print_test_creer_monome(-5, 7);
}

void print_test_creer_monome(int c, int d)
{
    printf("\np = creer_monome(%d, %d)\n", c, d);
    polynome *p = creer_monome(c, d);

    printf("p->coef = %d\n", p->coef);
    printf("p->degre = %d\n", p->degre);

    if (p->suiv == NULL)
    {
        printf("p->suiv = NULL\n");
    }

    polynome_destroy(p);
}

void test_evaluer_polynome()
{
    printf("\n# Test evaluer_polynome #\n");

    polynome *p = creer_polynome_vide();

    print_test_evaluer_polynome(p, 3, 0);

    ajouter_monome(p, 2, 0);
    print_test_evaluer_polynome(p, 3, 2);

    ajouter_monome(p, -3, 2);
    print_test_evaluer_polynome(p, -1, -1);

    ajouter_monome(p, 2, 3);
    print_test_evaluer_polynome(p, -1, -3);

    print_test_evaluer_polynome(p, -5, -323);

    polynome_destroy(p);
}

void print_test_evaluer_polynome(polynome *p, double x, double va)
{
    printf("\np = ");
    afficher_polynome(p);
    printf("evaluer_polynome(p, %lf) = %lf\n", x, evaluer_polynome(p, x));
    printf("valeur attendue : %lf\n", va);
}

void test_ajouter_monome()
{
    printf("\n# Test ajouter_monome (remplace si déjà existant) #\n");

    polynome *p = creer_polynome_vide();

    print_test_ajouter_monome(p, 3, 3);
    print_test_ajouter_monome(p, 1, 0);
    print_test_ajouter_monome(p, -3, 5);
    print_test_ajouter_monome(p, -1, 3);

    polynome_destroy(p);
}

void print_test_ajouter_monome(polynome *p, int c, int d)
{
    printf("\np = ");
    afficher_polynome(p);
    printf("ajouter_monome(%d, %d) : p = ", c, d);
    ajouter_monome(p, c, d);
    afficher_polynome(p);
}

void test_copie()
{
    printf("\n# Test copie #\n");

    polynome *p = creer_polynome_vide();
    print_test_copie(p);

    ajouter_monome(p, 3, 2);
    print_test_copie(p);

    ajouter_monome(p, -1, 0);
    print_test_copie(p);

    ajouter_monome(p, 4, 6);
    print_test_copie(p);

    polynome_destroy(p);
}

void print_test_copie(polynome *p)
{
    printf("\np = ");
    afficher_polynome(p);
    printf("addresse p : %p\n", p);
    printf("c = copie(p) = ");
    polynome *c = copie(p);
    afficher_polynome(c);
    printf("addresse c : %p\n", c);

    polynome_destroy(c);
}

void test_somme()
{
    printf("\n# Test somme #\n");

    polynome *p1 = creer_polynome_vide();
    polynome *p2 = creer_polynome_vide();

    print_test_somme(p1, p2);

    ajouter_monome(p1, 3, 2);
    ajouter_monome(p1, 1, 0);
    print_test_somme(p1, p2);

    ajouter_monome(p2, -1, 0);
    print_test_somme(p1, p2);

    ajouter_monome(p2, 5, 3);
    print_test_somme(p1, p2);

    ajouter_monome(p1, -3, 3);
    print_test_somme(p1, p2);

    ajouter_monome(p1, -5, 3);
    print_test_somme(p1, p2);

    ajouter_monome(p2, -3, 2);
    print_test_somme(p1, p2);

    polynome_destroy(p1);
    polynome_destroy(p2);
}

void print_test_somme(polynome *p1, polynome *p2)
{
    printf("\np1 = ");
    afficher_polynome(p1);

    printf("p2 = ");
    afficher_polynome(p2);

    printf("p1 + p2 = ");
    polynome *som = somme(p1, p2);
    afficher_polynome(som);

    polynome_destroy(som);
}

/*
assert le nombre d'argument pour main
*/
bool assertNbArg(int argc)
{
    if (argc != 3)
    {
        printf("Le nombre d'argument est différent de 3 !\n");
        return false;
    }
    return true;
}

/*
Return un int si la chaine en est un
*/
int getInt(char *s)
{
    int nb = 0;
    for (unsigned i = 0; i < strlen(s); ++i)
    {
        int ascii = *(s + i);
        assert(ascii >= 48 && ascii <= 57);

        nb *= 10;
        nb += (int)(*(s + i)) - 48;
    }

    return nb;
}

/*
Demande un polynome à l'utilisateur (assert si erreur) avec n le nombre d'ajout (possibilité d'avoir des valeurs écrasés)
*/
polynome *askPolynome(int n)
{
    assert(n >= 0);

    if (n == 0)
    {
        return creer_polynome_vide();
    }

    int tempCoef;
    unsigned tempDegre;

    polynome *res = creer_polynome_vide();

    for (unsigned i = 0; i < n; ++i)
    {
        printf("Coefficient (!= 0):\n");
        scanf("%d", &tempCoef);

        printf("Degré (> 0) (si même degré que précédent, remplacé):\n");
        scanf("%u", &tempDegre);

        ajouter_monome(res, tempCoef, tempDegre);
    }
    return res;
}

/*
Return true si le polynome est valide :
- p n'est pas nulle
- il y a bien le maillon fictif au début de degré -1
- que tout les degré après le maillon fictif sont dans l'ordre décroissant
*/
bool isValidePolynome(polynome *p)
{
    if (p == NULL || p->degre != -1)
    {
        return false;
    }

    while (p->suiv != NULL)
    {
        if (p->suiv->coef == 0 || p->suiv->degre < 0 || p->suiv->degre >= p->degre)
        {
            if (p->degre != -1)
            {
                return false;
            }
        }
        p = p->suiv;
    }
    return true;
}

/*
Creer un polynome vide (équivalent au polynome nul)
*/
polynome *creer_polynome_vide()
{
    polynome *p = malloc(sizeof(polynome));

    p->coef = 0;
    p->degre = -1;
    p->suiv = NULL;

    return p;
}

/*
Creer un monome (pour aider à l'ajout) (n'est pas un polynome valide)
*/
polynome *creer_monome(int c, int d)
{
    assert(d > -1 && c != 0);

    polynome *p = malloc(sizeof(polynome));

    p->coef = c;
    p->degre = d;
    p->suiv = NULL;

    return p;
}

/*
Free tout le polynome
*/
void polynome_destroy(polynome *p)
{
    if (p != NULL)
    {
        polynome_destroy(p->suiv);
        free(p);
    }
}

/*
Evalue le polynome p en x
*/
double evaluer_polynome(polynome *p, double x)
{
    assert(isValidePolynome(p));
    double eval = 0;

    p = p->suiv;

    int deg_prec = p != NULL ? p->degre : 0;

    while (p != NULL)
    {
        for (unsigned i = 0; i < deg_prec - p->degre; ++i)
        {
            eval *= x;
        }

        eval += p->coef;

        deg_prec = p->degre;
        p = p->suiv;
    }
    return eval;
}

/*
Afficher le polynome
Exemple : 2x^5 - 3X^2 + X - 1
*/
void afficher_polynome(polynome *p)
{
    assert(isValidePolynome(p));

    if (p->suiv == NULL)
    {
        printf("0\n");
        return;
    }
    p = p->suiv;

    if (p->degre == 0)
    {
        printf("%d", p->coef);
    }
    else if (p->degre >= 1)
    {
        if (p->coef == 1)
        {
            printf("X");
        }
        else if (p->coef == -1)
        {
            printf("-X");
        }
        else
        {
            printf("%dX", p->coef);
        }

        if (p->degre > 1)
        {
            printf("^%d", p->degre);
        }
    }

    p = p->suiv;

    while (p != NULL)
    {
        if (p->degre == 0)
        {
            if (p->coef > 0)
            {
                printf(" + %d", p->coef);
            }
            else if (p->coef < 0)
            {
                printf(" - %d", -p->coef);
            }
        }
        else if (p->degre >= 1)
        {
            if (p->coef == 1)
            {
                printf(" + X");
            }
            else if (p->coef == -1)
            {
                printf(" - X");
            }
            else if (p->coef > 0)
            {
                printf(" + %dX", p->coef);
            }
            else if (p->coef < 0)
            {
                printf(" - %dX", -p->coef);
            }

            if (p->degre > 1)
            {
                printf("^%d", p->degre);
            }
        }
        p = p->suiv;
    }
    puts("");
}

/*
Ajoute un monome au polynome (écrase l'ancienne version si existe déjà)
*/
void ajouter_monome(polynome *p, int c, int d)
{
    assert(isValidePolynome(p));

    polynome *nv_p = creer_monome(c, d);
    polynome *temp_p;

    while (p->suiv != NULL)
    {
        if (p->suiv->degre < d)
        {
            temp_p = p->suiv;
            p->suiv = nv_p;
            nv_p->suiv = temp_p;

            return;
        }

        if (p->suiv->degre == d)
        {
            temp_p = p->suiv->suiv;

            p->suiv->suiv = NULL;
            polynome_destroy(p->suiv);

            p->suiv = nv_p;
            nv_p->suiv = temp_p;

            return;
        }
        p = p->suiv;
    }
    p->suiv = nv_p;
}

/*
Renvoie le polynome copié
*/
polynome *copie(polynome *p)
{
    assert(isValidePolynome(p));

    polynome *rep = creer_polynome_vide();
    polynome *temp = rep;

    while (p->suiv != NULL)
    {
        p = p->suiv;

        temp->suiv = creer_monome(p->coef, p->degre);
        temp = temp->suiv;
    }
    return rep;
}

/*
Fait la somme entre deux polynomes
*/
polynome *somme(polynome *p1, polynome *p2)
{
    assert(isValidePolynome(p1));
    assert(isValidePolynome(p2));

    polynome *res = creer_polynome_vide(); // Garder l'adresse à renvoyer
    polynome *temp = res;

    p1 = p1->suiv;
    p2 = p2->suiv;

    while (p1 != NULL || p2 != NULL)
    {
        if (p1 == NULL || (p2 != NULL && p2->degre > p1->degre))
        {
            temp->suiv = creer_monome(p2->coef, p2->degre);
            p2 = p2->suiv;
            temp = temp->suiv;
        }
        else if (p2 == NULL || (p1 != NULL && p2->degre < p1->degre))
        {
            temp->suiv = creer_monome(p1->coef, p1->degre);
            p1 = p1->suiv;
            temp = temp->suiv;
        }
        else // Egalité
        {
            if (p1->coef + p2->coef != 0)
            {
                temp->suiv = creer_monome(p1->coef + p2->coef, p1->degre);
                temp = temp->suiv;
            }
            p1 = p1->suiv;
            p2 = p2->suiv;
        }
    }
    return res;
}