#pragma once
class fio
{
	friend class prepod;
public:
	fio(char* fam, char* name, char* father);
	fio();
	~fio();
	char* getFam();
	char* getName();
	char* getFath();
	void setFam(char* f);
	void setName(char* n);
	void setFath(char* o);
	char* fam;
	char* name;
	char* father;
};