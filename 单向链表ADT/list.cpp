#include"list.h"
void showmenu() {
    printf("menu:1.清屏\n2.遍历输出链表\n3.插入元素\n4.删除元素\n5.排序\n输入-1退出\n请输入你的选择\n");
}
PNODE create_list(void) {
    int len;//链表成员个数，由用户输入
    int i;
    int val;//链表成员值，由用户输入

    PNODE pHead = (PNODE)malloc(sizeof(NODE));//定义头结点指针
    if (NULL == pHead)
    {
        printf("分配内存失败，程序结束\n");
        exit(-1);
    }

    printf("请输入链表长度,len=");
    scanf_s("%d", &len);

    PNODE pTail = pHead;
    pTail->pNext = NULL;

    for (i = 0; i < len; i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("分配内存失败，程序结束\n");
            exit(-1);
        }
        printf("请输入要插入链表的值,val=");
        scanf_s("%d", &val);

        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        printf("%d\t", p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}

bool is_empty(PNODE pHead)
{
    if (NULL == pHead->pNext)
        return true;
    else
        return false;
}

int length_list(PNODE pHead)
{
    int len = 0;
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        ++len;
        p = p->pNext;
    }
    return len;
}

bool insert_list(PNODE pHead, int pos, int val)
{
    int i = 0;
    PNODE p = pHead;
    //循环到p指向pos-1的位置
    while (NULL != p && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    if (NULL == p || i > pos - 1)
    {
        return false;
    }
    //插入的数申请内存
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("分配内存失败，程序终止！\n");
        exit(-1);
    }
    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
    return true;
}

bool delete_list(PNODE pHead, int pos, int* pVal)
{
    int i = 0;
    PNODE p = pHead;
    //循环到p指向pos-1的位置
    while (NULL != p->pNext && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    if (NULL == p->pNext || i > pos - 1)
    {
        return false;
    }
    PNODE q = p->pNext;
    *pVal = p->data;
    p->pNext = q->pNext;
    free(q);
    q = NULL;
    return true;
}

void sort_list(PNODE pHead) {
    int i, j, t;
    PNODE p, q;
    int len = length_list(pHead);
    for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
    {
        for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
        {
            if (p->data > q->data)
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    return;
}