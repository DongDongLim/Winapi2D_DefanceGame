#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
	hitDistance = 0;
	m_scale = { 0, 0 };
	m_pozition = { 0, 0 };
}

virtual CGameObject::~CGameObject()
{

}

void CGameObject::SetScale(POINT scale)
{
	m_scale = scale;
}

void CGameObject::SetPozition(POINT pos)
{
	m_pozition = pos;
}

double CGameObject::GetHitDis()
{
	return hitDistance;
}

POINT CGameObject::GetScale()
{
	return m_scale;
}

POINT CGameObject::GetPozition()
{
	return m_pozition;
}