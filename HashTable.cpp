#include "HashTable.h"



Employee::Employee() :employeeId(""), firstName(""), lastName(""), department(""), isPresent(false), next(NULL) {

}

// Add methods to manage notifications
void Employee::addNotification(string& notification) {
	notifications.insertFirst(notification);
}

Singly_Linked_list Employee::getNotifications() {
	return notifications;
}




void Employee::clearNotifications() {
	notifications.clear();
}


Employee::Employee(string& id, string& first, string& last, string& dept)
	: employeeId(id), firstName(first), lastName(last), department(dept), isPresent(false), next(NULL) {
}




void Employee::setEmployee() {
	cout << "ID        : ";
	cin >> employeeId;
	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name : ";
	cin >> lastName;
	cout << "Department: ";
	cin >> department;

}


void Employee::clockIn() { isPresent = true; }

void Employee::clockOut() { isPresent = false; }


void Employee::printEmployeeInfo() {
	cout << "\nEmployee ID: " << employeeId << "\n";
	cout << "Name       : " << firstName << " " << lastName << "\n";
	cout << "Department : " << department << "\n";
	cout << "Status     : ";
	if (isPresent) cout << "Present" << endl;
	else cout << "Absent" << "\n";
}
void Employee::Erase() {
	employeeId.clear();
	firstName.clear();
	lastName.clear();
	department.clear();
	isPresent = false;
	notifications.clear();
}
Employee Employee::operator&=(Employee& a) {   //considering notifications as empty
	employeeId = a.employeeId;

	firstName = a.firstName;
	lastName = a.lastName;
	department = a.department;
	isPresent = a.isPresent;
	next = a.next;
	return *this;
}







HashTable::HashTable() {
	Employees = new Employee * [Default_size];
	size = 0;
	for (int i = 0; i < Default_size; i++) {
		Employees[i] = NULL;
	}
}

HashTable::HashTable(int size) {
	Hash_size = size;
	Employees = new Employee * [size];

	size = 0;
}

HashTable::~HashTable() {

	for (int i = 0; i < Hash_size; i++) {
		if (Employees[i] != NULL) {
			Employee* current = Employees[i];
			while (current != nullptr) {
				Employee* temp = current;
				current = current->next;
				delete temp;
				
			}
		}
	}
	delete[] Employees;
	Employees = nullptr; // Set Employees pointer to nullptr after deletion
}




int HashTable::hash_function(string key) {

	int sum = 0;
	int index;
	for (int i = 0; i < key.size(); i++) {
		sum += key[i];
	}
	index = sum % Hash_size;
	return index;
}
void HashTable::Insert() {

	Employee* b = new Employee;
	b->setEmployee();
	if (this->foundEmployee(b->employeeId))
		cout << "This Employee id is already registered\n";  //handling duplicates
	else {
		int index = hash_function(b->employeeId);

		if (Employees[index] == NULL) {

			Employees[index] = b;
		}
		else if (Employees[index]->next == NULL) {
			Employees[index]->next = b;
		}
		else {
			//insert at first Node:::
			b->next = Employees[index]->next;
			Employees[index]->next = b;

		}
		
	}
}
void HashTable::Insert(string& id, string& fname, string& lname, string& dep) {

	Employee* b = new Employee(id, fname, lname, dep);
	if (this->foundEmployee(id))
		cout << "This Employee id is already registered\n";
	else {
		int index = hash_function(b->employeeId);

		if (Employees[index] == NULL) {

			Employees[index] = b;
		}
		else if (Employees[index]->next == NULL) {
			Employees[index]->next = b;
		}

		else {
			b->next = Employees[index]->next;
			Employees[index]->next = b;

		}
	}
}

void HashTable::delete_Employee(string Id_Arg) {  //or id
	int index = hash_function(Id_Arg);
	if (Employees[index] == NULL) cout << "No Employee found" << endl;
	else if (Employees[index]->next == NULL) Employees[index]->Erase();
	else {

		Employee* current = Employees[index];
		while (current->next != NULL && Id_Arg != current->next->employeeId) {
			current = current->next;
		}
		if (current->next == NULL) cout << "No Employee found" << endl;
		else {
			Employee* temp = current->next;
			current->next = temp->next;
			delete temp;
		}
	}
}


Employee* HashTable:: get_Contact(int i) {
	return this->Employees[i];
}



