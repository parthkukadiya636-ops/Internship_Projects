#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    int age;
    string course;

    void addStudent(){
        ofstream file("student.txt", ios::app);

        cout<<"\nEnter the roll number:";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cin.ignore();

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Course: ";
        getline(cin, course);

        file << rollNo << "|" << name << "|" << age << "|" << course << endl;

        file.close();

        cout << "\nStudent Record Added Successfully!\n";
    }

    void displayStudents(){
        ifstream file("student.txt"); // file open

        string data;

        while(getline(file,data)){
            cout<<data<<endl;
        }

        file.close();
}
     void searchStudent(){
        ifstream file("student.txt");

        int searchRoll;
        string data;

        bool found = false;

        cout<<"\nEnter the roll no to find the student:";
        cin>>searchRoll;

        while(getline(file,data)){
            int pos = data.find("|");
            int roll = stoi(data.substr(0,pos));

            if(roll == searchRoll){
                cout << "\nStudent Found:\n";
                cout<<data<<endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "\nStudent Not Found!\n";
        }
         file.close();
     }

    void deleteStudent(){

        ifstream file("student.txt");
        ofstream temp("temp.txt",ios::app);

        int deleteRoll;
        string data;

        bool found = false;

        cout<<"\nEnter the Roll Number to Delete:";
        cin>> deleteRoll;

        while(getline(file,data)){
            int pos = data.find("|");
            int roll = stoi(data.substr(0,pos));

            if(deleteRoll != roll){
                temp<<data<<endl;
            }
            else{
                found =true;
            }
        }

        file.close();
        temp.close();

        remove("student.txt");
        rename("temp.txt", "student.txt");

        if(found== true){
             cout << "\nStudent Record Deleted Successfully!\n"; 
            } 
        else { 
            cout << "\nStudent Not Found!\n";
         }

    }

};


int main(){

    Student s;
    int choice;

    do{
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.addStudent();
            break;

        case 2:
            s.displayStudents();
            break;

        case 3:
            s.searchStudent();
            break;

        case 4:
            s.deleteStudent();
            break;

        case 5:
            cout << "\nExiting Program...\n";
            cout<<"\n...Thanks for Visiting...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;

}
