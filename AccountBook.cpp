#include "AccountBook.h"
#include <ctime>


AccountBook::AccountBook()
{
	total=0;
}
void AccountBook::Create()
{
	fout.close();
	total=0;
	fout.open("AccountBook.txt",ios::trunc);
	cout<<"Successfully created."<<endl;
}
ERR_Code AccountBook::Push(double income)
{
	if(total+income<0)
	{
		cerr<<"ERROR-Overflow"<<endl;
		return overflow;
	}
	else
	{
		total+=income;
		Time();
		fout<<"Deposit money: RMB "<<income<<"."<<endl;
		fout<<"Current Money: RMB "<<total<<endl<<endl;
		cout<<"Successfully saved."<<endl;
		return success;
	}
}
ERR_Code AccountBook::Pop(double outcome)
{
	if(total-outcome<0)
	{
		cerr<<"ERROR-Underflow"<<endl;
		return underflow;
	}

	else
	{
		total-=outcome;
		cout<<"Please enter the purpose:"<<endl;
		string purpose;
		cin>>purpose;
		Time();
		fout<<"Draw money: RMB "<<outcome<<"."<<endl;
		fout<<"Purpose: "<<purpose<<endl<<"Current Money: RMB "<<total<<endl<<endl;
		cout<<"Successfully drawn."<<endl;
		return success;
	}
}
void AccountBook::Print()
{
	ContinueWrite();
	cout<<"Current Money: RMB "<<total<<endl;
}
bool AccountBook::OpenFin()
{
	fin.open("AccountBook.txt");
	if(!fin.is_open())
	{
		cerr<<"ERROR-File cannot open"<<endl;
		return false;
	}
	return true;
}
void AccountBook::Read()
{
	fin.close();
	if(!OpenFin())
	{
		cerr<<"ERROR-No files to read"<<endl;
		return;
	}
	else
	{
		char list[100]={0};
		for(;!fin.eof();)
		{
			fin.getline(list,100);
			cout<<list<<endl;
		}
	}
}
ERR_Code AccountBook::PrintCurrent()
{
	fout.close();;
	Read();
	fin.close();
}
void AccountBook::ContinueWrite()
{
	fout.close();
	char list[50]={0};
	double tmp=0;
	if(!OpenFin())
	{
		cerr<<"ERROR-No files to read"<<endl;
		return;
	}
	for(;!fin.eof();)
	{
		fin.getline(list,50);
		string obj=list;
		if(obj.compare(0,14,"Current Money:")==0)
		{
			obj.erase(0,19);
			tmp=stod(obj);
		}
	}
	fin.close();
	total=tmp;
	if(fout.is_open())
	{
		cerr<<"ERROR-File has been opened for write"<<endl;
		return;
	}
	fout.open("AccountBook.txt",ios::app);
}
void AccountBook::Time()
{
	const time_t t=time(NULL);
	tm *current_time=localtime(&t);
	fout<<1900+current_time->tm_year<<"/"<<current_time->tm_mon+1<<"/"<<current_time->tm_mday<<" ";
	switch(current_time->tm_wday)
	{
		case 0:
			fout<<"Mon";
			break;
		case 1:
			fout<<"Tue";
			break;
		case 2:
			fout<<"Wed";
			break;
		case 3:
			fout<<"Tur";
			break;
		case 4:
			fout<<"Fri";
			break;
		case 5:
			fout<<"Sat";
			break;
		case 6:
			fout<<"Sun";
			break;
	}
	fout<<" "<<current_time->tm_hour<<":"<<current_time->tm_min<<":"<<current_time->tm_sec<<endl;

}