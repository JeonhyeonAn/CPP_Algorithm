#pragma once

enum class Color
{
	Red = 0,
	Black = 1, 
};

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};

	Color color = Color::Black;
	//bool external; ��� ���簪�� ���� �������ֱ⵵ �Ѵ� 
};


// REd-Balck Tree
// 1) ��� ���� Red or Black
// 2) Root�� Black
// 3) Leaf(NIL)�� Black
// 4) Red ����� �ڽ��� Black(�����ؼ� Red-Red X)
// 5) �� ���κ��� ~ �������� ���� ��ε��� ��� ���� ���� Black

class RedBlackTree
{
public:

	RedBlackTree();
	~RedBlackTree();
	void Print();
	void Print(Node* node, int x, int y);

//	void Print_Inorder() { Print_Inorder(_root); }
//	void Print_Inorder(Node* node);

	void Insert(int key);
	void InsertFixup(Node* node);



	Node* Search(Node* node, int key);


	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void Delete(int key);
	void Delete(Node* node);
	void DeleteFixup(Node* node);

	void Replace(Node* u, Node* v);

	// REd-Balck
	void LeftRotate(Node* node);
	void RightRotate(Node* node);

private:
	Node* _root = nullptr;
	Node* _nil = nullptr;
};

