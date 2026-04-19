#include "airlines.h"
#include <iomanip>

int seat[SIZE];
int reserve=999;
bool taken=false;

Airlines::Airlines(){start=nullptr;}

void seatFill(){for(int i=0;i<SIZE;i++)seat[i]=0;}

bool seatNo(int y){
    if(seat[y-1]==-1){
        cout<<"This seat is already taken.\nAvailable seats:\n";
        for(int i=1;i<SIZE;i++){
            if(seat[i-1]!=-1)cout<<"|"<<i<<"|";
            if(i%10==0)cout<<endl;
        }
        return true;
    }
    return false;
}

void menu(){
    int choice;
    Airlines obj;
    do{
        cout<<"\n====== AIRLINE RESERVATION SYSTEM ======\n";
        cout<<"1. Make Reservation\n2. Cancel Reservation\n3. Search Passenger\n4. Change Reservation\n5. Print Passenger List\n6. Print Status Report\n7. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: obj.makeReservation(); break;
            case 2: obj.cancelReservation(); break;
            case 3: obj.searchPassenger(); break;
            case 4: obj.changeReservation(); break;
            case 5: obj.printList(); break;
            case 6: obj.printReport(); break;
            case 7: cout<<"Thank you!\n"; break;
            default: cout<<"Invalid choice.\n";
        }
    }while(choice!=7);
}

void Airlines::makeReservation(){
    Node *temp=new Node;
    int meal_choice,x;

    cout<<"\nEnter First Name: ";
    cin>>temp->fname;
    cout<<"Enter Last Name: ";
    cin>>temp->lname;
    cout<<"Enter ID: ";
    cin>>temp->ID;
    cout<<"Enter Phone Number: ";
    cin>>temp->phone_num;

    do{
        cout<<"Enter Seat Number(1-100): ";
        cin>>x;
        while(x<1||x>SIZE){
            cout<<"Invalid! Enter again: ";
            cin>>x;
        }
        taken=seatNo(x);
    }while(taken);

    seat[x-1]=-1;
    temp->seat_num=x;

    cout<<"1. Veg\n2. Non-Veg\n3. No Meal\nChoice: ";
    cin>>meal_choice;

    if(meal_choice==1)temp->menu="Veg";
    else if(meal_choice==2)temp->menu="Non-Veg";
    else temp->menu="No Meal";

    reserve++;
    temp->reserve_num=reserve;
    temp->next=nullptr;

    if(start==nullptr)start=temp;
    else{
        Node *ptr=start;
        while(ptr->next!=nullptr)ptr=ptr->next;
        ptr->next=temp;
    }
    cout<<"Reservation Successfull! No: "<<reserve<<endl;
}

void Airlines::cancelReservation(){
    int num;
    cout<<"Enter Reservation Number:";
    cin>>num;

    Node *cur=start,*prev=nullptr;

    while(cur!=nullptr && cur->reserve_num!=num){
        prev=cur;
        cur=cur->next;
    }

    if(cur==nullptr){
        cout<<"Not found.\n";
        return;
    }

    seat[cur->seat_num-1]=0;

    if(prev==nullptr)start=start->next;
    else prev->next=cur->next;

    delete cur;
    cout<<"Cancelled Succesfully.\n";
}

void Airlines::searchPassenger(){
    string name;
    cout<<"Enter first name: ";
    cin>>name;

    Node *cur=start;
    while(cur!=nullptr){
        if(cur->fname==name){
            cout<<"Found:\n";
            cout<<cur->fname<<" "<<cur->lname<<endl;
            cout<<"Seat: "<<cur->seat_num<<endl;
            return;
        }
        cur=cur->next;
    }
    cout<<"Not found.\n";
}

void Airlines::changeReservation(){
    int oldSeat,newSeat;
    cout<<"Enter current seat:";
    cin>>oldSeat;

    Node *cur=start;
    while(cur!=nullptr && cur->seat_num!=oldSeat)cur=cur->next;

    if(cur==nullptr){
        cout<<"Seat not found.\n";
        return;
    }

    cout<<"Enter new seat: ";
    cin>>newSeat;

    while(newSeat<1||newSeat>SIZE||seat[newSeat-1]==-1){
        cout<<"Seat not available. Enter again: ";
        cin>>newSeat;
    }

    seat[cur->seat_num-1]=0;
    cur->seat_num=newSeat;
    seat[newSeat-1]=-1;

    cout<<"Seat updated.\n";
}

void Airlines::printList(){
    Node *temp=start;
    int count=1;
    while(temp!=nullptr){
        cout<<count++<<". "<<temp->fname<<" "<<temp->lname<<" Seat: "<<temp->seat_num<<endl;
        temp=temp->next;
    }
}

void Airlines::printReport(){
    int reserved=0;
    for(int i=0;i<SIZE;i++)if(seat[i]==-1)reserved++;
    cout<<"Reserved Seats: "<<reserved<<endl;
    cout<<"Available Seats: "<<SIZE-reserved<<endl;
}