// CPP_Algorithm(18. 최소 스패닝 트리).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

// 그래프/트리 응용
// 최소 스패닝 트리 (Minimum Spanning Tree)

// 상호 베타적 집합 (disjoint Set)
// -> 유니온-파인드 union-find

// Lineage BattleGround(혼종)
// 혈맹전 + 서바이벌 
// 1인 팀 1000명 ( 팀 id 0 ~ 999 )
// 동맹  ( 1번 + 2번 팀 )

void LineageBattleground()
{
    struct User
    {
        int teamId;
        // TODO
    };

    // userManager
    vector<User> users;
    for (int i = 0; i < 1000; i++)
    {
        users.push_back(User{ i });
    }

    // 팀 동맹 
    users[5].teamId = users[1].teamId; // 1



    // team id 1, 2인 팀의 통합

    for (User& user : users)
    {
        if (user.teamId == 1)
            user.teamId = 2;
    }

    // 찾기 연산 O(1)
    // 합치기 연산 O(N)

}



// 트리 구조를 이용한 상호 베타적 집합의 표현

struct Node
{
	Node* leader;
};

// [1]          // 1번은 스스로를 가리키고
// [2]          // 2번이 1번을 가리킴

// 시간 복잡도 : 트리의 높이에 비례한 시간이 걸림
class NaiveDisjointSet
{
public:
	NaiveDisjointSet(int n) : _parent(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	// 대장이 누구니?
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return Find(_parent[u]);
	}

	// u 와 v를 합친다 (일단 u가 v 밑으로)
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;
	}



private:
	vector<int> _parent;
};


// 트리가 한쪽으로 기우는 문제 해결?
// 트리를 합칠 때, 항상 [높이가 낮은 트리]를 [높이가 높은 트리] 밑으로 들어가게 유도
// (Union-By-Rank) 랭크에 의한 합치기 최적화

// O(Ackermann(n)) = O(1)
class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	// 대장이 누구니?
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return _parent[u] = Find(_parent[u]);
	}

	// u 와 v를 합친다
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		// rank[u] > rank[v] 보장됨

		_parent[u] = v;
		if (_rank[u] == _rank[v])
			_rank[v]++;
	}



private:
	vector<int> _parent;
	vector<int> _rank;
};


int main()
{
	DisjointSet teams(1000);

	teams.Merge(10, 1);

	int teamId = teams.Find(1);
	int teamId2 = teams.Find(10);
}

