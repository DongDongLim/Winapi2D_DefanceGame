#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	map<wstring, CTexture*> m_mapTexture;

public:
	CTexture* FindTexture(const wstring& strKey);

	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath);
};

