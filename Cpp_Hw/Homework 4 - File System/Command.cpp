#include "Command.h"
#include <iostream>
using namespace std;

Command::Command(void) {
	mRoot = new EntryFolder("root", NULL);
	mNowFolder = mRoot;
}

Command::~Command(void) { }

void Command::query() {
	int cmd;
	while (true) {
		cout << "�ثe��Ƨ� " << mNowFolder->getPath() << "/" << endl;
		cout << "[ 1] �^��W�@�h��Ƨ�\t[ 8] �j�M�ɮשθ�Ƨ�\n"
			<< "[ 2] �i�J�U�@�h��Ƨ�\t[ 9] �C�L�ثe��ƧX���ɮ�\n"
			<< "[ 3] �W�[�@���ɮ�\t[10] �C�L�ثe��ƧX���ɮ�(�]�t�l��ƧX)\n"
			<< "[ 4] �C�L�ɮפ��e\t[11] �j�M�ɮפ��r��\n"
			<< "[ 5] �W�[�@�Ӹ�Ƨ�\t[12] �ɮשθ�ƧX�j�p\n"
			<< "[ 6] �R���ɮ�\t\t[13] �����ާ@\n"
			<< "[ 7] �R����Ƨ��Τl��Ƨ�\n > ";
		cin >> cmd;
		switch(cmd) {
		case  1:
			exitFolder(); break;
		case  2:
			cdFolder(); break;
		case  3:
			addFile(); break;
		case  4:
			printFile(); break;
		case  5:
			addFolder(); break;
		case  6:
			deleteFile(); break;
		case  7:
			deleteFolder(); break;
		case 13:
			return ; break;
		}
		system("PAUSE");
		system("CLS");
	}
}

void Command::exitFolder() {
	mNowFolder = mNowFolder->lastFolder();
}

void Command::addFile() {
	string name = getName(false), content;
	if (!isEmpty(mNowFolder->search(name, false))) {
		cout << "�w�s�b�ۦP�W�٪��ɮ�" << endl;
		return ;
	}
	cout << "�п�J�ɮפ��e�G";
	cin >> content;
	EntryFile *newFile = new EntryFile(name, content);
	mNowFolder->addEntry(newFile);
}

void Command::addFolder() {
	string name = getName(true);
	if (!isEmpty(mNowFolder->search(name, true))) {
		cout << "�w�s�b�ۦP�W�٪���Ƨ�" << endl;
		return ;
	}
	EntryFolder *newFolder = new EntryFolder(name, mNowFolder);
	mNowFolder->addEntry(newFolder);
}

string Command::getName(bool isFolder) {
	string name;
	if (isFolder) cout << "�п�J��Ƨ��W�١G";
	else cout << "�п�J�ɮצW�١G";
	cin >> name;
	return name;
}

void Command::cdFolder() {
	string name = getName(true);
	auto result = mNowFolder->search(name, true);
	if (!isEmpty(result)) mNowFolder = (EntryFolder*)*result;
	else cout << "�L����Ƨ�" << endl;
}

void Command::printFile() {
	string name = getName(false);
	auto result = mNowFolder->search(name, false);
	if (!isEmpty(result)) ((EntryFile*)*result)->print();
	else cout << "�L���ɮ�" << endl;
}

void Command::deleteFile() {
	string name = getName(false);
	auto result = mNowFolder->search(name, false);
	if (!isEmpty(result)) mNowFolder->removeEntry(result);
}

bool Command::isEmpty(EntryIt it) {
	if (it == mNowFolder->dump()) return true;
	return false;
}

void Command::deleteFolder() {

}