// CPP_Algorithm(20. 동적 계획법).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <windows.h>
using namespace std;


// 동적 계획법 Dynamic Programming
// 본인 스타일을 정해서 지키는 것이 좋다 

// 메모이제이션 (memoization)
int cache[50][50];  // n r


int combination(int n, int r)
{
	// 기저 사례
	if (r == 0 || n == r)
		return 1;


	// 이미 답을 구한 적 있으면 바로 반환ㅇ (캐쉬)
	int& ret = cache[n][r];		// 캐시를 레퍼런스로 걸어서
	if (ret != -1)
		return ret;


	// 새로 답을 구해서 캐시에 저장

	// return combination(n - 1, r - 1) + combination(n - 1, r); // 느리다 
	return ret = combination(n - 1, r - 1) + combination(n - 1, r); // 빠르다
}


int main()
{
	::memset(cache, -1, sizeof(cache));		// 절대 나올 수 없는 값으로 밀어줌


	__int64 start = GetTickCount64();
	int lotto = combination(45, 6);
	__int64 end = GetTickCount64();

	cout << end - start << endl;
}
