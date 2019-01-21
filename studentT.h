#ifndef STUDENTT_H_
#define STUDENTT_H_
#include<iostream>
#include<string>
using namespace std;

class studentT {
	friend ostream& operator<<(ostream&, const studentT&);
	friend istream& operator>>(istream&, studentT&);

public:
	//studentT();
	//~studentT();
	studentT(string Name = "", int Score = 0);
	void setName(string na);
	string getName();
	void setScore(int s);
	int getScore();
	void getVaules(void);
	void putVaules(void);
	bool operator==(string);
private:
	string fname;
	int score;
};

#endif /* STUDENTT_H_ */
