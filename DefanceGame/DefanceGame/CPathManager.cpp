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

	// ����� ������ ����, wcslen : wstring lenght
	int size = wcslen(m_szContentPath);

	// �ڿ������� �ϳ��� ���̸鼭
	for (int i = size - 1; i >= 0; --i)
	{
		// \\�� ã��
		if ('\\' == m_szContentPath[i])
		{
			// \\�� \0���� ���� ����
			m_szContentPath[i] = '\0';
			break;
		}
	}
	// WCHAR �� wstirng �߰�
	wcscat_s(m_szContentPath, MAXSIZE_PATH, L"\\Release\\content\\");
}

const WCHAR* CPathManager::GetContentPath()
{
	return m_szContentPath;
}