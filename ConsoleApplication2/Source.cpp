#include <iostream>
#include "Linked.h"
using namespace std;
void main()
{
	system("color 79");
	string y;
	Linked L;
	L.Read_File();
	cout << setw(52) << "Welcom to Bank System \n\n" << endl;
	int x;
	do
	{
		cout << "Enter 1 to 'Open New Account'\n " << endl
			<< "Enter 2 to 'Modify Account'\n " << endl
			<< "Enter 3 to 'Delete Account'\n " << endl
			<< "Enter 4 to 'Deposit'\n " << endl
			<< "Enter 5 to 'Withdraw'\n " << endl
			<< "Enter 6 to 'Transfer'\n " << endl
			<< "Enter 7 to 'View Account Information'\n " << endl
			<< "Enter 8 to 'List Bank Accounts'\n " << endl
			<< "Enter 0 to exit\n" << endl;
		cin >> x;
		switch (x)
		{
		case 1:{
				   L.Add_Account();
				   break;
		}
		case 2:{
				   L.Modify_Account();
				   break;
		}
		case 3:{
				   L.Delete_Account();
				   break;
		}
		case 4:{
				   L.Deposite();
				   break;
		}
		case 5:{
				   L.Withdraw();
				   break;
		}
		case 6:{
				   L.Transfer();
				   break;
		}
		case 7:{
				   L.Search();
				   break;
		}
		case 8:{
				   L.View_Account();
				   break;
		}
		case 0:{
				   cout << "\t\t\t\tTHE END\n" << endl;    
				   exit(0);
		}
		}
		cout << "Write 'Yes' to continue  or  'No' to exit program" << endl;
		cin >> y;
	} while (y=="yes" || y=="Yes");
	cout << "\t\t\t\tThe End" << endl << endl;
	L.Store_File();
}