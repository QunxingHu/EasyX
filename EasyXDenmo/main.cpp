#include "Demo.h"
#include <iostream>

using namespace std;

int main(void)
{	
	int key;
	while (1) {
		cout << "============================================================" << endl;
		cout << "====                Welcome to EasyX                    ====" << endl;
		cout << "============================================================" << endl;
		cout << "====                   1. �ַ�����                        ====" << endl;
		cout << "====                   2. �ǿ�                           ====" << endl;
		cout << "====                   3. ��껭ͼ                        ====" << endl;
		cout << "====                   4. �ʺ�                           ====" << endl;
		cout << "====                   5. �˳�                           ====" << endl;
		cout << "============================================================" << endl;
		cout << "��ѡ�񣺣�1~5��" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
			CharacterShow();
			break;
		case 2:
			ShowStars();
			break;
		case 3:
			MouseOpt();
			break;
		case 4:
			ShowRainbow();
			break;
		case 5:
			
			return 0;
		default:
			cout << "��Ч�����룡" << endl;
			break;
		}
		system("cls");
	}
	return 0;
}