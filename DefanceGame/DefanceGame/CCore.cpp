#include "framework.h"

CCore::CCore()
{
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);// 사용한 dc 반납
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBMP);
}


void CCore::Init()
{
	CTimeManager::getInst()->Init();
	CSceneManager::getInst()->Init();
	CPathManager::getInst()->Init();
	// 코어의 초기화 과정
	m_hDC = GetDC(hWnd); // 그려야하는 윈도우의 dc를 가져오는 방법
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}
 
void CCore::Update()
{
	CTimeManager::getInst()->Update();
	CSceneManager::getInst()->Update();
	
}

void CCore::Render()
{
	// 배경 초기화
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	// TODO : 게임 표현(게임의 정보를 통해 그려주는 작업)
	CSceneManager::getInst()->Render(m_hMemDC);
	// fps를 표현
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", FPS);
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);


	// m_hMemDC에 그린 복사본을 원본 DC에 그리는 작업
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);

}

HDC CCore::GetMainDC()
{
	return m_hMemDC;
}
