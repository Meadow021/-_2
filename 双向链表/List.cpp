#include"d-list.h"

head* listcreat() {
	head* p;
	p = (head*)malloc(sizeof(head));
	assert(p);
	p->length = 0;
	p->next = NULL;
	return p;
}

void listinsert(head* p, int pos, int x) {
	node* temp;
	temp = (node*)malloc(sizeof(node));
	assert(temp);
	temp->val = x;
	if (p == NULL || pos<0 || pos>p->length) {
		printf("error\n");
		return;
	}
	//判断双链表为空的情况
	if (p->length == 0) {
		p->next = temp;
		temp->next = NULL;
		temp->prev = NULL;
		p->length++;
		return;
	}
	//记录第一个数据节点的指针
	node* pcur = p->next;

	//如果是头插
	if (pos == 0) {
		p->next = temp;
		temp->prev = NULL;
		temp->next = pcur;
		pcur->prev = temp;
		p->length++;
		return;
	}
	for (int i = 1; i < pos; i++) {
		pcur = pcur->next;
	}
	//此时pcur指向要插入位置的前一个数据节点
	//如果是尾插
	if (pos == p->length) {
		pcur->next = temp;
		temp->next = NULL;
		temp->prev = pcur;
		pcur->next = temp;
	}
	//如果既非头插也非尾插
	else {
		temp->next = pcur->next;
		pcur->next->prev = temp;
		temp->prev = pcur;
		pcur->next = temp;
	}
	p->length++;
	return;
}

void listdelete(head* p, int x) {
	//temp为指向第一个数据节点的指针
	node* temp = p->next;
	assert(temp);
	while (temp->val != x && temp != NULL) {
		temp = temp->next;
	}
	assert(temp);
	if (temp->val != x) {
		printf("链表中没有要删除的数据\n");
		return;
	}
	node* pRe = temp->prev;//pRe指向要删除的元素的前一个数据节点
	node* pnext = temp->next;//pnext指向要删除数据的下一个节点
	//如果要删除的数据节点是第一个数据节点的话
	if (pRe == NULL) {
		p->next = pnext;
		pnext->prev = NULL;
	}
	//如果要删除的数据是最后一个数据节点的话
	else if (pnext == NULL) {
		pRe->next = NULL;
	}
	//删除的既不是第一个也不是最后一个
	else {
		pRe->next = pnext;
		pnext->prev = pRe;
	}
	free(temp);
	p->length--;
	return;

}

void print(head* p) {
	if (p == NULL) {
		printf("error\n");
		return;
	}
	//temp指向第一个数据节点
	node* temp = p->next;
	while (temp != NULL) {
		printf("%d", temp->prev->val);
		temp = temp->next;
	}
	printf("\n");
	return;
}