#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string name;
    int age;
    string disease;
    Patient* next;
};

class HospitalSystem {
private:
    Patient* head;

public:
    HospitalSystem() { head = nullptr; }

    void addPatient(string name, int age, string disease) {
        Patient* newPatient = new Patient{name, age, disease, nullptr};
        if (head == nullptr) {
            head = newPatient;
        } else {
            Patient* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newPatient;
        }
        cout << "Patient added successfully.\n";
    }

    void showPatients() {
        if (head == nullptr) {
            cout << "No patients in the hospital.\n";
            return;
        }
        Patient* temp = head;
        int count = 1;
        cout << "\n--- Hospital Patients List ---\n";
        while (temp != nullptr) {
            cout << count << ". Name: " << temp->name 
                 << ", Age: " << temp->age 
                 << ", Disease: " << temp->disease << endl;
            temp = temp->next;
            count++;
        }
    }

    void removePatient(string name) {
        if (head == nullptr) {
            cout << "Patient not found.\n";
            return;
        }
        if (head->name == name) {
            Patient* temp = head;
            head = head->next;
            delete temp;
            cout << "Patient discharged successfully.\n";
            return;
        }
        Patient* temp = head;
        while (temp->next != nullptr && temp->next->name != name) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Patient* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Patient discharged successfully.\n";
        } else {
            cout << "Patient not found.\n";
        }
    }
};

int main() {
    HospitalSystem hospital;
    int choice;
    do {
        cout << "\n1. Add Patient  2. Show Patients  3. Discharge Patient  0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string name, disease;
            int age;
            cout << "Name: "; getline(cin, name);
            cout << "Age: "; cin >> age;
            cin.ignore();
            cout << "Disease: "; getline(cin, disease);
            hospital.addPatient(name, age, disease);
        } else if (choice == 2) {
            hospital.showPatients();
        } else if (choice == 3) {
            string name;
            cout << "Patient Name to discharge: "; getline(cin, name);
            hospital.removePatient(name);
        }
    } while (choice != 0);
    return 0;
}
