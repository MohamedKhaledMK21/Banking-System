#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Bank
{
public:
	string name;
	long id;
	string telephone;
	string address;
	long amount;
};
class Node
{
public:
	Node* next;
	Bank value;

	Node();
	Node(Bank val);
};
class Linked
{
	int size;
	Node* head;
	Node* tail;
public:
	Linked();
	void Read_File();
	void Store_File();
	void Add_Account();
	void Search();
	void Delete_Account();
	void Modify_Account();
	void View_Account();
	void Deposite();
	void Withdraw();
	void Transfer();
	~Linked(void);
};


