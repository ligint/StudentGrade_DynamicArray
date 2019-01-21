#ifndef STUDENTDB_H_
#define STUDENTDB_H_
#include"studentT.h"

class studentDB {

public:
	void filetoArray();
	void writetoFile();
	void average();
	//void recompute();
	void removeStudent(string);
	void addStudent(string, int);

private:
	string fname;
	int score;
};

#endif /* STUDENTDB_H_ */
