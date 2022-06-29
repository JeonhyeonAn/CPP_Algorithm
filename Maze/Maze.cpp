// Maze.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include "ConsoleHelper.h"

int main()
{
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


		// 렌더링

		ConsoleHelper::SetCursorPosition(0, 0);
		ConsoleHelper::ShowConsoleCursor(false);
		ConsoleHelper::SetCursorColor(ConsoleColor::RED);

		const char* TILE = "■";
		for (int32 y = 0; y < 25; y++)
		{
			for (int32 x = 0; x < 25; x++)
			{
				cout << TILE;
			}

			cout << endl;
		}
		
		
	}



}

