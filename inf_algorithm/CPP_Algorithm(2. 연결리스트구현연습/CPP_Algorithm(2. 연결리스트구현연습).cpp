﻿// CPP_Algorithm(2. 연결리스트구현연습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}


	Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}


public:
	Node*	_prev;
	Node*	_next;
	T		_data;

};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{

	}

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}


	// it++
	Iterator operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}


	// it--
	Iterator operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}



	// *it
	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}


public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;		// null check 가능
	}

	~List()
	{
		while (_size > 0)
			pop_back();


		delete _head;
		delete _tail;
	}


	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}


	void pop_back()
	{
		RemoveNode(_tail->_prev);
	}


private:

	// head <-> 1 <-> prevNode <-> before <-> tail
	// head <-> 1 <-> prevNode <-> newNode <-> before <-> tail
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = newNode;

		before->_prev = newNode;
		newNode->_next = before;


		_size++;

		return newNode;
	}

	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }


public:
	using iterator = Iterator<T>;


	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }


	// it '앞에' 추가
	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

public:
	Node<T>*	_head;
	Node<T>*	_tail;
	int			_size;
};

int main()
{
	List<int> li;

	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back();
	//li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}

	// 리스트는 임의 접근이 안된다 -> n 번째 데이터를 찾는건 느린데 n번째 데이터를 삭제하는건 빠르다?
	// => 삭제 위치를 iterator 로 들고있을 떄 빠르다!
	// => 찾아야 하면 탐색을 해야하니까 느리다. (조건부 적으로 빠르다)
}

