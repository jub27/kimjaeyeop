#pragma once
#include<Windows.h>
#include"Bitmap.h"
#define BITMAP_NUMS 20
class Gamemanager
{
private:
	static Gamemanager* m_pThis;
	Bitmap* m_bt[BITMAP_NUMS];
	Bitmap* back;

public:
	static Gamemanager* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new Gamemanager;
		}
		return m_pThis;
	}
	Gamemanager();

	void Init(HWND hWnd, HINSTANCE hInst);
	void Draw(HDC hdc, int x, int y);
	void Release();

	~Gamemanager();
};

