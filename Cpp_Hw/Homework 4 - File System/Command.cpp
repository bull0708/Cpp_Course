#include "Command.h"
#include <iostream>
using namespace std;

Command::Command(void) {
	ifstream fin("data.dat");
	int id;
	if (fin) {
		fin >> id;
		if (id != 1) cout << "錯誤的檔案格式" << endl;
		else mRoot = new EntryFolder(fin, NULL);
	} else mRoot = new EntryFolder("root", NULL);
	mNowFolder = mRoot;
}

Command::~Command(void) { }

void Command::query() {
	int cmd;
	while (true) {
		cout << "目前資料夾 " << mNowFolder->getPath() << "/" << endl;
		cout << "[ 1] 回到上一層資料夾\t[ 8] 搜尋檔案或資料夾\n"
			<< "[ 2] 進入下一層資料夾\t[ 9] 列印目前資料匣內檔案\n"
			<< "[ 3] 增加一個檔案\t[10] 列印目前資料匣內檔案(包含子資料匣)\n"
			<< "[ 4] 列印檔案內容\t[11] 搜尋檔案內字串\n"
			<< "[ 5] 增加一個資料夾\t[12] 檔案或資料匣大小\n"
			<< "[ 6] 刪除檔案\t\t[13] 結束操作\n"
			<< "[ 7] 刪除資料夾及子資料夾\n > ";
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
		case  8:
			searchEntry(); break;
		case  9:
			printList(false); break;
		case 10:
			printList(true); break;
		case 11:
			searchFile(); break;
		case 12:
			getSize(); break;
		case 13:
			save(); return ;
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
		cout << "已存在相同名稱的檔案" << endl;
		return ;
	}
	cout << "請輸入檔案內容：";
	cin >> content;
	EntryFile *newFile = new EntryFile(name, content);
	mNowFolder->addEntry(newFile);
}

void Command::addFolder() {
	string name = getName(true);
	if (!isEmpty(mNowFolder->search(name, true))) {
		cout << "已存在相同名稱的資料夾" << endl;
		return ;
	}
	EntryFolder *newFolder = new EntryFolder(name, mNowFolder);
	mNowFolder->addEntry(newFolder);
}

string Command::getName(bool isFolder) {
	string name;
	if (isFolder) cout << "請輸入資料夾名稱：";
	else cout << "請輸入檔案名稱：";
	cin >> name;
	return name;
}

string Command::reqName(string msg) {
	string name;
	cout << "請輸入" << msg << "：";
	cin >> name;
	return name;
}

void Command::cdFolder() {
	string name = getName(true);
	auto result = mNowFolder->search(name, true);
	if (!isEmpty(result)) mNowFolder = (EntryFolder*)*result;
	else cout << "無此資料夾" << endl;
}

void Command::printFile() {
	string name = getName(false);
	auto result = mNowFolder->search(name, false);
	if (!isEmpty(result)) ((EntryFile*)*result)->print();
	else cout << "無此檔案" << endl;
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
	string name = getName(true);
	auto result = mNowFolder->search(name, true);
	if (!isEmpty(result)) {
		(*result)->removeEntry();
		mNowFolder->removeEntry(result);
	}
}

void Command::searchEntry() {
	string name = reqName("檔案或資料夾名稱");
	auto result = mNowFolder->search(name, true);
	if (isEmpty(result)) result = mNowFolder->search(name, false);
	if (isEmpty(result))
		cout << "不存在此名稱的檔案或資料夾\n";
	else 
		cout << mNowFolder->getPath() << "/" << name << endl;
}

void Command::printList(bool printFolder) {
	mNowFolder->printList(0, printFolder);
}

void Command::searchFile() {
	string content = reqName("欲搜尋的字串");
	auto result = mNowFolder->searchFile(content);
	if (!isEmpty(result)) {
		cout << mNowFolder->getPath() << "/" << (*result)->getName() << endl
			<< "檔案內容：" << ((EntryFile*)*result)->getContent() << endl;
	} else cout << "當前資料夾無檔案包含該字串" << endl;
}

void Command::getSize() {
	string target;
	cin.get();
	cout << "請輸入檔案或資料夾名稱（不輸入則為當前資料夾）：";
	getline(cin, target);
	if (target == "") cout << mNowFolder->getSize() << " Bytes\n";
	else {
		auto result = mNowFolder->search(target, true);
		if (isEmpty(result)) result = mNowFolder->search(target, false);
		if (isEmpty(result))
			cout << "不存在此名稱的檔案或資料夾\n";
		else 
			cout << (*result)->getSize() << " Bytes\n";
	}
}

void Command::save() {
	ofstream fout("data.dat");
	mRoot->save(fout);
}