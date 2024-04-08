#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node* next;
} Stacknode, * LinkStack; //定义结点和头指针类型名

void Init_LinkStack(LinkStack& s);
void Push(LinkStack& s, ElemType e);
int Pop(LinkStack& s);
int GetTop(LinkStack& s);
void Display_LinkStack(LinkStack& s);