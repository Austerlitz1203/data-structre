#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SeqListPrint(SL* ps)
{
    assert(ps);
    for (int i = 0;i < ps->size;++i)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SeqListInit(SL* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

void SeqListCheck(SL* ps)
{
    assert(ps);
    if (ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
        if (tmp == NULL)
        {
            printf("realloc fail!\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }

}

void SeqListPushBack(SL* ps, SLDataType x)
{
    assert(ps);
    SeqListCheck(ps);
    ps->a[ps->size] = x;
    ps->size++;
}

void SeqListPopBack(SL* ps)
{
    assert(ps);
    if (ps->size >= 0)
        ps->size--;
}
void SeqListPushFront(SL* ps, SLDataType x)
{
    assert(ps);
    SeqListCheck(ps);
    for (int i = ps->size - 1;i >= 0;i--)
    {
        ps->a[i+1] = ps->a[i];
    }
    ps->a[0] = x;
    ps->size++;
}

void SeqListPopFront(SL* ps)
{
    assert(ps);
    for (int i = 1;i < ps->size;i++)
    {
        ps->a[i - 1] = ps->a[i];
    }
    ps->size--;
}

//找到指定数据，找到了返回下标，没找到返回-1
int SeqListFind(SL* ps, SLDataType x)
{
    assert(ps);
    assert(ps);
    int i = 0, flag = 0;
    for (i = 0;i < ps->size;i++)
    {
        if (x == ps->a[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        return i;
    else
        return -1;
}
//在指定位置插入数据
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
    assert(ps);
    SeqListCheck(ps);
    for (int i = ps->size-1 ;i >= pos-1;i--)
    {
        ps->a[i + 1] = ps->a[i];
    }
    ps->a[pos-1] = x;
    ps->size++;
}
//删除pos位置的数据
void SeqListDelete(SL* ps, int pos)
{
    assert(ps);
    for (int i = pos;i < ps->size;i++)
    {
        ps->a[i - 1] = ps->a[i];
    }
    ps->size--;
}