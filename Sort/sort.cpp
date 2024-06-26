#include"sort.h"
void Menu() {
	cout << "11.查看大数据用时" << " 22.查看100个数据多次排序用时" << " 33.按要求生成文件并读取排序" << "  输入-1退出" << endl;
}
void menu() {
	cout << "1.计数\t2.插入\t3.归并\t4.快排\t5.基数\n";
	cout << "1.M=10000\t2.N=50000\t3.K=200000\n";
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void time1(int* arr, int len) {
	double start1 = clock();
	InsertSort(arr, len);
	double end1 = clock();
	cout << "插入排序用时：" << end1 - start1 << "ms" << endl;

	double start2 = clock();
	MergeSort(arr, len);
	double end2 = clock();
	cout << "归并排序用时：" << end2 - start2 << "ms" << endl;

	//double start3= clock();
	//QuickSort(arr, 0,len-1);
	//double end3 = clock();
	//cout << "快速排序用时：" << end3 - start3<<"ms"<<endl;

	double start4 = clock();
	CountSort(arr, len);
	double end4 = clock();
	cout << "计数排序用时：" << end4 - start4 << "ms" << endl;

	double start5 = clock();
	InsertSort(arr, len);
	double end5 = clock();
	cout << "插入排序用时：" << end5 - start5 << "ms" << endl;

}

void time2(int* arr, int len, int n) {
	double start1 = clock();
	for (int i = 0; i < n; i++) {
		InsertSort(arr, len);
	}
	double end1 = clock();
	cout << "插入排序用时：" << end1 - start1 << "ms" << endl;

	double start2 = clock();
	for (int i = 0; i < n; i++) {
		MergeSort(arr, len);
	}
	double end2 = clock();
	cout << "归并排序用时：" << end2 - start2 << "ms" << endl;

	double start3 = clock();
	for (int i = 0; i < n; i++) {
		QuickSort(arr, 0, len - 1);
	}
	double end3 = clock();
	cout << "快速排序用时：" << end3 - start3 << "ms" << endl;

	double start4 = clock();
	for (int i = 0; i < n; i++) {

		CountSort(arr, len);
	}
	double end4 = clock();
	cout << "计数排序用时：" << end4 - start4 << "ms" << endl;

	double start5 = clock();
	for (int i = 0; i < n; i++) {
		InsertSort(arr, len);
	}
	double end5 = clock();
	cout << "插入排序用时：" << end5 - start5 << "ms" << endl;


}
/*void insertsort(int* arr, int length) {
	int i, j;
	for (i = 1; i < length ; i++) {
		for (j = 1; j > 0; j--) {
			if (arr[j] > arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
			else {
				break;
			}
		}
	}

}*/
void InsertSort(int par_array[], int array_size)
{
	int i, j;
	int temp;

	for (i = 1; i < array_size; i++)    //从第二个数开始，每一次取一个数插入到有序序列中
	{
		temp = par_array[i];    //将取出的数存到临时变量temp里面

		for (j = i - 1; j >= 0; j--)    //将这个数依次与前面的数进行比较
		{
			if (temp < par_array[j])    //这是从小到大排序，如果要从大到小排序，只需将这里的<改成>即可
			{
				par_array[j + 1] = par_array[j];
				//如果这个数比前面的数要小，那么就将前面的这个数往后移一个位置
			}
			else
			{
				break;    //否则，break跳出这轮循环，表明找到了放这个数的合适位置
			}
		}
		par_array[j + 1] = temp;    //把这个数放到这个位置即可
	}
}
//合并
void merge(int arr[], int tempArr[], int left, int mid, int right) {
	//标记左半区第一个未排序的元素
	int l_pos = left;
	//标记右半区第一个未排序的元素
	int r_pos = mid + 1;
	//临时数组元素的下标
	int pos = left;
	//合并
	while (l_pos <= mid && r_pos <= right) {
		//如果左半区剩余的第一个元素小于右边区剩余的第一个元素，就把小的那个放到临时数组
		if (arr[l_pos] < arr[r_pos]) {
			tempArr[pos++] = arr[l_pos++];
		}
		else {
			tempArr[pos++] = arr[r_pos++];
		}
	}
	//合并左半区剩余的元素
	while (l_pos <= mid) {
		tempArr[pos++] = arr[l_pos++];
	}
	//合并右半区剩余的元素
	while (r_pos <= right) {
		tempArr[pos++] = arr[r_pos++];
	}
	//把临时数组中合并的元素赋值回原来的数组
	while (left <= right) {
		arr[left] = tempArr[left];
		left++;
	}
}
//划分
void msort(int arr[], int tempArr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		//递归划分左半区和右半区
		msort(arr, tempArr, left, mid);
		msort(arr, tempArr, mid + 1, right);
		//合并排好序的那部分
		merge(arr, tempArr, left, mid, right);
	}
}

