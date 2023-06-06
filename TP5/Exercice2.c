#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct array
{
    int *content;
    size_t capacity;
    size_t size;
};
typedef struct array array;

#define N1 2
#define N2 10

void test_array_init();
void test_array_init_from();
void test_array_get();
void test_array_set();
void test_array_append();
void test_array_search();
void test_array_remove();
void test_array_insert();
void print_tab(int *t, size_t length);

array *array_init(size_t capacity);
array *array_init_from(int *data, size_t length, size_t capacity);
void array_destroy(array *pa);
int array_get(array *pa, size_t index);
void array_set(array *pa, size_t index, int value);
bool array_append(array *pa, int value);
void array_print(array *pa);
int *array_search(array *pa, int value);
void array_remove(array *pa, size_t index);
void array_insert(array *pa, size_t index, int value);

int main()
{
    test_array_init();
    test_array_init_from();
    test_array_get();
    test_array_set();
    test_array_append();
    test_array_search();
    test_array_remove();
    test_array_insert();
}

void test_array_init()
{
    printf("###################\n# Test array_init #\n###################\n");

    printf("Creation d'un array a1 de taille 10 :\n");
    array *a1 = array_init(10);
    printf("a1->size = %lu, a1->capacity = %lu, addrese de array->content = %p\n", a1->size, a1->capacity, a1->content);

    printf("\nCreation d'un array a2 de taille 0 :\n");
    array *a2 = array_init(0);
    printf("a2->size = %lu, a2->capacity = %lu, adresse de array->content = %p\n", a2->size, a2->capacity, a2->content);

    array_destroy(a1);
    array_destroy(a2);
}

void test_array_init_from()
{
    printf("\n########################\n# Test array_init_from #\n########################\n");

    int *t1 = malloc(N1 * sizeof(int));

    for (size_t i = 0; i < N1; ++i)
    {
        t1[i] = i + 1;
    }
    printf("Creation d'un array a1 de taille 10 from ");
    print_tab(t1, N1);

    array *a1 = array_init_from(t1, N1, 10);
    printf("a1->size = %lu, a1->capacity = %lu, array->content = ", a1->size, a1->capacity);
    array_print(a1);

    int *t2 = malloc(N2 * sizeof(int));

    for (size_t i = 0; i < N2; ++i)
    {
        t2[i] = i + 1;
    }

    printf("\nCreation d'un array a2 de taille 10 from ");
    print_tab(t2, N2);

    array *a2 = array_init_from(t2, N2, 10);
    printf("a2->size = %lu, a2->capacity = %lu, array->content = ", a2->size, a2->capacity);
    array_print(a2);

    free(t1);
    free(t2);
    array_destroy(a1);
    array_destroy(a2);
}

void test_array_get()
{
    printf("\n##################\n# Test array_get #\n##################\n");

    int *t1 = malloc(N1 * sizeof(int));

    for (size_t i = 0; i < N1; ++i)
    {
        t1[i] = i + 1;
    }

    array *a1 = array_init_from(t1, N1, 10);
    printf("Pour a1 = ");
    array_print(a1);

    for (size_t i = 0; i < a1->size; ++i)
    {
        printf("array_get(a1, %lu) = %d\n", i, array_get(a1, i));
    }

    printf("\n");

    int *t2 = malloc(N2 * sizeof(int));

    for (size_t i = 0; i < N2; ++i)
    {
        t2[i] = i + 1;
    }

    array *a2 = array_init_from(t2, N2, 10);

    printf("Pour a2 = ");
    array_print(a2);

    for (size_t i = 0; i < a2->size; ++i)
    {
        printf("array_get(a2, %lu) = %d\n", i, array_get(a2, i));
    }

    free(t1);
    free(t2);
    array_destroy(a1);
    array_destroy(a2);
}

void test_array_set()
{
    printf("\n##################\n# Test array_set #\n##################\n");

    int *t1 = malloc(N1 * sizeof(int));

    for (size_t i = 0; i < N1; ++i)
    {
        t1[i] = i + 1;
    }

    array *a1 = array_init_from(t1, N1, 10);
    printf("Pour a1 = ");
    array_print(a1);

    for (size_t i = 0; i < a1->size; ++i)
    {
        printf("array_set(a1, %lu, %lu) : a1 = ", i, i - 5);
        array_set(a1, i, i - 5);
        array_print(a1);
    }

    printf("\n");

    int *t2 = malloc(N2 * sizeof(int));

    for (size_t i = 0; i < N2; ++i)
    {
        t2[i] = i + 1;
    }

    array *a2 = array_init_from(t2, N2, 10);

    printf("Pour a2 = ");
    array_print(a2);

    for (size_t i = 0; i < a2->size; ++i)
    {
        printf("array_set(a2, %lu, %lu) : a2 = ", i, i + 5);
        array_set(a2, i, i + 5);
        array_print(a2);
    }

    free(t1);
    free(t2);
    array_destroy(a1);
    array_destroy(a2);
}

