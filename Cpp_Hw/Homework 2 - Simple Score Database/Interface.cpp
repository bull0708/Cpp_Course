#include "main.h"

int displayMenu(Menu menuType, const char dataName[]) {
	char opCode;

	cout << "�п�ܤU�C�ާ@�G" << endl;
	if (menuType == Main) {
		cout << "[1] ��J��Ʈw�ɮצW��" << endl
			 << "[2] ���}�t��" << endl;
	} else if (menuType == Operation) {
		cout << "[1] �W�[�@�W�ǥ�" << endl
			 << "[2] ��@�ǥͼW�[�@�s���Z" << endl
			 << "[3] �d�ߤ@�ǥͤ��Ҧ����Z" << endl
			 << "[4] ���@�ǥͤ����Z" << endl
			 << "[5] �R���Y�@�ǥ�" << endl
			 << "[6] �C�L��ܩҦ���Ʈw�������" << endl
			 << "[7] �s�ɨ����� " << dataName << " �ɮ�" << endl
		     << "[8] ����" << endl;
	}
	do {
		cout << " > "; 
		cin >> opCode;
	} while (!(opCode > '0' && opCode <= '0' + menuType));

	return opCode - '0';
}