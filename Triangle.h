#ifndef TRIANGLE_H
#define TRIANGLE_H

// Структура точки (вершины)
typedef struct
{
	double x;
	double y;
} point;

/* Параметры треугольника */

double sideA; // Сторона a
double sideB; // Сторона b
double sideC; // Сторона c
double angleA; // Угол A
double angleB; // Угол B
double angleC; // Угол C
double medianA; // Медиана на сторону а
double medianB; // Медиана на сторону b
double medianC; // Медиана на сторону c
double heightA; // Высота на сторону a
double heightB; // Высота на сторону b
double heightC; // Высота на сторону c
point vertexA; // Координаты вершины А
point vertexB; // Координаты вершины B
point vertexC; // Координаты вершины C
double S; // Площадь треугольника
double p; // Полупериметр сторон треугольника

/* Функции */

// Перевод градусов в радианы
double degToRad(double a);

// Перевод радианов в градусы
double radToDeg(double a);

// Вычислить стороны по координатам вершин
void calcSidesUsingVerts();

// Решить треугольник (найти все стороны и углы)
void solveTriangle();

// Вычислить полупериметр
void calcSemiperimeter();

// Вычислить площадь
void calcArea();

// Вычислить медианы треугольника
void calcMedians();

// Вычислить высоты треугольника
void calcHeights();

#endif