void test_array_append()
{
    printf("\n#####################\n# Test array_append #\n#####################\n");

    int *t1 = malloc(N1 * sizeof(int));

    for (size_t i = 0; i < N1; ++i)
    {
        t1[i] = i + 1;
    }

    array *a1 = array_init_from(t1, N1, 10);
    printf("Pour a1 (de capacité %lu) = ", a1->capacity);
    array_print(a1);

    for (size_t i = a1->size; i < a1->capacity; ++i)
    {
        printf("array_append(a1, %lu) : ", 3 * i);
        array_append(a1, 3 * i);
        array_print(a1);
    }

    printf("\n");

    array *a2 = array_init(10);
    printf("Pour a2 (de capacité %lu)\n", a1->capacity);

    for (size_t i = a2->size; i < a2->capacity; ++i)
    {
        printf("array_append(a2, %lu) : ", 2 * i);
        array_append(a2, 2 * i);
        array_print(a2);
    }

    free(t1);
    array_destroy(a1);
    array_destroy(a2);
}

void test_array_search()
{
    printf("\n#####################\n# Test array_search #\n#####################\n");

    int *t1 = malloc(N2 * sizeof(int));

    for (size_t i = 0; i < N2; ++i)
    {
        t1[i] = i + 1;
    }

    array *a = array_init_from(t1, N2, 10);
    printf("Pour a = ");
    array_print(a);

    printf("\nadresse de a->content[4] : %p", a->content + 4);
    int *temp = array_search(a, 5);
    printf("\narray_search(a1, %d) : adresse : %p, valeur : %d", 5, temp, *temp);

    printf("\nadresse de a->content[0] : %p", a->content);
    temp = array_search(a, 1);
    printf("\narray_search(a1, %d) : adresse : %p, valeur : %d", 1, temp, *temp);

    printf("\nadresse de a->content[9] : %p", a->content + 9);
    temp = array_search(a, 10);
    printf("\narray_search(a1, %d) : adresse : %p, valeur : %d", 10, temp, *temp);

    printf("\nL'adresse n'existe pas pour 12");
    temp = array_search(a, 12);
    printf("\narray_search(a1, %d) == NULL : ", 12);
    printf(temp == NULL ? "true\n" : "false\n");

    free(t1);
    array_destroy(a);
}

void test_array_remove()
{
    printf("\n#####################\n# Test array_remove #\n#####################\n");
    int *t1 = malloc(N1 * sizeof(int));

    for (size_t i = 0; i < N1; ++i)
    {
        t1[i] = i + 1;
    }

    array *a1 = array_init_from(t1, N1, 10);
    printf("Pour a1 = ");
    array_print(a1);
    printf("a1->size = %lu\n", a1->size);

    for (size_t i = 0; i <= a1->size; ++i)
    {
        printf("array_remove(a1, 0) : a1 = ");
        array_remove(a1, 0);
        array_print(a1);
        printf("a1->size = %lu\n", a1->size);
    }

    printf("\n");

    int *t2 = malloc(N2 * sizeof(int));

    for (size_t i = 0; i < N2; ++i)
    {
        t2[i] = i + 1;
    }

    array *a2 = array_init_from(t2, N2, 10);

    printf("Pour a2 = ");
    array_print(a2);
    printf("a2->size = %lu\n", a2->size);

    for (size_t i = 1; i < a2->size; i++)
    {
        printf("array_remove(a2, %lu) : a2 = ", i);
        array_remove(a2, i);
        array_print(a2);
        printf("a2->size = %lu\n", a2->size);
    }

    free(t1);
    free(t2);
    array_destroy(a1);
    array_destroy(a2);
}

