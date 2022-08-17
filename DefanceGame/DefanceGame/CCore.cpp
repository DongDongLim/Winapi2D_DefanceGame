#include "framework.h";

CCore::CCore()
{
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);// 사용한 dc 반납
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBMP);
}

POINT g_rectPos;

void CCore::init()
{
	// 코어의 초기화 과정
	m_hDC = GetDC(hWnd); // 그려야하는 윈도우의 dc를 가져오는 방법
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
	g_rectPos.x = 300;
	g_rectPos.y = 300;
}
 
void CCore::update()
{

}

void CCore::render()
{
}
