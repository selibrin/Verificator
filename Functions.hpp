#pragma once
#include <fstream>
#include <iostream>
#include <string>
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

double CountLine(int x1, int y1, int x2, int y2, Matrix& a, Matrix& b) {
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
	return double(count) / double(amount); // �������� ������
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
	return double(count) / double(amount); // �������� ������
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
	 setlocale(LC_ALL, "RUSSIAN");
	//****��������  �������� ��������� �����������****
	//������� �������� ����� � ��������� ��� � ������
	ifstream in;
	in.open(filename);

	if (in.is_open())
	{
		//���� �������� ����� ������ �������

		//������� ��������� ������� ����� � �����
		int count = 0;// ����� ����� � �����
		int temp;//��������� ����������

		while (!in.eof())// ��������� ���� �� �������� ����� ����� eof
		{
			in >> temp;//� ������� ��������� �� ����� �����
			count++;// ����������� ������� ����� �����
		}

		//����� ����� ���������, ������ ��� ����� ������ �������
		//����� � ����� ������
		//��� ����� ��������� ����� �������� �� ����� �������� �� ����� ������ 

		//������� ��������� ������� � ������ � ������ �����
		in.seekg(0, ios::beg);
		in.clear();

		//����� �������� � ������ ������� ������� ����� 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//�� ������ ������ ���� ������������ ������ �����
		{
			//������ ��� ����� ��������� �� �����, � ����������� ��������� ������
			in.get(symbol);//������� ������� ������
			if (symbol == ' ') count_space++;//���� ��� ������, �� ����� �������� �����������
			if (symbol == '\n') break;//���� ����� �� ����� ������, �� ������� �� �����
		}

		//������� � ������ � ������ �����
		in.seekg(0, ios::beg);
		in.clear();

		//������ �� ����� ������� ����� � ����� � ������� �������� � ������ ������.
		//������ ����� ������� �������.

		n = count / (count_space + 1);//����� �����
		m = count_space + 1;//����� �������� �� ������� ������ ����� ��������

		Matrix x(n, vector<int>(m));

		//���������� ������� �� �����
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
	//****�������� ����� �� ���������� �������****
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
			// � ����� �������� ������ ��������� �� ������
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
	//����� ������� � �������
	for (size_t i = 0; i < x.size(); i++)
	{
		for (size_t j = 0; j < x[0].size(); j++)
			cout << x[i][j] << "\t";
		cout << "\n";
	}
}

double Metric(Matrix x1, Matrix x2) { // ��� ���������� ����������
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

bool FileExist(const char* filePath) // ��� ������ � �����, ����� ���� �������
{
	bool isExist = false;
	ofstream ofs(filePath);

	if (ofs.is_open())
		isExist = true;

	ofs.close();
	return isExist;
}

vector<int> AdviceLine(int x1, int y1, int x2, int y2, Matrix& a) // ������� ������� ���� ��������� ��� ������� ������ ������������, �������� �������� �����
{
	Matrix x(a.size(), vector<int>(a[0].size())); // ������ ������� ������ �� ������� ��� � "a", �.�. ���������� �����������
	drawLine(x1, y1, x2, y2, x); // ������ ����� ��� ���������� ������
	double limit = CountLine(x1, y1, x2, y2, a, x); // ������ ������������ ��� ���������� �� ����� � ������ ��������, ����� �� �� ��� �� ��������, ���������� ����� ������ � ����� � ��������
	x.shrink_to_fit(); // ����������� ������ 

	vector<int> v(4); // ���� ������� ����������� ���������� 

	vector<int> vec;// ����� �������� ��������
	vec.push_back(-1); vec.push_back(-1); vec.push_back(-1); vec.push_back(-1);


	while (vec[0] < 2) {
		Matrix y(a.size(), vector<int>(a[0].size()));
		drawLine(x1 + vec[0], y1 + vec[1], x2 + vec[2], y2 + vec[3], y);
		
		if (CountLine(x1 + vec[0], y1 + vec[1], x2 + vec[2], y2 + vec[3], a, y) < limit) { // ���� ���� ������������ ������ ��� limit(��� x1,y1,x2,y2)
			limit = CountLine(x1 + vec[0], y1 + vec[1], x2 + vec[2], y2 + vec[3], a, y); // �� ������ limit
			v[0] = (x1 + vec[0]); v[1] = (y1 + vec[1]); v[2] = (x2 + vec[2]); v[3] = (y2 + vec[3]); // � ����������� ����������
		}
		
		vec = run(vec[0], vec[1], vec[2], vec[3]); // ������ ��������, �� ������ �������� ������ ���������� ��������
		
	}
	
	return v;
}


vector<int> AdviceCircle(int x0, int y0, int r, Matrix& a) // ������� ������� ���� ��������� ��� ������� ������ ������������, �������� �������� �����
{


	Matrix x(a.size(), vector<int>(a[0].size())); // ������ ������� ������ �� ������� ��� � "a", �.�. ���������� �����������
	drawCircle(x0, y0, r, x); // ������ ����� ��� ���������� ������
	double limit = CountCircle(x0, y0, r, a, x);
	x.shrink_to_fit();
	
	vector<int> v(3); // ���� ������� ����������� ���������� 
	

	vector<int> vec;// ����� �������� ��������
	vec.push_back(-1); vec.push_back(-1); vec.push_back(-1);
	
	while (vec[0] < 2) {
		Matrix y(a.size(), vector<int>(a[0].size()));
		drawCircle(x0 + vec[0], y0 + vec[1], r + vec[2], y);

		if (CountCircle(x0 + vec[0], y0 + vec[1], r + vec[2], a, y) < limit) { // ���� ���� ������������ ������ ��� limit(��� x0,y0,r), �� ������ limit
			limit = CountCircle(x0 + vec[0], y0 + vec[1], r + vec[2], a, y); // �� ������ limit
			v[0] = x0 + vec[0]; v[1] = y0 + vec[1]; v[2] = r + vec[2];  // � ����������� ����������
		}
		
		vec = run(vec[0], vec[1], vec[2]);// ������ ���� ��������� ����� � ������ � ����� �������
	
		
	}
	
	
	return v;
}

void Recomendations(const char* filename, int n, int m, double limit, Matrix a)
{
	double lim = limit; // ����������� ��������, � ��� ���������� �������� �����

	ifstream in; //��������� ���� � �����������
	in.open(filename);

	ofstream out;
	out.open("recom.txt"); //������� ���� ���� ����� ���������� ����������� ��������� �����

	if (in.is_open() && out.is_open())
	{
		while (!in.eof())
		{
			Matrix x(n, vector<int>(m));

			vector<int> vec;
			string s;
			getline(in, s); // ��������� ������ �� ����� � string
			get_numbers(vec, s); // ������ ��������� �� ����� � ���������� � ������

			
			if (vec.size() == 3) // � ������� 3 ����� (x0, y0, r) - ��� ����������
			{
				vector<int> v; // ����������� ���������
				drawCircle(vec[0], vec[1], vec[2], x);
				//if (CountCircle(vec[0], vec[1], vec[2], x, a) < limit) //���� �������� ������ ����������� ��������, ���� ������ ���������
					v = AdviceCircle(vec[0], vec[1], vec[2], a);  // 
				out << v[0] << ' ' << v[1] << ' ' << v[2] <<  endl; //������ � ����

			}

			if (vec.size() == 4) // � ������� 4 ����� (x1, y1, x2, y2) - ��� �������
			{
				vector<int> v; // ����������� ���������
				drawLine(vec[0], vec[1], vec[2], vec[3], x);
				if (CountLine(vec[0], vec[1], vec[2], vec[3], x, a) < limit) //���� �������� ������ ����������� ��������, ���� ������ ���������
				v = AdviceLine(vec[0], vec[1], vec[2], vec[3], a);  // 
				out << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << endl; //������ � ����
			
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