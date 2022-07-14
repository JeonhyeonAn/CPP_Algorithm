﻿// CPP_Algorithm(16. 퀵 정렬).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int low = left + 1;
	int high = right;

	// O(N)
	while (low <= high)
	{
		while (low <= right &&  pivot >= v[low]  )
			low++;

		while (high >= left + 1 && pivot <= v[high]  )
			high--;


		if (low < high)
			swap(v[low], v[high]);
	}

	swap(v[left], v[high]);
	return high;
}

// O(N^2) 최악
// O(N * logN) 평균적으로
void QuickSort(vector<int>& v, int left, int right)
{
	if (left > right)
		return;

	int pivot = Partition(v, left, right);
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
}

int main()
{
	vector<int> v;

	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		int randValue = rand() % 100;

		v.push_back(randValue);
	}

	QuickSort(v, 0, v.size() - 1);
	return 0;
}

