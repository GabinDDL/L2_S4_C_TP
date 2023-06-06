#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node;
struct node
{
    int val;
    node *left;
    node *right;
};

node *cons_tree(int val, node *tl, node *tr);
void free_tree(node *t);
int size_tree(node *t);
int sum_tree(node *t);
int depth_tree(node *t);
void print_abr(node *t);
node *insert_abr(node *t, int val);
node *search_abr(node *t, int val);
node *max_abr(node *t);
node *min_abr(node *t);
int check_abr(node *t);
node *delete_abr(node *t, int val);

void print_head(int depth, int addr)
{
    if (depth > 1)
    {
        int pre = addr / 2;
        print_head(depth - 1, pre);
        printf("%s", (pre % 2) != (addr % 2) ? "|    " : "     ");
        return;
    }
    if (depth == 1)
        printf("     ");
}

void pretty_rec(node *t, int depth, int addr)
{
    if (t == NULL)
    {
        print_head(depth, addr);
        printf("|----N\n");
        return;
    }
    pretty_rec(t->right, depth + 1, 2 * addr + 1);
    print_head(depth, addr);
    char c =
        (depth == 0) ? '-' : '|';
    printf("%c----%d\n", c, t->val);
    pretty_rec(t->left, depth + 1, 2 * addr);
}

// fonction principale d'affichage.
void pretty_print(node *t)
{
    pretty_rec(t, 0, 0);
}

int main()
{
    node *t;
    t = cons_tree(1, cons_tree(3, NULL, NULL),
                  cons_tree(6, cons_tree(4, NULL, NULL), NULL));
    pretty_print(t);
    printf("Size : %d\n", size_tree(t));
    printf("Somme : %d\n", sum_tree(t));
    printf("Profondeur : %d\n", depth_tree(t));
    printf("%d\n", check_abr(t));

    free_tree(t);

    t = cons_tree(4, cons_tree(2, cons_tree(1, NULL, NULL), cons_tree(3, NULL, NULL)), cons_tree(7, cons_tree(5, NULL, cons_tree(6, NULL, NULL)), cons_tree(8, NULL, cons_tree(9, NULL, NULL))));
    pretty_print(t);
    print_abr(t);
    printf("%d\n", check_abr(t));

    free_tree(t);

    t = NULL;
    int vals[10] = {8, 3, 1, 2, 6, 4, 7, 10, 14, 13};
    for (int i = 0; i < 10; i++)
    {
        t = insert_abr(t, vals[i]);
    }
    pretty_print(t);

    pretty_print(search_abr(t, 2));
    pretty_print(search_abr(t, 6));
    pretty_print(search_abr(t, 15));

    pretty_print(max_abr(t));
    pretty_print(min_abr(t));

    printf("%d\n", check_abr(t));

    t = delete_abr(t, 8);
    pretty_print(t);

    free_tree(t);
}

node *cons_tree(int val, node *tl, node *tr)
{
    node *arbre = malloc(sizeof(node));
    arbre->val = val;
    arbre->left = tl;
    arbre->right = tr;

    return arbre;
}

void free_tree(node *t)
{
    if (t == NULL)
    {
        return;
    }
    free_tree(t->left);
    free_tree(t->right);

    free(t);
}

int size_tree(node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    return 1 + size_tree(t->left) + size_tree(t->right);
}

int sum_tree(node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    return t->val + sum_tree(t->left) + sum_tree(t->right);
}

int depth_tree(node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    int left = depth_tree(t->left);
    int right = depth_tree(t->right);

    if (left > right)
    {
        return 1 + left;
    }
    return 1 + right;
}

void anx_print_abr(node *t)
{
    if (t == NULL)
    {
        return;
    }
    anx_print_abr(t->left);
    printf("%d ", t->val);
    anx_print_abr(t->right);
}

void print_abr(node *t)
{
    anx_print_abr(t);
    puts("");
}

node *insert_abr(node *t, int val)
{
    if (t == NULL)
    {
        return cons_tree(val, NULL, NULL);
    }
    if (t->val >= val)
    {
        t->left = insert_abr(t->left, val);
    }
    else
    {
        t->right = insert_abr(t->right, val);
    }
    return t;
}

node *search_abr(node *t, int val)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->val == val)
    {
        return t;
    }
    if (val < t->val)
    {
        return search_abr(t->left, val);
    }
    return search_abr(t->right, val);
}

node *max_between_nodes(node *n1, node *n2)
{
    if (n1 == NULL && n2 == NULL)
    {
        return NULL;
    }
    if (n1 == NULL)
    {
        return n2;
    }
    if (n2 == NULL)
    {
        return n1;
    }
    if (n1->val > n2->val)
    {
        return n1;
    }
    return n2;
}

node *max_abr(node *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    node *max_edge = max_between_nodes(max_abr(t->left), max_abr(t->right));

    return max_between_nodes(t, max_edge);
}

node *min_between_nodes(node *n1, node *n2)
{
    if (n1 == NULL && n2 == NULL)
    {
        return NULL;
    }
    if (n1 == NULL)
    {
        return n2;
    }
    if (n2 == NULL)
    {
        return n1;
    }
    if (n1->val < n2->val)
    {
        return n1;
    }
    return n2;
}

node *min_abr(node *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    node *min_edge = min_between_nodes(min_abr(t->left), min_abr(t->right));

    return min_between_nodes(t, min_edge);
}

int check_abr(node *t)
{
    if (t == NULL)
    {
        return 1;
    }
    node *min_node = min_abr(t);
    node *max_node = max_abr(t);

    if (min_node->val > max_node->val)
    {
        return 0;
    }

    if (check_abr(t->left) == 0 || check_abr(t->right) == 0)
    {
        return 0;
    }
    return 1;
}

node *delete_abr(node *t, int val)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->val > val)
    {
        t->left = delete_abr(t->left, val);
        return t;
    }
    if (t->val < val)
    {
        t->right = delete_abr(t->right, val);
        return t;
    }
    if (t->left == NULL)
    {
        node *temp_node = t->right;
        free(t);
        return temp_node;
    }
    if (t->right == NULL)
    {
        node *temp_node = t->left;
        free(t);
        return temp_node;
    }
    node *max_left = max_abr(t->left);
    int temp = t->val;
    t->val = max_left->val;
    max_left->val = temp;

    delete_abr(t->left, temp);
    return t;
}