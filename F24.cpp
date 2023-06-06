#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Employee {
private:
    int empId;
    char name[50];
    char designation[50];
    double salary;

public:
    void addEmployee() {
        ofstream file("employees.dat", ios::binary | ios::app);
        if (!file) {
            cout << "eRROR oPENING fILE!" << endl;
            return;
        }
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Employee Designation: ";
        cin.getline(designation, 50);
        cout << "Enter Employee Salary: ";
        cin >> salary;

        file.write(reinterpret_cast<char*>(this), sizeof(Employee));

        file.close();
    }

    void deleteEmployee(int empId) {
        fstream file("employees.dat", ios::binary | ios::in | ios::out);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        Employee emp;
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
            if (emp.empId == empId) {
                found = true;
                break;
            }
        }

        if (found) {
            long pos = file.tellg();
            file.seekp(pos - sizeof(Employee));  
            Employee blankEmp;
            file.write(reinterpret_cast<char*>(&blankEmp), sizeof(Employee));  
            cout << "Employee with ID " << empId << " deleted successfully." << endl;
        } else {
            cout << "Employee with ID " << empId << " not found." << endl;
        }

        file.close();
    }


    void displayEmployee(int empId) {
        ifstream file("employees.dat", ios::binary);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        bool found = false;
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(this), sizeof(Employee));
            if (this->empId == empId) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Employee ID: " << empId << endl;
            cout << "Name: " << name << endl;
            cout << "Designation: " << designation << endl;
            cout << "Salary: " << salary << endl;
        } else {
            cout << "Employee with ID " << empId << " not found." << endl;
        }

        file.close();
    }
};

int main() {
    int choice;
    int empId;

    Employee emp;

    do {
        cout << "\n1. Add Employee" << endl;
        cout << "\n2. Delete Employee" << endl;
        cout << "\n3. Display Employee" << endl;
        cout << "\n4. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                emp.addEmployee();
                break;
            case 2:
                cout << "Enter Employee ID to delete: ";
                cin >> empId;
                emp.deleteEmployee(empId);
                break;
            case 3:
                cout << "Enter Employee ID to display: ";
                cin >> empId;
                emp.displayEmployee(empId);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
    return 0;
}
/*1. Add Employee

2. Delete Employee

3. Display Employee

4. Exit

Enter your choice: 1
Enter Employee ID: 101
Enter Employee Name: sahil
Enter Employee Designation: manager
Enter Employee Salary: 8000

1. Add Employee

2. Delete Employee

3. Display Employee

4. Exit

Enter your choice: 1
Enter Employee ID: 102
Enter Employee Name: omkar
Enter Employee Designation: engineer
Enter Employee Salary: 45000

1. Add Employee

2. Delete Employee

3. Display Employee

4. Exit

Enter your choice: 1
Enter Employee ID: 103
Enter Employee Name: vinayak
Enter Employee Designation: officer
Enter Employee Salary: 6000

1. Add Employee

2. Delete Employee

3. Display Employee

4. Exit

Enter your choice: 3
Enter Employee ID to display: 102
Employee ID: 102
Name: omkar
Designation: engineer
Salary: 45000

1. Add Employee

2. Delete Employee

3. Display Employee

4. Exit

Enter your choice: 2
Enter Employee ID to delete: 101
Employee with ID 101 deleted successfully.

1. Add Employee

2. Delete Employee

3. Display Employee

4. Exit

Enter your choice: 3
Enter Employee ID to display: 101
Employee with ID 101 not found.*/
