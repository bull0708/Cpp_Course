#include "main.h"

Class::Class() : maxStudentNum(100), mNumStudent(0) {
	mStudent = new Student[maxStudentNum];
}

Class::~Class() {
	delete [] mStudent;
}

void Class::addStudent() {
	string name, ID;
	cout << "�п�J�ǥͩm�W�G";
	cin >> name;
	cout << "�п�J�ǥ;Ǹ��G";
	cin >> ID;
	mStudent[mNumStudent++].setStudent(name, ID);
	cout << "�s�W����" << endl;
}

void Class::addScore() {
	int i = findStudent();
	if (i != -1) mStudent[i].addScore();
	cout << "�s�W����" << endl;
}

void Class::show() {
	if (isEmpty()) return;
	for (int i = 0; i < mNumStudent; i++) {
		mStudent[i].show(0);
	}
}

void Class::showStudent() {
	if (isEmpty()) return;
	int i = findStudent();
	if (i != -1) mStudent[i].show(1);
}

int Class::findStudent() {
	string name; int i;
	cout << "�п�J�ǥͩm�W�G";
	cin >> name;
	for (i = 0; i < mNumStudent; i++)
		if (name == mStudent[i].getName()) break;
	
	if (i == mNumStudent) {
		cout << "�d�L���ǥ�" << endl;
		return -1;
	}
	return i;
}

void Class::fixScore() {
	int i = findStudent(), select, score;
	if (!mStudent[i].getNumScore()) {
		cout << "���ǥͩ|����J�����Z";
		return;
	}
	mStudent[i].show(1);
	cout << "�аݭn�ק�ĴX�����Z�G";
	do {
		cin >> select;
	    if (select > mStudent[i].getNumScore() || select < 1)
		    cout << "�L�����Z�A�Э��s��J�G";
	} while (select > mStudent[i].getNumScore() || select < 1);
	cout << "�п�J���Z�G";
	cin >> score;
	mStudent[i].setScore(select, score);
	cout << "���Z�ק粒��" << endl;
}

void Class::deleteStudent() {
	if (isEmpty()) return;
	int i = findStudent();
	mNumStudent--;
	mStudent[i] = mStudent[mNumStudent];
}

bool Class::isEmpty() {
	if (!mNumStudent) {
		cout << "��Ʈw���S��������" << endl;
		return true;
	}
	return false;
}

void Class::save() {
	ofstream fout(className, ios::out, ios::binary);
	fout.put(mNumStudent);
	for (int i = 0; i < mNumStudent; i++)
		mStudent[i].save(fout);
}

void Class::load(char className[]) {
	ifstream fin(className, ios::in | ios::binary);
	if (!fin) return;
	char tmp;
	fin.get(tmp); mNumStudent = tmp;
	for (int i = 0; i < mNumStudent; i++)
	    mStudent[i].load(fin);
}

void Class::query() {
	int cmd;
	do {
		cmd = displayMenu(Main, "none");
		if (cmd == 1) {
			cout << "�п�J�ɮצW�١G";
			cin >> className;
			load(className);
			system("CLS");
			do {
				cmd = displayMenu(Operation, className);
				if (cmd == 1) addStudent();
				else if (cmd == 2) addScore();
				else if (cmd == 3) showStudent();
				else if (cmd == 4) fixScore();
				else if (cmd == 5) deleteStudent();
				else if (cmd == 6) show();
				else if (cmd == 7) save();
				if (cmd != 7 && cmd != 8) system("PAUSE");
				system("CLS");
			} while (cmd != 8 && cmd != 7);
		}
	} while (cmd != 2);
}