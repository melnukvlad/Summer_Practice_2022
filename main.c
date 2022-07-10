#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <float.h>

#include "Triangle.h"

double inputDouble(const char* text)
{
	double d;
	char str[80];

	// Считать строку
	printf("%s: ", text);
	fgets(str, 80, stdin);

	// Удалить знак \n из строки
	if(str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	else
		(void)getchar();

	// Если строка пустая
	// Вернуть минимально возможное значение
	if(str[0] == '\n' || str[0] == '\0')
		return DBL_MIN;

	// Извлечь число из строки
	if(sscanf(str, "%lf", &d) == 1)
		return d;

	// Если не удалось извлечь число из строки
	// Вернуть минимально возможное значение
	return DBL_MIN;
}

point inputPoint(const char* text)
{
	point p;
	char str[80];

	// Считать строку
	printf("%s: ", text);
	fgets(str, 80, stdin);

	// Удалить знак \n из строки
	if(str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	else
		(void)getchar();

	// Если строка пустая
	// Вернуть минимально возможные значения
	if(str[0] == '\n' || str[0] == '\0')
	{
		p.x = DBL_MIN;
		p.y = DBL_MIN;
		return p;
	}

	// Извлечь числа из строки
	if(sscanf(str, "%lf %lf", &p.x, &p.y) == 2)
		return p;

	// Если не удалось извлечь числа из строки
	// Вернуть минимально возможные значения
	p.x = DBL_MIN;
	p.y = DBL_MIN;
	return p;
}

int main()
{
	double d;
	setlocale(LC_CTYPE, "");

	// Ввод параметров треугольника
	printf("Введите известные данные треугольника\n");
	sideA = inputDouble("Сторона a");
	sideB = inputDouble("Сторона b");
	sideC = inputDouble("Сторона c");
	angleA = inputDouble("Угол A");
	angleB = inputDouble("Угол B");
	angleC = inputDouble("Угол C");
	medianA = inputDouble("Медиана на сторону а");
	medianB = inputDouble("Медиана на сторону b");
	medianC = inputDouble("Медиана на сторону c");
	heightA = inputDouble("Высота на сторону а");
	heightB = inputDouble("Высота на сторону b");
	heightC = inputDouble("Высота на сторону c");
	vertexA = inputPoint("Координаты вершины А");
	vertexB = inputPoint("Координаты вершины B");
	vertexC = inputPoint("Координаты вершины C");
	S = inputDouble("Площадь треугольника");
	p = inputDouble("Полупериметр сторон треугольника");

	// Если пользователь ввел все данные
	// Завершить работу программы
	if(sideA != DBL_MIN && sideB != DBL_MIN && sideC != DBL_MIN &&
		angleA != DBL_MIN && angleB != DBL_MIN && angleC != DBL_MIN &&
		medianA != DBL_MIN && medianB != DBL_MIN && medianC != DBL_MIN &&
		heightA != DBL_MIN && heightB != DBL_MIN && heightC != DBL_MIN &&
		vertexA.x != DBL_MIN && vertexA.y != DBL_MIN &&
		vertexB.x != DBL_MIN && vertexB.y != DBL_MIN &&
		vertexC.x != DBL_MIN && vertexC.y != DBL_MIN &&
		S != DBL_MIN && p != DBL_MIN)
	{
		printf("\nВсе данные уже известны\n");
		return 0;
	}

	// Вычислить стороны по координатам вершин
	calcSidesUsingVerts();
	// Решить треугольник (найти все стороны и углы)
	solveTriangle();
	// Вычислить полупериметр
	calcSemiperimeter();
	// Вычислить площадь
	calcArea();
	// Вычислить медианы треугольника
	calcMedians();
	// Вычислить высоты треугольника
	calcHeights();

	// Если все данные остались незаполненными
	// Завершить работу программы
	if(sideA == DBL_MIN && sideB == DBL_MIN && sideC == DBL_MIN &&
		angleA == DBL_MIN && angleB == DBL_MIN && angleC == DBL_MIN &&
		medianA == DBL_MIN && medianB == DBL_MIN && medianC == DBL_MIN &&
		heightA == DBL_MIN && heightB == DBL_MIN && heightC == DBL_MIN &&
		vertexA.x == DBL_MIN && vertexA.y == DBL_MIN &&
		vertexB.x == DBL_MIN && vertexB.y == DBL_MIN &&
		vertexC.x == DBL_MIN && vertexC.y == DBL_MIN &&
		S == DBL_MIN && p == DBL_MIN)
	{
		printf("\nНе хватает исходных данных\n");
		return 0;
	}

	// Вывести все значения
	printf("\nДанные, которые удалось вычислить\n");
	if(sideA != DBL_MIN) printf("Сторона a: %g\n", sideA);
	if(sideB != DBL_MIN) printf("Сторона b: %g\n", sideB);
	if(sideC != DBL_MIN) printf("Сторона c: %g\n", sideC);
	if(angleA != DBL_MIN) printf("Угол A: %g\n", angleA);
	if(angleB != DBL_MIN) printf("Угол B: %g\n", angleB);
	if(angleC != DBL_MIN) printf("Угол C: %g\n", angleC);
	if(medianA != DBL_MIN) printf("Медиана на сторону а: %g\n", medianA);
	if(medianB != DBL_MIN) printf("Медиана на сторону b: %g\n", medianB);
	if(medianC != DBL_MIN) printf("Медиана на сторону c: %g\n", medianC);
	if(heightA != DBL_MIN) printf("Высота на сторону а: %g\n", heightA);
	if(heightB != DBL_MIN) printf("Высота на сторону b: %g\n", heightB);
	if(heightC != DBL_MIN) printf("Высота на сторону c: %g\n", heightC);
	if(vertexA.x != DBL_MIN && vertexA.y != DBL_MIN) printf("Координаты вершины А: %g %g\n", vertexA.x, vertexA.y);
	if(vertexB.x != DBL_MIN && vertexB.y != DBL_MIN) printf("Координаты вершины B: %g %g\n", vertexB.x, vertexB.y);
	if(vertexC.x != DBL_MIN && vertexC.y != DBL_MIN) printf("Координаты вершины C: %g %g\n", vertexC.x, vertexC.y);
	if(S != DBL_MIN) printf("Площадь треугольника: %g\n", S);
	if(p != DBL_MIN) printf("Полупериметр сторон треугольника: %g\n", p);

	getchar();
}