//归并排序入口
void MergeSort(int arr[], int n) {
	//分配了一个辅助的数组
	int* tempArr = (int*)malloc(n * sizeof(int));
	if (tempArr) {
		msort(arr, tempArr, 0, n - 1);
		free(tempArr);
	}
	else {
		printf("error:failed to allocate memory\n");
	}
}

void QuickSort(int arr[], int L, int R) {

	if (L >= R) {
		return;
	}
	int left = L;
	int right = R;
	int pivot = arr[left];
	while (left < right) {
		while (left < right && arr[right] >= pivot) right--;
		arr[left] = arr[right];
		while (left < right && arr[left] <= pivot)  left++;
		arr[right] = arr[left];
	}
	arr[left] = pivot;
	QuickSort(arr, L, left - 1);
	QuickSort(arr, left + 1, R);

}


void CountSort(int* a, int len)
{
	assert(a);
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max = a[0], min = a[0];
	for (int i = 0; i < len; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//使用calloc将数组都初始化为0
	int range = max - min + 1;
	int* b = (int*)calloc(range, sizeof(int));
	//使用临时数组记录原始数组中每个数的个数
	for (int i = 0; i < len; i++) {
		//这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min] += 1;
	}
	int j = 0;
	//根据统计结果，重新对元素进行回收
	for (int i = 0; i < range; i++) {
		while (b[i]--) {
			//要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
		}
	}
	//释放临时数组
	free(b);
	b = NULL;
}

//基数排序
void RadixSort(int* arr, int n)
{
	//max为数组中最大值
	int max = arr[0];
	int base = 1;

	//找出数组中的最大值
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//循环结束max就是数组最大值
	//临时存放数组元素的空间
	int* tmp = (int*)malloc(sizeof(int) * n);

	//循环次数为最大数的位数
	while (max / base > 0)
	{
		//定义十个桶，桶里面装的不是数据本身，而是每一轮排序对应（十、白、千...）位的个数
		//统计每个桶里面装几个数
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			//arr[i] / base % 10可以取到个位、十位、百位对应的数字
			bucket[arr[i] / base % 10]++;
		}
		//循环结束就已经统计好了本轮每个桶里面应该装几个数


		//将桶里面的元素依次累加起来，就可以知道元素存放在临时数组中的位置
		for (int i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		//循环结束现在桶中就存放的是每个元素应该存放到临时数组的位置


		//开始放数到临时数组tmp
		for (int i = n - 1; i >= 0; i--)
		{
			if (tmp != NULL) {
				tmp[bucket[arr[i] / base % 10] - 1] = arr[i];
				bucket[arr[i] / base % 10]--;

			}
		}
		//把临时数组里面的数拷贝回去
		for (int i = 0; i < n; i++)
		{
			arr[i] = tmp[i];
		}
		base *= 10;
	}
	free(tmp);
}
void putout(int len, int max) {
	int* arr = new int[len];
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % max + 1;
	}
	ofstream ofs;
	ofs.open("Testfile.txt", ios::out);
	for (int i = 0; i < len; i++) {
		ofs << arr[i] << endl;
	}
	ofs.close();
}
void putin(int len, int op_1) {
	ifstream ifs;
	ifs.open("Testfile.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "fail to open" << endl;
		return;
	}
	int* buf = new int[len];
	int cnt = 0;
	while (!ifs.eof()) {
		ifs >> buf[cnt++];
	}
	switch (op_1) {
	case 1:CountSort(buf, len);
		break;
	case 2:InsertSort(buf, len);
		break;
	case 3:MergeSort(buf, len);
		break;
	case 4:QuickSort(buf, 0, len - 1);
		break;
	case 5:RadixSort(buf, len);
		break;
	default:cout << "input error" << endl;
		break;
	}
	for (int i = 0; i < len; i++) {
		cout << buf[i] << endl;
	}
	ifs.close();
}