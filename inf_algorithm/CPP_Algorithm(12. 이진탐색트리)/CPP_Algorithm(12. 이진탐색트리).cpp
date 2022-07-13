// CPP_Algorithm(12. 이진탐색트리).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

#include "BinarySearchTree.h"
int main()
{

	BinarySearchTree bst;

	bst.insert(20);
	bst.insert(10);

	bst.insert(30);
	bst.insert(25);
	bst.insert(26);
	bst.insert(40);
	bst.insert(50);

	//bst.Print_Inorder();

	//bst.Print();

	bst.Delete(20);

	bst.Print();
}

