#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node* next;
} Stacknode, * LinkStack; //定义结点和头指针类型名

//初始化链栈
void Init_LinkStack(LinkStack& s)
{
    //printf("init执行开始\n");
    s = (Stacknode*)malloc(sizeof(Stacknode));
    s->next = NULL;
    //printf("init执行结束\n");
}


//入栈
void Push(LinkStack& s, ElemType e)
{
    //printf("push执行开始\n");
    Stacknode* p;
    p = (Stacknode*)malloc(sizeof(Stacknode));
    p->data = e;//头插法
    p->next = s;
    s = p;
    //printf("push执行结束\n");
}

//出栈
int Pop(LinkStack& s)
{
    Stacknode* p;
    if (s == NULL)
    {
        printf("栈空\n");
        return 1;
    }
    else
    {
        p = s;
        s = p->next;//往后挪一位
        free(p);
        return 1;
    }
}

//查看栈顶元素
int GetTop(LinkStack& s)
{
    if (s == NULL)
    {
        printf("栈空\n");
        return 0;
    }
    else
    {
        printf("%d", s->data);
        return 1;
    }
}

//链表的显示
void Display_LinkStack(LinkStack& s)
{
    //printf("display执行开始\n");
    Stacknode* p;
    p = s;

    //printf("%d",p->data);
    while (p->next != NULL)
    {
        printf("             %6d\n", p->data);
        //printf("12");
        p = p->next;
    }
    //printf("display执行结束\n");
}