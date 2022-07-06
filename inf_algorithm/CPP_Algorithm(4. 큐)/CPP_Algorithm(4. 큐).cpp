﻿// CPP_Algorithm(4. 큐).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Queue (FIFO first-in-first-out
// ex. 대기열

template<typename T>
class ArrayQueue
{
public:
	ArrayQueue()
	{
		_container.resize(100);

	}


	void push(const T& value)
	{
		// 다 찼는지
		if (_size == _container.size())
		{
			// 증설
			int newSize = max(1, _size * 2);
			vector<T> newData;
			newData.resize(newSize);

			// 데이터 복사
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_rear = _size;
		}


		_container[_rear] = value;
		_rear = (_rear + 1) % _container.size();
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; };
	int size() { return _size; };




private:
	vector<T> _container;

	int _front = 0;
	int _rear = 0;
	int _size = 0;

};


int main()
{
	ArrayQueue<int> q;

	for (int i = 0; i < 100; i++)
		q.push(i);


	while (q.empty() == false)
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();
}

