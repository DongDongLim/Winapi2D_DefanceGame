#pragma once
class CPathManager
{
	SINGLETON(CPathManager);

public:
	// 윈도우에서 최대로 표시할 수 있는 경로가 255
	const static int MAXSIZE_PATH = 255;

private:
	// 리소스 경로[]
	WCHAR m_szContentPath[MAXSIZE_PATH];

public:
	void Init();

	const WCHAR* GetContentPath();
};

