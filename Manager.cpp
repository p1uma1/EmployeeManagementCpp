#include "Manager.h"


    // Record clock-in time
Manager::Manager(HashTable& hashtable) : EmployeeHashTable(hashtable) {

        Queues leaveRequests(100);
    }
    void Manager::clockIn(string& employeeId) {
       

        if (EmployeeHashTable.SearchById(employeeId) != NULL) {

            EmployeeHashTable.SearchById(employeeId)->clockIn();   //status - online

            string attendance = employeeId + " in " + getDateTime();

            attendanceRecords.insertLast(attendance);

            ofstream outputFile("Logins.txt",ios::app);

            if (!outputFile.is_open()) {
                std::cerr << "Failed to open the file for appending." << std::endl;

            }
            else {


                // Append the data to the file

                outputFile << attendance << endl;

                // Close the file
                outputFile.close();
            }
        }
       
    }

    string Manager::getDateTime() {
        time_t currentTime = time(0);
       
        return ctime(&currentTime);  //return a string
    }

    // Record clock-out time
    void Manager::clockOut(string& employeeId) {
        string attendance = employeeId + " Out " + getDateTime();
        attendanceRecords.insertLast(employeeId + " Out " + getDateTime());
        EmployeeHashTable.SearchById(employeeId)->clockOut();
        ofstream outputFile("Leavings.txt",ios::app);

        if (!outputFile.is_open()) {
            std::cerr << "Failed to open the file for appending." << std::endl;

        }
        else {


            // Append the data to the file

            outputFile << attendance << endl;

            // Close the file
            outputFile.close();
        }
    }
    // Request leave
    void Manager::requestLeave(string& employeeId) {
        
        
        
        string descrip;
        cout << "Description: ";
        getline(std::cin, descrip); //ignore the input buffer (kinda)
        getline(cin, descrip);
        leaveRequests.Enqueue(employeeId, descrip);
        cout << "Request was sent successfully.";
    }



    // Generate attendance report
    void Manager::generateAttendanceReport() {
        cout << "Attendance Report: \n\n";
        attendanceRecords.printelem();
    }

    // Generate leave requests report
    void Manager::generateLeaveRequestsReport() {
        cout << "Leave Requests:\n";
        leaveRequests.print();
    }

    void Manager::ManageLeaveRequests() {
        int c = 0;

        while (c != 3) {
            if (leaveRequests.isEmpty()) { cout << "\nNo Requests.\n"; break; }
            leaveRequests.printFirst();
            cout << "\n1.Reject               2.Accept             3.Back\n";
            cout << "Enter your response: ";
            cin >> c;
            if (c == 1) {
                request temp = leaveRequests.Dequeue();
                string notifi = "\nYour leaving request was rejected.     \n"+getDateTime();
                EmployeeHashTable.SearchById(temp.id)->addNotification(notifi);

            }
            else if (c == 2) {
                request temp = leaveRequests.Dequeue();
                string notifi = "Your leaving request was accepted.\n" + getDateTime();
                EmployeeHashTable.SearchById(temp.id)->addNotification(notifi);
            }
        }
    }

    
