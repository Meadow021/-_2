#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef struct node {
	int val;
	struct node* prev;
	struct node* next;
}node;

typedef struct header {
	int length;
	struct node* next;
}head;

head* listcreat();
void listinsert(head* p, int pos, int x);
void listdelete(head* p, int x);
void print(head* p);