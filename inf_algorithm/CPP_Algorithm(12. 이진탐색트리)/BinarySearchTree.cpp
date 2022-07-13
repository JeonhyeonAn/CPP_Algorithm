#include "BinarySearchTree.h"
# include <iostream>
#include <windows.h>

using namespace std;


void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}


void BinarySearchTree::Print()
{
	Print(_root, 10, 0); 
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

}

void BinarySearchTree::Print_Inorder(Node* node)
{
	// Preorder traverse 전위
	// inorder 중위
	// postorder 후위 


	// preorder
	if (node == nullptr)
		return;

	cout << node->key << endl;
	Print_Inorder(node->left);
	Print_Inorder(node->right);
}

void BinarySearchTree::insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;

	// 성능상은 스택프레임 및 함수를 구성하는 단계가 없는 무한루프 가 재귀보다 좋긴하다 
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;



	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);



}

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;

}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
	{
		Replace(node, node->right);
	}
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	else
	{
		// 다음 데이터 찾기
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}

}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parent == nullptr)
		_root = v;

	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v)
		v->parent = u->parent;

	delete u;	// 동적 할당 삭제 
}
