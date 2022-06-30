// Maze.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include "ConsoleHelper.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
	::srand(static_cast<unsigned>(time(nullptr)));
	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;
	while (true)
	{
#pragma region 프레임관리
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		// 프레임 고정하고 싶으면 continue
		//if(일정 deltaTick 이상)
		//	continue
		lastTick = currentTick;
#pragma endregion

		// 입력


		// 로직
		player.Update(deltaTick);

		// 렌더링

		board.Render();
		
	}



}

