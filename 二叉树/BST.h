#pragma once
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;
#define N 50

typedef struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
}BSTNode;

void Menu();
void menu();
BSTNode* Insert(BSTNode* root, int x);
BSTNode* CreateTreeNode(int x);
void Create(BSTNode*& root, int arr[], int len);
BSTNode* Search(BSTNode* root, int x);
bool Delete(BSTNode* p);
bool DeleteBST(BSTNode* root, int x);
void preOrderRecursive(BSTNode* root);
void preOrderIterative(BSTNode* root);
void inOrderRecursive(BSTNode* root);
void inOrderIterative(BSTNode* root);
void postOrderRecursive(BSTNode* root);
void postOrderIterative(BSTNode* root);
void levelOrder(BSTNode* root);