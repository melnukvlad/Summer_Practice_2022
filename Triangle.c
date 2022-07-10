#include "Triangle.h"

#define _USE_MATH_DEFINES

#include <math.h>
#include <float.h>

// Перевод градусов в радианы
double degToRad(double a)
{
	return a * (M_PI / 180);
}

// Перевод радианов в градусы
double radToDeg(double a)
{
	return a * (180 / M_PI);
}

// Вычислить стороны по координатам вершин
void calcSidesUsingVerts()
{
	// Вычислить строну c по координатам вершин A и B
	if(vertexA.x != DBL_MIN && vertexA.y != DBL_MIN &&
		vertexB.x != DBL_MIN && vertexB.y != DBL_MIN &&
		sideC == DBL_MIN) sideC = sqrt((vertexA.x - vertexB.x) * (vertexA.x - vertexB.x) +
			(vertexA.y - vertexB.y) * (vertexA.y - vertexB.y));

	 // Вычислить строну a по координатам вершин B и C
	if(vertexB.x != DBL_MIN && vertexB.y != DBL_MIN &&
		vertexC.x != DBL_MIN && vertexC.y != DBL_MIN &&
		sideA == DBL_MIN) sideA = sqrt((vertexB.x - vertexC.x) * (vertexB.x - vertexC.x) +
			(vertexB.y - vertexC.y) * (vertexB.y - vertexC.y));

	// Вычислить строну b по координатам вершин A и C
	if(vertexA.x != DBL_MIN && vertexA.y != DBL_MIN &&
		vertexC.x != DBL_MIN && vertexC.y != DBL_MIN &&
		sideB == DBL_MIN) sideB = sqrt((vertexA.x - vertexC.x) * (vertexA.x - vertexC.x) +
			(vertexA.y - vertexC.y) * (vertexA.y - vertexC.y));
}

// Решить треугольник (найти все стороны и углы)
void solveTriangle()
{
	// По трем сторонам
	if(sideA != DBL_MIN && sideB != DBL_MIN && sideC != DBL_MIN)
	{
		if(angleA == DBL_MIN)
		{
			angleA = (sideB * sideB + sideC * sideC - sideA * sideA) / (2 * sideB * sideC);
			angleA = radToDeg(acos(angleA));
		}

		if(angleC == DBL_MIN)
		{
			angleC = (sideB * sideB + sideA * sideA - sideC * sideC) / (2 * sideA * sideB);
			angleC = radToDeg(acos(angleC));
		}

		if(angleB == DBL_MIN) angleB = 180 - (angleA + angleC);
		return;
	}

	// По двум сторонам и углу между ними
	if(sideA != DBL_MIN && sideB != DBL_MIN && angleC != DBL_MIN)
	{
		sideC = sqrt(sideA * sideA + sideB * sideB - 2 * sideA * sideB * cos(degToRad(angleC)));

		if(angleA == DBL_MIN)
		{
			angleA = (sideB * sideB + sideC * sideC - sideA * sideA) / (2 * sideB * sideC);
			angleA = radToDeg(acos(angleA));
		}

		angleB = 180 - (angleA + angleC);
		return;
	}
	else if(sideB != DBL_MIN && sideC != DBL_MIN && angleA != DBL_MIN)
	{
		sideA = sqrt(sideB * sideB + sideC * sideC - 2 * sideB * sideC * cos(degToRad(angleA)));

		if(angleC == DBL_MIN)
		{
			angleC = (sideB * sideB + sideA * sideA - sideC * sideC) / (2 * sideA * sideB);
			angleC = radToDeg(acos(angleC));
		}

		angleB = 180 - (angleA + angleC);
		return;
	}
	else if(sideA != DBL_MIN && sideC != DBL_MIN && angleB != DBL_MIN)
	{
		sideB = sqrt(sideA * sideA + sideC * sideC - 2 * sideA * sideC * cos(degToRad(angleB)));

		if(angleA == DBL_MIN)
		{
			angleA = (sideB * sideB + sideC * sideC - sideA * sideA) / (2 * sideB * sideC);
			angleA = radToDeg(acos(angleA));
		}

		angleC = 180 - (angleA + angleB);
		return;
	}

	// По стороне и прилежащим к ней углам
	if(sideA != DBL_MIN && angleB != DBL_MIN && angleC != DBL_MIN)
	{
		angleA = 180 - (angleB + angleC);
		sideB = (sideA * sin(degToRad(angleB))) / sin(degToRad(angleA));
		sideC = (sideA * sin(degToRad(angleC))) / sin(degToRad(angleA));
	}
	else if(sideB != DBL_MIN && angleA != DBL_MIN && angleC != DBL_MIN)
	{
		angleB = 180 - (angleA + angleC);
		sideA = (sideB * sin(degToRad(angleA))) / sin(degToRad(angleB));
		sideC = (sideB * sin(degToRad(angleC))) / sin(degToRad(angleB));
	}
	else if(sideC != DBL_MIN && angleA != DBL_MIN && angleB != DBL_MIN)
	{
		angleC = 180 - (angleA + angleB);
		sideA = (sideC * sin(degToRad(angleA))) / sin(degToRad(angleC));
		sideB = (sideC * sin(degToRad(angleB))) / sin(degToRad(angleC));
	}

	// По двум сторонам и противолежащему к одной из них углу
	if(sideA != DBL_MIN && sideB != DBL_MIN && angleB != DBL_MIN)
	{
		angleA = radToDeg(asin(sideA / sideB * sin(degToRad(angleB))));
		angleC = 180 - (angleA + angleB);
		sideC = sideA * sin(degToRad(angleC)) / sin(degToRad(angleA));
	}
	else if(sideA != DBL_MIN && sideB != DBL_MIN && angleA != DBL_MIN)
	{
		angleB = radToDeg(asin(sideB / sideA * sin(degToRad(angleA))));
		angleC = 180 - (angleA + angleB);
		sideC = sideA * sin(degToRad(angleC)) / sin(degToRad(angleA));
	}
	else if(sideB != DBL_MIN && sideC != DBL_MIN && angleB != DBL_MIN)
	{
		angleC = radToDeg(asin(sideC / sideB * sin(degToRad(angleB))));
		angleA = 180 - (angleB + angleC);
		sideA = sideB * sin(degToRad(angleA)) / sin(degToRad(angleB));
	}
	else if(sideB != DBL_MIN && sideC != DBL_MIN && angleC != DBL_MIN)
	{
		angleB = radToDeg(asin(sideB / sideC * sin(degToRad(angleC))));
		angleA = 180 - (angleB + angleC);
		sideA = sideB * sin(degToRad(angleA)) / sin(degToRad(angleB));
	}
	else if(sideA != DBL_MIN && sideC != DBL_MIN && angleA != DBL_MIN)
	{
		angleC = radToDeg(asin(sideC / sideA * sin(degToRad(angleA))));
		angleB = 180 - (angleA + angleC);
		sideB = sideA * sin(degToRad(angleB)) / sin(degToRad(angleA));
	}
	else if(sideA != DBL_MIN && sideC != DBL_MIN && angleC != DBL_MIN)
	{
		angleA = radToDeg(asin(sideA / sideC * sin(degToRad(angleC))));
		angleB = 180 - (angleA + angleC);
		sideB = sideA * sin(degToRad(angleB)) / sin(degToRad(angleA));
	}
}

