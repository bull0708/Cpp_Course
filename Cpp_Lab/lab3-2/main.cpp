#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int main()
{
	int i, nItems;
	struct SaleItem *items[100];

	initialize(&nItems, items);

	for (i = 0; i < nItems; i++)
		(*items[i]->print)(items[i]);
	// �Цb���B���g�@�Ӱj��ӦC�L�Ҧ� nItems �Ӱӫ~
	// �����e�A�o�Ӱj�骺���e���ӥu���@��²�檺�禡
	// �I�s�A�q�q�z�L��� print �o�Ө禡�����ܼƨөI�s�A
	// �]�����ɤw�g�N�Ҧ��ӫ~��H�Ƭݦ��O�@�P�� SaleItem 
	// ���F��F

	for (i = 0; i < nItems; i++)
		free(items[i]); // �Ъ`�N���B�]���ݭn�Ϥ���ƪ�����

	printf("Press enter to continue...");
	getchar();
}