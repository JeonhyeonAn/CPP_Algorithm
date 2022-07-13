// CPP_Algorithm(14. 정렬).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;


// A* openList (우선순위 큐) 왜 쓰느냐 -> 기본 sort 함수로 정렬하면 안되냐 -> sort는 구현에 따라 빠르기만 한게 아니다  
// priority queue, red-black 은 log N



// 1) 버블 정렬 (Bubble Sort)
void BubbleSort(vector<int>& v)		// 효율은 최악
{
	const int n = (int)v.size();

	//  a * ( (N-1) + (n-2) + ... + 2 + 1 )
	// 등차수열 합 = N * (N-1) / 2
	// O(N^2) => 현실적으로 매우 부담스러운 연산
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				swap<int>(v[j], v[j + 1]);
// 				int temp = v[j + 1];
// 				v[j] = v[j + 1];
// 				v[j + 1] = temp;
			}
		}
	}
}


// 2) 선택 정렬 (Selection Sort)
// O(N^2)
void SelectionSort(vector<int>& v)
{
	const int n = (int)v.size();

	for (int i = 0; i < n - 1; i++)
	{
		int bestIdx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}

		swap<int>(v[i], v[bestIdx]);
	}
}


// 3) 삽입 정렬 (Insertion Sort)
// [5][J]   [9][3][K]
// O(N^2) 이지만 이미 정렬되어있으면 좋다
void InsertionSort(vector<int>& v)
{
	const int n = (int)v.size();

	for (int i = 1; i < n; i++)		// 1 부터
	{
		int insertData = v[i];

		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}
		v[j + 1] = insertData;
	}
}

int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };

	//std::sort(v.begin(), v.end());


	//BubbleSort(v);
	//SelectionSort(v);
	InsertionSort(v);

	return 0;
}

