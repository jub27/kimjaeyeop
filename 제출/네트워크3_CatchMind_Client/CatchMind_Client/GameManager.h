#pragma once
#include <Windows.h>
#include <vector>
#include "Bitmap.h"

using namespace std;

#define EDIT_ID 1

#define BITMAP_NUMS 8
#define BUF_SIZE 12
#define MAX_ROOM_NUM 5
#define MAX_ROOM_PLAYER 4

#define GAME_WIDTH 1024
#define GAME_HEIGHT 768

#define BUTTON_WIDTH 80
#define BUTTON_HEIGHT 30

#define ROOM_START_X 120
#define ROOM_START_Y 150

#define BOARD_X_START 250
#define BOARD_Y_START 151
#define BOARD_X_END 770
#define BOARD_Y_END 468

#define EDIT_BOX_X 550
#define EDIT_BOX_Y 590
#define EDIT_BOX_X_SIZE 200
#define EDIT_BOX_Y_SIZE 22


enum INST {
	MAKE_ROOM_REQUEST, MAKE_ROOM_ACCEPT, JOIN_ROOM_REQUEST, JOIN_ROOM_ACCEPT, PLAYER_ID_REQUEST, SET_PLAYER_ID
	, GET_ROOM_LIST, SET_ROOM_LIST, EXIT_ROOM_REQUEST, EXIT_ROOM_ACCEPT, ROOM_INFO_REQUEST, ROOM_INFO_ACCEPT
	, GAME_START_REQUEST, GAME_START_ACCEPT, DRAW_REQUEST, DRAW_ACCEPT
};

enum bitmaps {
	MAIN_BACKGROUND, MAKE_ROOM, EXIT, ROOM_LIST, ROOM_BACKGROUND, ROOM_INFO, CHARACTER, START
};

enum STATE {
	MAIN_MENU, ROOM, GAME_EXIT, GAME_START
};

typedef struct {
	int x1, y1, x2, y2;
}Line;

class GameManager
{
private:
	HWND m_hWnd;
	HDC pHDC;
	HDC		MemDC;
	HBITMAP	MyBitMap;
	HBITMAP	OldBitMap;
	static GameManager* instance;
	LPCSTR source[BITMAP_NUMS] = {"res\\MAIN_BACKGROUND.bmp","res\\MAKE_ROOM.bmp","res\\EXIT.bmp", "res\\ROOM_LIST.bmp", "res\\ROOM_BACKGROUND.bmp"
	, "res\\ROOM_INFO.bmp", "res\\CHARACTER.bmp", "res\\START.bmp"};
	Bitmap* bitmap[BITMAP_NUMS];
	STATE state;
	POINT mouse;
	SOCKET sock;
	bool click;
	bool draw;
	vector<Line> lineList;
	int roomNum;
	int playerID;
	int roomList[MAX_ROOM_NUM];
	int roomInfo[MAX_ROOM_PLAYER];
	int curRoomNums;
	int pos;
	bool turn;
	int msg[BUF_SIZE];
	bool firstMain;
	bool firstExit;
	bool firstRoom;
	bool is_playerID;
	HWND edit;
public:
	GameManager();
	static GameManager* GetInstance() {
		if (instance == NULL)
			instance = new GameManager();
		return instance;
	}
	void MainMenu();
	void Room();
	void ShowRoomList();
	void SetRoomList(int * msg);
	void RoomListRequest();
	void MakeRoomRequest();
	void ExitRoomRequest();
	void RoomInfoRequest();
	void GameStartRequest();
	void GameStart();
	void SetRoomInfo(int * msg);
	void SetTurnTrue();
	void ExitRoom();
	void JoinRoomRequest(int roomNum);
	void JoinRoom(int roomNum, int pos);
	void Init(HWND hWnd, SOCKET sock);
	STATE GetState();
	void SetMousePoint(int x, int y);
	void SetMouseClick(bool c);
	void PlayerIDRequest();
	void SetPlayerID(int playerID);
	void SetDrawTrue();
	void SetDrawFalse();
	void DrawRequest(int newX, int newY);
	void AddLine(int x1, int y1, int x2, int y2);
	bool RangeCheck(int x, int y);
	int GetPlayerID();
	int GetRoomNum();
	bool GetTurn();
	bool GetDraw();
	HWND GetEdit();
	void FirstMainInit();
	void FirstRoomInit();
	bool ClickCehck(int x, int y);
	~GameManager();
};