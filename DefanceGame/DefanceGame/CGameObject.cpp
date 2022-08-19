#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
	hitDistance = 0;
	size = { 0, 0 };
	pozition = { 0, 0 };
}

CGameObject::~CGameObject()
{

}

void CGameObject::SetSize(int x, int y)
{
	size = { x, y };
}

void CGameObject::SetPoint(int x, int y)
{
	pozition = { x, y };
}

double CGameObject::GetHitDis()
{
	return hitDistance;
}

POINT CGameObject::GetSize()
{
	return size;
}

POINT CGameObject::GetPozition()
{
	return pozition;
}