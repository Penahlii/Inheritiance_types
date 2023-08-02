#pragma once

class Employee {
protected:
    string name;
    int age;
    string department;

public:
    Employee(string name, int age, string department) {
        this->name = name;
        this->age = age;
        this->department = department;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
    }
};


class Manager : public Employee {
private:
    int numSubordinates;

public:
    Manager(string name, int age, string department, int numSubordinates)
        : Employee(name, age, department) {
        this->numSubordinates = numSubordinates;
    }

    void displayDetails() {
        cout << "Manager Details" << endl;
        Employee::displayDetails(); 
        cout << "Number of Subordinates: " << numSubordinates << endl;
    }
};


class Developer : public Employee {
private:
    string programmingLanguage;

public:
    Developer(string name, int age, string department, string programmingLanguage)
        : Employee(name, age, department) {
        this->programmingLanguage = programmingLanguage;
    }

    void displayDetails() {
        cout << "Developer Details" << endl;
        Employee::displayDetails(); 
        cout << "Programming Language: " << programmingLanguage << endl;
    }
};


class Intern : public Developer {
private:
    string schoolName;

public:
    Intern(string name, int age, string department, string programmingLanguage, string schoolName)
        : Developer(name, age, department, programmingLanguage) {
        this->schoolName = schoolName;
    }

    void displayDetails() {
        cout << "Intern Details" << endl;
        Developer::displayDetails(); 
        cout << "School Name: " << schoolName << endl;
    }
};