// Search Employee by ID
Employee* HashTable::SearchById(string& id) {
	int index = hash_function(id);


	Employee* current = Employees[index];

	while (current != NULL) {
		if (current->employeeId == id) {
			return current;
		}
		current = current->next;
	}


	return nullptr;


}
bool HashTable::foundEmployee(string& id) {
	int index = this->hash_function(id);


	Employee* current = Employees[index];

	while (current != NULL) {
		if (current->employeeId == id) {
			return true;
		}
		current = current->next;
	}
	return false;
}
Employee* HashTable::SearchById() {
	string id;
	cout << "Enter id:";
	cin >> id;
	int index = hash_function(id);
	Employee* current = Employees[index];

	while (current != NULL) {
		if (current->employeeId == id) {
			return current;
		}
		current = current->next;
	}

	cout << "No Employee with that id\n";
	return nullptr;

}


void HashTable::EditEmployee(string& id) {

	Employee* contact = SearchById(id);

	if (SearchById(id) != nullptr) {
		cout << "Current Detail: \n";
		SearchById(id)->printEmployeeInfo();
		cout << "\n\nEnter New Details: \n";

		delete_Employee(id);

		Employee* b = new Employee;
		b->setEmployee();
		if (b->employeeId == id) {
			Employees[hash_function(id)] = b;
			
		}
		
		else {
			int index = hash_function(b->employeeId);

			if (Employees[index] == NULL) {

				Employees[index] = b;
			}
			else if (Employees[index]->next == NULL) {
				Employees[index]->next = b;
			}
			else {
				//insert at first Node:::
				b->next = Employees[index]->next;
				Employees[index]->next = b;

			}

		}
	}
	else {
		cout << "Employee not found." << endl;
	}
}

void HashTable::EditEmployee() {
	string id;
	cout << "\nEnter the Employee Id to edit: ";
	cin >> id;
	Employee* contact = SearchById(id);

	if (SearchById(id) != nullptr) {
		cout << "Current Detail: \n";
		SearchById(id)->printEmployeeInfo();
		cout << "\n\nEnter New Details: \n";

		delete_Employee(id);

		Employee* b = new Employee;
		b->setEmployee();
		if (b->employeeId == id) {
			Employees[hash_function(id)] = b;

		}

		else {
			int index = hash_function(b->employeeId);

			if (Employees[index] == NULL) {

				Employees[index] = b;
			}
			else if (Employees[index]->next == NULL) {
				Employees[index]->next = b;
			}
			else {
				//insert at first Node:::
				b->next = Employees[index]->next;
				Employees[index]->next = b;

			}

		}
		cout << "\nEdited Successfully\n";
	}
	else {
		cout << "Employee not found." << endl;
	}
}

void HashTable::saveToFile(ofstream& file) {
	ofstream outputFile("DSA.txt");
	if (outputFile.is_open()) {
		// Write data to the file


		for (int i = 0; i < Hash_size; i++) {
			Employee* current = Employees[i];
			while (current != NULL) {

				file << current->employeeId << "," << current->firstName << "," << current->lastName << "," << current->department << "\n";


				current = current->next;
			}
		}
	}
	else {
		cerr << "Failed to open the file for writing." << endl;
	}
}

void HashTable::loadFromFile(ifstream& file) {
	string line;
	if (file.is_open()) {
		if (file.peek() == ifstream::traits_type::eof())
			cerr << "The file is empty." << endl;
		else {
			while (std::getline(file, line)) {
				string data[4];
				string substring;
				int i = 0;
				for (char c : line) {

					if (c == ',') {

						data[i] = substring;
						i++;
						// Reset the substring
						substring.clear();
					}
					else {
						substring += c;
					}
				}
				// the last substring after the last delimiter
				data[i] = substring;
				Insert(data[0], data[1], data[2], data[3]);
			}
		}
		file.close();  // Close the file when done


	}
	else {
		cerr << "Failed to open the file for reading." << endl;
	}
} //get the employee data from file

void HashTable::addNotice(string& notice) {
	for (int i = 0; i < Hash_size; i++) {
		if (Employees[i] != NULL) {
			Employees[i]->addNotification(notice);
			if (Employees[i]->next != NULL) {
				Employee* current = Employees[i]->next;
				while (current != NULL) {
					current->addNotification(notice);
					current = current->next;
				}
			}
		}
	}
}

