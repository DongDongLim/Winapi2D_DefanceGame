#pragma once

class CCore
{
	SINGLETON(CCore);

private:
	// ������ DC
	HDC m_hDC;
	// �޸� DC
	HDC m_hMemDC;
	// �޸� ��Ʈ��
	HBITMAP m_hBMP;

public:

	void init();
	void update();
	void render();
};

