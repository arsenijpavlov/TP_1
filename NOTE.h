#include <iostream>
#include <string>
#include "Exception.h"

#pragma once
using namespace std;

class NOTE {
private:
	string _Name;
	string _SName;
	__int64 _Phone;
	int birth[3];
	/*__int64 date;	/*	[0] - day
						[1] - month
						[2] - year */
					//	5+4+12 = 21 ��� == 6 ����
public:
	//get
	//set
	NOTE(const string& name = "", const string& surname = "", const __int64& phone = 0, int day = 0, int month = 0, int year = 0);
	NOTE(const NOTE& note);
	~NOTE();
	void sort();

	//������� � �������
	string& Name();
	string& Surname();
	__int64& Phone();
	int& Month();
	int& Day();
	int& Year();
	
	//���������
	friend ostream& operator<<(ostream& out, const NOTE& note);	//�����
	friend istream& operator>> (istream& in, NOTE& note);		//����
	NOTE& operator =(const NOTE& note);							//������������
};