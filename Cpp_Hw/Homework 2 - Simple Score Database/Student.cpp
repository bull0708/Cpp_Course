#include "main.h"

Student::Student() {

}

Student::~Student() {

}

void Student::setStudent(string name, string ID) {
	mName = name;
	mID = ID;
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
	os.put(mName.length());
	os.write((char*)mName.c_str(), mName.length());

	os.put(mID.length());
	os.write((char*)mID.c_str(), mID.length());
}

void Student::load(istream &fin) {
	
}