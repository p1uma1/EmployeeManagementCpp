#include "Manager.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "HashTable.h"


void hold() {
    int hold = 0;
    while (hold != 1) {
        cout << "\nPress 1 to go back: ";
        cin >> hold;
    }
}

void clearScreen() {
    for (int i = 0; i < 100; i++) {
        std::cout << "\n";
    }
}

void Admin(HashTable& a, Manager& b) {
    
    int Adminchoice;
    std::string empId;
    do {
        
        cout <<  "\n"<< setw(40) <<"\t\t----------------------------------------------------------------\n";
        cout << "                                           Admin Menu\n";
        cout << setw(40) << "\t\t----------------------------------------------------------------\n";

        // Display centered menu options
        cout << setw(60) << "1. Search Employees\n";
        cout << setw(65) << "2. Edit Employee Details\n";
        cout << setw(56) << "3. Add Employee\n";
        cout << setw(59) << "4. Remove Employee\n";

        cout << setw(60) << "5. Check Attendance\n";
        cout << setw(56) << "6. Add a Notice\n";
        cout << setw(65) << "7. Manage Leave Requests\n";
        cout << setw(56) << "8. Send Message\n";
        cout << setw(50) << "9. Logout\n";

        // Display the centered footer
        cout << setw(50) << "\t\t----------------------------------------------------------------\n";
        cout << "Enter your choice: ";
        
        cin >> Adminchoice;
        string id;
        string notice;
        switch (Adminchoice) {
        case 1: // Search Employees
            clearScreen();
            std::cout << "---Search---\n";
            std::cout << "Enter the Id : ";
            std::cin >> id;
            std::cout << "\n";
            
            if (a.foundEmployee(id)) {
                std::cout << "Employee Details\n";
                std::cout << "----------------\n";
                a.SearchById(id)->printEmployeeInfo();
                int subchoice;
                do
                {
                    std::cout << "\n1-Edit         \n2-Back\n";
                    cout << "Enter choice: ";
                    
                    std::cin >> subchoice;
                    cout << "\n";
                    if (subchoice == 1) {
                        a.EditEmployee(id);
                        
                    }
                    else if(subchoice != 2) cout << "Invalid Choice\n";
                } while (subchoice != 2);

            }
            else std::cout << "\nNo Employee found\n";
            break;
     
        case 2: // Edit Employee Details
            
            a.EditEmployee();
            
            hold();

            break;

        case 3: // Add Employee
          
            a.Insert();
            std::cout << "\nEmployee was added to the system successfully!\n";
            hold();
            
            break;

        case 4: // Remove Employee
           
            std::cout << "Enter the Id: ";
            std::cin >> id;
            cout << "\n";
            if (a.foundEmployee(id)) {
                a.SearchById(id)->printEmployeeInfo();
                a.delete_Employee(id);
                std::cout << "\nEmployee was removed from the system successfully!\n";
            }
            else std::cout << "No Employee Found\n";
            break;

       

        case 5: // Check Attendance
            
            b.generateAttendanceReport();
            hold();
            break;

        case 6:
           
            std::cout << "Enter Notice: ";
            
            getline(cin,notice);
            getline(cin, notice);

            notice = notice + "\n" + b.getDateTime();

            a.addNotice(notice);
            cout << "Notice was added successfully.";
            hold();
            break;
        case 7:
            
            b.ManageLeaveRequests();
         
            break;
        case 8: // send a msg
           
            cout << "Enter the Id: ";
            cin >> id;
            if (a.foundEmployee(id)) {
                cout << "Enter text: ";
                getline(cin, notice);  //clearing input buffer
                getline(cin, notice);
                notice = notice + "\n" + b.getDateTime();

                a.SearchById(id)->addNotification(notice);
                cout << "Message was sent successfully\n";
            }
            else {
                cout << "User not found\n";
            }
            hold();
            break;
        case 9:
            std::cout << "Logged out\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (Adminchoice != 9);
}

void user(HashTable& a, Manager& b) {
    
    cout << "UserID: ";
    std::string empId;
   std:: cin >> empId;   
   b.clockIn(empId); 
   if (a.SearchById(empId) != NULL)// Mark Attendance
   {
       a.SearchById(empId)->isPresent = true;

       int choice;
       do {
           clearScreen();
           cout << "\n\t\t\t--------------------------------------------\n";
           cout << "\t\t\t                  User Menu        \n";
           cout << "\t\t\t--------------------------------------------\n";

           cout << setw(50) << "1. Your Info\n";
           cout << setw(60) << "2. Check Notifications\n";
           cout << setw(63) << "3. Make a Leaving Request\n";
           cout << setw(47) << "4. Logout\n";

           cout << "\t\t\t--------------------------------------------\n";
           cout << "Enter your choice: \n";
           std::cin >> choice;

           switch (choice) {
           case 1:  //info
               cout << "\n---Your Details---";
               a.SearchById(empId)->printEmployeeInfo();
               hold();
               break;

           case 2:

               int subchoice;
               do {
                   std::cout << "\n      Notifications: \n\n";
                   a.SearchById(empId)->getNotifications().printelem();

                   std::cout << "\n\n1. Clear Notifications\n2. Back\n";
                   std:cout << "\nEnter your choice: ";
                   std::cin >> subchoice;
                   switch (subchoice) {
                   case 1:
                       a.SearchById(empId)->clearNotifications();
                       break;
                   default:
                       break;
                   }

               } while (subchoice != 2);
               break;

           case 3:  //leaving request 
               b.requestLeave(empId);
               hold();
               break;
           case 4: // LogOut
               std::cout << "Logged out\n";
               b.clockOut(empId);
               a.SearchById(empId)->isPresent = false;
               break;

           default:
               std::cout << "Invalid choice. Please try again.\n";
           }
       } while (choice != 4);
   }
   else
       std::cout << "Error: You haven't registered to the system\n";
  

}




int main() {

   
    HashTable HMRS; //---------
   ifstream inputFile("DSA.txt");
  HMRS.loadFromFile(inputFile);
    Manager system(HMRS);  //--------
    

    int choice;
    do {
        clearScreen();
        cout << "\n"
            << "\t\t==================================================================\n"
            << "\t\t           Welcome to Human Resource Management System        \n"
            << "\t\t                                                          \n"
            << "\t\t==================================================================\n\n";

        
        cout << setw(60) << "1. Login as Admin\n";
        cout << setw(56) << "2. User Login\n";
        cout << setw(51) << "3. Exit\n\n";
        cout<< "\t\t------------------------------------------------------------------\n\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        
        
        switch (choice) {
        case 1: // Search Employees
            Admin(HMRS,system);
            break;

        case 2: // Edit Employee Details
            user(HMRS, system);
            break;

        case 3: // Exit
            std::cout << "Exiting HRMS. Goodbye!\n";
            
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    ofstream outputFile("DSA.txt");
  HMRS.saveToFile(outputFile);

    return 0;
}

