#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "prepod.h"
#include "fio.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	prepod* t;
	FILE* f;
	int n = 0, menu;
	t = (prepod*)malloc(n * sizeof(prepod));
	prepod::loadTeacher("data.txt", &t, n);
	n--;
	fio a;
	bool flag = 0;
	while (1) {
		printf("%s\n", "");
		printf("%s\n", "����");
		printf("%s\n", "1 - �������� �������������");
		printf("%s\n", "2 - ����������� ���������� � ���� ��������������");
		printf("%s\n", "3 - ����� ������������� �� �������");
		printf("%s\n", "4 - ����� ������������� �� ��������");
		printf("%s\n", "5 - ����� ������������� �� ���");
		printf("%s\n", "0 - ����� ");
		printf("%s", "����� ����: ");
		scanf("%d", &menu);
		switch (menu) {

		case 1: 
			prepod(&t, n);
			n++;
			break;

		case 2: 
			printf("%s\n", "");
			printf("%s", "������ ���� ��������������");
			printf("%s\n", "");
			printf("%s", "�������");
			printf("%18s", "���");
			printf("%23s", "��������");
			printf("%22s", "�������");
			printf("%28s", "������ ������");
			printf("%22s\n", "�������");
			for (int i = 0; i < 140; i++) {
				printf("%s", "-");
			}
			printf("%s\n", "");
			for (int i = 0; i < n; i++) cout << t[i];
			for (int i = 0; i < 140; i++) {
				printf("%s", "-");
			}
			printf("%s\n", "");
			break;

		case 3: t[0].searchDep(t, n);

			break;


		case 4: t[0].searchSubject(t, n);

			break;

		case 5:
			printf("%s\n", "");
			printf("%s\n", "����� ������������� �� ���");
			char sur[100]; char im[100]; char ot[100];
			printf("%s", "������� �������: ");
			while (getchar() != '\n');
			gets_s(sur);
			printf("%s", "������� ���: ");
			gets_s(im);
			printf("%s", "������� ��������: ");
			gets_s(ot);
			a = fio(sur, im, ot);
			for (int i = 0; i < n; i++)
			{
				if (!(a == t[i]))
				{
					cout << endl << "������������� ������! " << endl;
					flag = 1;
					printf("%s\n", "");
					printf("%s", "�������");
					printf("%18s", "���");
					printf("%23s", "��������");
					printf("%22s", "�������");
					printf("%28s", "������ ������");
					printf("%22s\n", "�������");
					for (int i = 0; i < 140; i++) {
						printf("%s", "-");
					}
					printf("%s\n", "");
					cout << t[i];
					for (int i = 0; i < 140; i++) {
						printf("%s", "-");
					}
					printf("%s\n", "");
					break;
				}
			}
			if(flag==0)
			cout << "������ ������������� ���!" << endl;
			flag = 0;
			break;

		case 0: prepod::saveTeacher("data.txt", t, n);
			free(t);
			return 0;
			break;

		default:cout << "������� ������ �����!" << endl;

			break;

		}
	}
}