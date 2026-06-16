#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string gender;
    string phone;
    string department;
};

void addStudent();
void displayStudents();
void updateStudent();
void deleteStudent();

void addStudent()
{
    Student s;

    cout << "\n===== ADD STUDENT =====\n";

    cout << "Enter ID: ";
    cin >> s.id;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Age: ";
    cin >> s.age;

    cout << "Enter Gender: ";
    cin >> s.gender;

    cout << "Enter Phone: ";
    cin >> s.phone;

    cout << "Enter Department: ";
    cin >> s.department;

    ofstream file("students.txt", ios::app);

file << s.id << ","
     << s.name << ","
     << s.age << ","
     << s.gender << ","
     << s.phone << ","
     << s.department << endl;

file.close();

cout << "\nStudent Added Successfully!\n";
}

void displayStudents()
{
    ifstream file("students.txt");

    string line;

    cout << "\n===== STUDENT RECORDS =====\n";

    while(getline(file, line))
    {
        stringstream ss(line);

        string id, name, age, gender, phone, department;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, gender, ',');
        getline(ss, phone, ',');
        getline(ss, department);

        cout << "\n========================\n";
        cout << "Student Details\n";
        cout << "========================\n";
        cout << "ID         : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
        cout << "Gender     : " << gender << endl;
        cout << "Phone      : " << phone << endl;
        cout << "Department : " << department << endl;
        cout << "========================\n";
    }

    file.close();
}

void updateStudent()
{
    int searchId;
    cout << "\nEnter Student ID to Update: ";
    cin >> searchId;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string id, name, age, gender, phone, department;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, gender, ',');
        getline(ss, phone, ',');
        getline(ss, department, ',');

        if(stoi(id) == searchId)
        {
            found = true;

            cout << "\nStudent Found!\n";

            cout << "Enter New Name: ";
            cin >> name;

            cout << "Enter New Age: ";
            cin >> age;

            cout << "Enter New Gender: ";
            cin >> gender;

            cout << "Enter New Phone: ";
            cin >> phone;

            cout << "Enter New Department: ";
            cin >> department;
        }

        temp << id << ","
             << name << ","
             << age << ","
             << gender << ","
             << phone << ","
             << department << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
        cout << "\nStudent Updated Successfully!\n";
    else
        cout << "\nStudent ID Not Found!\n";
}

void deleteStudent()
{
    int searchId;
    cout << "\nEnter Student ID to Delete: ";
    cin >> searchId;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string id;
        getline(ss, id, ',');

        if(stoi(id) == searchId)
        {
            found = true;
            continue;
        }

        temp << line << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
        cout << "\nStudent Deleted Successfully!\n";
    else
        cout << "\nStudent ID Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << "   STUDENT MANAGEMENT SYSTEM\n";
        cout << "=================================\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Students\n";
        cout << "5. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
           case 1:
              addStudent();
              break;

          case 2:
              updateStudent();
            break;

            case 3:
                deleteStudent();
                break;

            case 4:
              displayStudents();
              break;


            case 5:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
