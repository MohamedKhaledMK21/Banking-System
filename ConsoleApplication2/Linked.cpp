#include "Linked.h"
Node::Node()
{
	value.name = "";
	value.id = 0;
	value.telephone = "";
	value.address = "";
	value.amount = 0;
	next = 0;
}
Node::Node(Bank val)
{
	value = val;
	next = 0;
}
Linked::Linked(void)
{
	head = tail = 0;
	size = 0;
}
void Linked::Read_File()
{
	Bank val;
	Node*T=head;
	ifstream myfile;                       
	myfile.open("data.txt");               
	myfile >> size;
		if (size==0)
		{
			return;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				myfile.ignore();
				getline(myfile, val.name);
				myfile >> val.id;
				myfile >> val.telephone;
				myfile.ignore();
				getline(myfile, val.address);
				myfile >> val.amount;
				Node*new_node = new Node(val);
				if (head == 0)
				{
					head = tail = new_node;
				}
				else
				{
					tail->next = new_node;
					tail = new_node;
				}
			}
		}
	myfile.close();
}
void Linked::Store_File()
{
	Node*T = head;
	ofstream file;                 
	file.open("data.txt");        
	file << size << endl;
	for (int i = 0; i < size; i++)
	{
		file << T->value.name << endl;
		file << T->value.id << endl;
		file << T->value.telephone << endl;
		file << T->value.address << endl;
		file << T->value.amount << endl;
		T = T->next;
	}
	file.close();
}
void Linked::Add_Account()
{
	string x;
	Node*temp = head;
	Bank val;
	cout << "Enter Account ID : ";
	cin >> val.id;
	if (size == 0)
	{
		cout << "Enter the amount You Want to Add in this Account : ";
		cin >> val.amount;
		if (val.amount > 500)
		{
			cout << "Enter Account Name : ";
			cin.ignore();
			getline(cin, val.name);

			cout << "Enter Telephone Number : ";
			cin >> val.telephone;

			cout << "Enter Account Address : ";
			cin.ignore();
			getline(cin, val.address);
			Node *new_node = new Node(val);
			if (head==0)
			{
				head = tail = new_node;
			}
			else
			{
				tail->next = new_node;
				tail = new_node;
			}
			size++;
			cout << "Account has been added successfully" << endl;
		}

		else
			cout << "You must enter amount over than 500$ to add account "<<endl;
	}
	else
	{

		for (int i = 0; i < size; i++)
		{
			if (temp->value.id == val.id)
			{
				cout << "ID is already exist" << endl;
				break;
			}
			else
			{
				cout << "Enter The Amount of Account : ";
				cin >> val.amount;

				if (val.amount > 500)
				{
					cout << "Enter Account Name : ";
					cin.ignore();
					getline(cin, val.name);

					cout << "Enter Telephone Number : ";
					cin >> val.telephone;

					cout << "Enter Account Address : ";
					cin.ignore();
					getline(cin, val.address);

					Node *new_node = new Node(val);
					if (head == 0)
					{
						head = tail = new_node;
					}
					else
					{
						tail->next = new_node;
						tail = new_node;
					}
					size++;
					cout << "Account has been added successfully" << endl;
					break;
				}

				else
				{
					cout << "You must enter amount over than 500$ to add account \n";
					break;
				}

			}
		}
	}
	cout << "Write 'Yes' to add another account" << endl << "Write 'No' to exit" << endl;
	cin >> x;
	if (x == "yes" || x == "Yes")
	{
		Add_Account();
	}
	else
	{
		cout << "The End of Adding" << endl;
	}
}
void Linked::Delete_Account()
{
	Node*T = head;
	Node*D = head;
	string x;
	long id1;
	cout << "Enter ID you want to delete : ";
	cin >> id1;
	for (int i = 0; i <= size; i++)
	{
		if (i == size)
		{
			cout << "Wrong Id" << endl << "Write 'Yes' to Enter ID again you want to delete or  'No' to exit" << endl;
			cin >> x;
			if (x == "yes" || x == "Yes")
			{
				Delete_Account();
			}
			else if (x == "No" || x == "no")
			{
				break;
			}
		}
		else if (id1==D->value.id)
		{
			if (i==0)
			{
				head = head->next;
				delete D;
				size--;
				cout << "Account has been deleted" << endl;
				break;
			}
			else if (i==size-1)
			{
				tail = T;
				delete D;
				size--;
				cout << "Account has been deleted" << endl;
				break;
			}
			T->next = D->next;
			delete D;
			size--;
			cout << "Account has been deleted" << endl;
			break;
		}
		D = D->next;
		if (i>0)
		{
			T = T->next;
		}
	}
	cout << "Write 'Yes' to continue delete" << " or " << "Write 'No' to exit" << endl;
	cin >> x;
	if (x == "yes" || x == "Yes")
	{
		Delete_Account();
	}
	else if (x == "No" || x == "no")
	{
		cout << "The End of Deleting" << endl;
	}
}
void Linked::Search()
{
	long id1;
	string x;
	cout << "Enter ID you want to search for : ";
	cin >> id1;
	Node*temp = head;
	for (int i = 0; i <= size; i++)
	{
		if (i==size)
		{
			cout << "Wrong Id" << endl << "Write 'Yes' to research  or  'No' "<<endl;
			cin >> x;
			if (x == "yes" || x == "Yes")
			{
				Search();
			}
			else if(x == "No" || x == "no")
			{
				break;
			}
		}
		else if (id1==temp->value.id)
		{
			cout << temp->value.name << "\t"
				<< temp->value.id << "\t"
				<< temp->value.telephone << "\t"
				<< temp->value.address << "\t"
				<< temp->value.amount << endl;
			break;
		}
		temp = temp->next;
	}
	cout << "Write 'Yes' to continue search" << " or " << "Write 'No' to exit" << endl;
	cin >> x;
	if (x=="yes" || x=="Yes")
	{
		Search();
	}
	else if (x == "No" || x == "no")
	{
		cout << "The End of Search" << endl;
	}
}
void Linked::Modify_Account()
{
	string y;
	int id1;
	cout << "Enter ID you want to modify : ";
	cin >> id1;
	Node*search = head;
	int x = 0;
	while (search->value.id != id1)
	{
		if (search->next == NULL)
		{
			x++;

			cout << "id not found" << endl;
			break;
		}
		else
			search = search->next;

	}
	string string1, again = "yes";
	if (x == 0)
	{
		while (again == "yes")
		{
			cout << "what are you want to change(name,adress ,telephone, id,amount)" << endl;
			cin >> string1;
			cout << "write the value you want to modify it" << endl;
			if (string1 == "name")
			{
				cin.ignore();
				getline(cin, search->value.name);
			}
			else if (string1 == "adress")
			{
				cin.ignore();
				getline(cin, search->value.address);
			}


			else if (string1 == "telephone")
				cin >> search->value.telephone;
			else if (string1 == "amount")
				cin >> search->value.amount;
			else if (string1 == "id")
				cin >> search->value.id;

			else
				cout << "error" << endl;



			cout << "write yes if you want to modify agian or write no if you don't want" << endl;
			cin >> again;
		}
	}
	cout << "Write 'Yes' to continue modify" << " or " << "Write 'No' to exit" << endl;
	cin >> y;
	if (y == "yes" || y == "Yes")
	{
		Modify_Account();
	}
	else if (y == "No" || y == "no")
	{
		cout << "The End of Modify" << endl;
	}
}
void Linked::Deposite()
{
	string x;
	int id1;
	cout << "Enter ID Account you want to deposite in : ";
	cin >> id1;
	Node*search = head;
	int y = 0;
	while (search->value.id != id1)
	{
		if (search->next == NULL)
		{
			y++;
			cout << "id not found" << endl;
			break;
		}
		else
			search = search->next;

	}

	if (y == 0)
	{

		cout << "please enter the money";
		int z = 0;
		cin >> z;
		search->value.amount += z;
		cout << "The Process has succeeded" << endl;
	}
	cout << "Write 'Yes' to continue deposite" << " or " << "Write 'No' to exit" << endl;
	cin >> x;
	if (x == "yes" || x == "Yes")
	{
		Deposite();
	}
	else if (x == "No" || x == "no")
	{
		cout << "The End of Deposite" << endl;
	}
}
void Linked::Withdraw()
{
	string x;
	long id1;
	Node*T = head;
	cout << "Enter ID Account you want to withdraw from : ";
	cin >> id1;
	for (int i = 0; i <= size; i++)
	{
		if (i == size)
		{
			cout << "Wrong Id" << endl << "Write 'Yes' to Enter ID again you want to withdraw from or  'No'" << endl;
			cin >> x;
			if (x == "yes" || x == "Yes")
			{
				Withdraw();
			}
			else if (x == "No" || x == "no")
			{
				break;
			}
		}
		else if (id1==T->value.id)
		{
			long z;
			cout << "Enter the money you want to withdraw : ";
			cin >> z;
			if (z>T->value.amount)
			{
				cout << "Error" << endl;
				break;
			}
			else
			{
				T->value.amount -= z;
				cout << "The Process has succeeded" << endl;
				break;
			}
		}
		T = T->next;
	}
	cout << "Write 'Yes' to continue withdraw" << " or " << "Write 'No' to exit" << endl;
	cin >> x;
	if (x == "yes" || x == "Yes")
	{
		Withdraw();
	}
	else if (x == "No" || x == "no")
	{
		cout << "The End of withdraw" << endl;
	}
}
void Linked::Transfer()
{
	string x;
	long id1, id2;
	Node*T = head;
	Node*S = head;
	cout << "Enter ID Account you want to withdraw from : ";
	cin >> id1;
	cout << "Enter ID Account you want to transfer for : ";
	cin >> id2;
	for (int i = 0; i <= size; i++)
	{
		if (size==0)
		{
			cout << "Please check IDs you have entered" << endl << "Write 'Yes' to Enter IDs again  or  'No' " << endl;
			cin >> x;
			if (x == "yes" || x == "Yes")
			{
				Transfer();
			}
			else if (x == "No" || x == "no")
			{
				break;
			}
		}
		else if (id1==T->value.id && id2==S->value.id)
		{
			long z;
			cout << "Enter the money you want to transfer : ";
			cin >> z;
			if (z>T->value.amount)
			{
				cout << "Error" << endl;
				break;
			}
			else
			{
				T->value.amount -= z;
				S->value.amount += z;
				cout << "The Process has succeeded" << endl;
				break;
			}
		}
		while (id1!=T->value.id)
		{
			T = T->next;
		}
		while (id2!=S->value.id)
		{
			S = S->next;
		}
	}
	cout << "Write 'Yes' to continue transfer" << " or " << "Write 'No' to exit" << endl;
	cin >> x;
	if (x == "yes" || x == "Yes")
	{
		Transfer();
	}
	else if (x == "No" || x == "no")
	{
		cout << "The End of Transfer" << endl;
	}
}
void Linked::View_Account()
{
	Node*T = head;
	cout << setw(20) << setiosflags(ios::left) << "Name";             
	cout << setw(17) << setiosflags(ios::left) << "ID";     
	cout << setw(19) << setiosflags(ios::left) << "Telephone";              
	cout << setw(13) << setiosflags(ios::left) << "Address";       
	cout << setw(5) << setiosflags(ios::left) << "Amount($)" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(20) << setiosflags(ios::left) << T->value.name;
		cout << setw(17) << setiosflags(ios::left) << T->value.id;
		cout << setw(19) << setiosflags(ios::left) << T->value.telephone;
		cout << setw(13) << setiosflags(ios::left) << T->value.address;
		cout << setw(5) << setiosflags(ios::left) << T->value.amount<<endl;
		T = T->next;
	}
}
Linked::~Linked(void)
{
}
