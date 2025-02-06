#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "SinglyLinkedList.h"

using namespace std;
class Employee
{
public:
	string employeeId;
	string firstName;
	string lastName;
	string department;
	bool isPresent;
	Employee* next;
	Singly_Linked_list notifications; // Add this line to store notifications
	Employee();

	// Add methods to manage notifications
	void addNotification(string& notification);

	Singly_Linked_list getNotifications();


	void clearNotifications();

	Employee(string& id, string& first, string& last, string& dept);



	// Setter methods
	void setEmployee();

	// Record attendance (clock in/clock out)
	void clockIn();

	void clockOut();

	// Print employee information
	void printEmployeeInfo();

	void Erase();
	Employee operator&=(Employee& a);
};








class HashTable
{
private:

	static const int Default_size = 1009;  //prime number
	int Hash_size = Default_size;
	Employee** Employees;
	const double loadFactorThreashold = 0.9;
	int size;
	  
	

public:
	HashTable();

	HashTable(int size);

	~HashTable();




	int hash_function(string key);
	void Insert();

	void Insert(string& id, string& fname, string& lname, string& dep);

	void delete_Employee(string Id_Arg);

	
	Employee* get_Contact(int i);

	

	// Search Employee by ID
	Employee* SearchById(string& id);

	bool foundEmployee(string& id);

	Employee* SearchById();

	// Edit 
	void EditEmployee(string& id);

	void EditEmployee();

	void saveToFile(ofstream& file);

	void loadFromFile(ifstream& file);

	void addNotice(string& notice);


};
