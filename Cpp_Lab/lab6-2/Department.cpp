#include "main.h"

Department::Department(istream &in) {
	in >> mName;
}

Department::~Department() {

}

void Department::print(ostream &os) {
	os << "    ��t�W�١G" << mName << endl;
}