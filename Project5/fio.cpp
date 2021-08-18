#include "fio.h"
#include <iostream>
using namespace std;

fio::fio() {

}
fio::fio(char* fam, char* name, char* father)
{
	setFam(fam); setName(name); setFath(father);
}
fio:: ~fio() {
}
char* fio::getFam() {
	return fam;
}
char* fio::getName() {
	return name;
}
char* fio::getFath() {
	return father;
}
void fio::setFam(char* f) {
	fam = f;
}
void fio::setName(char* n) {
	name = n;
}
void fio::setFath(char* o) {
	father = o;
}

