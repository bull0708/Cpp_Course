#include "main.h"


Course::Course(istream &in) {
	in >> mName >> mID >> mYear >> mSemester >> mTeacher;
}


Course::~Course(void) { }

void Course::print(ostream &os) {
	os << "      �ҵ{�W�١G" << mName << endl
		<< "      �ҵ{�N���G" << mID << endl
		<< "      �Ǧ~�סG" << mYear << endl
		<< "      �Ǵ��G" << mSemester << endl
		<< "      �}�ұЮv�G" << mTeacher << endl;
}