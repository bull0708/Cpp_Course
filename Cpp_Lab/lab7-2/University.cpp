#include "main.h"

University::University(istream &in) {
	in >> mName >> numCollege;
	for (int i = 0; i < numCollege; i++)
		mCollege.push_back(new College(in));
}

University::University() { }

University::~University() {
	for (int i = 0; i < numCollege; i++)
		delete mCollege[i];
}

void University::print(ostream &os) {
	os << "�ǮզW�١G" << mName << endl;
	/*for (int i = 0; i < numCollege; i++)
		mCollege[i]->print(os);*/
}

void University::unitTest() {
	print(cout);
}

string University::getName(string tag) {
	cout << "�п�J" << tag << "�W�١G";
	getline(cin, tag);
	return tag;
}

bool University::checkString(string s) {
	if (s == "") {
		cout << "����J������" << endl;
		return false;
	}
	return true;
}

void University::query() {
    int cmd;
	string s;
	while (1) {
		system("cls");
		cout << "[1] �d�߱Юv�򥻸��\n"
			 << "[2] �d�߽ҵ{�򥻸��\n"
			 << "[3] �d�߱Юv�}�½ҵ{\n"
			 << "[4] �d�ߨt�ҽҵ{\n"
			 << "[5] �d�ߨt�ұЮv\n"
			 << "[6] �s�W�ҵ{\n"
			 << "[7] �s�W�Юv\n"
			 << "[8] ���}�t��\n"
			 << " > ";
		cin >> cmd; cin.get();
		if (cmd == 8) return;
		else if (cmd == 1) {
			s = getName("�Юv");
			if (checkString(s))
				viewTeacher(s, cout);
		} else if (cmd == 2) {
			s = getName("�ҵ{");
			if (checkString(s))
				viewCourse(s, cout);
		} else if (cmd == 3) {

		}
		system("PAUSE");
	}
}

void University::viewTeacher(string name, ostream &os) {
	for (auto it = mCollege.begin();
			it != mCollege.end(); it++) {
		(*it)->viewTeacher(name, os);
	}
}

void University::viewCourse(string name, ostream &os) {
	for (auto it = mCollege.begin();
			it != mCollege.end(); it++) {
		(*it)->viewCourse(name, os);
	}
}