#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Node {
public:
	string elem;
	Node* next;

	Node();

	Node(string e);
};

class Singly_Linked_list
{
private:
	Node* head;
	Node* tail;
	int size;

public:
	Singly_Linked_list();

	
	void insertFirst(string elem);

	

	void insertLast(string elem);



	void insertAt(int pos, string elem);
	

	void deleteFirst();

	void deleteLast();
	

	void deleteAt(int pos);
	void deleteElm(string elm);
	void reverse();
	void printelem();
	


	void clear();


};
