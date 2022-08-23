#include "framework.h"

CPathManager::CPathManager()
{
	m_szContentPath[0] = {};
}


CPathManager::~CPathManager()
{

}

void CPathManager::Init()
{
	GetCurrentDirectory(255, (LPSTR)m_szContentPath);

	// 경로의 사이즈 구함, wcslen : wstring lenght
	int size = wcslen(m_szContentPath);

	// 뒤에서부터 하나씩 줄이면서
	for (int i = size - 1; i >= 0; --i)
	{
		// \\를 찾음
		if ('\\' == m_szContentPath[i])
		{
			// \\를 \0으로 만들어서 끊음
			m_szContentPath[i] = '\0';
			break;
		}
	}
	// WCHAR 에 wstirng 추가
	wcscat_s(m_szContentPath, MAXSIZE_PATH, L"\\Release\\content\\");
}

const WCHAR* CPathManager::GetContentPath()
{
	return m_szContentPath;
}