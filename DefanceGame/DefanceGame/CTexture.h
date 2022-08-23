#pragma once
#include "CResource.h"
class CTexture : public CResource
{
private:
	HDC m_hDC;
	BITMAP m_bmpInfo;
	HBITMAP m_hBMP;

public:
	CTexture();
	virtual ~CTexture();

	HDC GetDC();
	BITMAP GetBmpInfo();
	HBITMAP GetBitMap();

	int GetBmpWidth();
	int GetBmpHeight();

	void Load(const wstring& strFilePath);

};

