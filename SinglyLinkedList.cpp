#include "SinglyLinkedList.h"


	Node::Node() {
		next = NULL;
	}

	Node::Node(string e) { //Overloaded Constructor
		elem = e;
		next = NULL;
	} 


	
	Singly_Linked_list::Singly_Linked_list() {
		head = NULL;
		tail = NULL;
		size = 0;

	}

	void Singly_Linked_list::insertFirst(string elem) {
		Node* temp = new Node(elem);

		if (head == NULL) {//empty list
			head = temp;
			tail = temp;

		}
		else {// non empty list
			temp->next = head;
			head = temp;
		}
		size++;
	}

	//insert Last

	void Singly_Linked_list::insertLast(string elem) {
		Node* temp = new Node(elem);

		if (head == NULL) {//empty list
			head = temp;
			tail = temp;

		}
		else {
			// non empty list
			tail->next = temp;
			tail = temp;
		}
		size++;
	}

	//Insert At

	void Singly_Linked_list::insertAt(int pos, string elem) {
		if (pos < 0 || pos > size)
			cout << "Not a valid index" << endl;
		else if (pos == 0)
			insertFirst(elem);
		else if (pos == size)
			insertLast(elem);
		else {
			Node* temp = new Node(elem);
			Node* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}

			temp->next = current->next;
			current->next = temp;
			size++;

		}
	}
	//delete first

	void Singly_Linked_list::deleteFirst()
	{
		if (head == NULL) // list is empty
			cout << "List is empty " << endl;
		else {
			Node* temp = head;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				delete temp;
				size--;
			}
		}
	}
	void Singly_Linked_list::deleteLast() {
		if (head == NULL) // list is empty
			cout << "List is empty " << endl;
		else {
			Node* temp = tail;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				Node* current = head;
				for (int i = 0; i < size - 2; i++)
				{
					current = current->next;
				}
				tail = current;
				tail->next = NULL;
				delete temp;
				size--;
			}



		}
	}
	//delete At

	void Singly_Linked_list::deleteAt(int pos) {
		if (pos < 0 || pos >= size)
			cout << "Invalid position" << endl;
		else if (pos == 0)
			deleteFirst();
		else if (pos == size - 1)
			deleteLast();
		else {
			Node* current = head;
			for (int i = 0; i < pos - 1; i++)
			{
				current = current->next;
			}
			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}
	void Singly_Linked_list:: deleteElm(string elm)
	{
		if (head == NULL) // list is empty
			cout << "List is empty " << endl;
		else {
			Node* temp = head;
			bool check = false;
			int pos = 0;
			while (temp != NULL)
			{
				if (temp->elem == elm)
				{
					temp = temp->next;
					deleteAt(pos);
					check = true;
					pos--;
				}
				else {
					temp = temp->next;
				}
				pos++;

			}
			if (not(check)) cout << "there exist no element";
		}
	}
	void Singly_Linked_list::reverse()
	{
		/*
		Node* temp = tail;
		Node* current = head;
		head = tail;
		tail = current;
		for (int j = 0; j < size-1;  j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				current = current->next;

			}
			temp->next = current;
			temp = current;
			current = tail;
		}
		temp->next = tail;
		tail->next = NULL;*/

		Node* previous = NULL;
		Node* current = head;
		Node* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		tail = head;
		head = previous;

	}
	void Singly_Linked_list::printelem()
	{
		if (head == NULL) { cout << "Empty\n"; }
		else {
			Node* current = head;
			int i = 1;
			while (current != NULL)
			{
				cout << current->elem << endl;
				current = current->next;
				i++;
			}
		}

	}



	void Singly_Linked_list::clear() {
		if (head == NULL) {}
		else {
			while (head != NULL) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
	}



