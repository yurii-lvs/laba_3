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
		printf("%s\n", "Меню");
		printf("%s\n", "1 - Добавить преподавателя");
		printf("%s\n", "2 - Распечатать информацию о всех преподавателях");
		printf("%s\n", "3 - Поиск преподавателя по кафедре");
		printf("%s\n", "4 - Поиск преподавателя по предмету");
		printf("%s\n", "5 - Поиск преподавателя по фио");
		printf("%s\n", "0 - Выход ");
		printf("%s", "Пункт меню: ");
		scanf("%d", &menu);
		switch (menu) {

		case 1: 
			prepod(&t, n);
			n++;
			break;

		case 2: 
			printf("%s\n", "");
			printf("%s", "Список всех преподавателей");
			printf("%s\n", "");
			printf("%s", "Фамилия");
			printf("%18s", "Имя");
			printf("%23s", "Отчество");
			printf("%22s", "Кафедра");
			printf("%28s", "Ученое звание");
			printf("%22s\n", "Предмет");
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
			printf("%s\n", "Поиск преподавателя по фио");
			char sur[100]; char im[100]; char ot[100];
			printf("%s", "Введите фамилию: ");
			while (getchar() != '\n');
			gets_s(sur);
			printf("%s", "Введите имя: ");
			gets_s(im);
			printf("%s", "Введите отчество: ");
			gets_s(ot);
			a = fio(sur, im, ot);
			for (int i = 0; i < n; i++)
			{
				if (!(a == t[i]))
				{
					cout << endl << "Преподаватель найден! " << endl;
					flag = 1;
					printf("%s\n", "");
					printf("%s", "Фамилия");
					printf("%18s", "Имя");
					printf("%23s", "Отчество");
					printf("%22s", "Кафедра");
					printf("%28s", "Ученое звание");
					printf("%22s\n", "Предмет");
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
			cout << "Такого преподавателя нет!" << endl;
			flag = 0;
			break;

		case 0: prepod::saveTeacher("data.txt", t, n);
			free(t);
			return 0;
			break;

		default:cout << "Введите нужную цифру!" << endl;

			break;

		}
	}
}