#include "framework.h"
#include "CTexture.h"

CResourceManager::CResourceManager()
{
    m_mapTexture = {};
}

CResourceManager::~CResourceManager()
{
    for (map<wstring, CTexture*>::iterator iter = m_mapTexture.begin(); iter != m_mapTexture.end(); ++iter)
    {
        if (nullptr != iter->second)
            delete iter->second;
    }
}

CTexture* CResourceManager::FindTexture(const wstring& strKey)
{
    map<wstring, CTexture*>::iterator iter = m_mapTexture.find(strKey);

    if (m_mapTexture.end() == iter)
        return nullptr;

    return iter->second;
}

CTexture* CResourceManager::LoadTexture(const wstring& strKey, const wstring& strPath)
{
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
		return pTex;

    WCHAR strFilePath[255];
    GetCurrentDirectory(255, (LPSTR)strFilePath);

	// 경로의 사이즈 구함, wcslen : wstring lenght
	int size = wcslen(strFilePath);

	// 뒤에서부터 하나씩 줄이면서
	for (int i = size - 1; i >= 0; --i)
	{
		// \\를 찾음
		if ('\\' == strFilePath[i])
		{
			// \\를 \0으로 만들어서 끊음
			strFilePath[i] = '\0';
			break;
		}
	}

	wcscat_s(strFilePath, 255, L"\\Release\\content\\"); // WCHAR 에 wstirng 추가


	pTex = new CTexture();
    pTex->Load(strFilePath);
	pTex->SetKey(strKey);
	pTex->SetPath(strPath);

	m_mapTexture.insert(make_pair(strKey, pTex));

	return pTex;
}
