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
public:
	NOTE(const string& name = "", const string& surname = "", const __int64& phone = 0, int day = 0, int month = 0, int year = 0);
	NOTE(const NOTE& note);
	~NOTE();

	//геттеры и сеттеры
	string& Name();
	string& Surname();
	__int64& Phone();
	int& Month();
	int& Day();
	int& Year();
	
	//операторы
	friend ostream& operator<<(ostream& out, const NOTE& note);	//вывод
	friend istream& operator>> (istream& in, NOTE& note);		//ввод
	NOTE& operator =(const NOTE& note);							//присваивание
};