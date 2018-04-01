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

<<<<<<< HEAD
/*! Складывает два верхних числа стека.
 * \return При успешной операции возвращает 1.
 * Если в стеке недостаточно данных для операции, оставляет стек неизменным, ставит errno = EACCESS,
 * возвращает 0.
 * Внимание! Функция перед своим выполнением обнуляет значение errno
=======
/*! Ñêëàäûâàåò äâà âåðõíèõ ÷èñëà ñòåêà.
 * \return Ïðè óñïåøíîé îïåðàöèè âîçâðàùàåò 1.
 * Åñëè â ñòåêå íåäîñòàòî÷íî äàííûõ äëÿ îïåðàöèè, îñòàâëÿåò ñòåê íåèçìåííûì, ñòàâèò errno = EACCESS,
 * âîçâðàùàåò 0.
 * Âíèìàíèå! Ôóíêöèÿ ïåðåä ñâîèì âûïîëíåíèåì îáíóëÿåò çíà÷åíèå errno
>>>>>>> d02d1396f2a9b82f2df22f6e110ae668ef12df74
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
<<<<<<< HEAD
/*! Перемножает два верхних числа стека.
 * \return При успешной операции возвращает 1.
 * Если в стеке недостаточно данных для операции, оставляет стек неизменным, ставит errno = EACCESS,
 * возвращает 0.
 * Если не хватает памяти для записи результата, ставит errno = ENOMEM, возвращает 0.
 * Внимание! Функция перед своим выполнением обнуляет значение errno
=======
/*! Ïåðåìíîæàåò äâà âåðõíèõ ÷èñëà ñòåêà.
 * \return Ïðè óñïåøíîé îïåðàöèè âîçâðàùàåò 1.
 * Åñëè â ñòåêå íåäîñòàòî÷íî äàííûõ äëÿ îïåðàöèè, îñòàâëÿåò ñòåê íåèçìåííûì, ñòàâèò errno = EACCESS,
 * âîçâðàùàåò 0.
 * Åñëè íå õâàòàåò ïàìÿòè äëÿ çàïèñè ðåçóëüòàòà, ñòàâèò errno = ENOMEM, âîçâðàùàåò 0.
 * Âíèìàíèå! Ôóíêöèÿ ïåðåä ñâîèì âûïîëíåíèåì îáíóëÿåò çíà÷åíèå errno
>>>>>>> d02d1396f2a9b82f2df22f6e110ae668ef12df74
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

<<<<<<< HEAD
/*! Вычитает два верхних числа стека (из верхнего вычитает нижнее).
 * \return При успешной операции возвращает 1.
 * Если в стеке недостаточно данных для операции, оставляет стек неизменным, ставит errno = EACCESS,
 * возвращает 0.
 * Если не хватает памяти для записи результата, ставит errno = ENOMEM, возвращает 0.
 * Внимание! Функция перед своим выполнением обнуляет значение errno
=======
/*! Âû÷èòàåò äâà âåðõíèõ ÷èñëà ñòåêà (èç âåðõíåãî âû÷èòàåò íèæíåå).
 * \return Ïðè óñïåøíîé îïåðàöèè âîçâðàùàåò 1.
 * Åñëè â ñòåêå íåäîñòàòî÷íî äàííûõ äëÿ îïåðàöèè, îñòàâëÿåò ñòåê íåèçìåííûì, ñòàâèò errno = EACCESS,
 * âîçâðàùàåò 0.
 * Åñëè íå õâàòàåò ïàìÿòè äëÿ çàïèñè ðåçóëüòàòà, ñòàâèò errno = ENOMEM, âîçâðàùàåò 0.
 * Âíèìàíèå! Ôóíêöèÿ ïåðåä ñâîèì âûïîëíåíèåì îáíóëÿåò çíà÷åíèå errno
>>>>>>> d02d1396f2a9b82f2df22f6e110ae668ef12df74
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

<<<<<<< HEAD
/*! Делит два верхних числа стека (верхнее на более нижнее).
 * \return При успешной операции возвращает 1.
 * Если в стеке недостаточно данных для операции, оставляет стек неизменным, ставит errno = EACCESS,
 * возвращает 0.
 * Если не хватает памяти для записи результата, ставит errno = ENOMEM, возвращает 0.
 * Если есть деление на 0, оставляет стек неизменным, ставит errno = EPERM, возвращает 0.
 * Внимание! Функция перед своим выполнением обнуляет значение errno
=======
/*! Äåëèò äâà âåðõíèõ ÷èñëà ñòåêà (âåðõíåå íà áîëåå íèæíåå).
 * \return Ïðè óñïåøíîé îïåðàöèè âîçâðàùàåò 1.
 * Åñëè â ñòåêå íåäîñòàòî÷íî äàííûõ äëÿ îïåðàöèè, îñòàâëÿåò ñòåê íåèçìåííûì, ñòàâèò errno = EACCESS,
 * âîçâðàùàåò 0.
 * Åñëè íå õâàòàåò ïàìÿòè äëÿ çàïèñè ðåçóëüòàòà, ñòàâèò errno = ENOMEM, âîçâðàùàåò 0.
 * Åñëè åñòü äåëåíèå íà 0, îñòàâëÿåò ñòåê íåèçìåííûì, ñòàâèò errno = EPERM, âîçâðàùàåò 0.
 * Âíèìàíèå! Ôóíêöèÿ ïåðåä ñâîèì âûïîëíåíèåì îáíóëÿåò çíà÷åíèå errno
>>>>>>> d02d1396f2a9b82f2df22f6e110ae668ef12df74
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

<<<<<<< HEAD
//Формирование набора команд
=======
//Ôîðìèðîâàíèå íàáîðà êîìàíä
>>>>>>> d02d1396f2a9b82f2df22f6e110ae668ef12df74
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
<<<<<<< HEAD
//Набор команд сформирован

/*! Начинает исполнять указанный массив команд на процессоре.
 * \return Возвращает значение errno (т.е. при успешном завершении - 0)
 * errno может быть равным:
 * ENXIO, если передан нулевой указатель на массив команд
 * EACCESS, если была совершена некорректная операция со стеком
 * EPERM, если было произведено деление на 0
 * ENOMEM, если возникла нехватка памяти
 * EINVAL, если был неверно указан номер регистра
 * EIO, если была найдена необъявленная команда
=======
//Íàáîð êîìàíä ñôîðìèðîâàí

/*! Íà÷èíàåò èñïîëíÿòü óêàçàííûé ìàññèâ êîìàíä íà ïðîöåññîðå.
 * \return Âîçâðàùàåò çíà÷åíèå errno (ò.å. ïðè óñïåøíîì çàâåðøåíèè - 0)
 * errno ìîæåò áûòü ðàâíûì:
 * ENXIO, åñëè ïåðåäàí íóëåâîé óêàçàòåëü íà ìàññèâ êîìàíä
 * EACCESS, åñëè áûëà ñîâåðøåíà íåêîððåêòíàÿ îïåðàöèÿ ñî ñòåêîì
 * EPERM, åñëè áûëî ïðîèçâåäåíî äåëåíèå íà 0
 * ENOMEM, åñëè âîçíèêëà íåõâàòêà ïàìÿòè
 * EINVAL, åñëè áûë íåâåðíî óêàçàí íîìåð ðåãèñòðà
 * EIO, åñëè áûëà íàéäåíà íåîáúÿâëåííàÿ êîìàíäà
>>>>>>> d02d1396f2a9b82f2df22f6e110ae668ef12df74
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
