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
		cout << "====                   1. ×Ö·û¾ØÕó                        ====" << endl;
		cout << "====                   2. ÐÇ¿Õ                           ====" << endl;
		cout << "====                   3. Êó±ê»­Í¼                        ====" << endl;
		cout << "====                   4. ²Êºç                           ====" << endl;
		cout << "====                   5. ÍË³ö                           ====" << endl;
		cout << "============================================================" << endl;
		cout << "ÇëÑ¡Ôñ£º£¨1~5£©" << endl;
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
			cout << "ÎÞÐ§µÄÊäÈë£¡" << endl;
			break;
		}
		system("cls");
	}
	return 0;
}