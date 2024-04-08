#include"sort.h"
int main() {
	Menu();
	int op;
	cin >> op;
	while (op != -1) {
		switch (op) {
		case 11: {
			cout << "请输入想查看大数据量层次" << endl;
			menu();
			int op_0;
			cin >> op_0;
			switch (op_0) {
			case 1: {
				int* arr = new int[M];
				for (int i = 0; i < M; i++) {
					arr[i] = rand();
				}
				time1(arr, M);
			}
				  break;
			case 2: {
				int* arr = new int[N];
				for (int i = 0; i < N; i++) {
					arr[i] = rand();
				}
				time1(arr, N);
			}
				  break;
			case 3: {
				int* arr = new int[K];
				for (int i = 0; i < K; i++) {
					arr[i] = rand();
				}
				time1(arr, K);
			}
				  break;
			default:
				cout << "input error" << endl;
				break;
			}
		}
			   break;
		case 22: {
			int* arr = new int[100];
			for (int i = 0; i < 100; i++) {
				arr[i] = rand();
			}
			cout << "请输入想排序的次数" << endl;
			int op_2;
			cin >> op_2;
			time2(arr, 100, op_2);
		}
			   break;
		case 33: {
			cout << "请输入你想生成数组的长度及最大值" << endl;
			int len = 0;
			int max = 0;
			cin >> len >> max;
			putout(len, max);
			int op_1 = 0;
			cout << "请输入你想调用的函数排序" << endl;
			menu();
			cin >> op_1;
			putin(len, op_1);

		}
			   break;
		default:break;
		}
		Menu();
		cin >> op;

	}


	return 0;
}