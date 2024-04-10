#include"BST.h"
void Menu() {
	cout << "menu:" << endl;
	cout << "1.查找 " << "2.插入 " << "3.删除 " << "4.遍历输出 " << "5.清屏 "<<"输入 - 1退出 "<<endl;
	cout << "请输入你的选择：" << endl;
}
void menu() {
	cout << "1.先序遍历递归版 " << "2.先序遍历非递归版 " << "3.中序遍历递归版 " << "4.中序遍历非递归版 " << "5.后序遍历递归版 " <<
		"6.后序遍历非递归版 " << "7.层序遍历"<<endl<<"输入-1退出查看遍历情况"<<endl;
}
//插入的递归算法
BSTNode* Insert(BSTNode* root, int x) {
	if (root == NULL) {
		root = CreateTreeNode(x);
		return root;
	}
	else if (x < root->data) {
		root->left = Insert(root->left, x);
	}
	else if (x > root->data) {
		root->right = Insert(root->right, x);
	}
	return root;
}
//创建二叉树节点
BSTNode* CreateTreeNode(int x) {
	BSTNode* p = (BSTNode*)malloc(sizeof(BSTNode));
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

//创建并初始化数
void Create(BSTNode*& root, int arr[], int len) {
	root = NULL;
	for (int i = 0; i < len; i++) {
		root = Insert(root, arr[i]);
	}
}
//查找
BSTNode* Search(BSTNode* root, int x) {
	if (root == NULL) {
		return NULL;
	}
	else if (x < root->data) {
		return Search(root->left, x);
	}
	else if(x>root->data){
		return Search(root->right, x);
	}
	else {
		return root;
	}
}
//删除
bool Delete(BSTNode* p) {
	BSTNode* q, * s;   
	//情况一：p是叶子节点
	if (p->left == NULL && p->right == NULL) {
		p = NULL;
	}
	//情况二：p的左子树为空
	else if (p->left == NULL) {
		q = p;
		p = p->right;
		free(q);
	}
	//或者p的右子树为空
	else if (p->right == NULL) {
		q = p;
		p = p->right;
		free(q);
	}
	//左右子树均不为空
	else {
		q = p;
		//s指向当前节点中序的直接后继
		s = p->right;
		while (s->left != NULL) {
			q = s;
			s = s->left;
		}
		p->data = s->data;
		//判断是否执行上述while语句
		if (q != p) {
			q->left = s->right;//执行了，重接*q的左子树
		}
		else {
			q->right = s->right;//未执行，重接*q的右子树
		}
		free(s);
	}
	return true;
}

bool DeleteBST(BSTNode* root, int x) {
	if (root == NULL) {
		return false;
	}
	else {
		if (x == root->data) {
			return Delete(root);
		}
		else if (x < root->data) {
			return DeleteBST(root->left, x);
		}
		else {
			return DeleteBST(root->right, x);
		}
	}
}
//先序遍历
void preOrderRecursive(BSTNode* root) {
	if (NULL == root) {
		return;
	}
	cout << root->data<<endl;
	preOrderRecursive(root->left);
	preOrderRecursive(root->right);
}

void preOrderIterative(BSTNode* root) {
	if (NULL == root) {
		return;
	}
	stack<BSTNode*>nodeStack;//创建一个栈存储的是节点的指针，这个栈的名字叫nodeStack
	nodeStack.push(root);//根节点进栈
	while ( nodeStack.empty()!=1)//栈非空时才做迭代处理
	{
		BSTNode* node = nodeStack.top();//保存栈顶节点
		cout<< node->data<<endl;//访问节点数据
		nodeStack.pop();//栈顶节点出栈

		//子节点入栈,右节点先入，然后再左节点
		if (node->right) {
			nodeStack.push(node->right);
		}
		if (node->left) {
			nodeStack.push(node->left);
		}
	}
}
//中序遍历
void inOrderRecursive(BSTNode*root) {
	if (NULL == root) {
		return;
	}
	inOrderRecursive(root->left);
	cout << root->data;
	inOrderRecursive(root->right);
}
void inOrderIterative(BSTNode* root) {
	if (NULL == root) {
		return;
	}
	stack<BSTNode*>nodeStack;//创建一个栈存储节点指针，名字叫nodeStack
	BSTNode* currentNode = root;//创建一个指向当前节点的指针
	//当前节点非空或者栈非空就做迭代处理
	while (currentNode || !nodeStack.empty())
	{   //当前节点非空沿着左子树方向入栈
		while (currentNode) {
			nodeStack.push(currentNode);
			currentNode = currentNode->left;
		}
		currentNode = nodeStack.top();
		cout << currentNode->data;
		nodeStack.pop();
		currentNode = currentNode->right;

	}

}
//后序遍历
void postOrderRecursive(BSTNode* root) {
	if (NULL == root) {
		return;
	}
	postOrderRecursive(root->left);
	postOrderRecursive(root->right);
	cout << root->data<<endl;
}
void postOrderIterative(BSTNode* root) {
	if (NULL == root) {
		return;
	}
	stack<BSTNode*>nodeStack;
	BSTNode* currentNode = root;//创建一个指向当前节点的指针
	BSTNode* visitedNode = root;//创建一个指向上一次访问节点的指针
	//当前节点非空就沿着左子树入栈
	while (currentNode || !nodeStack.empty())
	{
		while (currentNode) {
			nodeStack.push(currentNode);
			currentNode = currentNode->left;
		}
		currentNode = nodeStack.top();
		//如果栈顶元素有右子树，且没有被访问
		if (currentNode->right && currentNode->right != visitedNode)
		{
			currentNode = currentNode->right;
		}
		//栈顶元素没有右子树或者已经被访问
		else {
			cout << currentNode->data;
			visitedNode = currentNode;
			currentNode = NULL;//当前节点设置为NULL，防止重复访问左子树
			nodeStack.pop();
			cout << endl;

		}

	}
}
//层序遍历
void levelOrder(BSTNode* root){
	if (NULL == root) {
		return;
	}
	queue<BSTNode*>nodeQueue;
	nodeQueue.push(root);
	while ( nodeQueue.empty()!=1) {
		BSTNode* node = nodeQueue.front();
		cout<< node->data<<endl;
		if (node->left) {
			nodeQueue.push(node->left);
		}
		if (node->right) {
			nodeQueue.push(node->right);
		}
		nodeQueue.pop();
	}
}