void test_array_insert()
{
    printf("\n#####################\n# Test array_insert #\n#####################\n");

    int *t1 = malloc(N1 * sizeof(int));

    for (size_t i = 0; i < N1; ++i)
    {
        t1[i] = i + 1;
    }

    array *a1 = array_init_from(t1, N1, 10);
    printf("Pour a1 = ");
    array_print(a1);
    printf("a1->size = %lu, a1->capacity = %lu\n", a1->size, a1->capacity);

    for (size_t i = 0; i < a1->capacity; i += 2)
    {
        printf("array_insert(a1, 0, %lu) : a1 = ", i + 3);
        array_insert(a1, 0, i + 3);
        array_print(a1);
        printf("a1->size = %lu, a1->capacity = %lu\n", a1->size, a1->capacity);
    }

    printf("\n");

    int *t2 = malloc(N2 * sizeof(int));

    for (size_t i = 0; i < N2; ++i)
    {
        t2[i] = i + 1;
    }

    array *a2 = array_init_from(t2, N2, 10);

    printf("Pour a2 = ");
    array_print(a2);
    printf("a2->size = %lu, a2->capacity = %lu\n", a2->size, a2->capacity);

    for (size_t i = 0; i <= N2 + 1; ++i)
    {
        printf("array_insert(a2, %lu, %lu) : a2 = ", i, i + 3);
        array_insert(a2, i, i + 3);
        array_print(a2);
        printf("a2->size = %lu, a2->capacity = %lu\n", a2->size, a2->capacity);
    }

    free(t1);
    free(t2);
    array_destroy(a1);
    array_destroy(a2);
}

void print_tab(int *t, size_t length)
{
    printf("[");
    for (int *p = t; p < t + length - 1; ++p)
    {
        printf("%d, ", *(p));
    }
    if (length > 0)
    {
        printf("%d", *(t + length - 1));
    }
    printf("]\n");
}

array *array_init(size_t capacity)
{
    array *res = malloc(sizeof(array));

    if (res == NULL)
    {
        printf("La structure n'a pu être créé : erreur d'allocation.");
        return NULL;
    }
    res->content = malloc(capacity * sizeof(int));

    if (res->content == NULL)
    {
        printf("Le tableau de la structure n'a pu être créé : erreur d'allocation.");
        return NULL;
    }
    res->capacity = capacity;
    res->size = 0;

    return res;
}

array *array_init_from(int *data, size_t length, size_t capacity)
{
    assert(capacity >= length);

    array *res = array_init(capacity);

    for (int *p = data; p < data + length; ++p)
    {
        array_append(res, *p);
    }

    return res;
}

void array_destroy(array *pa)
{
    assert(pa != NULL);

    free(pa->content);
    free(pa);
}

int array_get(array *pa, size_t index)
{
    assert(pa != NULL);
    assert(index < pa->size);

    return pa->content[index];
}

void array_set(array *pa, size_t index, int value)
{
    assert(pa != NULL);
    assert(index < pa->size);

    pa->content[index] = value;
}

bool array_append(array *pa, int value)
{
    assert(pa != NULL);

    if (pa->size < pa->capacity)
    {
        pa->content[pa->size] = value;
        pa->size++;
        return true;
    }
    return false;
}

void array_print(array *pa)
{
    assert(pa != NULL);

    printf("[");

    for (int *p = pa->content; p < pa->content + pa->size - 1; ++p)
    {
        printf("%d, ", *p);
    }

    if (pa->size > 0)
    {
        printf("%d", pa->content[pa->size - 1]);
    }
    printf("]\n");
}

int *array_search(array *pa, int value)
{
    assert(pa != NULL);

    for (int *p = pa->content; p < pa->content + pa->size; ++p)
    {
        if (*p == value)
        {
            return p;
        }
    }
    return NULL;
}

void array_remove(array *pa, size_t index)
{
    assert(pa != NULL);
    assert(index < pa->size);

    memmove(pa->content + index, pa->content + index + 1, (pa->capacity - index - 1) * sizeof(int));

    if (index == pa->size - 1)
    {
        pa->content[pa->size - 1] = 0;
    }
    pa->size--;
}

void doubleAllocContentArray(array *pa)
{
    int *tempArray = realloc(pa->content, 2 * pa->capacity * sizeof(int));

    assert(tempArray != NULL);

    pa->content = tempArray;
    pa->capacity *= 2;
}

void array_insert(array *pa, size_t index, int value)
{
    assert(pa != NULL);

    if (pa->size == pa->capacity)
    {
        doubleAllocContentArray(pa);
    }

    assert(index <= pa->size);

    for (int *p = pa->content + pa->size - 1; p >= pa->content + index; --p)
    {
        *(p + 1) = *(p);
    }
    pa->content[index] = value;
    ++pa->size;
}