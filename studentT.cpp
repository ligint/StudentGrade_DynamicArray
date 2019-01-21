#include<fstream>
#include<sstream>
#include <iostream>
#include<string>
#include"studentT.h"
#define MAX 50
using namespace std;

studentT::studentT(string Name, int Score) {
	fname = Name;
	score = Score;
}

ostream& operator<<(ostream& os, const studentT &right) {
	os << right.fname << " " << right.score << endl;
	return os;
}
istream& operator >>(istream& is, studentT &right) {
	//char c;
	is >> right.fname;
	//is>>c;
	is >> right.score;
	return is;
}

bool studentT::operator ==(string right) {
	if (fname == right) {
		return true;
	} else
		return false;

}
void studentT::setName(string na) {
	fname = na;
}

string studentT::getName() {
	return fname;
}

void studentT::setScore(int s) {
	score = s;
}

int studentT::getScore() {
	return score;
}
