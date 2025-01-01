#include <iostream>

using std::cout;
using std::endl;

template <typename T>
void mergeSort(T &arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	T leftArr(n1);
	T rightArr(n2);

	for (int i = 0; i < n1; i++)
		leftArr[i] = arr[left + i];
	for (int i = 0; i < n2; i++)
		rightArr[i] = arr[mid + 1 + i];

	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		} else {
			arr[k++] = rightArr[j++];
		}
	}
	while (i < n1) {
		arr[k++] = leftArr[i++];
	}
	while (j < n2) {
		arr[k++] = rightArr[j++];
	}
}

template <typename T>
void insertSort(T &arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

template <typename T>
void fordJhonson(T &arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		if (mid - left <= 10)
			insertSort(arr, left, mid);
		else
			fordJhonson(arr, left, mid);
		if (right - mid <= 10)
			insertSort(arr, mid + 1, right);
		else
			fordJhonson(arr, mid + 1, right);
		mergeSort(arr, left, mid, right);
	}
}

template <typename T>
void PrintArr(T &arr, int num)
{
	if (num == 0)
		num = arr.size();
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
