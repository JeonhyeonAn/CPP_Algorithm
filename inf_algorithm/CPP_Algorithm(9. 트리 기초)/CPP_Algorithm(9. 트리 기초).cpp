// CPP_Algorithm(9. 트리 기초).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

using NodeRef = shared_ptr<struct Node>;

struct Node
{
    Node() {}
    Node(const string& data) : data(data) {}

    string data;
    vector<NodeRef> children;

};


NodeRef CreateTree()
{
    NodeRef root = make_shared<Node>("R1 개발실");
    {
		NodeRef node = make_shared<Node>("디자인팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("전투");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("경제");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("스토리");
			node->children.push_back(leaf);
		}
    }
	{
		NodeRef node = make_shared<Node>("프로그래밍");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("서버");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("클라");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("엔진");
			node->children.push_back(leaf);
		}
	}
	{
		NodeRef node = make_shared<Node>("아트팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("배경");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("캐릭터");
			node->children.push_back(leaf);
			{
				NodeRef leaf2 = make_shared<Node>("더미");
				leaf->children.push_back(leaf2);
			}
		}
	}

	return root;
}

void PrintTree(NodeRef root, int depth)
{
	for (int i = 0; i < depth; i++)
		cout << "-";
	cout << root->data << endl;
	
	for (NodeRef& child : root->children)
		PrintTree(child, depth + 1);
}

// 깊이 depth : 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수 (aka. 몇층)
// 높이 height : 가장 깊숙히 있는 노드의 깊이 (max(depth));
int GetHeight(NodeRef root)
{
	int height = 1;

	for (NodeRef& child : root->children)
	{
// 		if (height < GetHeight(child) + 1)
// 			height = GetHeight(child) + 1;
		// == 
		height = max(height, GetHeight(child) + 1);
	}

	cout << height << endl;


	return height;
}


int main()
{

	NodeRef root = CreateTree();


	PrintTree(root, 0);

	int height = GetHeight(root);
	cout << height << endl;
}
