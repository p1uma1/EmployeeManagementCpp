#include "Queues.h"

request::request() {
        id = "";
        description = "";
        status = NULL;
    }
    void request::GetRequest() {
        cout << "Employee ID: "; cin >> id;
        cout << "\nDescription: "; cin >> description;
    }
    void request::print() {
        cout << "Employee ID: " << id;
        cout << "\nDescription: " << description << endl;

    }
    request request::operator=(request const& arg) {
        id = arg.id;
        description = arg.description;
        return *this;
    }


    Queues::Queues() {
        capacity = 10;
        data = new request[capacity];
        size = 0;
        front = 0;
        rear = 0;
    }
    Queues::Queues(const int  acapacity) {
        data = new request[acapacity];
        capacity = acapacity;
        size = 0;
        front = 0;
        rear = 0;

    }
    void Queues::Enqueue(string& id, string& des) {
        if (size == capacity) std::cout << "Queue is full" << std::endl;
        else {
            data[rear].id = id;
            data[rear].description = des;
            size++;
            rear = (rear + 1) % capacity;
        }
    }
    void Queues::Enqueue(request& arg) {
        if (size == capacity) std::cout << "Queue is full" << std::endl;
        else {
            data[rear] = arg;
            size++;
            rear = (rear + 1) % capacity;
        }
    }

    request Queues::Dequeue() {
        request k;
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return k;
        }
        else {
            k = data[front];

            size--;
            front = (front + 1) % capacity;

            return k;

        }
    }
    void Queues::print() {
        if (size == 0) cout << "Empty queue" << endl;
        else {
            // int j = front;
            for (int i = 0; i < size; i++)
            {
                cout << data[(front + i) % capacity].id << ": " << data[(front + i) % capacity].description << "\n";

            }

        }
    }

    void Queues::printFirst() {
        if (size == 0) cout << "Empty queue" << endl;
        else {
            data[front].print();
        }
    }

    bool Queues::isEmpty()
    {
        if (size == 0) return true;
        else return false;
    }

