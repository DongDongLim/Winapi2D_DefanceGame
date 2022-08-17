#include "framework.h";

CCore::CCore()
{
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);// ����� dc �ݳ�
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBMP);
}

POINT g_rectPos;

void CCore::init()
{
	// �ھ��� �ʱ�ȭ ����
	m_hDC = GetDC(hWnd); // �׷����ϴ� �������� dc�� �������� ���
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
