#pragma once
#include<stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node
{
    int data;//数据域
    struct Node* pNext;//指针域
} NODE, * PNODE; //NODE相当于struct Node，*PNODE相当于struct Node *

void showmenu();
//创建链表
PNODE create_list(void);
//遍历链表
void traverse_list(PNODE pHead);
//判断是否为空
bool is_empty(PNODE pHead);
//返回链表长度
int length_list(PNODE pHead);
//在指定节点处插入某个元素
bool insert_list(PNODE, int, int);
//删除指定位置的元素
bool delete_list(PNODE, int, int*);
//对链表排序
void sort_list(PNODE pHead);
//void showmenu();