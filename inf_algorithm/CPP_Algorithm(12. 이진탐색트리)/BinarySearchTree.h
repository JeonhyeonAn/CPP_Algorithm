#pragma once

// Template
struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};

	//bool external; 노드 존재값을 따로 지정해주기도 한다 
};

class BinarySearchTree
{
public:
	void Print();
	void Print(Node* node, int x, int y);

	void Print_Inorder() { Print_Inorder(_root); }
	void Print_Inorder(Node* node);

	void insert(int key);



	Node* Search(Node* node, int key);


	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void Delete(int key);
	void Delete(Node* node);

	void Replace(Node* u, Node* v);

private:
	Node* _root = nullptr;

};



