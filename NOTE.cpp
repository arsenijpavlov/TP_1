#include "NOTE.h"

NOTE::NOTE(const string& name, const string& surname, const __int64& phone, int day, int month, int year) {
	this->_Name = name;
	this->_SName = surname;
	this->_Phone = phone;
	this->birth[0] = day;
	this->birth[1] = month;
	this->birth[2] = year;
}
NOTE::NOTE(const NOTE& note) {
	this->_Name = note._Name;
	this->_SName = note._SName;
	this->_Phone = note._Phone;
	this->birth[0] = note.birth[0];
	this->birth[1] = note.birth[1];
	this->birth[2] = note.birth[2];
}
NOTE::~NOTE() {}

//get'теры и set'теры
string& NOTE::Name() {
	return _Name;
}
string& NOTE::Surname() {
	return _SName;
}
__int64& NOTE::Phone() {
	return _Phone;
}
int& NOTE::Day() {
	return birth[0];
}
int& NOTE::Month() {
	return birth[1];
}
int& NOTE::Year() {
	return birth[2];
}

//операторы
ostream& operator<<(ostream& out, const NOTE& note) {
	out << note._Name << ' ' << note._SName << ' ' << note._Phone << ' ' << note.birth[0] << '.' << note.birth[1] << '.' << note.birth[2] << '\n';
	return out;
}
istream& operator >> (istream& in, NOTE& note) {
	if (!(in >> note._Name >> note._SName >> note._Phone >> note.birth[0] >> note.birth[1] >> note.birth[2])) {
		throw Exception("Ошибка ввода");
	}
	return in;
}
NOTE& NOTE::operator =(const NOTE& note) {
	if (this == &note) return *this;
	this->_Name = note._Name;
	this->_SName = note._SName;
	this->_Phone = note._Phone;
	this->birth[0] = note.birth[0];
	this->birth[1] = note.birth[1];
	this->birth[2] = note.birth[2];
	return *this;
}