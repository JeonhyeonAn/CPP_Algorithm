// CPP_Algorithm(5. 그래프 기초).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;



void CreateGraph_1()
{
    struct Vertex
    {
		vector<Vertex*> edges;
        // int data;
    };

    vector<Vertex> v;
    v.resize(6);

    
	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);
    

    // Q)0번 -> 3번 정점이 연결되어 있는지?
    bool connected = false;
    for (Vertex* vertex : v[0].edges)
    {
        if (vertex == &v[3])
        {
            connected = true;
            break;
        }
    }

}

void CreateGraph_2()
{
	struct Vertex
	{
		//vector<Vertex*> edges;
		// int data;
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// adjacent[n] -> n번째 정점과 연결된 정점 목록
	vector<vector<int>> adjacent(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };
	// 가중치 넣고 싶으면 pair로 넣을 수 있다. 

	// 정점이 100개
	// - 지하철 노선도 -> 서로 드문 드문 연결(양옆, 환승역이라면 조금 더 ++)
	// - 페이스북 친구 -> 서로 빽뺵하게 연결

	// Q)0번 -> 3번 정점이 연결되어 있는지?
	bool connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			break;
		}
	}

	//STL
	vector<int>& adj = adjacent[0];
	bool connected2 = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}

void CreateGraph_3()	// 속도 향상으로 일반적으로 씀
{
	struct Vertex
	{
		//vector<Vertex*> edges;
		// int data;
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// [x][x][x][x][x][x]
	// [x][x][x][x][x][x]
	// [x][x][x][x][x][x]
	// [x][x][x][x][x][x]
	// [x][x][x][x][x][x]
	// [x][x][x][x][x][x]

	// 읽는 방법 : adjacent[form][to]
	// 행렬을 이용한 그래프 표현(2차원 배열)
	// 메모리 소모가 심하지만, 빠른 접근이 가능하다
	// (간선이 많은 경우 이점이 있다.)
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;
	// 가중치 넣고 싶으면 bool 이 아니라 값으로 넣을 수 있다. 




	// Q)0번 -> 3번 정점이 연결되어 있는지?
	bool connected = adjacent[0][3];


	vector<vector<int>> adjacent2 =
	{
		vector<int> { -1, 15, -1, 35, -1, -1},
		vector<int> { 15, -1, 5, 10, -1, -1},
		vector<int> { -1, -1, -1, -1, -1, -1},
		vector<int> { -1, -1, -1, -1, 5, -1},
		vector<int> { -1, -1, -1, -1, -1, -1},
		vector<int> { -1, -1, -1, -1, 5, -1},

	};

	bool connected2 =  adjacent2[0][3] != -1;
	int weight = adjacent2[0][3] != -1;
}

int main()
{
    CreateGraph_1();
	CreateGraph_2();
	CreateGraph_3();
}

