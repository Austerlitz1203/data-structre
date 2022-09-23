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

//交集
int cmp(const void* e1, const void* e2)
{
    return *(SLDataType*)e1 - *(SLDataType*)e2;
}

void Intersection(SL* ps1, SL* ps2)
{
    assert(ps1 && ps2);
    assert(ps1->a && ps2->a);
    SLDataType ret[N] = {0};
    int count = 0;
    //暴力解法
    for (int i = 0;i < ps1->size;i++)
    {
        for (int j = 0;j < ps2->size;j++)
        {
            if (ps1->a[i] == ps2->a[j])
                ret[count++] = ps1->a[i];
        }
    }
    //打印交集
    printf("这两个集合的交集是：");
    for (int i = 0;i < count;i++)
        printf("%d ", ret[i]);
    printf("\n");
    return ret;
}

//并集
void  Merge(SL* ps1, SL* ps2)
{
    assert(ps1 && ps2);
    assert(ps1->a || ps2->a);
    SLDataType ret[N] = { 0 };
    //把第一个集合的元素全部放进去
    for (int i = 0;i < ps1->size;i++)
        ret[i] = ps1->a[i];
    int count = ps1->size;

    //并上第二个集合的元素
    for (int i = 0;i < ps2->size;i++)
    {
        int flag = 1;
        for (int j = 0;j < ps1->size;j++)
        {
            if (ps2->a[i] == ps1->a[j])//有重复的那么就跳过
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            ret[count++] = ps2->a[i];
    }
    //打印并集
    printf("这两个集合的并集是：");
    for (int i = 0;i < count;i++)
        printf("%d ", ret[i]);
    printf("\n");
    return ret;

}

//差集
void Minus(SL* ps1, SL* ps2)
{
    assert(ps1 && ps2);
    assert(ps1->a || ps2->a);
    SLDataType ret[N] = { 0 };
    int count = 0;
    for (int i = 0;i < ps1->size;i++)
    {
        int flag = 1;
        for (int j = 0;j < ps2->size;j++)
        {
            if (ps1->a[i] == ps2->a[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            ret[count++] = ps1->a[i];
        }
    }
    //打印差集
    printf("这两个集合的差集是：");
    for (int i = 0;i < count;i++)
        printf("%d ", ret[i]);
    printf("\n");
    return;
}

void gb(SL* ps1, SL* ps2)
{
    assert(ps1 && ps2);
    assert(ps1->a && ps2->a);
    SLDataType* p1 = ps1->a;
    SLDataType* p2 = ps2->a;
    SLDataType* ret[N] = { 0 };
    int count = 0;//记录ret存了多少个有效数据
    //记录每一个顺序表归并了多少个数据
    int count1 = 0;
    int count2 = 0;
    while (count1 < ps1->size && count2<ps2->size)
    {
        if (p1[count1] <= p2[count2])
        {
            ret[count++] = p1[count1++];
        }
        else if (p1[count1] > p2[count2])
        {
            ret[count++] = p2[count2++];
        }
    }
    if (count1 == ps1->size)
    {
        while (count2 < ps2->size)
        {
            ret[count++] = p2[count2++];
        }
    }
    else if (count2 == ps2->size)
    {
        while (count1 < ps1->size)
        {
            ret[count++] = p1[count1++];
        }
    }
    //打印归并
    printf("这两个集合归并后的结果是：");
    for (int i = 0;i < count;i++)
        printf("%d ", ret[i]);
    printf("\n");
}