// ListIntegers.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include"List.h"

using namespace std;

int main()
{
	List list;
	cout << "Entra la llista d'enters acabada amb 0:" << endl;
	int enter;
	cin >> enter;
	while (enter != 0) {
		list.Manager(enter,'i');
		cin >> enter;
	}
	//list.displayContent();
	cout << "Entra un enter per a ser esborrat:" << endl;
	cin >> enter;
	cout << "Llista ordenada sense repetits: " << endl;
	list.displayContent();
	if (list.is_there(enter)) {
		cout << "L'element "<<enter<< " existeix a la llista" << endl;
	}
	else {
		cout << "L'element " << enter << " no hi es a la llista" << endl;
	}
	cout << "Llista ordenada sense el possible element a esborrar:" << endl;
	list.Manager(enter, 'd');
	list.displayContent();
    return 0;
}
