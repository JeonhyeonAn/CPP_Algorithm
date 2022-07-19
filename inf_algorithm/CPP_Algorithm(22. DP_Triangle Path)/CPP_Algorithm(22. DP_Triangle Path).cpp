// CPP_Algorithm(22. DP_Triangle Path).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;


// triangle path
// - (0,0) 부터 시작해서 아래 or 아래 우측으로 이동
// - 만나는 숫자를 모두 더함
// - 더한 숫자가 최대가 되는 경로? 합?


// { 6},
// { 1, 2 },
// { 3, 7, 4 },
// { 9, 4, 1, 7 },
// { 2, 7, 5, 9, 4 }


int N;
vector<vector<int>> board;
vector<vector<int>> cache;
vector<vector<int>> nextX;

int path(int y, int x)
{
	// 기저 사항
	// if( y == N - 1 )
	//		return board[y][x];
	if (y == N)
		return 0;

	// 캐시 사항
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	{
		int nextBottom = path(y + 1, x);
		int nextBottomRight = path(y + 1, x + 1);
		if (nextBottom > nextBottomRight)
			nextX[y][x] = x;
		else
			nextX[y][x] = x + 1;
	}
	// 적용
	return ret = board[y][x] + max(path(y + 1, x), path(y + 1, x + 1));

}


int main()
{
	board = vector<vector<int>>
	{
		{6},
		{1, 2},
		{3, 7, 4},
		{9, 4, 1, 7},
		{2, 7, 5, 9, 4}
	};

	N = board.size();
	cache = vector<vector<int>>(N, vector<int>(N, -1));
	nextX = vector<vector<int>>(N, vector<int>(N));

	int ret = path(0, 0);
	cout << ret << endl;

	// 경로 만들기
	int y = 0;
	int x = 0;

	while (y < N)
	{
		cout << board[y][x] << " -> ";
		
		x = nextX[y][x];
		y++;
	}
}

