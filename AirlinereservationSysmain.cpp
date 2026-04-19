#include<iostream>
#include<vector>
using namespace std;
//session 1
class Flight{
    private:
        string flightNo, departure, destination;
        int capacity, reservedSeats;
    public:
        Flight(string flight, string dep,  string des, int cap){
            flightNo = flight;
            departure = dep;
            destination = des;
            capacity = cap;
            reservedSeats = 0;
        }
bool reservation(){
    if(reservedSeats < capacity){
        reservedSeats++;
        return true;
    }
    return false;
    }
    friend class ReservationSystem;
};
//session 2
class ReservationSystem{
    public:
    vector<Flight> ve;

    void add(string flight ,string dep, string des, int cap){
        Flight newflight(flight, dep, des, cap);
        ve.push_back(newflight);
    }

    void reserveSeat(){
        cout<<"<<< Available Flights >>>>>>"<<endl<<endl;
        for(int i=0; i<ve.size();i++){
            cout<<"Flight: "<<ve[i].flightNo<<endl;
            cout<<"Departure: "<<ve[i].departure<<endl;
            cout<<"Destination: "<<ve[i].destination<<endl;
            cout<<"Capacity: "<<ve[i].capacity<<endl<<endl;

        }
        string fn;
        cout<<"Enter Flight No: "; cin>>fn;
        for(int  i=0; i<ve.size(); i++){
            if(fn==ve[i].flightNo){
        if(ve[i].reservation()){
         cout<<"You have reserved seat on flight: "<<ve[i].flightNo<<endl;
        }//nested if
        else{
            cout<<"Sorry! Seats not availabe:"<<endl<<endl;
        }
            }//if
        }//for

    }//function
};

int main(){
    ReservationSystem rs;
    rs.add("F101", "UAE", "USA", 100);
    rs.add("F202", "UK", "Canada", 150);
    rs.add("F303", "UK", "UAE", 100);
    cout<<"<<<< RDF Airline >>>>"<<endl<<endl;
    while(true){
        int choice;
    cout<<"Enter 1 for reserve seat "<<endl;
    cout<<"Enter 0 for exit"<<endl;
    cout<<"Enter choice: "; cin>>choice;
    if(choice==1){
    system("cls");
    rs.reserveSeat();
    }
    else if(choice==0){
        exit(0);
    }
    }
}
