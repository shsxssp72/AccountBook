#ifndef ACCOUNTBOOK_ACCOUNTBOOK_H
#define ACCOUNTBOOK_ACCOUNTBOOK_H

#include <fstream>
#include <iostream>


using namespace std;
enum ERR_Code
{
	success,underflow,overflow
};

class AccountBook
{
public:
	AccountBook();
	ERR_Code Push(double income);
	ERR_Code Pop(double outcome);
	ERR_Code PrintCurrent(void);
	void Print(void);
	void Create(void);
	void Read(void);
	bool OpenFin(void);
	void ContinueWrite(void);
	void Time();
private:
	ofstream fout;
	ifstream fin;
	double total;

};


#endif //ACCOUNTBOOK_ACCOUNTBOOK_H
