// CPP_Algorithm(15. 힙정렬과 병합정렬).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace  std;

void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// O(N*logN)_
	for (int num : v)
		pq.push(num);

	v.clear();

	// O(N*logN)_
	while (pq.empty() == false)
	{
		v.push_back(pq.top());
		pq.pop();
	}

	// O(N*logN) + O(N*logN) => O(N*logN)_
}

// 병합 정렬
// 분할 정복( Divide and Conquer)
// - 분할(Divide)  문제를 더 단순하게 분할한다
// - 정복(Conquer) 분할된 문제를 해결
// - 결합(Combine) 결과를 취합하여 마무리

//[3][K][7][2][J][4][8][9]
//[3][K][7][2]   [J][4][8][9]
//[2][3][7][K]   [4][8][9][J]
//[2][3][4][7][8][9][J][K]   


// O(N * logN)  각 전체 배열 원소 비교 ,쪼갰을 떄 
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;
	
	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	// 왼쪽이 먼저 끝났으면, 오른쪽 나머지 데이터 복사
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back((v[rightIdx]));
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back((v[leftIdx]));
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
		v[left + i] = temp[i];
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };
	
	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		int randValue = rand() % 100;

		v.push_back(randValue);
	}


	//HeapSort(v);



	MergeSort(v, 0, v.size() - 1);


	return 0;
}

