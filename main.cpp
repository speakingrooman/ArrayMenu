//Rooman Zahid CS 373 Assignment 1
#include <iostream>
#include <string>
using namespace std;
const int ARRSIZE=100;
static string Students[ARRSIZE][2]={}; 


void addStudent();
void printRoster();
void changeGrade();
void search();
void removeStudents();
int menu();
int getID();
int idNum();
int main(){
    while(true){
        switch (menu()) {
            case 1:
                addStudent();
                break;
            case 2:
                changeGrade();
                break;
            case 3:
                search();
                break;
            case 4:
                removeStudents();
                break;
            case 5:
                printRoster();
                break;
            case 6:
                return false;
                break;
            default:
                break;
        }
    }
    return 0;
}

    
int menu(){
        int temp;
        do{
            cout<<"1. Add a student"<<endl;
            cout<<"2. Change a grade"<<endl;
            cout<<"3. Search by ID"<<endl;
            cout<<"4. Remove a student"<<endl;
            cout<<"5. Print class roster"<<endl;
            cout<<"6. Exit"<<endl;
            cout<<"Please enter your choice === > ";
            cin>>temp;
        } while(temp<1||temp>6);
        return temp;
    }


void addStudent(){
    int studentID;
    string grade;
    string name;
    studentID=getID();
    if(!(Students[studentID][1].empty())){
        cout<<"Duplicate ID, already exists"<<endl;
    }
    if(Students[studentID][1].empty()){
        cout<<"Enter student name ";
        cin>>name;
        cout<<"Enter student grade ";
        cin>>grade;
        for (int i=0; name[i]=toupper(name[i]); i++) {
            Students[studentID][0]=name;
        }
        for (int i=0; grade[i]=toupper(grade[i]); i++) {
            Students[studentID][1]=grade;
        }
           cout<<"Student Added successfully "<<endl;
    }
 
}

void changeGrade(){
    int studentID;
    string newGrade;
     studentID=getID();
    if(Students[studentID][0].empty()){
        cout<<"Student not found "<<endl;
    } else {
        cout<<"Enter new Grade ";
        cin>>newGrade;
        Students[studentID][1]=newGrade;
    }
}


void removeStudents(){
    int studentID;
    studentID=getID();
    if(Students[studentID][0].empty()){
        cout<<"Student not found "<<endl;
    } else{
    Students[studentID][0].clear();
    Students[studentID][1].clear();
    }
}



void search(){
    int temp;
    int studentID;
    studentID=getID();
    temp=studentID+1;
    if(Students[studentID][0].empty()){
        cout<<"Student not found "<<endl;
    } else{
    cout<<temp<<") Name: "<<Students[studentID][0]<<" \t"<<"Grade: "<<Students[studentID][1]<<endl;
    }
}


int getID(){
    int studentID;
    cout<<"Enter Student ID ";
    cin>>studentID;
    while (studentID<1||studentID>ARRSIZE) {
        cout<<"Enter ID values between 1-100 ";
        cin>>studentID;
    }
    return studentID-1;
}





void printRoster(){
   
    for (int i=0; i<ARRSIZE; i++) {
        if (!(Students[i][0].empty())) {
                cout<<"Name: "<<Students[i][0]<<" \t"<<"Grade: "<<Students[i][1]<<endl;
        }
    }
}
    
    
    


