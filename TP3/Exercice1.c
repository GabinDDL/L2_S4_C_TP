#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NBC 5

enum etat
{
    VALIDE,
    ENCOURS,
    EXPEDIEE
};
typedef enum etat etat;

struct commande
{
    int num_com;
    int prix_exp;
    int prix_prod;
    etat etat_com;
};
typedef struct commande commande;

void affiche_com(commande c);
void affiche_coms(commande t[], size_t taille);
commande com_alea(int num);
void generateCommandeTab(commande t[], size_t taille);
void affiche_exp(commande t[], size_t taille);
int nbr_en_cours(commande t[], size_t taille);
int cout_validees(commande t[], size_t taille);
void change_prix(commande *c, int newprice);
void expedie_tout(commande tab[], size_t n);

int main()
{
    srand(time(NULL));

    puts("################\n# Exercice 1-2 #\n################");

    commande c1;
    c1.num_com = 202;
    c1.prix_exp = 5;
    c1.prix_prod = 10;
    c1.etat_com = EXPEDIEE;
    affiche_com(c1);

    printf("\n");

    commande c2 = {.num_com = 101,
                   .prix_exp = 4,
                   .prix_prod = 5,
                   .etat_com = VALIDE};
    affiche_com(c2);

    puts("\n################\n# Exercice 3-4 #\n################");

    commande tab[NBC];
    generateCommandeTab(tab, NBC);
    affiche_coms(tab, NBC);

    puts("\n##############\n# Exercice 5 #\n##############");

    affiche_exp(tab, NBC);

    puts("\n##############\n# Exercice 6 #\n##############");

    printf("nbr_en_cours(tab, %d) = %d\n", NBC, nbr_en_cours(tab, NBC));

    puts("\n##############\n# Exercice 7 #\n##############");

    printf("cout_validees(tab, %d) = %d\n", NBC, cout_validees(tab, NBC));

    puts("\n##############\n# Exercice 8 #\n##############");

    commande c = {.prix_prod = 100};
    commande *cp = &c;
    printf("%d (avant change_prix)\n", c.prix_prod);
    change_prix(cp, 200);
    printf("%d (après change_prix)\n", c.prix_prod);

    puts("\n##############\n# Exercice 9 #\n##############");

    expedie_tout(tab, NBC);
    affiche_exp(tab, NBC);
    return 0;
}

// Affiche une commande
void affiche_com(commande c)
{
    printf("Commande N°%d :\nPrix expédition : %d\nPrix Production : %d\nEtat : ", c.num_com, c.prix_exp, c.prix_prod);
    switch (c.etat_com)
    {
    case VALIDE:
        printf("VALIDE\n");
        break;
    case EXPEDIEE:
        printf("EXPEDIE\n");
        break;
    case ENCOURS:
        printf("ENCOURS\n");
        break;
    }
}

// Affiche un tableau de commande
void affiche_coms(commande t[], size_t taille)
{
    for (unsigned i = 0; i < taille; ++i)
    {
        affiche_com(t[i]);
    }
}

// Genere aleatoirement le contenu d'un tableau de commande
void generateCommandeTab(commande t[], size_t taille)
{
    for (unsigned i = 0; i < taille; ++i)
    {
        t[i] = com_alea(i);
    }
}

// Renvoie une commande aleatoire
commande com_alea(int num)
{
    // initialisation de la suite de nombre aléatoires (pas mis ici car la fonction generate donnerait des mêmes commandes)
    // srand(time(NULL));
    commande c = {.num_com = num, .prix_exp = rand() % 20 + 1, .prix_prod = rand() % 2000 + 1, .etat_com = rand() % 3};
    return c;
}

// Affiche toutes les commandes d'un tableau qui sont expediee
void affiche_exp(commande t[], size_t taille)
{
    for (unsigned i = 0; i < taille; ++i)
    {
        switch (t[i].etat_com)
        {
        case EXPEDIEE:
            affiche_com(t[i]);
            break;

        default:
            break;
        }
    }
}

// Renvoie le nombre de commande en cours dans un tableau
int nbr_en_cours(commande t[], size_t taille)
{
    unsigned n = 0;

    for (unsigned i = 0; i < taille; ++i)
    {
        switch (t[i].etat_com)
        {
        case ENCOURS:
            n++;
            break;

        default:
            break;
        }
    }
    return n;
}

// Renvoie le cout des commandes valides d'un tableau
int cout_validees(commande t[], size_t taille)
{
    int sum = 0;

    for (unsigned i = 0; i < taille; ++i)
    {
        switch (t[i].etat_com)
        {
        case VALIDE:
            sum += t[i].prix_exp;
            break;

        default:
            break;
        }
    }
    return sum;
}

// Change le prix d'une commande
void change_prix(commande *c, int newprice)
{
    c->prix_prod = newprice;
}

// Met en expedie toutes les commandes
void expedie_tout(commande tab[], size_t n)
{
    for (unsigned i = 0; i < n; ++i)
    {
        tab[i].etat_com = EXPEDIEE;
    }
}