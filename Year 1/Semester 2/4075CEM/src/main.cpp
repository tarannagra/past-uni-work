/* Copyright (C) 2023 Harry Clark - Student No. 12340530 */
/* DATE: 26/01/23 */

#include "engine.h"
#include <iostream>
#include <Windows.h>

/* DECLARING THE ATTRIBUTES RELATIVE TO THE WINDOWS API */
/* THE WINDOWS API PROVIDES A GREAT BASE FOR THIS PROJECT */

/* I'M USING A HANDLE AS PART OF THE WINDOWS API */
/* TO CREATE A GENERIC POINTER BETWEEN THE BASE OBJECT */
/* AND WHAT IT IS POINTING TOWARDS */

static int SET_ATTRIBUTES()
{
	CONSOLE = {0, 0, (SHORT)SCREEN_WIDTH - 1, (SHORT)SCREEN_HEIGHT - 1 };
	SCREEN = new WIDE_CHAR[SCREEN_WIDTH * SCREEN_HEIGHT];
	memset(SCREEN, 0, sizeof(WIDE_CHAR) * SCREEN_WIDTH * SCREEN_HEIGHT);

	if (!SetConsoleWindowInfo(CONSOLE_HANDLER, TRUE, &CONSOLE))
		return ERROR(L"Invalid Console Information");

	if (!GetConsoleScreenBufferInfo(CONSOLE_HANDLER, CONSOLE_INFORMATION))
		return ERROR(L"Invalid Screen Buffer");

	if (SCREEN_HEIGHT > CONSOLE_INFORMATION->dwMaximumWindowSize.Y)
		return ERROR(L"Size is too large for the Screen Buffer");

	if(SCREEN_WIDTH > CONSOLE_INFORMATION->dwMaximumWindowSize.X)
		return ERROR(L"Size is too large for the Screen Buffer");

	return SCREEN_WIDTH;
	return SCREEN_HEIGHT;

	return 1;
}

/* MAP CREATION IS DEFINED BY A WIDE STRING CONSISTING */
/* OF A 16 X 16 MATRIX OF ASCII CHARACTERS */

/* ACCESSING THE STATICALLY AVAILABLE WIDE STRING */
/* FROM THE MAP STRUCTURE ALLOWS US TO ACHIEVE THIS */

/* THE USAGE OF A WIDE STRING COMES AT THE EXPENSE OF */
/* BEING ABLE TO DECLARE THE ARRANGEMENT OF WIDE CHARACTERS */

/* WIDE CHARS ON THE OTHER HAND GIVE US A BIT MORE RIGIDITY */
/* FOR SCREEN DECLARATIONS SUCH AS WIDTH AND HEIGHT WHICH REMAIN AS CONSTANTS */

static bool CREATE_MAP()
{
	MAP_LINE += L"#########.......#########.......";
	MAP_LINE += L"#...............#...............";
	MAP_LINE += L"#.......#########.......########";
	MAP_LINE += L"#..............##..............#";
	MAP_LINE += L"#......##......##......##......#";
	MAP_LINE += L"#......##..............##......#";
	MAP_LINE += L"#..............##..............#";
	MAP_LINE += L"###............####............#";
	MAP_LINE += L"##.............###.............#";
	MAP_LINE += L"#............####............###";
	MAP_LINE += L"#..............................#";
	MAP_LINE += L"#..............##..............#";
	MAP_LINE += L"#..............##..............#";
	MAP_LINE += L"#...........#####...........####";
	MAP_LINE += L"#..............................#";
	MAP_LINE += L"###..####....########....#######";
	MAP_LINE += L"####.####.......######..........";;
	MAP_LINE += L"#...............#...............";;
	MAP_LINE += L"#.......#########.......##..####";;
	MAP_LINE += L"#..............##..............#";;
	MAP_LINE += L"#......##......##.......#......#";;
	MAP_LINE += L"#......##......##......##......#";;
	MAP_LINE += L"#..............##..............#";;
	MAP_LINE += L"###............####............#";;
	MAP_LINE += L"##.............###.............#";;
	MAP_LINE += L"#............####............###";;
	MAP_LINE += L"#..............................#";;
	MAP_LINE += L"#..............................#";;
	MAP_LINE += L"#..............##..............#";;
	MAP_LINE += L"#...........##..............####";;
	MAP_LINE += L"#..............##..............#";;
	MAP_LINE += L"################################";

	return true;
}

