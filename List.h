#pragma once
#include <iostream>
using namespace std;
class List
{
public:
	//constructor
	List();
	//consultors
	void displayContent()const;
	bool is_there(int integer)const;
	//modificadors
	void Manager(int integer,char opcio);
	void deleteNode();
		//constructor de copia
	List(const List& o);
	//operador d'assignacio
	List& operator=(const List& o);
	//destructor
	
	~List();
private:
	struct Node
	{
		int enter;
		Node *_next;
	};
	Node *_inici;
	void allibera();
	void copia(const List& o);
	void addLast(int integer);
	void deleteLast();
	void addBetween(int integer,Node *ant,Node *cur);
	void deleteBetween(Node *ant,Node *cur);
	void addFirst(int integer);
	void deleteFirst();
};

