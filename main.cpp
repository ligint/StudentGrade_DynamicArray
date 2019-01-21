#include"studentT.h"
#include"studentDB.h"
using namespace std;
int main() {
	studentDB s;
	s.filetoArray();
	s.writetoFile();
	s.average();
	s.removeStudent("Frank");
	s.addStudent("Chris", 89);
	//s.recompute();
	s.average();
}