// Вычислить полупериметр
void calcSemiperimeter()
{
	if(p == DBL_MIN && sideA != DBL_MIN && sideB != DBL_MIN && sideC != DBL_MIN)
		p = (sideA + sideB + sideC) / 2;
}

// Вычислить площадь
void calcArea()
{
	// По полупериметру
	if(p != DBL_MIN)
	{
		S = sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
		return;
	}

	// По двум сторонам и углу между ними
	if(sideA != DBL_MIN && sideB != DBL_MIN && angleC != DBL_MIN)
		S = 0.5 * sideA * sideB * sin(degToRad(angleC));
	else if(sideB != DBL_MIN && sideC != DBL_MIN && angleA != DBL_MIN)
		S = 0.5 * sideB * sideC * sin(degToRad(angleA));
	else if(sideA != DBL_MIN && sideC != DBL_MIN && angleB != DBL_MIN)
		S = 0.5 * sideA * sideC * sin(degToRad(angleB));

	// По координатам вершин
	if(vertexA.x != DBL_MIN && vertexA.y != DBL_MIN &&
		vertexB.x != DBL_MIN && vertexB.y != DBL_MIN &&
		vertexC.x != DBL_MIN && vertexC.y != DBL_MIN)
	{
		S = (vertexB.x - vertexA.x) * (vertexC.y - vertexA.y) -
			(vertexC.x - vertexA.x) * (vertexB.y - vertexA.y);
		S = 0.5 * fabs(S);
	}
}

// Вычислить медианы треугольника
void calcMedians()
{
	if(sideA != DBL_MIN && sideB != DBL_MIN && sideC != DBL_MIN)
	{
		medianA = 0.5 * sqrt(2 * sideB * sideB + 2 * sideC * sideC - sideA * sideA);
		medianB = 0.5 * sqrt(2 * sideA * sideA + 2 * sideC * sideC - sideB * sideB);
		medianC = 0.5 * sqrt(2 * sideA * sideA + 2 * sideB * sideB - sideC * sideC);
	}
}

// Вычислить высоты треугольника
void calcHeights()
{
	// Вычислить высоту на сторону a
	if(heightA == DBL_MIN)
	{
		// Через сторону и площадь
		if(sideA != DBL_MIN && S != DBL_MIN)
			heightA = 2 * S / sideA;
		else if(sideB != DBL_MIN && angleC != DBL_MIN) // Через сторону и угол
			heightA = sideB * sin(degToRad(angleC));
		else if(sideC != DBL_MIN && angleB != DBL_MIN)
			heightA = sideC * sin(degToRad(angleB));
	}

	// Вычислить высоту на сторону b
	if(heightB == DBL_MIN)
	{
		// Через сторону и площадь
		if(sideB != DBL_MIN && S != DBL_MIN)
			heightB = 2 * S / sideB;
		if(sideC != DBL_MIN && angleA != DBL_MIN) // Через сторону и угол
			heightB = sideC * sin(degToRad(angleA));
		else if(sideA != DBL_MIN && angleC != DBL_MIN)
			heightB = sideA * sin(degToRad(angleC));
	}

	// Вычислить высоту на сторону c
	if(heightC == DBL_MIN)
	{
		// Через сторону и площадь
		if(sideC != DBL_MIN && S != DBL_MIN)
			heightC = 2 * S / sideC;
		if(sideA != DBL_MIN && angleB != DBL_MIN) // Через сторону и угол
			heightC = sideA * sin(degToRad(angleB));
		else if(sideB != DBL_MIN && angleA != DBL_MIN)
			heightC = sideB * sin(degToRad(angleA));
	}
}
