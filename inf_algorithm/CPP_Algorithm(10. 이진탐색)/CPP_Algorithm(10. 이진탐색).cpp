// CPP_Algorithm(10. 이진탐색).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


// binary search
// 상황) 배열에 데이터가 정렬되어 있다.

// Q) 82라는 수가 배열에 있는지?
// A) 데이터가 많아질수록 O(n) 은 좋지 않다. 
// A) 이진탐색  O(logN)

// 정렬된 배열을 이요해서 이진 탐색 가능 (numbers[mid])
// - 배열은 단점: 중간 삽입/삭제가 느리다 -> 노드 기반의 트리로 만들어서 데이터를 유동적으로 처리하기 위해 
// 정렬된 연결 리스트로는 불가 (임의 접근X)
vector<int> numbers;
void BinarySearch(int N)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		
		cout << "탐색 범위: " << left << "~" << right << endl;

		if (N < numbers[mid])
		{
			cout << N << "<" << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << ">" << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
		cout << "찾음!" << endl;
		break;
		}
	}
}

 
int main()
{
	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	BinarySearch(81);
  
}
