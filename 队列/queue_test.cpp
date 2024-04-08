#include"queue.h"
int main() {
	Queue q;
	initQueue(&q);
	push(&q, 7);
	push(&q, 9);
	push(&q, 2);
	push(&q, 4);
	printf("menu:1.获取当前队头元素\n2.获取当前队尾元素\n3.入队\n4.出队\n5.遍历输出当前队列\n6.清屏\n输入-1退出\n请输入你的选择\n");
	int op;
	scanf_s("%d", &op);
	while (op!=-1) {
		if (op == 1) {
			int front = getFront(&q);
			printf("当前队头元素是%d\n", front);
		}
		else if(op==2){
			int rear = getRear(&q);
			printf("当前队尾元素是%d\n", rear);
		}

		else if(op==3){
			printf("请输入要入队的元素\n");
			int val;
			scanf_s("%d", &val);
			push(&q, val);
		}
		else if(op==4) {
			int out = pop(&q);
			printf("出队元素是%d\n", out);
		}
		else if(op== 5) {
			for (int i = 0; i < Maxsize; i++)
			{
				int temp = pop(&q);
				printf("%d\t", temp);
			}
			printf("\n");
		}
		else if (op == 6) {
			system("cls");
		}
		else{
			printf("input error\n");
		}
		printf("menu:1.获取当前队头元素\n2.获取当前队尾元素\n3.入队\n4.出队\n5.遍历输出当前队列\n6.清屏\n输入-1退出\n请输入你的选择\n");
		scanf_s("%d", &op);
	}
	//printf("%d", pop(&q));
	return 0;
}