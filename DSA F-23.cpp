#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

struct student {
    int roll_no;
    char name[15];
    int age;
};

// Comparison function to sort by roll number
bool compareByRoll(student a, student b) {
    return a.roll_no < b.roll_no;
}

void addStudent(vector<student> &students);
void displayStudents(fstream &f, int n);
void searchStudent(fstream &f, int n);
void updateStudent(fstream &f, int n);
void deleteStudent(fstream &f, int &n);

int main() {
    fstream f;
    student s;
    int n, choice;
    vector<student> students;

    cout << "Enter total no. of students: ";
    cin >> n;
    
    for (int i=0; i<n; i++){
        addStudent(students);
    }
    
    sort(students.begin(), students.end(), compareByRoll);

    f.open("Student.txt", ios::in | ios::out | ios::trunc | ios::binary);
    for (int i = 0; i < students.size(); i++) {
        f.write((char*)&students[i], sizeof(students[i]));
    }
    f.close(); 

    do {
        cout << "\nMenu:\n";
        cout << "1. Display All Students\n";
        cout << "2. Search a Student\n";
        cout << "3. Update a Student\n";
        cout << "4. Delete a Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        f.open("Student.txt", ios::in | ios::out | ios::binary); 

        switch (choice) {
            case 1:
                displayStudents(f, n);
                break;
            case 2:
                searchStudent(f, n);
                break;
            case 3:
                updateStudent(f, n);
                break;
            case 4:
                deleteStudent(f, n);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        f.close(); 
    } while (choice != 5);

    return 0;
}

void addStudent(vector<student> &students) {
    student s;
    cout << "Enter roll no., name, age: ";
    cin >> s.roll_no >> s.name >> s.age;
    students.push_back(s);
}
void displayStudents(fstream &f, int n) {
    f.seekg(0, ios::beg);
    student s;
    cout << "\nAll records:\n";
    for (int i = 0; i < n; i++) {
        f.read((char*)&s, sizeof(s));
        cout << "Roll number: " << s.roll_no << " Name: " << s.name << " Age: " << s.age << endl;
    }
}
void searchStudent(fstream &f, int n) {
    f.seekg(0, ios::beg);
    student s;
    int key;
    bool found = false;
    cout << "\nEnter a roll number to be searched: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        f.read((char*)&s, sizeof(s));
        if (key == s.roll_no) {
            cout << "Record Found:\n";
            cout << "Roll number: " << s.roll_no << " Name: " << s.name << " Age: " << s.age << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found!!\n";
    }
}
void updateStudent(fstream &f, int n) {
    f.clear();
    f.seekg(0, ios::beg);
    student s;
    int key;
    bool found = false;
    cout << "\nEnter a roll number to be updated: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        streampos pos = f.tellg();
        f.read((char*)&s, sizeof(s));
        if (key == s.roll_no) {
            found = true;
            cout << "Enter new name and age: ";
            cin >> s.name >> s.age;
            f.seekp(pos);
            f.write((char*)&s, sizeof(s));
            cout << "Record updated.\n";
            break;
        }
    }
    if (!found) {
        cout << "Record not found!!\n";
    }
}

void deleteStudent(fstream &f, int &n) {
    f.close();
    ifstream fin("Student.txt", ios::binary);
    ofstream temp("Temp.txt", ios::binary);
    student s;
    int key;
    bool found = false;

    cout << "\nEnter a roll number to be deleted: ";
    cin >> key;

    while (fin.read((char*)&s, sizeof(s))) {
        if (s.roll_no == key) {
            found = true;
            continue; // Skip this record
        }
        temp.write((char*)&s, sizeof(s));
    }

    fin.close();
    temp.close();

    remove("Student.txt");
    rename("Temp.txt", "Student.txt");

    if (found) {
        cout << "Record deleted successfully.\n";
        n--;
    } else {
        cout << "Record not found!!\n";
    }
}

