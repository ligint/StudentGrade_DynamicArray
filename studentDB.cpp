#include<iostream>
#include<fstream>
using namespace std;
#include"studentDB.h"
#include"studentT.h"
#define MAX 30

void studentDB::filetoArray() {
	studentT student[MAX];
	ifstream fin;
	string line;
	int elements = 0;
	fin.open("frankDB.txt");
	while (!fin.eof()) {
		getline(fin, line);
		elements++;
	}
	fin.close();

	fin.open("frankDB.txt");
	for (int i = 0; i < elements; i++) {
		fin >> student[i];
		cout << student[i] << endl;
	}
	fin.close();
}

void studentDB::writetoFile() {
	studentT student[MAX];
	ifstream fin;
	int count = 0;
	fin.open("frankDB.txt");
	while (!fin.eof()) {
		for (int i = 0; i < MAX; i++) {
			fin >> student[i];
			if (student[i].getName() == "") {
				continue;
			} else
				count++;

		}
	}
	fin.close();

	ofstream fout;
	fout.open("frankDB2.txt");
	for (int i = 0; i < count; i++) {
		fout << student[i];
		//cout<<student[i]<<endl;
	}
	fout.close();
}

void studentDB::average() {
	studentT student[MAX];
	ifstream fin;
	int sum = 0;
	int count = 0;
	//cout<<"No.of elemets in average"<<elements<<endl;
	fin.open("frankDB2.txt");
	while (!fin.eof()) {
		for (int i = 0; i < MAX; i++) {
			fin >> student[i];
			sum = sum + student[i].getScore();
			if (student[i].getName() == "") {
				continue;
			} else
				count++;
		}
	}
	fin.close();
	//int elements1=sizeof(student)/sizeof(student[0]);
	cout << "Count in average is " << count << endl;
	int average = sum / count;
	ofstream fout;
	fout.open("exam_9059.txt", ofstream::app);
	fout << "The Class average is " << average << endl;
	for (int i = 0; i < count; i++) {
		if (student[i].getScore() > average) {
			fout << student[i] << endl;
		}
	}
	fout.close();
}
void studentDB::removeStudent(string name) {
	studentT student[MAX];
	ifstream fin;
	string line;
	fin.close();
	int count = 0;
	fin.open("frankDB.txt");
	while (!fin.eof()) {
		for (int i = 0; i < MAX; i++) {
			fin >> student[i];
			if (student[i].getName() == "") {
				continue;
			} else
				count++;

		}
	}
	cout << "Count1 in remove is " << count << endl;
	fin.close();

	ofstream fout, fout1;
	fout.open("exam_9059.txt", ofstream::app);
	fout1.open("frankDB2.txt");
	fout << "After removing " << name << " the class..." << endl;
	for (int i = 0; i < count; i++) {
		//string n = student[i].getName();
		if (student[i].getName() == name) {
			student[i] = student[i + 1];
			i = i + 1;
		} else {
			fout << student[i] << endl;
			fout1 << student[i] << endl;
		}

	}
	fout.close();
	fout1.close();
}

void studentDB::addStudent(string Name, int Score) {
	studentT student[MAX];
	ifstream fin;
	string line;
	int count = 0;
	fin.open("frankDB2.txt");
	for (int i = 0; i < MAX; i++) {
		fin >> student[i];
		if (student[i].getName() == "") {
			continue;
		} else
			count++;

		//count++;
	}
	fin.close();
	cout << "Count is in add" << count << endl;
	if (count <= MAX) {
		student[count].setName(Name);
		student[count].setScore(Score);
		count = count + 1;
	} else {
		cout << "Array is full" << endl;
	}
	ofstream fout;
	ofstream fout1;
	fout.open("exam_9059.txt", ofstream::app);
	fout1.open("frankDB2.txt");
	fout << "After adding " << Name << " the class..." << endl;
	for (int i = 0; i < count; i++) {
		fout << student[i];
		fout1 << student[i];
		//cout << student[i] << endl;
	}
	fout.close();
	//fout1.close();
}

/*void studentDB::recompute() {
 studentT student[MAX];
 ifstream fin;
 int sum = 0;
 string line;
 int count = 0;
 fin.open("frankDB2.txt");
 while (!fin.eof()) {
 for (int i = 0; i < MAX; i++) {
 fin >> student[i];
 sum = sum + student[i].getScore();
 if (student[i].getName() == "") {
 continue;
 } else
 count++;
 }
 }
 fin.close();
 //int elements1=sizeof(student)/sizeof(student[0]);
 cout << "Count is in recompute " << count << endl;
 int average = sum / count;
 ofstream fout;
 fout.open("exam_9059.txt", ofstream::app);
 fout << "The Class average after recompute is " << average << endl;
 for (int i = 0; i < count; i++) {
 if (student[i].getScore() > average) {
 fout << student[i] << endl;
 }
 }
 fout.close();
 }
 */
