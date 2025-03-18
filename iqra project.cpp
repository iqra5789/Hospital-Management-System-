#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
    string contact;
};

struct Doctor {
    int id;
    string name;
    string specialization;
    string availability;
};

struct Appointment {
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;
};

void displayMenu();
void registerPatient(vector<Patient>& patients);
void viewPatients(const vector<Patient>& patients);
void addDoctor(vector<Doctor>& doctors);
void viewDoctors(const vector<Doctor>& doctors);
void scheduleAppointment(vector<Appointment>& appointments, const vector<Patient>& patients, const vector<Doctor>& doctors);
void viewAppointments(const vector<Appointment>& appointments);
bool patientExists(const vector<Patient>& patients, int id);
bool doctorExists(const vector<Doctor>& doctors, int id);

int main() {
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    int choice;
    
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch (choice) {
            case 1:
                registerPatient(patients);
                break;
            case 2:
                viewPatients(patients);
                break;
            case 3:
                addDoctor(doctors);
                break;
            case 4:
                viewDoctors(doctors);
                break;
            case 5:
                scheduleAppointment(appointments, patients, doctors);
                break;
            case 6:
                viewAppointments(appointments);
                break;
            case 7:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}

void displayMenu() {
    cout << "\n                                                                   	    Hospital Management System                  " << endl;
    cout << "1. Register Patient" << endl;
    cout << "2. View Patients" << endl;
    cout << "3. Add Doctor" << endl;
    cout << "4. View Doctors" << endl;
    cout << "5. Schedule Appointment" << endl;
    cout << "6. View Appointments" << endl;
    cout << "7. Exit" << endl;
}

void registerPatient(vector<Patient>& patients) {
    Patient newPatient;
    cout << "Enter Patient ID: ";
    cin >> newPatient.id;
    cin.ignore();
    
    cout << "Enter Patient Name: ";
    getline(cin, newPatient.name);
    
    cout << "Enter Age: ";
    cin >> newPatient.age;
    cin.ignore();
    
    cout << "Enter Disease: ";
    getline(cin, newPatient.disease);
    
    cout << "Enter Contact Number: ";
    getline(cin, newPatient.contact);
    
    patients.push_back(newPatient);
    cout << "Patient registered successfully!\n";
}

void viewPatients(const vector<Patient>& patients) {
    if (patients.empty()) {
        cout << "No patients registered yet.\n";
        return;
    }
    
    cout << "\nList of Patients:" << endl;
    for (const auto& patient : patients) {
        cout << "ID: " << patient.id << endl;
        cout << "Name: " << patient.name << endl;
        cout << "Age: " << patient.age << endl;
        cout << "Disease: " << patient.disease << endl;
        cout << "Contact: " << patient.contact << endl;
        cout << "---------------------------" << endl;
    }
}

void addDoctor(vector<Doctor>& doctors) {
    Doctor newDoctor;
    cout << "Enter Doctor ID: ";
    cin >> newDoctor.id;
    cin.ignore();
    
    cout << "Enter Doctor Name: ";
    getline(cin, newDoctor.name);
    
    cout << "Enter Specialization: ";
    getline(cin, newDoctor.specialization);
    
    cout << "Enter Availability (Days/Time): ";
    getline(cin, newDoctor.availability);
    
    doctors.push_back(newDoctor);
    cout << "Doctor added successfully!\n";
}

void viewDoctors(const vector<Doctor>& doctors) {
    if (doctors.empty()) {
        cout << "No doctors available.\n";
        return;
    }
    
    cout << "\nList of Doctors:" << endl;
    for (const auto& doctor : doctors) {
        cout << "ID: " << doctor.id << endl;
        cout << "Name: " << doctor.name << endl;
        cout << "Specialization: " << doctor.specialization << endl;
        cout << "Availability: " << doctor.availability << endl;
        cout << "---------------------------" << endl;
    }
}

void scheduleAppointment(vector<Appointment>& appointments, const vector<Patient>& patients, const vector<Doctor>& doctors) {
    Appointment newAppointment;
    cout << "Enter Appointment ID: ";
    cin >> newAppointment.appointmentID;
    
    cout << "Enter Patient ID: ";
    cin >> newAppointment.patientID;
    if (!patientExists(patients, newAppointment.patientID)) {
        cout << "Error: Patient not found!\n";
        return;
    }
    
    cout << "Enter Doctor ID: ";
    cin >> newAppointment.doctorID;
    if (!doctorExists(doctors, newAppointment.doctorID)) {
        cout << "Error: Doctor not found!\n";
        return;
    }
    
    cout << "Enter Appointment Date (DD/MM/YYYY): ";
    cin >> newAppointment.date;
    cout << "Enter Appointment Time (HH:MM): ";
    cin >> newAppointment.time;
    
    appointments.push_back(newAppointment);
    cout << "Appointment scheduled successfully!\n";
}

void viewAppointments(const vector<Appointment>& appointments) {
    if (appointments.empty()) {
        cout << "No appointments scheduled yet.\n";
        return;
    }
    
    cout << "\nList of Appointments:" << endl;
    for (const auto& appointment : appointments) {
        cout << "Appointment ID: " << appointment.appointmentID << endl;
        cout << "Patient ID: " << appointment.patientID << endl;
        cout << "Doctor ID: " << appointment.doctorID << endl;
        cout << "Date: " << appointment.date << endl;
        cout << "Time: " << appointment.time << endl;
        cout << "---------------------------" << endl;
    }
}

bool patientExists(const vector<Patient>& patients, int id) {
    for (const auto& patient : patients) {
        if (patient.id == id) return true;
    }
    return false;
}

bool doctorExists(const vector<Doctor>& doctors, int id) {
    for (const auto& doctor : doctors) {
        if (doctor.id == id) return true;
    }
    return false;
}
