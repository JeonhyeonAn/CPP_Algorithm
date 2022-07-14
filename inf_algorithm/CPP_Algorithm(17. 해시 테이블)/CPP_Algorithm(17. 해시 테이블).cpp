// CPP_Algorithm(17. 해시 테이블).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Q) map vs hash_map (= C++11 표준 unordered_map)
// 
// map : Red-Black Tree(균형 이진트리) -  트리 구조로 관리 - 한쪽으로 쏠리는 거 예방
// - 추가/탐색/삭제 O(logN)

// hash_map(unordered_map),  == C# dictionary
// - 추가/탐색/삭제 O(1)   항상은 X
// =>메모리를 내주고 속도를 취한다.  -> 충돌이 일어나지 않는다는 가정하에 해쉬 맵이 훨씬 빠르다

// 아파트 우편함
// [201][202][203][204][205]
// [101][102][103][104][105]

// 1~999 user(userID = 1 ~ 999)
// [1][2][3]...[999]

// '해시'   '테이블'     => 테이블이지만 해시를 이용한       => 원하는 키값을 매우 빠르게 찾아주는 데에만 최적화
// O(1)
void TestTable()
{
    struct User
    {
        int userId = 0;
        string username;
    };

    vector<User> users;
    users.resize(100);


    /// 777번 유저 정보 세팅
    users[777] = User{ 777, "ajh" };

    /// 777번 유저 이름은?
    string name = users[777].username;
    cout << name << endl;


    // 테이블
    // 키를 알면, 데이터를 단번에 찾을 수 있다

    // 문제 상황
    // int32_max(3억~)
    // 메모리도 무한은 아니다 
    // -> 해시 이용
}


// 보안
// id: ajh + pw: 1234
// id: ajh + pw: hash(1234) -> KHJ(E978&^&8ha // 암호화
// DB[ajh][1234]

void TestHash()
{
	struct User
	{
		int userId = 0;   // 1~int32_max
		string username;
	};

	vector<User> users;
	users.resize(1000);

    const int userId = 123456789;
    int key = (userId % 1000); // hash 알고리즘은 매우 다양
	/// 123456789번 유저 정보 세팅
	users[key] = User{ 123456789, "ajh" };

	/// 123456789번 유저 이름은?
    User& user = users[key];
    if (user.userId == userId)
    {
	    string name = users[key].username;
	    cout << name << endl;
    }


    // 충돌문제 (키값이 겹치는 문제)
    // - 충돌이 발생한 자리를 대신해서 다른 빈자리르 찾아나선다
    // -- 선형 조사법 (linear probing)
    // --- hash(key) + 1 -> hash(key) + 2   => 문제점: 인접한 곳에 데이터가 몰릴 수 있다. 
    // -- 이차 조사법 (quadratic probing)
    // --- hash(key) + 1^2 -> hash(key) + 2^2  => 조금 더 분산시킴
    // etc


}


// 체이닝

void TestHashTableChaining()
{
    struct User
    {
        int userId = 0;   // 1~int32_max
        string username;
    };

    vector<vector<User>> users;
    users.resize(1000);

    const int userId = 123456789;
    int key = (userId % 1000); // hash 알고리즘은 매우 다양
    /// 123456789번 유저 정보 세팅
    users[key].push_back(User{ 123456789, "ajh" });     // 동일해도 덮어씌워지는게 아니라 push_back -> 동일한 bucket에 추가
    users[789].push_back(User{ 789, "aaa" });


    // 123456789 유저 이름은?
    vector<User>& bucket = users[key];
    for (User& user : bucket)
    {
        if (user.userId == userId)
        {
            string name = user.username;
            cout << name << endl;
        }
    }
}

int main()
{
    //TestTable();

   // TestHash();

    TestHashTableChaining();

    return 0;
}

