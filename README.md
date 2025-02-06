
## Classes and Functionality

### 1. `Request` and `Queues`

- **Request**: Represents a leave request with fields for ID, description, and status.
    - Methods: `GetRequest()`, `print()`, `operator=`
    
- **Queue**: Implements a queue to store leave request objects.
    - Methods: `Enqueue()`, `Dequeue()`, `print()`, `isEmpty()`

### 2. `Manager`
- Handles employee management tasks like attendance and leave requests.
    - **Attendance**: `clockIn()`, `clockOut()`
    - **Leave Requests**: `requestLeave()`, `ManageLeaveRequests()`
    - **Reports**: `generateAttendanceReport()`, `generateLeaveRequestsReport()`

### 3. `SinglyLinkedList`
- Implements a singly linked list for storing attendance records.
    - Methods: 
        - Insertions: `insertFirst()`, `insertLast()`, `insertAt()`
        - Deletions: `deleteFirst()`, `deleteLast()`, `deleteAt()`, `deleteElm()`
        - Utility functions: `reverse()`, `clear()`, `printelem()`

### 4. `HashTable`
- Implements a hash table for storing employee data and sending notifications.
- Allows chaining to handle hash collisions.

## Compilation and Execution

### To compile the program:
```bash
g++ main.cpp HashTable.cpp Manager.cpp Queues.cpp SinglyLinkedList.cpp -o main
