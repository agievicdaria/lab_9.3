#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string lastName;
    string initials;
    int grades[5];
};

const int MAX_STUDENTS = 100;
void displayMenu();
void addStudent(Student*& students, int& count);
void removeStudent(Student*& students, int& count);
void editStudentInfo(Student* students, int count);
void displayAllStudents(const Student* students, int count);
void displayTopStudents(const Student* students, int count);
void displayStudentsWithThrees(const Student* students, int count);
void displayStudentsWithTwos(const Student* students, int count);
void saveToFile(const Student* students, int count, const string& filename);
void loadFromFile(Student*& students, int& count, const string& filename);

int main() {
    Student* students = new Student[MAX_STUDENTS];
    int studentCount = 0;

    while (true) {
        displayMenu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                removeStudent(students, studentCount);
                break;
            case 3:
                editStudentInfo(students, studentCount);
                break;
            case 4:
                displayAllStudents(students, studentCount);
                break;
            case 5:
                displayTopStudents(students, studentCount);
                break;
            case 6:
                displayStudentsWithThrees(students, studentCount);
                break;
            case 7:
                displayStudentsWithTwos(students, studentCount);
                break;
            case 8:
                {
                    string filename;
                    cout << "Enter the filename to save: ";
                    cin >> filename;
                    saveToFile(students, studentCount, filename);
                }
                break;
            case 9:
                {
                    string filename;
                    cout << "Enter the filename to load: ";
                    cin >> filename;
                    loadFromFile(students, studentCount, filename);
                }
                break;
            case 0:
                delete[] students;
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

void displayMenu() {
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Edit Student Information\n";
    cout << "4. Display All Students\n";
    cout << "5. Display Top Students\n";
    cout << "6. Display Students with Threes\n";
    cout << "7. Display Students with Twos\n";
    cout << "8. Save to File\n";
    cout << "9. Load from File\n";
    cout << "0. Exit\n";
}

void addStudent(Student*& students, int& count) {
    if (count < MAX_STUDENTS) {
        Student newStudent;
        cout << "Enter last name: ";
        cin >> newStudent.lastName;
        cout << "Enter initials: ";
        cin >> newStudent.initials;

        cout << "Enter grades for 5 subjects:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Enter grade for subject " << i + 1 << ": ";
            cin >> newStudent.grades[i];
        }

        students[count++] = newStudent;
        cout << "Student added successfully.\n";
    } else {
        cout << "Maximum number of students reached.\n";
    }
}

void removeStudent(Student*& students, int& count) {
    string lastNameToRemove;
    cout << "Enter the last name of the student to remove: ";
    cin >> lastNameToRemove;

    int indexToRemove = -1;
    for (int i = 0; i < count; ++i) {
        if (students[i].lastName == lastNameToRemove) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1) {
        for (int i = indexToRemove; i < count - 1; ++i) {
            students[i] = students[i + 1];
        }
        --count;
        cout << "Student removed successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

void editStudentInfo(Student* students, int count) {
    string lastNameToEdit;
    cout << "Enter the last name of the student to edit: ";
    cin >> lastNameToEdit;

    int indexToEdit = -1;
    for (int i = 0; i < count; ++i) {
        if (students[i].lastName == lastNameToEdit) {
            indexToEdit = i;
            break;
        }
    }

    if (indexToEdit != -1) {
        cout << "Enter new information for the student:\n";
        cout << "Enter last name: ";
        cin >> students[indexToEdit].lastName;
        cout << "Enter initials: ";
        cin >> students[indexToEdit].initials;

        cout << "Enter grades for 5 subjects:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Enter grade for subject " << i + 1 << ": ";
            cin >> students[indexToEdit].grades[i];
        }

        cout << "Student information updated successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

void displayAllStudents(const Student* students, int count) {
    if (count > 0) {
        cout << "List of all students:\n";
        for (int i = 0; i < count; ++i) {
            cout << "Student " << i + 1 << ":\n";
            cout << "Last Name: " << students[i].lastName << "\n";
            cout << "Initials: " << students[i].initials << "\n";
            cout << "Grades: ";
            for (int j = 0; j < 5; ++j) {
                cout << students[i].grades[j] << " ";
            }
            cout << "\n\n";
        }
    } else {
        cout << "No students to display.\n";
    }
}

void displayTopStudents(const Student* students, int count) {
    if (count > 0) {
        cout << "List of top students:\n";
        for (int i = 0; i < count; ++i) {
            bool allGradesAreFive = true;
            for (int j = 0; j < 5; ++j) {
                if (students[i].grades[j] != 5) {
                    allGradesAreFive = false;
                    break;
                }
            }
            if (allGradesAreFive) {
                cout << "Student " << i + 1 << ":\n";
                cout << "Last Name: " << students[i].lastName << "\n";
                cout << "Initials: " << students[i].initials << "\n";
                cout << "\n\n";
            }
        }
    } else {
        cout << "No students to display.\n";
    }
}

void displayStudentsWithThrees(const Student* students, int count) {
    if (count > 0) {
        cout << "List of students with threes:\n";
        for (int i = 0; i < count; ++i) {
            bool hasThrees = false;
            for (int j = 0; j < 5; ++j) {
                if (students[i].grades[j] == 3) {
                    hasThrees = true;
                    break;
                }
            }
            if (hasThrees) {
                cout << "Student " << i + 1 << ":\n";
                cout << "Last Name: " << students[i].lastName << "\n";
                cout << "Initials: " << students[i].initials << "\n";
                cout << "\n\n";
            }
        }
    } else {
        cout << "No students to display.\n";
    }
}

void displayStudentsWithTwos(const Student* students, int count) {
    if (count > 0) {
        cout << "List of students with twos:\n";
        for (int i = 0; i < count; ++i) {
            bool allGradesAreTwo = true;
            int countOfTwos = 0;
            for (int j = 0; j < 5; ++j) {
                if (students[i].grades[j] == 2) {
                    countOfTwos++;
                    if (countOfTwos > 1) {
                        allGradesAreTwo = false;
                        break;
                    }
                } else if (students[i].grades[j] != 2) {
                    allGradesAreTwo = false;
                    break;
                }
            }
            if (allGradesAreTwo) {
                cout << "Student " << i + 1 << ":\n";
                cout << "Last Name: " << students[i].lastName << "\n";
                cout << "Initials: " << students[i].initials << "\n";
                cout << "\n\n";
            }
        }
    } else {
        cout << "No students to display.\n";
    }
}

void saveToFile(const Student* students, int count, const string& filename) {
    ofstream outFile(filename);

    // if (outFile.is_open()) {
        for (int i = 0; i < count; ++i) {
            outFile << students[i].lastName << " " << students[i].initials << " ";
            for (int j = 0; j < 5; ++j) {
                outFile << students[i].grades[j] << " ";
            }
            outFile << "\n";
        }

        cout << "Data saved to " << filename << " successfully.\n";
        // outFile.close();
    // } else {
    //     cerr << "Unable to open file: " << filename << "\n";
    // }
}

void loadFromFile(Student*& students, int& count, const string& filename) {
    ifstream inFile(filename);

    // if (inFile.is_open()) {
        count = 0;
        while (!inFile.eof() && count < MAX_STUDENTS) {
            inFile >> students[count].lastName >> students[count].initials;
            for (int j = 0; j < 5; ++j) {
                inFile >> students[count].grades[j];
            }
            count++;
        }

        cout << "Data loaded from " << filename << " successfully.\n";
        // inFile.close();
    // } else {
    //     cerr << "Unable to open file: " << filename << "\n";
    // }
}
