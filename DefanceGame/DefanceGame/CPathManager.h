#pragma once
class CPathManager
{
	SINGLETON(CPathManager);

public:
	// �����쿡�� �ִ�� ǥ���� �� �ִ� ��ΰ� 255
	const static int MAXSIZE_PATH = 255;

private:
	// ���ҽ� ���[]
	WCHAR m_szContentPath[MAXSIZE_PATH];

public:
	void Init();

	const WCHAR* GetContentPath();
};

