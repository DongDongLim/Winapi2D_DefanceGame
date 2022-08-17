#pragma once

class CCore
{
	SINGLETON(CCore);

private:
	// 윈도우 DC
	HDC m_hDC;
	// 메모리 DC
	HDC m_hMemDC;
	// 메모리 비트맵
	HBITMAP m_hBMP;

public:

	void init();
	void update();
	void render();
};

