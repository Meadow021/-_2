#include"BST.h"
int main() {
	BSTNode* root;
	cout << "请输入想创建的树的节点" << endl;
	int len;
	cin >> len;
	int* arr = new int[len];
	cout << "请依次输入各个节点的数据" << endl;
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	Create(root, arr, len);
	cout << "当前层序遍历输出结果：" << endl;
	preOrderIterative(root);
	int op;
	do
	{
		cout << endl;
		Menu();
		cin >> op;
		if (op == 1) {
			cout << "请输入你想查找的值" << endl;
			int x;
			cin >> x;
			BSTNode* node = Search(root, x);
			if (node == NULL) {
				cout << "查找失败" << endl;
			}
			else {
				cout << "查找结果：" << node->data << endl;
			}
		}
		else if (op == 2) {
			cout << "请输入你想插入的值" << endl;
			int y;
			cin >> y;
			Insert(root, y);
		}
		else if (op == 3) {
			cout << "请输入你想删除的值" << endl;
			int z;
			cin >> z;
			if (DeleteBST(root, z)) {
				cout << "删除成功" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
			
		}
		else if (op == 4) {
			menu();
			cout << endl<< "请输入你想调用的函数" << endl;
			int op_1;
			cin >> op_1;
			switch (op_1) {
			case 1:
				cout << "遍历结果为：" << endl;
				preOrderRecursive(root);
				break;
			case 2:
				cout << "遍历结果为：" << endl;
				preOrderIterative(root);
				break;
			case 3:
				cout << "遍历结果为：" << endl;
				inOrderRecursive(root);
				break;
			case 4:
				cout << "遍历结果为：" << endl; 
				inOrderIterative(root);
				break;
			case 5:
				cout << "遍历结果为：" << endl;
				postOrderRecursive(root);
				break;
			case 6:
				cout << "遍历结果为：" << endl;
				postOrderIterative(root);
				break;
			case 7:
				cout << "遍历结果为：" << endl;
				levelOrder(root);
				break;
			default:cout << "input error" << endl;
				break;
			}
		}
		else if (op == 5) {
			system("cls");
		}
		else {
			cout << "input error" << endl;
		}
	} while (op != -1);
	return 0;
}