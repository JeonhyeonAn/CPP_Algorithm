// CPP_Algorithm(1. 동적배열구현연습).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{

	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapcity = static_cast<int>(_capacity * 1.5);
			if (newCapcity == _capacity)
				newCapcity++;


			reserve(newCapcity);
		}

		// 데이터 저장
		_data[_size] = value;

		// 데이터 개수 증가
		_size++;

	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		_capacity = capacity;

		T* newData = new T[_capacity];
		
		// copy data
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data)
			delete[] _data;

		// 교체
		_data = newData;
	}

	T& operator[](const int pos) { return _data[pos]; }

	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];		// 클래스일 경우 각 해당 소멸자 호출 필요 -> 서버 allocate 시간에 설명
		}

		_size = 0;
	}

private:
	T* _data = nullptr;
	int _size = 0;		// 실질 사용
	int _capacity = 0;	// 할당 받은 크기
};




int main()
{
	vector<int> v;

	//v.reserve(100); // 초반에 미리 메모리 크기를 유추할 수 있으면 지정해 놓고 쓰면 더 효율적

	v.resize(10);	//실제 데이터 갯수 변환		// capacity 가 작으면 사이즈만큼 증설 , 더 크면 그대로		//데이터가 있으면 그 뒤는 밀어버림

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
	}

	v.clear();
	cout << v.size() << " " << v.capacity() << endl;  
}
