#include <conio.h>
#include "Note.h"

int main() {
	__int64 phone;
	const int size_arr = 8;//������ �������
	setlocale(LC_ALL, "");
	system("color 0a");

	NOTE notes[size_arr];//������ �������

	while (true) {
		cout << "\n1) ����\n2) �������� ������\n3) �����\n4) �����\n\n> ";
		switch (_getch()) {
		case 49/*1*/:
			cout << "8 ������� ���������������: ���, �������, ����� ��������, ���� �������� (DD MM YYYY)\n";
			try {
				//���� ������
				for (int i = 0; i < size_arr; ++i) {
					cin >> notes[i];
				}
				/*���������*/
				int j, n = size_arr;
				do {
					int nn = 0;
					for (j = 1; j < n; ++j)
						if (notes[j - 1].Day() > notes[j].Day()
							&& notes[j - 1].Month() > notes[j].Month()
							&& notes[j - 1].Year() > notes[j].Year()) {
							NOTE temp = notes[j - 1];
							notes[j - 1] = notes[j];
							notes[j] = temp;
							nn = j;
						}
					n = nn;
				} while (n);

			}
			catch (const Exception& e) {
				cout << "\n" << e.what();
			}
			break;
		case 50/*2*/:
			int index;
			do {
				cout << "������� ������ (1..8, ����� �� ���� ��������� - ����� ������ �����):\n> ";
				cin >> index;
				index--;
			} while (index < 0 || index >= 8);//������ �� ������������� �����
			cout << "���, �������, ����� ��������, ���� �������� (DD MM YYYY)\n";
			cin >> notes[index];
			break;
		case 51/*3*/:
			//����� �� ����� � �������
			//TO DO..
			
			break;
		case 52/*4*/:
			return 0;
			break;
		}
	}
}