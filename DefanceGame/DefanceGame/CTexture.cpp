#include "framework.h"
#include "CTexture.h"

CTexture::CTexture()
{
	m_hDC = 0;
	m_bmpInfo = {};
	m_hBMP = 0;
}

CTexture::~CTexture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBMP);
}

HDC CTexture::GetDC()
{
	return m_hDC;
}

BITMAP CTexture::GetBmpInfo()
{
	return m_bmpInfo;
}

HBITMAP CTexture::GetBitMap()
{
	return m_hBMP;
}

int CTexture::GetBmpWidth()
{
	return m_bmpInfo.bmWidth;
}

int CTexture::GetBmpHeight()
{
	return m_bmpInfo.bmHeight;
}

void CTexture::Load(const wstring& strFilePath)
{
	// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadimagea
	m_hBMP = (HBITMAP)LoadImage(
		// 인스턴스 핸들값(nullprt == 다른 프로그램에서 가져오지 않음)
		nullptr,
		// 이름(파일 패스)
		(LPCTSTR)strFilePath.c_str(),
		// 이미지 타입
		IMAGE_BITMAP,
		// 이미지 크기
		0,
		// 이미지 크기
		0,
		// 이미지 속성
		LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	if (!m_hBMP)
		assert(nullptr);
	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDC, m_hBMP);
	GetObject(m_hBMP, sizeof(BITMAP), &m_bmpInfo);
}
