#include<iostream>
#include<string>
#include<regex>

using namespace std;

// EMAIL VALIDATION
bool emailValidate(string email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

// ADMIN MENU
char adminMenuDisplay() {
    char options;
    cout << "\n--- Admin Menu ---\n";
    cout << "1. Students and Courses Management\n";
    cout << "2. Result Management\n";
    cout << "3. Display Result\n";
    cout << "0. Exit\n";
    cout << "Select Option: ";
    cin >> options;
    return options;
}

// PASSWORD VALIDATION
bool passwordValidate(string password) {
    return (password.length() >= 8 && password.length() <= 15);
}

// CREATE ADMIN ACCOUNT
bool createAdminAccount() {
    string adminEmail, adminPass;
    cout << "Enter Admin Email: ";
    cin >> adminEmail;
    cout << "Enter Admin Password: ";
    cin >> adminPass;

    bool isValidEmail = emailValidate(adminEmail);
    bool isValidPassword = passwordValidate(adminPass);

    if (isValidEmail && isValidPassword) {
        cout << "Valid credentials\n";
        return true;
    } else {
        cout << "Invalid credentials\n";
        return false;
    }
}

// ADMIN LOGIN
int AdminLogin() {
    string adminEmail, adminPass;
    cout << "Enter Admin Email: ";
    cin >> adminEmail;
    cout << "Enter Admin Password: ";
    cin >> adminPass;

    bool isValidEmail = emailValidate(adminEmail);
    bool isValidPassword = passwordValidate(adminPass);

    if (isValidEmail && isValidPassword) {
        string storedEmail = "test@gmail.com";
        string storedPassword = "password";

        if (adminEmail == storedEmail && adminPass == storedPassword) {
            
            float percentage;
            char grade;
            int totalsubjects;
            string name, rollno;

            while (true) {

                char optionSelected = adminMenuDisplay();
                if (optionSelected == '0') {
                    break;

                } else if (optionSelected == '1') {
                    // Student info & course info
                    cin.ignore();
                    cout << "\nEnter student name: ";
                    getline(cin, name);
                    cout << "Enter student roll number: ";
                    cin >> rollno;
                    cout << "\nHow many subjects? ";
                    cin >> totalsubjects;

                    if (totalsubjects > 0) {
                        int subjects[totalsubjects];
                        int i = 0;
                        while (i < totalsubjects) {
                            int marks;
                            cout << "Enter marks for subject " << (i + 1) << ": ";
                            cin >> marks;
                            if (marks >= 0 && marks <= 100) {
                                subjects[i] = marks;
                                i++;
                            } else {
                                cout << "Invalid marks. Please enter between 0 and 100.\n";
                            }
                        }
                        cout << "Student and course data added successfully!\n";
                    } else {
                        cout << "Invalid number of subjects.\n\n";
                    }

                } else if (optionSelected == '2') {
                    // Result Management
                    int n;
                    cout << "\nEnter total number of subjects: ";
                    cin >> n;

                    if (n > 0) {
                        int marks[n];
                        int total = 0;

                        for (int i = 0; i < n; i++) {
                            cout << "Enter marks for subject " << (i + 1) << ": ";
                            cin >> marks[i];

                            if (marks[i] < 0 || marks[i] > 100) {
                                cout << "Invalid marks. Enter again.\n";
                                i--;  // ask again
                                continue;
                            }
                            total += marks[i];
                        }

                        percentage = (float)total / (n * 100) * 100;
                        

                        if (percentage >= 90) grade = 'A';
                        else if (percentage >= 80) grade = 'B';
                        else if (percentage >= 70) grade = 'C';
                        else if (percentage >= 60) grade = 'D';
                        else grade = 'F';

                        cout << "\n--- Result ---\n";
                        cout << "Total Marks: " << total << " / " << n * 100 << endl;
                        cout << "Percentage: " << percentage << "%\n";
                        cout << "Grade: " << grade << "\n";

                    } else {
                        cout << "Invalid number of subjects.\n";
                    }

                } else if (optionSelected == '3') {
                    // Displaying result
                    cout << "\n----Displaying result :----\n";
                    cout << "Student Name : " << name << endl;
                    cout << "Student RollNo : " << rollno << "\n\n";
                    cout << "Total Marks : " << totalsubjects << endl;
                    cout << "Percentage : " << percentage << endl;
                    cout << "Grade : " << grade << endl; 
                } else {
                    cout << "Invalid option.\n";
                }
            }

        } else {
            cout << "Login failed! Incorrect credentials.\n";
        }

    } else {
        cout << "Incorrect email or password format.\n";
    }
    return 0;
}

// MAIN MENU
char getAdminAction() {
    char options;
    cout << "\n--- Welcome ---\n";
    cout << "1. Create Admin Account\n";
    cout << "2. Login Account\n";
    cout << "3. Exit\n";
    cout << "Select Option: ";
    cin >> options;
    return options;
}


int main() {
    while (true) {
        char selectedOption = getAdminAction();

        if (selectedOption == '1') {
            if (createAdminAccount())
                cout << "Account created successfully.\n";
            else
                cout << "Account creation failed.\n";

        } else if (selectedOption == '2') {
            AdminLogin();

        } else if (selectedOption == '3') {
            cout << "Thank You.\nApplication closed.\n";
            break;

        } else {
            cout << "Please select a valid option.\n";
        }
    }
    return 0;
}
