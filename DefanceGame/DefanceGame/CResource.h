#pragma once
class CResource
{
private:
	wstring m_strKey;
	wstring m_strPath;

public:
	CResource();
	virtual ~CResource();

	void SetKey(const wstring& strKey);
	void SetPath(const wstring& strPath);

	const wstring& GetKey();
	const wstring& GetPath();

};

