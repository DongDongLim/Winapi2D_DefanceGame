#pragma once

inline POINT PointSum(POINT POINT1, POINT POINT2)
{
	POINT point = { POINT1.x + POINT2.x, POINT1.y + POINT2.y };
	return point;
}

inline POINT PointSub(POINT POINT1, POINT POINT2)
{
	POINT point = { POINT1.x - POINT2.x, POINT1.y - POINT2.y };
	return point;
}

inline POINT PointMultiply(POINT POINT1, POINT POINT2)
{
	POINT point = { POINT1.x * POINT2.x, POINT1.y * POINT2.y };
	return point;
}


inline POINT PointDivide(POINT POINT1, POINT POINT2)
{
	POINT point = { POINT2.x != 0 ? POINT1.x / POINT2.x : 0
		,  POINT2.y != 0 ? POINT1.y / POINT2.y : 0};
	return point;
}
