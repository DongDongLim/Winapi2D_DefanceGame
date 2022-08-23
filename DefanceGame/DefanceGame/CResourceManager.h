#pragma once

class CResource;

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	map<wstring, CResource> m_mapResource;

public:
	CResource* FindResource(const wstring& strKey);

	CResource* LoadResource(const wstring& strKey);
};

