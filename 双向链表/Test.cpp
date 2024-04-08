#include"d-list.h"
int main() {
	head* p = listcreat();
	printf("请输入双链表数据节点\n");
	int num;
	scanf_s("%d", &num);
	int* a = (int*)malloc(sizeof(int) * num);
	assert(a);
	printf("请依次输入初始值：\n");
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &a[i]);
	}
	for (int i = num - 1; i > 0; i--) {
		listinsert(p, 0, a[i]);
	}
	printf("初始链表输出\n");
	print(p);
	printf("请输入插入的位置和元素\n");
	int m = 0;
	int n = 0;
	scanf_s("%d %d", &m, &n);
	listinsert(p, m, n);
	printf("插入后的链表\n");
	print(p);

	printf("请输入要删除的元素\n");
	int del = 0;
	scanf_s("%d", &del);
	listdelete(p, del);
	printf("删除元素之后的链表\n");
	print(p);
	return 0;
}