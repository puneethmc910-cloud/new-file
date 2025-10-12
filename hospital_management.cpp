#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
private:
    int id;
    string name;
    int age;
    string medicalHistory;

public:
    Patient(int patientId, string patientName, int patientAge, string history) {
        id = patientId;
        name = patientName;
        age = patientAge;
        medicalHistory = history;
    }

    void displayPatient() {
        cout << "ID: " << id << " | Name: " << name << " | Age: " << age << " | History: " << medicalHistory << endl;
    }

    int getId() { return id; }
    string getName() { return name; }
};

class Appointment {
private:
    int appointmentId;
    int patientId;
    string patientName;
    string date;
    string time;

public:
    Appointment(int appId, int patId, string patName, string appDate, string appTime) {
        appointmentId = appId;
        patientId = patId;
        patientName = patName;
        date = appDate;
        time = appTime;
    }

    void displayAppointment() {
        cout << "Appointment ID: " << appointmentId << " | Patient: " << patientName << " | Date: " << date << " | Time: " << time << endl;
    }

    int getAppointmentId() { return appointmentId; }
};

class HospitalSystem {
private:
    vector<Patient> patients;
    vector<Appointment> appointments;
    int nextPatientId;
    int nextAppointmentId;

public:
    HospitalSystem() {
        nextPatientId = 1;
        nextAppointmentId = 1;
    }

    void addPatient() {
        string name, history;
        int age;

        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter patient age: ";
        cin >> age;
        cout << "Enter medical history: ";
        cin.ignore();
        getline(cin, history);

        patients.push_back(Patient(nextPatientId++, name, age, history));
        cout << "Patient added successfully!" << endl;
    }

    void displayPatients() {
        cout << "All Patients:" << endl;
        for (auto &patient : patients) {
            patient.displayPatient();
        }
    }

    Patient* findPatient(int id) {
        for (auto &patient : patients) {
            if (patient.getId() == id) {
                return &patient;
            }
        }
        return nullptr;
    }

    void scheduleAppointment() {
        int patientId;
        string date, time;

        cout << "Enter patient ID: ";
        cin >> patientId;

        Patient* patient = findPatient(patientId);
        if (patient == nullptr) {
            cout << "Patient not found!" << endl;
            return;
        }

        cout << "Enter date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter time (HH:MM): ";
        cin >> time;

        appointments.push_back(Appointment(nextAppointmentId++, patientId, patient->getName(), date, time));
        cout << "Appointment scheduled successfully!" << endl;
    }

    void displayAppointments() {
        cout << "All Appointments:" << endl;
        for (auto &appointment : appointments) {
            appointment.displayAppointment();
        }
    }
};

int main() {
    HospitalSystem hospital;
    int choice;

    while (true) {
        cout << "\n1. Add Patient\n2. View Patients\n3. Schedule Appointment\n4. View Appointments\n5. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hospital.addPatient();
                break;
            case 2:
                hospital.displayPatients();
                break;
            case 3:
                hospital.scheduleAppointment();
                break;
            case 4:
                hospital.displayAppointments();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}