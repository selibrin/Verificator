#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "run.hpp"
using namespace std;


using Row = vector<int>;
using Matrix = vector<Row>;

//const int a = 100;
//const int b = 100;
int n = 0;
int m = 0;


void drawLine(int x1, int y1, int x2, int y2, Matrix& a) {
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;
	//

	a[x2][y2] = 1;
	while (x1 != x2 || y1 != y2)
	{
		a[x1][y1] = 1;
		const int error2 = error * 2;
		//
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}

}

double CountLine(int x1, int y1, int x2, int y2, Matrix &a, Matrix &b) {
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;
	//
	int count = 0;
	int amount = 0;

	if (a[x2][y2] != b[x2][y2]) count++;
	amount++;
	while (x1 != x2 || y1 != y2)
	{
		if (a[x1][y1] != b[x1][y1]) count++;
		amount++;
		const int error2 = error * 2;
		//
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
	return double(count) / double(amount); // отношение несовпавших к общему числу точек
}

void drawCircle(int x0, int y0, int radius, Matrix& a) {
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (y >= 0) {
		if (((x0 + x) > -1) && ((y0 + y) > -1)) a[x0 + x][y0 + y] = 1;
		if (((x0 + x) > -1) && ((y0 - y) > -1)) a[x0 + x][y0 - y] = 1;
		if (((x0 - x) > -1) && ((y0 + y) > -1)) a[x0 - x][y0 + y] = 1;
		if (((x0 - x) > -1) && ((y0 - y) > -1)) a[x0 - x][y0 - y] = 1;
		error = 2 * (delta + y) - 1;
		if (delta < 0 && error <= 0) {
			++x;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if (delta > 0 && error > 0) {
			--y;
			delta += 1 - 2 * y;
			continue;
		}
		++x;
		delta += 2 * (x - y);
		--y;
	}
}

double CountCircle(int x0, int y0, int radius, Matrix &a, Matrix &b) {
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;

	int count = 0;
	int amount = 0;
	while (y >= 0) {
		if (((x0 + x) > -1) && ((y0 + y) > -1) && (a[x0 + x][y0 + y] != b[x0 + x][y0 + y])) count++;
		if (((x0 + x) > -1) && ((y0 + y) > -1) ) amount++;
		if (((x0 + x) > -1) && ((y0 - y) > -1) && (a[x0 + x][y0 - y] != b[x0 + x][y0 - y])) count++;
		if (((x0 + x) > -1) && ((y0 - y) > -1)) amount++;
		if (((x0 - x) > -1) && ((y0 + y) > -1) && (a[x0 - x][y0 + y] != b[x0 - x][y0 + y])) count++;
		if (((x0 - x) > -1) && ((y0 + y) > -1)) amount++;
		if (((x0 - x) > -1) && ((y0 - y) > -1) && (a[x0 - x][y0 - y] != b[x0 - x][y0 - y])) count++;
		if (((x0 - x) > -1) && ((y0 - y) > -1)) amount++;
		error = 2 * (delta + y) - 1;
		if (delta < 0 && error <= 0) {
			++x;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if (delta > 0 && error > 0) {
			--y;
			delta += 1 - 2 * y;
			continue;
		}
		++x;
		delta += 2 * (x - y);
		--y;
	}
	return double(count)/double(amount); // отношение несовпавших к общему числу точек
}

void get_numbers(vector<int>& result, const string& s) {
	bool found = false;
	int number = 0;

	for (string::size_type i = 0; i < s.length(); i++) {
		const char ch = s[i];
		if (ch >= '0' && ch <= '9') {
			const int digit = ch - '0';
			number = number * 10 + digit;
			found = true;
		}
		else {
			if (found) {
				result.push_back(number);

				number = 0;
				found = false;
			}
		}
	}

	if (found) {
		result.push_back(number);
	}
}



Matrix CopyBitmap(const char* filename) {
	// setlocale(LC_ALL, "RUSSIAN");
	//****Считываю  исходное растровое изображение****
	//Создаем файловый поток и связываем его с файлом
	ifstream in;
	in.open(filename);

	if (in.is_open())
	{
		//Если открытие файла прошло успешно

		//Вначале посчитаем сколько чисел в файле
		int count = 0;// число чисел в файле
		int temp;//Временная переменная

		while (!in.eof())// пробегаем пока не встретим конец файла eof
		{
			in >> temp;//в пустоту считываем из файла числа
			count++;// увеличиваем счетчик числа чисел
		}

		//Число чисел посчитано, теперь нам нужно понять сколько
		//чисел в одной строке
		//Для этого посчитаем число пробелов до знака перевода на новую строку 

		//Вначале переведем каретку в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Число пробелов в первой строчке вначале равно 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//на всякий случай цикл ограничиваем концом файла
		{
			//теперь нам нужно считывать не числа, а посимвольно считывать данные
			in.get(symbol);//считали текущий символ
			if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
			if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
		}

		//Переход в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строке.
		//Теперь можем считать матрицу.

		n = count / (count_space + 1);//число строк
		m = count_space + 1;//число столбцов на единицу больше числа пробелов

		Matrix x(n, vector<int>(m));

		//Считывание матрицы из файла
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				in >> x[i][j];

		in.close();
		return x;
	}
	else
	{
		cout << "File doesn't exist." << endl;
		in.close();
		Matrix x;
		return x;
		//exit(EXIT_FAILURE);
	}
	//system("pause");

}

Matrix CreateBitmap(const char* filename, int n, int m) {
	//****Создание растр по параметрам вектора****
	ifstream in;
	in.open(filename);
	Matrix x(n, vector<int>(m));
	if (in.is_open())
	{
		while (!in.eof())
		{
			vector<int> vec;
			string s;
			getline(in, s);
			get_numbers(vec, s);

			if (vec.size() == 4) drawLine(vec[0], vec[1], vec[2], vec[3], x);
			if (vec.size() == 3) drawCircle(vec[0], vec[1], vec[2], x);
			// в конце итерации вектор удаляется из памяти
		}
		in.close();
		return x;
	}
	else
	{
		cout << "File doesn't exist." << endl;
		in.close();
		x.shrink_to_fit();
		return x;
	//	exit(EXIT_FAILURE);
	}
}

void ConsoleOutput(Matrix x) {
	//Вывод матрицы в консоль
	for (size_t i = 0; i < x.size(); i++)
	{
		for (size_t j = 0; j < x[0].size(); j++)
			cout << x[i][j] << "\t";
		cout << "\n";
	}
}

double Metric(Matrix x1, Matrix x2) { // для одинаковых разрешений
	int count = 0;
	double value = 0;
	
	for (size_t i = 0; i < x1.size(); i++)
		for (size_t j = 0; j < x1[0].size(); j++)
			if (x1[i][j] != x2[i][j]) count++;
	value = double(x1.size()) * double(x1[0].size()) - count;
	value /= double(x1.size()) * double(x1[0].size());
	value = round(value * 1000) / 1000;
	return value;
}

vector<int> TakeSize(Matrix a)
{
	vector<int> vec;
	vec.push_back(int(a.size()));
	vec.push_back(int(a[0].size()));
	return vec;
}

bool FileExist(const char* filePath) // для записи
{
	bool isExist = false;
	ofstream ofs(filePath);

	if (ofs.is_open())
		isExist = true;

	ofs.close();
	return isExist;
}

void AdviceLine(int x1, int y1, int x2, int y2, Matrix& a) // Параметры при которых меньше несовпадений 
{
	Matrix x(a.size(), vector<int>(a[0].size())); // создаю матрицу такого же размера как и "a", т.е. растрового изображения
	int limit = CountLine(x1, y1, x2, y2, a, x);

	int deltaX1 = -1, deltaX2 = -1, deltaY1 = -1, deltaY2 = -1;
	int q = x1, w = y1, e = x2, r = y2;
	while (deltaX1 <= 1) {
		drawLine(x1 + deltaX1, y1 + deltaY1, x2 + deltaX2, y2 + deltaY2, x);
		if (CountLine(x1 + deltaX1, y1 + deltaY1, x2 + deltaX2, y2 + deltaY2, a, x) < limit) { // если доля несвопадений меньше чем limit(при x1,y1,x2,y2), то меняем limit
			limit = CountLine(x1 + 1, y1, x2, y2, a, x);
			q = (x1 + deltaX1); w = (y1 + deltaY1); e = (x2 + deltaX2); r = (y2 + deltaY2);
		}

		run(deltaX1, deltaY1, deltaX2, deltaY2); // проход всех ближайших точек у начала и конца отрезка

		x.clear(); // чистим нашу временную матрицу 
	}

}


int AdviceCircle(int x0, int y0, int r, Matrix& a) // Параметры при которых меньше несовпадений 
{
	Matrix x(a.size(), vector<int>(a[0].size())); // создаю матрицу такого же размера как и "a", т.е. растрового изображения
	int limit = CountCircle(x0, y0, r, a, x);
	int deltaX = -1, deltaY = -1, deltaR = -1;
	int q = x0, w = y0, e = r;

	while (deltaR <= 1) {
		drawCircle(x0 + deltaX, y0 + deltaY, r + deltaR, x);
		if (CountCircle(x0 + deltaX, y0 + deltaY, r + deltaR, a, x) < limit) { // если доля несвопадений меньше чем limit(при x0,y0,r), то меняем limit
			limit = CountCircle(x0 + deltaX, y0 + deltaY, r + deltaR, a, x);
			q = x0 + deltaX; w = y0 + deltaY; e = r + deltaR;
		}

		run(deltaX, deltaY, deltaR); // проход всех ближайших точек у начала и конца отрезка

		x.clear(); // чистим нашу временную матрицу
	}

	return q;
}

void Recomendations(const char* filename, int n, int m, double limit, Matrix a)
{
	int lim = (1 - int(limit)); // перевод из доли совпадений в долю несовпадений, так захотелось

	ifstream in;
	in.open(filename);

	ofstream out;
	out.open("recom.txt");

	if (in.is_open())
	{
		while (!in.eof())
		{
			Matrix x(n, vector<int>(m));

			vector<int> vec;
			string s;
			getline(in, s);
			get_numbers(vec, s);

			
			if (vec.size() == 4)
			{
				drawLine(vec[0], vec[1], vec[2], vec[3], x);
				if (CountLine(vec[0], vec[1], vec[2], vec[3], x, a) < limit) AdviceLine(vec[0], vec[1], vec[2], vec[3], a);
			}
			

			if (vec.size() == 3)
			{
				drawCircle(vec[0], vec[1], vec[2], x);
				if (CountCircle(vec[0], vec[1], vec[2], x, a) < limit) out << AdviceCircle(vec[0], vec[1], vec[2], a) << endl;
				
			}
		
		} 
		in.close();
		out.close();
	}
	else
	{
		cout << "File doesn't exist." << endl;
		in.close();
		out.close();
	}

}