#define _CRT_SECURE_NO_WARNINGS
#include "fio.h"
#include <iostream>
using namespace std;
#include "prepod.h"

int prepod::count = 0;

std::ostream& operator<< (std::ostream& os, prepod& temp)
{
	printf("%s", temp.fi.fam);
	for (int j = 0; j < 15 - strlen(temp.fi.fam) + 7; j++) printf("%s", " ");
	printf("%s", temp.fi.name);
	for (int j = 0; j < 15 - strlen(temp.fi.name) + 3; j++) printf("%s", " ");
	printf("%s", temp.fi.father);
	int s = 0;
	for (int j = 0; j < 15 - strlen(temp.fi.father) + 8; j++) printf("%s", " ");
	if (temp.departament == 1) printf("%s", "�����");
	if (temp.departament == 2) printf("%s", "��");
	if (temp.departament == 3) printf("%s", "��");
	if (temp.departament == 1) s = 5;
	if (temp.departament == 2) s = 2;
	if (temp.departament == 3) s = 2;
	for (int j = 0; j < 15 - s + 7; j++) printf("%s", " ");
	if (temp.status == 1) printf("%s", "�������������");
	if (temp.status == 2) printf("%s", "������");
	if (temp.status == 3) printf("%s", "������ ����");
	if (temp.status == 1) s = 13;
	if (temp.status == 2) s = 6;
	if (temp.status == 3) s = 11;
	for (int j = 0; j < 15 - s + 13; j++) printf("%s", " ");
	cout << temp.subj << endl;
	return os;
}  

int operator==(fio& a, prepod& b) {
	return (strcmp(a.fam, b.fi.fam) && strcmp(a.name, b.fi.fam) && strcmp(a.father, b.fi.fam));
}

prepod::prepod(int departament, fio fi, int status) {
	setDep(departament);
	setFio(fi);
	setSt(status);
}
prepod::prepod(prepod** t, int n) {
	*t = (prepod*)realloc(*t, (n + 1) * sizeof(prepod));
	printf("%s\n", "");
	printf("%s\n", "����������� ������ �������������");
	printf("%s", "������� ������� (1-�����, 2-��, 3-��): ");
	cin >> t[0][n].departament;
	char buff[100];
	while (getchar() != '\n');
	printf("%s", "������� �������: ");
	gets_s(buff);
	t[0][n].fi.fam = (char*)malloc(strlen(buff) + 1);
	strcpy(t[0][n].fi.fam, buff);
	printf("%s", "������� ���: ");
	gets_s(buff);
	t[0][n].fi.name = (char*)malloc(strlen(buff) + 1);
	strcpy(t[0][n].fi.name, buff);
	printf("%s", "������� ��������: ");
	gets_s(buff);
	t[0][n].fi.father = (char*)malloc(strlen(buff) + 1);
	strcpy(t[0][n].fi.father, buff);
	printf("%s", "������� ������ ������ (1- �������������, 2- ������,3-������ ����): ");
	cin >> t[0][n].status;
	printf("%s", "������� ������� (���� �����): ");
	while (getchar() != '\n');
	gets_s(buff);
	t[0][n].subj = (char*)malloc(strlen(buff) + 1);
	strcpy(t[0][n].subj, buff);
}
prepod::~prepod() {
}
int prepod::getDep() {
	return departament;
}

fio prepod::getFio() {
	return fi;
}
int prepod::getSt() {
	return status;
}
void prepod::setDep(int d) {
	departament = d;
}
void prepod::setFio(fio f) {
	fi = f;
}
void prepod::setSt(int s) {
	status = s;
}



void prepod::loadTeacher(const char* fileName, prepod** t, int& n) {
	FILE* f;
	char buff[100];
	if ((fopen(fileName, "r+")) == NULL) {
		printf("%s", "����� ��� ��������\n");
		f = fopen(fileName, "w+");
		fclose(f);
	}
	f = fopen(fileName, "r");
	for (int i = 0; !feof(f); i++) {
		*t = (prepod*)realloc(*t, (n + 1) * sizeof(prepod));
		fscanf(f, "%s", buff);
		t[0][i].departament = atof(buff);
		fscanf(f, "%s", buff);
		t[0][i].fi.fam = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].fi.fam, buff);
		fscanf(f, "%s", buff);
		t[0][i].fi.name = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].fi.name, buff);
		fscanf(f, "%s", buff);
		t[0][i].fi.father = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].fi.father, buff);
		fscanf(f, "%s", buff);
		t[0][i].status = atof(buff);
		fscanf(f, "%s", buff);
		t[0][i].subj = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].subj, buff);
		n++;
	}
	fclose(f);
}

void prepod::saveTeacher(const char* fileName, prepod* t, int n) {
	FILE* f;
	f = fopen(fileName, "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d ", t[i].departament);
		fprintf(f, "%s ", t[i].fi.fam);
		fprintf(f, "%s ", t[i].fi.name);
		fprintf(f, "%s ", t[i].fi.father);
		fprintf(f, "%d ", t[i].status);
		fprintf(f, "%s ", t[i].subj);
	}
	fclose(f);
}

void prepod::searchDep(prepod* t, int n)
{
	printf("%s\n", "");
	printf("%s\n", "����� �� �������");
	int temp;
	printf("%s", "������� ������� (1-�����, 2-��, 3-��): ");
	scanf("%d", &temp);
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
	for (int i = 0; i < n; i++) {
		if (t[i].departament == temp) cout<<t[i];
	}
	for (int i = 0; i < 140; i++) {
		printf("%s", "-");
	}
	printf("%s\n", "");
}

void prepod::searchSubject(prepod* t, int n)
{
	printf("%s\n", "");
	printf("%s\n", "����� �� ��������");
	char buff[100];
	char* temp;
	printf("%s", "������� �������: ");
	scanf("%s", buff);
	temp = (char*)malloc(strlen(buff) + 1);
	strcpy(temp, buff);
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
	for (int i = 0; i < n; i++) {
		if (strcmp(t[i].subj, temp)==0) cout<<t[i];
	}
	for (int i = 0; i < 140; i++) {
		printf("%s", "-");
	}
	printf("%s\n", "");
}


