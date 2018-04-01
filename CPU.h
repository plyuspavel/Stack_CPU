//
// Created by plyus_000 on 31.10.2015.
//

#ifndef STACK_CPU_CPU_H
#define STACK_CPU_CPU_H

#include "Stack.h"
#include <String.h>
#include <math.h>


typedef struct processor
{
    Stack stack;
    int ax, bx, cx;
} CPU;

int CPU_OK(CPU* This)
{
    if(This)
        return Stack_OK(&((*This).stack));
    else return 0;
}


void CPU_Dump(CPU* This, const char name[])
{
    printf("%s = CPU (%s)\n",name, CPU_OK(This)? "ok" : "CORRUPTED!!!");
    printf("{\n");
    if (This)
    {
        Stack_dump(&This->stack);
        printf("ax = %d\n", This->ax);
        printf("bx = %d\n", This->bx);
        printf("cx = %d\n", This->cx);
    }
    else
        printf ("CPU is NULL on your motherboard, possibly stolen?\n");
    printf("}\n");
}

#define CPU_dump(name) CPU_Dump((name), #name);

void CPU_ctor(CPU* This)
{
    assert(This);
    Stack_ctor(&This->stack);
    This->ax = This->bx = This->cx = 0;
    ASSERT_OK(CPU, This);
}

void CPU_dtor(CPU* This)
{
    ASSERT_OK(CPU, This);
    Stack_dtor(&This->stack);
    This->ax = (This->bx = (This->cx = -1));
}

/*! ���������� ��� ������� ����� �����.
 * \return ��� �������� �������� ���������� 1.
 * ���� � ����� ������������ ������ ��� ��������, ��������� ���� ����������, ������ errno = EACCESS,
 * ���������� 0.
 * ��������! ������� ����� ����� ����������� �������� �������� errno
 */
int add_cpu(CPU* This)
{
    ASSERT_OK(CPU, This);
    errno = 0;
    push_st(&This->stack, (pop_st(&This->stack) + pop_st(&This->stack)));
    ASSERT_OK(CPU, This);
    if (!errno)
        return 1;
    else return 0;
}
/*! ����������� ��� ������� ����� �����.
 * \return ��� �������� �������� ���������� 1.
 * ���� � ����� ������������ ������ ��� ��������, ��������� ���� ����������, ������ errno = EACCESS,
 * ���������� 0.
 * ���� �� ������� ������ ��� ������ ����������, ������ errno = ENOMEM, ���������� 0.
 * ��������! ������� ����� ����� ����������� �������� �������� errno
 */
int mul_cpu(CPU* This)
{
    ASSERT_OK(CPU, This);
    errno = 0;
    int multiplier1 = pop_st(&This->stack);
    if (errno)
    {
        ASSERT_OK(CPU, This);
        return 0;
    }
    int multiplier2 = pop_st(&This->stack);
    if (errno)
    {
        push_st(&This->stack, multiplier1);
        ASSERT_OK(CPU, This);
        return 0;
    }

    if (!push_st(&This->stack, multiplier1 * multiplier2))
    {
        errno = ENOMEM;
        push_st(&This->stack, multiplier2);
        push_st(&This->stack, multiplier1);
        ASSERT_OK(CPU, This);
        return 0;
    }

    ASSERT_OK(CPU, This);
    return 1;
}

/*! �������� ��� ������� ����� ����� (�� �������� �������� ������).
 * \return ��� �������� �������� ���������� 1.
 * ���� � ����� ������������ ������ ��� ��������, ��������� ���� ����������, ������ errno = EACCESS,
 * ���������� 0.
 * ���� �� ������� ������ ��� ������ ����������, ������ errno = ENOMEM, ���������� 0.
 * ��������! ������� ����� ����� ����������� �������� �������� errno
 */
int sub_cpu(CPU* This)
{
    ASSERT_OK(CPU, This);
    errno = 0;
    int minuend = pop_st(&This->stack);
    if (errno)
    {
        ASSERT_OK(CPU, This);
        return 0;
    }
    int subtrahend = pop_st(&This->stack);
    if (errno)
    {
        push_st(&This->stack, minuend);
        ASSERT_OK(CPU, This);
        return 0;
    }

    if (!push_st(&This->stack, minuend - subtrahend))
    {
        errno = ENOMEM;
        push_st(&This->stack, subtrahend);
        push_st(&This->stack, minuend);
        ASSERT_OK(CPU, This);
        return 0;
    }

    ASSERT_OK(CPU, This);
    return 1;
}

/*! ����� ��� ������� ����� ����� (������� �� ����� ������).
 * \return ��� �������� �������� ���������� 1.
 * ���� � ����� ������������ ������ ��� ��������, ��������� ���� ����������, ������ errno = EACCESS,
 * ���������� 0.
 * ���� �� ������� ������ ��� ������ ����������, ������ errno = ENOMEM, ���������� 0.
 * ���� ���� ������� �� 0, ��������� ���� ����������, ������ errno = EPERM, ���������� 0.
 * ��������! ������� ����� ����� ����������� �������� �������� errno
 */
int div_cpu(CPU* This)
{
    ASSERT_OK(CPU, This);
    errno = 0;
    int divident = pop_st(&This->stack);
    if (errno)
    {
        ASSERT_OK(CPU, This);
        return 0;
    }

    int dividor = pop_st(&This->stack);
    if (errno)
    {
        push_st(&This->stack, divident);
        ASSERT_OK(CPU, This);
        return 0;
    }

    if (dividor != 0)
        {
            if (!push_st(&This->stack, divident / dividor))
            {
                errno = ENOMEM;
                push_st(&This->stack, dividor);
                push_st(&This->stack, divident);
                ASSERT_OK(CPU, This);
                return 0;
            }
        }
    else
    {
        push_st(&This->stack, dividor);
        push_st(&This->stack, divident);
        errno = EPERM;
    }

    ASSERT_OK(CPU, This);
    return 1;
}

//������������ ������ ������
#define CMD(name, num, code) cmd_##name = num,

enum Commands
{
    #include "my_libraries/cmdList"
    cmd_last
};

#undef CMD

#define CMD(name, num, code)  \
    {cmd_##name, #name},

struct CmdInfo
{
    int num;
    const char* name;
};

const CmdInfo Info[] =
        {
                #include "my_libraries/cmdList"
                {}
        };

#undef CMD
//����� ������ �����������

/*! �������� ��������� ��������� ������ ������ �� ����������.
 * \return ���������� �������� errno (�.�. ��� �������� ���������� - 0)
 * errno ����� ���� ������:
 * ENXIO, ���� ������� ������� ��������� �� ������ ������
 * EACCESS, ���� ���� ��������� ������������ �������� �� ������
 * EPERM, ���� ���� ����������� ������� �� 0
 * ENOMEM, ���� �������� �������� ������
 * EINVAL, ���� ��� ������� ������ ����� ��������
 * EIO, ���� ���� ������� ������������� �������
 */
int startWorking(CPU* This, int* com_array, size_t size)
{
    ASSERT_OK(CPU, This);
    if (!com_array)
    {
        errno = ENXIO;
        return errno;
    }
    for (size_t i = 2; (i < size)&&(!errno); i++)
    {
        switch(com_array[i])
        {
            #define CMD(name, num, code) \
                case num: {code;} break;

            #include "my_libraries\cmdList"

            #undef CMD
            default:
            {
                errno = EIO;
                return errno;
            }
        }
    }
    stop: return errno;
}


#endif //STACK_CPU_CPU_H
