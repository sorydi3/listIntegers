//#include "stdafx.h"
#include "List.h"


List::List()
{
	_inici = NULL;
}

////////////////////////////////////insert///////////
void List::Manager(int integer,char opcio) {
	Node *ant = NULL;
	bool trobat = false;
	Node *t = _inici;

		while (t && !trobat) {
			if (integer > t->enter) {
				ant = t;
				t = t->_next;
				//cout << "incrementent el bucle" << endl;
			}
			else {
				trobat = true;
				//cout << "trobat posicio " << t->enter << endl;
			}
		}

		if (!t && !_inici) {
			if (opcio == 'i') {
				//cout << "firt node" << endl;
				Node *p = new Node;
				p->enter = integer;
				p->_next = NULL;
				_inici = p;
			}
		}
		else if (!t && ant) {
			if (integer != ant->enter) {
				if (opcio == 'i') {
					//cout << "added at las position" << endl;
					addLast(integer);
				}
				else {
					if (is_there(integer)) {
						deleteLast();
					}
				}
			}
		}
		else if (t && ant) {
			if (opcio == 'i') {
				if (integer != t->enter) {
					//cout << "added beween " <<t->enter<<", "<<integer<<endl;
					addBetween(integer, ant, t);
				}
			}
			else {
				if (is_there(integer)) {
					deleteBetween(ant, t);
				}
			}
		}
		else {
			if (integer!=_inici->enter) {
				if (opcio = 'i') {
					//cout << "addet at first position" << endl;
					addFirst(integer);
				}
				else {
					if (is_there(integer)) {
						deleteFirst();
					}
				}
			}
		}
}
void List::addLast(int integer){
	Node *p = new Node;
	p->enter = integer;
	p->_next = NULL;
	Node *ant = NULL;
	Node *t = _inici;
	while (t) {
		ant = t;
		t = t->_next;
	}
	ant->_next = p;
}
////////////////////////////deletees////////////////////////
void List::deleteLast() {
	Node *ant = NULL;
	Node *t = _inici;
	bool trobat = false;
	while (t && !trobat) {
		if (t->_next != NULL) {
			ant = t;
			t = t->_next;
		}
		else {
			trobat = true;
		}
	}
	ant->_next = NULL;
	delete t;
}

void List::deleteBetween(Node *ant,Node *cur) {
	ant->_next = cur->_next;
	delete cur;
}

void List::deleteFirst() {
	Node *aux = _inici;
	_inici = _inici->_next;
	delete aux;

}
///////////////////////////////////////////////////////////////////////

void List::addBetween(int integer, Node *ant, Node *cur) {
	Node *p = new Node;
	p->enter = integer;
	p->_next = cur;
	ant->_next = p;
 }
void List::addFirst(int integer)
{
	Node *p = new Node;
	p->enter = integer;
	p->_next = _inici;
	_inici = p;
 }
bool List::is_there(int integer)const {
	Node *t = _inici;
	bool trobat = false;
	while (t && !trobat) {
		if (integer == t->enter) trobat = true;
		t = t->_next;
	}
	return trobat;
}
///////////////////////////////////////////////////////////////////////
void List::displayContent() const{
	if (_inici) {
		Node *aux = _inici;
		while (aux) {
			cout << aux->enter<<" " ;
			aux = aux->_next;
		}
		cout << endl;
	}else{
		cout << "la llista es vuit" << endl;
	}
}
//////////////////////////////////////////////////////////////////



List& List::operator=(const List& o) {
	if (this != &o) {
		allibera();
		copia(o);
	}
	return *this;
}

List::List(const List& o)
{
	//constructor copia
	cout << "constructor copia llamado" << endl;
	_inici= NULL;
	copia(o);
}
void List::copia(const List& o) {
	Node *p=NULL;
	Node *ant = NULL;
	Node *t = NULL;
	if (o._inici) {
		p = new Node;
		t = o._inici;
		p->enter = t->enter;
		p->_next = NULL;
		_inici=ant= p;
		t = t->_next;
		while (t) {
			p = new Node;
			p->enter = t->enter;
			p->_next = NULL;
			ant->_next = p;
			ant = p;
			t = t->_next;
		}
	}
}
List::~List()
{
	allibera();
}

void List::allibera() {
	while (_inici) {
		Node *t = _inici;
		_inici = _inici->_next;
     	delete t;
	}
}
