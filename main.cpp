#include <iostream>
#include "AccountBook.h"


using namespace std;

int main()
{
	AccountBook myAccountBook;
	cout<<"Welcome to the Account Book program."<<endl;
	myAccountBook.ContinueWrite();
	cout<<"The valid commanders are: "<<endl
		<<"'S' for save money"<<endl
		<<"'D' for draw money"<<endl
		<<"'R' for print the whole account book;"<<endl
		<<"'P' for print the current money"<<endl
		<<"'C' for overwrite the file and create a new one"<<endl;
	for(;;)
	{
		char commander;
		bool flag;
		do
		{
			cout<<"Please enter a valid commander:"<<endl;
			cin>>commander;
			flag=(commander=='S'||commander=='D'||commander=='R'||commander=='P'||commander=='Q'||commander=='C');
		}
		while(!flag);
		double ToIncome=0;
		double ToOutcome=0;
		if(commander=='Q')
			break;
		switch(commander)
		{
			case 'S':
				cout<<"Please enter the amount you want to save:"<<endl;
				cin>>ToIncome;
				myAccountBook.Push(ToIncome);
				break;
			case 'D':
				cout<<"Please enter the amount you want to draw:"<<endl;
				cin>>ToOutcome;
				myAccountBook.Pop(ToOutcome);
				break;
			case 'R':
				myAccountBook.PrintCurrent();
				myAccountBook.ContinueWrite();
				break;
			case 'P':
				myAccountBook.Print();
				break;
			case 'C':
				cout<<"WARNING-Create process will delete the current file."<<endl;
				cout<<"Are you sure to create a new account book? (Y/N)"<<endl;
				char confirm=0;
				cin>>confirm;
				if(confirm=='Y'||confirm=='y')
					myAccountBook.Create();
				break;
		}
	}
	return 0;
}