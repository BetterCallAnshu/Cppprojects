#ifndef Airlines_h
#define Airlines_h

#include<iostream>
#include<string>
using namespace std;

#define SIZE 100

class Airlines{
    public:
    Airlines();
    void makeReservation();
    void cancelReservation();
    void searchPassenger();
    void changeReservation();
    void printList();
    void printReport();


private:

struct Node{
    string fname;
    string lname;
    string ID;
    string phone_num;
    string menu;

    int reserve_num;
    int seat_num;

    Node *next;

};

 Node *start;
};

void menu();
void seatFill();
bool seatNo(int y);

extern int seat[SIZE];
extern int reserve;

#endif