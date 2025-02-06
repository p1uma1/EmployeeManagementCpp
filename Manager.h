#pragma once
#include <iostream>
#include <string>
#include "Queues.h"
#include "SinglyLinkedList.h"
#include "HashTable.h"
#include <ctime>


using namespace std;

class Manager {
private:
    Singly_Linked_list attendanceRecords; // Pair of employee ID an d timestamp
    HashTable& EmployeeHashTable;
    Queues leaveRequests; // Employee ID requesting leave

public:
    // Record clock-in time
    Manager(HashTable& hashtable);

    void clockIn(string& employeeId);

    string getDateTime();

    // Record clock-out time
    void clockOut(string& employeeId);

    // Request leave
    void requestLeave(string& employeeId);
   

    // Generate attendance report
    void generateAttendanceReport();

    // Generate leave requests report
    void generateLeaveRequestsReport();

    void ManageLeaveRequests();

    void saveAttendance() ;
};