/* THIS FUNCTION WILL UPDATE THE PLAYER'S CURRENT POSTION IN WORLD SPACE */
/* THROUGH THIS, WE WILL USE THE MATHEMATICAL METHOD OF RAYCASTING IN ORDER */
/* TO DISCERN THE PLAYER'S POSITION IN RELATION TO WORLD SPACE */

static bool ON_UPDATE()
{
	for (U32 i = 0; i < SCREEN_WIDTH; i++)
	{
		RAY_CAST = (PLAYER_ROTATION - CAMERA_FOV / 2.0f) + ((F32)i / (F32)SCREEN_WIDTH) * CAMERA_FOV;
		STEP_SIZE = 0.01f;
		DIST = 0.0f;
		VEC_X = sinf(RAY_CAST);
		VEC_Y = cosf(RAY_CAST);
		HAS_HIT_WALL = false;
		BOUNDARY = false;

		while (!HAS_HIT_WALL && DIST < CAMERA_DOF)
		{
			DIST += STEP_SIZE;
			OOB_X = (U32)(PLAYER_X + VEC_X * DIST);
			OOB_Y = (U32)(PLAYER_Y + VEC_Y) * DIST;

			if (OOB_X < 0 || OOB_X >= WORLD_WIDTH && OOB_Y < 0 || OOB_Y >= WORLD_HEIGHT)
			{
				HAS_HIT_WALL = true;
				DIST = CAMERA_DOF;
			}
		}
	}

	return true;
}


/* IN THIS SITUATION, WE WILL USE A MEMSET TO ALLOCATE */
/* A SUM OF BYTES POINTED TOWARDS A SPECIFIC EXAMPLE */

/* THIS IS AN EXAMPLE OF DYNAMIC MEMORY ALLOCATION ESTABLISHED */
/* IN 4003CEM. */

/* THE MEMSET METHOD SUGGESTS THAT IF THE COUNT IS GREATER */
/* THAN THE SIZE OF AN OBJECT DEFINED BY AN ARRAY */

/* THE BEHAVIOUR IS ACCOUNTED FOR */
/* THIS IS JUST TO DETERMINE THAT GIVEN A LIMIT OF 256 BYTES */
/* WE WANT TO RECOGNISE BUTTON INPUTS */

/* RESOURCES: https://cplusplus.com/reference/cstring/memset/ */
/* https://en.cppreference.com/w/cpp/string/byte/memset */

static int GET_KEY_STATE()
{
	memset(NEW_KEY, 0, 256 * sizeof(short));
	memset(OLD_KEY, 0, 256 * sizeof(short));
	memset(KEY, 0, 256 * sizeof(KEY_STATE));
}

/* CREATE THE GAME THREAD */
/* USING THE STANDARD LIBRARY THREADING SCHEMA */
/* WE ARE ABLE TO USE A CONSTRUCTOR TO INITIALISE THE GAME THREAD */

static inline GAME_FUNCTIONS::START* START_GAME()
{
	GAME_FUNCTIONS::THREAD_ACTIVE = true;
	THREAD THREADING = THREAD(&GAME_FUNCTIONS::THREAD_CONSTRUCTOR);
}

static inline GAME_FUNCTIONS::GAME_THREAD* GAME_THREAD_INIT()
{
	if (!CREATE_MAP())
	{
		return 0;
	}
}

/* THIS FUNCTION USES A MERGE SORT ALGORITHM TO DIVIDE */
/* ARRAYS INTO SMALLER CHUNKS, UPON WHICH IT CULMINATES THE FINAL RESULT */

/* THE CONTEXT OF THE MERGE SORT ALGO IS TO DETERMINE THE FPS */
/* OF THE GAME IN REALTIME USING THE END USER'S VERTICAL SYNC */

/* FPS CODE WRITTEN BY VINCE DAYRIT */
/* REFACTORED BY HARRY CLARK */

static std::vector<int> FPS_MERGE_SORT()
{
	MERGE_SORT MERGE;
	U32 MIDDLE = ARRAY.size() / 2;
	LEFT(ARRAY.begin(), ARRAY.begin() + MIDDLE);
	RIGHT(ARRAY.begin() + MIDDLE, ARRAY.end());

	return MERGE();
}

int main(int argc, char* argv[])
{
	SET_ATTRIBUTES();
	CREATE_MAP();
	ON_UPDATE();
	KEY_STATE();
	GAME_THREAD_INIT();
	FPS_MERGE_SORT;
	return 0;
}
