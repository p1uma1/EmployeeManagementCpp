#pragma once
#include<iostream>
#include <string>
using namespace std;
class request {
public:
    string id;
    string description;
    bool status;
    request();
    void GetRequest();
    void print();
    request operator=(request const& arg);
};
class Queues {
private:
    int rear;   //points to an empty position
    int front;
    request* data;
    int capacity;
    int size; // current size of data
public:
    Queues();
    Queues(const int  acapacity);
    void Enqueue(string& id, string& des);
    void Enqueue(request& arg);

    request Dequeue();
    void print();

    void printFirst();

    bool isEmpty();
};
