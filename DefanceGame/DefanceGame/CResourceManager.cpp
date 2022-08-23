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

    wstring strFilePath = CPathManager::getInst()->GetContentPath();
    strFilePath += strPath;

	pTex = new CTexture();
    pTex->Load(strFilePath);
	pTex->SetKey(strKey);
	pTex->SetPath(strPath);

	m_mapTexture.insert(make_pair(strKey, pTex));

	return pTex;
}
