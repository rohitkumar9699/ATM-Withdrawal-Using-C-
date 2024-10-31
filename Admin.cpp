#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>  // For exit function

using namespace std;

void writeToFile(const string &filePath, int &account_number, string &name, int &pin, int &amount, int &number) {
    try {
        ofstream outFile(filePath.c_str(), ios::app);  // Open file in append mode
        if (!outFile) {
            throw runtime_error("File could not be opened for writing.");
        }

        outFile << account_number << ", " << name << ", " << pin << ", " << amount << ", " << number << "\n";
        cout << "Data written to file successfully." << endl;

        outFile.close();
    } catch (const runtime_error &e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void readFromFile(const string &filePath, int account_number) {
    ifstream inFile(filePath.c_str());  // Open file for reading
    
	string line;
    while (getline(inFile, line)) { 
        stringstream ss(line);  
        string substring;

        // Split and print each substring separated by commas
        while (getline(ss, substring, ',')) {
            cout << substring << endl;
            break;
        }
        cout << "-------------------------" << endl;  // Separator between lines for clarity
    }
  
}

int main() {
    cout << "*******Welcome Admin********";
    do {
        cout << "\n\nPress Buttons For Given Operations:";
        cout << "\n\n1. Add New User";
        cout << "\n2. Delete Existing User";
        cout << "\n3. Exit\n\n";

        int n;
        cin >> n;

        string filePath = "C:\\Users\\rohit\\Desktop\\c++\\Users.txt";

        switch(n) {
            case 1: {
                int account_number, pin, amount, number;
                string name;
                
                cout << "\nEnter Account Number: ";
                cin >> account_number;
                
                cout << "Enter Name: ";
                cin >> ws;  // To clear any whitespace before getline
                getline(cin, name);  // Use getline to allow names with spaces
                
                cout << "Enter PIN: ";
                cin >> pin;
                
                cout << "Enter Amount: ";
                cin >> amount;
                
                cout << "Enter Phone Number: ";
                cin >> number;

                writeToFile(filePath, account_number, name, pin, amount, number);
                break;
            }
            case 2:
            	int account_number;
            	cout << "\nEnter Account Number: ";
                cin >> account_number;
                readFromFile(filePath, account_number);
                break;
            case 3:
                exit(0);
            default:  // handle invalid user inputs
                cout << "\nInvalid Operation!!!";
        }
    } while (1);

    return 0;
}

