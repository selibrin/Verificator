#pragma once
#include "Functions.hpp"
#include <string>

void UI() {
	int instruction;
	if (FileExist("recom.txt")) remove("recom.txt"); // если файл с рекомендованными параметрами существует, удаляем его 
													 // не делаем этого в цикле чтобы после завершения программы можно было посмотреть файл
	while (1) {
		Matrix  b;
		instruction = 0;
		char* filename = new char[24];

		cout << "enter filename of your bitmap:" << endl;
		cin >> filename;
		Matrix a = CopyBitmap(filename);
		delete[] filename;

		if (a.size() != 0) {
			while (1) {


				instruction = 0;
				cout << "Your options:" << endl;
				cout << "     1 - Delete images and go back" << endl;
				cout << "     2 - Output copied bitmap" << endl;
				cout << "     3 - Create bitmap with parameters" << endl;
				cout << "     4 - Output created bitmap" << endl;
				cout << "     5 - Metric" << endl;
				cout << "     6 - Get recomended parameters based and output the bitmap" << endl;


					if (instruction == 0) {
						cin >> instruction;
					}



					if (instruction == 1)
					{
						a.shrink_to_fit();
						b.shrink_to_fit();
						break;
					}



					if (instruction == 2)
					{
						cout << endl;
						for (unsigned short int i = 0; i < a.size(); i++) cout << "--------";
						cout << endl;
						ConsoleOutput(a);
						for (unsigned short int i = 0; i < a.size(); i++) cout << "--------";
						cout << endl;
					}


					if (instruction == 3)
					{
						vector<int> u;
						char* name = new char[24];
						cout << "Enter name of the file with parameters" << endl;
						cin >> name;
						u = TakeSize(a);
						Matrix x = CreateBitmap(name, u[0], u[1]);
						b = x;
						delete[] name;
					}

					if (instruction == 4)
					{
						cout << endl;
						for (unsigned short int i = 0; i < a.size(); i++) cout << "--------";
						cout << endl;
						ConsoleOutput(b);
						for (unsigned short int i = 0; i < a.size(); i++) cout << "--------";
						cout << endl;
					}

					if (instruction == 5)
					{

						if (a.size() > 0 && b.size() > 0)
							cout << Metric(a, b) << endl;
						else
							cout << "Created bitmap doesn't exist. " << endl;
					}

					if (instruction == 6)
					{
						char* name = new char[24];
						double limit;
						cout << "Enter name of the file with parameters" << endl;
						cin >> name;
						
						cout << "Enter mimimal precision in percentage" << endl;
						cin >> limit;
						limit /= 100;

						Recomendations(name, int(a.size()), int(a[0].size()), limit, a);

						vector<int> u = TakeSize(a);
						Matrix x = CreateBitmap(name, u[0], u[1]);
						cout << endl;
						ConsoleOutput(x);
						
					}
				}
			}
		cout << endl << endl;
	}
}