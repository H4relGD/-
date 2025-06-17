#include <iostream>
#include <string>
using namespace std;

string username = "User";
bool setupDone = false;

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
}

void setup() {
    cout << "=== VS89Kernel Setup ===\n";
    cout << "Press Enter, Then Enter your username: ";
    cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, username);
    if (username == "") username = "User";
    setupDone = true;
    cout << "Setup complete! Welcome, " << username << "!\n";
    pause();
}

void showMenu() {
    cout << "\n=== VS89Kernel Alpha 1.6 ===\n";
    cout << "Welcome, " << username << "!\n";
    cout << "1. Calculator\n";
    cout << "2. About\n";
    cout << "3. Shutdown\n";
    cout << "Choose an option: ";
}

void runCalculator() {
    double a, b;
    char op;
    cout << "\nCalculator\n";
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter operator (+ - * /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> b;
    cin.ignore();

    cout << "Result: ";
    if (op == '+') cout << a + b;
    else if (op == '-') cout << a - b;
    else if (op == '*') cout << a * b;
    else if (op == '/') {
        if (b == 0) cout << "Error: Division by zero";
        else cout << a / b;
    } else cout << "Invalid operator";
    cout << endl;
    pause();
}

void showAbout() {
    cout << "\nVS89Kernel Alpha 1.6\n";
    cout << "Created by H4rel\n";
    pause();
}

void shutdown() {
    cout << "\nShutting down...\nGoodbye, " << username << "!\n";
}

int main() {
    if (!setupDone) setup();

    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) runCalculator();
        else if (choice == 2) showAbout();
        else if (choice == 3) {
            shutdown();
            running = false;
        } else {
            cout << "Invalid choice.\n";
            pause();
        }
    }

    return 0;
}