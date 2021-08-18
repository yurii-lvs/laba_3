#pragma once
#include"fio.h"
class prepod
{
private:
	int departament;
	fio fi;
	int status;
	char* subj;
public:
	friend std::ostream& operator<<(std::ostream&, prepod&);
	friend int operator==(fio& a, prepod& b);
	static int count;
	prepod(int departament, fio fi, int status);
	prepod(prepod** t, int n);
	~prepod();
	int getDep();
	fio getFio();
	int getSt();
	void setDep(int d);
	void setFio(fio f);
	void setSt(int s);
	void searchDep(prepod* t, int n);
	void searchSubject(prepod* t, int n);
	static void loadTeacher(const char* fileName, prepod** t, int& n);
	static void saveTeacher(const char* fileName, prepod* t, int n);
};
