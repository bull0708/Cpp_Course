#include "main.h"

Student::Student() : maxNameSize(11), maxIdSize(7) {
	mName = new char[maxNameSize];
	mID = new char[maxIdSize];
}

Student::~Student() {
	delete [] mName;
	delete [] mID;
}

void Student::setStudent(string name, string ID) {
	strcpy(mName, name.c_str());
	strcpy(mID, ID.c_str());
}

void Student::show(int mode) {
	cout << "�W�r�G" << mName << endl
		 << "�Ǹ��G" << mID << endl;
	if (!mode) cout << "�����G" << mGrade.avg() << endl;
	else {
		cout << "���Z�G";
		mGrade.show();
	}
}

string Student::getName() {
	return mName;
}

void Student::addScore() {
	if (mGrade.isFull()) {
		cout << "�W�L�ӤH�̦h���Z���ƵL�k�[�J��Ʈw��" << endl;
		return;
	}
	int score;
	
	cout << "�п�J���Z�G";
	cin >> score;
	mGrade.pushScore(score);
}

int Student::getNumScore() {
	return mGrade.getNumScore();
}

void Student::setScore(int index, int score) {
	mGrade.setScore(index - 1, score);
}

Student& Student::operator=(const Student &s) {
	mName = s.mName;
	mID = s.mID;
	mGrade = s.mGrade;
	return *this;
}

void Student::save(ostream &os) {
	os.write(mName, maxNameSize);
	os.write(mID, maxIdSize);
	mGrade.save(os);
}

void Student::load(istream &fin) {
	fin.read(mName, maxNameSize);
	fin.read(mID, maxIdSize);
	mGrade.load(fin);
}