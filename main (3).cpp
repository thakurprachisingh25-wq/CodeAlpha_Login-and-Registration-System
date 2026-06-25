/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Registration Function
void registerUser() {
    string username, password;
    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Validate input
    if (username.empty() || password.empty()) {
        cout << "Error: Username and Password cannot be empty!\n";
        return;
    }

    // Check duplicate username
    ifstream readFile("users.txt");
    string u, p;

    while (readFile >> u >> p) {
        if (u == username) {
            cout << "Error: Username already exists!\n";
            readFile.close();
            return;
        }
    }
    readFile.close();

    // Store credentials
    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser() {
    string username, password;
    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream readFile("users.txt");
    string u, p;
    bool found = false;

    while (readFile >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    readFile.close();

    if (found)
        cout << "Login Successful! Welcome, " << username << ".\n";
    else
        cout << "Error: Invalid Username or Password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== LOGIN & REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}