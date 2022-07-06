// CPP_Algorithm(3. 스택).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// stack (LIFO  last-in-first-out 후입선출)
// 되돌리기 ( ctrl + z)


template <typename T, typename Container = vector<T>>	// 기본상태에서는 벡터
class Stack
{

public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

// 	T pop()				// 데이터 가져오는 부분, 제거 부분 나누어서 구현된 이유 :   1. ref 로 받ㅇ면 동적배열에서 주소가 유효해지지 않아지면 문제  2. 그냥 복사면 무거우면 효율X, 예외 사항 등 있을 수 있다 
// 	{
// 		T ret = _data[_size - 1];
// 		_size--;
// 		return ret;
// 	}


	void pop()
	{
		_container.pop_back();

	}

	T& top()
	{
		return _container.back();

	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	//vector<T> _container;
	//list<T> _container;			// vector와 같은 함수 -> STL container의 장점
	Container _container;
};


int main()
{
	//Stack<int> s;
	Stack<int, list<int>> s;

	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);

	// 최상위 원소
	while (s.empty() == false)
	{
		int data = s.top();
		s.pop();
		
		cout << data << endl;
	}
	

	int size = s.size();
}

