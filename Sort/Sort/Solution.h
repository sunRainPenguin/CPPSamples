#pragma once
#include <iostream>
using namespace std;

class Solution
{
public:
	// ��������
	void insertionSort(int arr[], int n)
	{
		int v = -1;
		int j = -1;
		for (int i = 1; i < n; i++)
		{
			v = arr[i];
			j = i;
			while (j>=1 && arr[j-1]>v)
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = v;
		}
	}

	void printArr(int arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << endl;
		}
	}

	// �ϲ�����a[first]-a[mid]��a[mid+1]-a[last]
	void mergeArray(int  a[], int first, int mid, int last, int temp[])
	{
		int i = first, j = mid + 1;
		int m = mid, n = last;
		int k = 0;
		while (i <= m && j <= n)
		{
			if (a[i] < a[j])
			{
				temp[k++] = a[i++];
			}
			else
			{
				temp[k++] = a[j++];
			}
		}
		while (i <= m)
		{
			temp[k++] = a[i++];
		}
		while (j <= n)
		{
			temp[k++] = a[j++];
		}
		for (int i = 0; i < k; i++)
		{
			a[first+i] = temp[i];
		}
	}

	// �鲢���򣬶�first��last֮���Ԫ�ؽ�������
	void mergeSort(int a[], int first, int last, int temp[])
	{
		if (first < last)
		{
			int mid = (first + last) / 2;
			mergeSort(a, first, mid, temp);		// �������
			mergeSort(a, mid + 1, last, temp);	// �ұ�����
			mergeArray(a, first, mid, last, temp);	//��������������ϲ�
		}
	}

	// �鲢����������
	bool MergeSort(int a[], int n)
	{
		int *p = new int[n];
		if (p == nullptr)
		{
			return false;
		}
		else
		{
			mergeSort(a, 0, n - 1, p);
		}
	}

	// ��������
	void quickSort(int a[], int n, int low, int high)
	{
		if (low < high)
		{
			int pivot = partition(a, low, high);
			quickSort(a, n, low, pivot - 1);
			quickSort(a, n, pivot + 1, high);
		}
	}

	// ���ٷָ�
	int partition(int a[], int left, int right)
	{
		int base = a[left];
		while (left < right)
		{
			while (a[right] >= base && left<right)
			{
				right--;
			}
			if (a[right] < base)
			{
				swap(a[left], a[right]);
			}
			while (a[left] <= base && left<right)
			{
				left++;
			}
			if (a[left] > base)
			{
				swap(a[left], a[right]);
			}
		}
		return left;
	}

	// ����
	void swap(int& a, int&b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	// ð������
	// ѡ������
	// ��������
	// Ͱ����

};

