#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int marks;
    char grade;
};

char calculateGrade(int marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else return 'F';
}

void saveToFile(Student *s, int count) {
    ofstream file("students.txt");

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        file << s[i].name << "," << s[i].marks << "," << s[i].grade << endl;
    }
    cout << "Data saved successfully!\n";
}

void loadFromFile(Student *s, int &count) {
    ifstream file("students.txt");

    if (!file) {
        cout << "No previous file found, starting fresh.\n";
        return;
    }

    count = 0;
    while (getline(file, s[count].name, ',') &&
           file >> s[count].marks &&
           file.ignore(1) &&
           file >> s[count].grade &&
           file.ignore(1))
    {
        count++;
        if (count >= 50) break;  // Safety
    }

    cout << "Data loaded successfully!\n";
}

void addStudent(Student *s, int &count) {
    if (count >= 100) {
        cout << "Maximum student limit reached!\n";
        return;
    }

    cin.ignore();
    cout << "Enter full name: ";
    getline(cin, s[count].name);

    cout << "Enter marks: ";
    cin >> s[count].marks;

    s[count].grade = calculateGrade(s[count].marks);
    count++;

    cout << "Student added!\n";
}

void updateStudent(Student *s, int count) {
    int index;
    cout << "Enter index to update: ";
    cin >> index;

    if (index >= count) {
        cout << "Invalid index!\n";
        return;
    }

    cin.ignore();
    cout << "New full name: ";
    getline(cin, s[index].name);

    cout << "New marks: ";
    cin >> s[index].marks;

    s[index].grade = calculateGrade(s[index].marks);

    cout << "Student updated!\n";
}

void deleteStudent(Student *s, int &count) {
    int index;
    cout << "Enter index to delete: ";
    cin >> index;

    if (index >= count) {
        cout << "Invalid index!\n";
        return;
    }

    for (int i = index; i < count - 1; i++)
        s[i] = s[i + 1];

    count--;
    cout << "Student deleted!\n";
}

void display(Student *s, int count) {
    cout << "\n--- Student List ---\n";
    for (int i = 0; i < count; i++) {
        cout << i << ". Name: " << s[i].name
             << " | Marks: " << s[i].marks
             << " | Grade: " << s[i].grade << endl;
    }
}

int main() {
    Student s[50];
    int count = 0, choice;

    loadFromFile(s, count);

    while (true) {
        cout << "\n1. Add Student\n2. Update Student\n3. Delete Student\n4. Display\n5. Save to File\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(s, count); break;
            case 2: updateStudent(s, count); break;
            case 3: deleteStudent(s, count); break;
            case 4: display(s, count); break;
            case 5: saveToFile(s, count); break;
            case 6: saveToFile(s, count); return 0;
            default: cout << "Invalid choice!\n";
            return 0;
        }
