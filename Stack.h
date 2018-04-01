//
// Created by plyus_000 on 30.10.2015.
//

#ifndef STACK_CPU_STACK_H
#define STACK_CPU_STACK_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

typedef struct stack
{
    int* data;
    long count, maxCount;
} Stack;

const int START_SIZE = 128;

void Stack_Dump(Stack* This, char* name);

#define ASSERT_OK(type, what)                                               \
    if(!type##_OK(what))                                                    \
    {                                                                       \
        type##_Dump(what, #what);                                           \
        printf(#type " failed in %s, %d", __FILE__, __LINE__);              \
        abort();                                                            \
    }


int Stack_OK(Stack* This)
{
    if (!This) return 0;

    if (This->count < 0 || This->count > This->maxCount || This->data == NULL || This->maxCount < 0)
        return 0;
    else return 1;
}


void Stack_Dump(Stack* This, const char name[])
{
    printf("%s = Stack (%s)\n",name, Stack_OK(This)? "ok" : "CORRUPTED!!!");
    printf("\t{\n");
    if (This)
    {
        printf("\tcurrent size = %ld\n", This->count);
        printf("\tmax size = %ld\n", This->maxCount);
        if (This->count == 0)
        {
            if (This->data)
                printf("\tdata is empty\n");
            else printf("\tdata array is corrupted (NULL pointer)\n");
        }
        else
        {
            if (!This->data)
                printf("\tdata array is corrupted (NULL pointer)\n");
            else
            {
                if (This->count > 0)
                {
                    printf("\tdata = \n");
                    for (long i = 0; i < This->count; i++)
                        printf("\t\t[%ld] %ld\n", i, (This->data)[i]);
                }
                else
                {
                    printf("\tdata is probably empty. Lets see the first elements:\n");
                    for(long i = 0; i < 10; i++)
                        printf("\t\t[%ld] %ld\n", i, (This->data)[i]);
                }
            }
        }
    }
    else
        printf("\tStack is NULL\n");
    printf("\t}\n");
}

#define Stack_dump(name) Stack_Dump((name), #name);


void Stack_ctor(Stack* This)
{
    assert(This);
    This->count = 0;
    This->maxCount = START_SIZE;
    This->data = (int*)calloc(This->maxCount, sizeof((This->data)[1]));
    ASSERT_OK(Stack, This);
}

void Stack_dtor(Stack* This)
{
    ASSERT_OK(Stack, This);
    free(This->data);
    This->data = NULL;
    This->count = -1;
    This->maxCount = -1;
}

int push_st(Stack* st, int val)
{
    ASSERT_OK(Stack, st);
    if (st->count == st->maxCount)
    {
        int *temp = (int*)realloc(st->data, (st->maxCount * 2)*sizeof((st->data)[0]));

        if (temp == NULL || errno != 0)
            return 0;

        st->data = temp;
        st->maxCount *= 2;
    }

    (st->data)[st->count++] = val;
    ASSERT_OK(Stack, st);
    return 1;
}

/// Если элементов в стеке нет, то возвращает 0, ставит errno = EACCESS
int pop_st(Stack* st)
{
    ASSERT_OK(Stack, st);
    if (st->count > 0)
    {
        st->count--;
        return (st->data)[st->count];
    }
    else
    {
        errno = EACCES;
        return 0;
    }
}

#endif //STACK_CPU_STACK_H
