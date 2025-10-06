#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    void setEmployee(int i, const string& n) {
        id = i;
        name = n;
    }
    virtual void calculateSalary() = 0;
    virtual void display() = 0;
    virtual ~Employee() {}
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double bonus;
    double totalSalary;
public:
    void setSalary(double b, double bo) {
        basicSalary = b;
        bonus = bo;
    }
    void calculateSalary() override {
        totalSalary = basicSalary + bonus;
    }
    void display() override {
        cout << "Permanent Employee: " << name << ", ID: " << id << endl;
        cout << "Total Salary: " << totalSalary << endl << endl;
    }
};

class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
    double totalSalary;
public:
    void setSalary(int hours, double rate) {
        hoursWorked = hours;
        hourlyRate = rate;
    }
    void calculateSalary() override {
        totalSalary = hoursWorked * hourlyRate;
    }
    void display() override {
        cout << "Contract Employee: " << name << ", ID: " << id << endl;
        cout << "Total Salary: " << totalSalary << endl << endl;
    }
};

int main() {
    vector<Employee*> employees;
    int choice;

    do {
        cout << "===== Employee Management System =====\n";
        cout << "1. Add Permanent Employee\n2. Add Contract Employee\n3. Display All Employees\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline

        if(choice == 1) {
            int id;
            string name;
            double basic, bonus;

            cout << "Enter Employee ID: "; cin >> id; cin.ignore();
            cout << "Enter Employee Name: "; getline(cin, name);
            cout << "Enter Basic Salary: "; cin >> basic;
            cout << "Enter Bonus: "; cin >> bonus;

            PermanentEmployee* p = new PermanentEmployee();
            p->setEmployee(id, name);
            p->setSalary(basic, bonus);
            p->calculateSalary();
            employees.push_back(p);

            cout << "Permanent Employee added successfully!\n\n";
        }
        else if(choice == 2) {
            int id, hours;
            string name;
            double rate;

            cout << "Enter Employee ID: "; cin >> id; cin.ignore();
            cout << "Enter Employee Name: "; getline(cin, name);
            cout << "Enter Hours Worked: "; cin >> hours;
            cout << "Enter Hourly Rate: "; cin >> rate;

            ContractEmployee* c = new ContractEmployee();
            c->setEmployee(id, name);
            c->setSalary(hours, rate);
            c->calculateSalary();
            employees.push_back(c);

            cout << "Contract Employee added successfully!\n\n";
        }
        else if(choice == 3) {
            if(employees.empty()) {
                cout << "No employees to display.\n\n";
            } else {
                for(auto emp : employees) {
                    emp->display();
                }
            }
        }
        else if(choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n\n";
        }

    } while(choice != 4);

    for(auto emp : employees) delete emp; // Clean up memory
    return 0;
}
