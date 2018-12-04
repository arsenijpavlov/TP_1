#include <conio.h>
#include "Note.h"
using namespace std;

const int size_arr = 3;//размер массива
NOTE notes[size_arr];//массив записей


int main() {
	//__int64 phone;
	setlocale(LC_ALL, "");
	system("color 0a");

	string SName;
	bool flag, flag_n = false;
	int index;

	while (true) {
		flag = false;
		system("cls");
		if (flag_n) {
			for (int i = 0; i < size_arr; i++) {
				cout << notes[i];
			}
			cout << "\n";
		}
		cout << "1) Ввод\n2) Изменить запись\n3) Поиск\n4) Выход\n\n";
		switch (_getch()) {	//сработает при нажатии нужной клавиши
		case 49/*1*/:
			cout << "Введите последовательно:\nимя, фамилию, номер телефона, дату рождения (DD MM YYYY)\n";
			try {
				//ввод данных
				for (int i = 0; i < size_arr; ++i) {
					cin >> notes[i];
				}
				flag_n = true;
				/*Сортируем*/
				sort(size_arr);
				system("cls");
			}
			catch (const Exception& e) {
				cout << "\n" << e.what();
			}
			break;
		case 50/*2*/:
			do {
				cout << "Введите индекс (1.." << size_arr << ", выйти из окна изменений - любое другое число):\n> ";
				cin >> index;
				index--;
			} while (index < 0 || index >= size_arr);//защита от переполнения массива
			cout << "имя, фамилия, номер телефона, дата рождения (DD MM YYYY)\n";
			cin >> notes[index];
			sort(size_arr);
			break;
		case 51/*3*/:
			//поиск по имени и фамилии
			cout << "Введите фамилию:\n> ";
			cin >> SName;
			for (int i = 0; i < 8; i++) {
				if (notes[i].Surname() == SName) {
					cout << notes[i];
					flag = true;
				}
			}
			cout << "\n";
			if (!flag)
				cout << "Не найдено\n";
			system("pause");
			break;
		case 52/*4*/:
			return 0;
			break;
		}
	}
}

//сортировка (гномья)
void sort(int Size) {
	for(int i=1;i<Size;){
		if (i == 0 || notes[i - 1].Phone() <= notes[i].Phone())
			i++;
		else {
			NOTE temp = notes[i];
			notes[i] = notes[i - 1];
			notes[i - 1] = temp;
			i--;
		}
	}
}