#pragma once
#include <Windows.h>
#include "Bitmap.h"

#define BITMAP_NUMS 13
#define GAME_WIDTH 870
#define GAME_HEIGHT 570
#define START_X_0 300
#define START_Y_0 150
#define START_X_1 200
#define START_Y_1 45
#define START_X_2 43
#define START_Y_2 45

#define GAME_OVER 0
#define RANGE_OUT 1
#define CLICK_OK 2
#define GAME_WIN 3
enum BITMAP_NAME {
	BACK, BLOCK, BLOCK0, BLOCK1, BLOCK2, BLOCK3, BLOCK4, BLOCK5, BLOCK6, BLOCK7, BLOCK8, FLAG, MINE
};

struct Block {
	bool mine;
	bool push;
	bool flag;
	int nearMine;
};

class GameManager
{
private:
	HWND m_hWnd;
	HDC MemDC;
	HBITMAP MyBitmap;
	HBITMAP OldBitmap;
	LPCSTR resource[BITMAP_NUMS] = {"res\\back.bmp" , "res\\block.bmp" , "res\\block_0.bmp", "res\\block_1.bmp",
	"res\\block_2.bmp", "res\\block_3.bmp", "res\\block_4.bmp", "res\\block_5.bmp", "res\\block_6.bmp",
	"res\\block_7.bmp", "res\\block_8.bmp", "res\\flag.bmp", "res\\mine.bmp"};
	Bitmap * bitmap[BITMAP_NUMS];

	int startX[3];
	int startY[3];
	int mineNumByDifficulty[3] = { 10, 40, 99 };
	int width[3] = { 9, 16, 30 };
	int height[3] = { 9, 16, 16 };
	int difficulty;
	int curMine;
	int remainBlockNums;
	bool gameStart;
	int time;

	Block map[16][30];
	static GameManager * gameManager;
public:
	static GameManager * GetInstance() {
		if (gameManager == NULL) {
			gameManager = new GameManager();
		}
		return gameManager;
	}
	GameManager();
	void Init(HWND hWnd);
	void NewGame();
	void Draw();
	void DrawBack();
	void DrawBlocks();
	void InitMap();
	void SetDifficulty(int dif);
	int LeftClick(int clickX, int clickY);
	void RightClick(int clickX, int clickY);
	void AddNearMine(int x, int y);
	void DrawCurMineNume();
	void DrawTime();
	bool is_GameStart();
	void AddTime();
	~GameManager();
};