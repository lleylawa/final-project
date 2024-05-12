#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void main_menu();
void add();
void display();
void rooms();
void edit();
int check(int);
void modify();
void modify_name(int);
void modify_phone(int);
void modify_days(int);
void delete_rec();

// Main menu function
void main_menu() {
    int choice = 0;
    // Loop until user chooses to exit
    while (choice != 5) {
        system("cls"); // Clear the screen
        cout << "\n\t\t\t *********************************";
        cout << "\n\t\t\t **HOTEL ROOM RESERVATION SYSTEM**";
        cout << "\n\t\t\t *********************************";
        cout << "\n\t\t\t\t1. Book A Room";
        cout << "\n\t\t\t\t2. Customer Information";
        cout << "\n\t\t\t\t3. Rooms Allotted";
        cout << "\n\t\t\t\t4. Edit Customer Details";
        cout << "\n\t\t\t\t5. Exit";
        cout << "\n\t\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1: add(); // Call add function
            break;
        case 2: display(); // Call display function
            break;
        case 3: rooms(); // Call rooms function
            break;
        case 4: edit(); // Call edit function
            break;
        case 5: return; // Exit the program
        default:
            {
                cout << "\n\n\t\tWrong choice."; // Inform about wrong choice
                cout << "\n\t\tPress any key to continue.";
                getchar();
            }
        }
    }
}

// Function to book a room
void add() {
    system("cls");
    int r, flag;
    // Open files for writing outside the loop
    ofstream mainFile("Main.txt", ios::app); // ios::app to append to file
    ofstream deluxeFile("Deluxe.txt", ios::app);
    ofstream executiveFile("Executive.txt", ios::app);
    ofstream presidentialFile("Presidential.txt", ios::app);
    cout << "\n\t\t\t +-----------------------+";
    cout << "\n\t\t\t | Rooms  |   Room Type  |";
    cout << "\n\t\t\t +-----------------------+";
    cout << "\n\t\t\t |   1-50 |    Deluxe    |";
    cout << "\n\t\t\t |  51-80 |   Executive  |";
    cout << "\n\t\t\t | 81-100 | Presidential |";
    cout << "\n\t\t\t +-----------------------+";
    cout << "\n\n ENTER CUSTOMER DETAILS: ";
    cout << "\n\n Room Number: ";
    cin >> r;
    flag = check(r);
    if (flag == 1)
        cout << "\n Sorry, Room is already booked.\n";
    else {
        if (flag == 2)
            cout << "\n Sorry, Room does not exist.\n";
        else {
            string name, phone, rtype;
            long days, cost;
            cout << " Name: ";
            cin >> name;
            cout << " Phone Number: ";
            cin >> phone;
            cout << " Number of Days: ";
            cin >> days;
            if (r >= 1 && r <= 50) {
                rtype = "Deluxe";
                cost = days * 10000;
                deluxeFile << r << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
            }
            else if (r >= 51 && r <= 80) {
                rtype = "Executive";
                cost = days * 12500;
                executiveFile << r << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
            }
            else if (r >= 81 && r <= 100) {
                rtype = "Presidential";
                cost = days * 15000;
                presidentialFile << r << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
            }
            mainFile << r << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
            cout << "\n Room has been booked.";
        }
    }
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
    // Close files after adding all customers' details
    mainFile.close();
    deluxeFile.close();
    executiveFile.close();
    presidentialFile.close();
}
// Function to display customer information
void display() {
    system("cls");
    // Open files for reading
    ifstream mainFile("Main.txt");
    ifstream deluxeFile("Deluxe.txt");
    ifstream executiveFile("Executive.txt");
    ifstream presidentialFile("Presidential.txt");
    int r, room_no;
    cout << "\n Enter Room Number: ";
    cin >> r;
    bool found = false;
    string name, phone, rtype;
    long days, cost;
    // Search for the room number in the main file
    while (mainFile >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (r == room_no) {
            found = true;
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n\n Room Number: " << r;
            cout << "\n Name: " << name;
            cout << "\n Phone Number: " << phone;
            cout << "\n Staying for " << days << " days.";
            cout << "\n Room Type: " << rtype;
            cout << "\n Total cost of stay: " << cost;
            break;
        }
    }
    if (!found)
        cout << "\n Room is Vacant.";
    cout << "\n\n Press any key to continue.";
    getchar();
    getchar();
    // Close files
    mainFile.close();
    deluxeFile.close();
    executiveFile.close();
    presidentialFile.close();
}

// Function to display all allotted rooms
void rooms() {
    system("cls");
    // Open files for reading
    ifstream mainFile("Main.txt");
    ifstream deluxeFile("Deluxe.txt");
    ifstream executiveFile("Executive.txt");
    ifstream presidentialFile("Presidential.txt");
    cout << "\n\t\t\t    LIST OF ROOMS ALLOTTED";
    cout << "\n\t\t\t   -----------------------";
    cout << "\n\n +---------+-----------------+---------------+-------------+";
    cout << "\n | Room No.|   Guest Name    |  Room Type    | Contact No. |";
    cout << "\n +---------+-----------------+---------------+-------------+";
    int r;
    string name, phone, rtype;
    long days, cost;
    // Display all customer information from the main file
    while (mainFile >> r >> name >> phone >> days >> rtype >> cost) {
        cout << "\n | " << setw(7) << left << r << " | " << setw(15) << left << name << " | " << setw(13) << left << rtype << " | " << setw(11) << left << phone << " |";
    }
    cout << "\n +---------+-----------------+---------------+-------------+";
    cout << "\n\n\n\t\t\tPress any key to continue.";
    getchar();
    getchar();
    // Close files
    mainFile.close();
    deluxeFile.close();
    executiveFile.close();
    presidentialFile.close();
}

// Function to edit customer details or check out
void edit() {
    system("cls");
    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n\n 1. Modify Customer Information.";
    cout << "\n 2. Customer Check Out.";
    cout << "\n Enter your choice: ";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 1:
        modify(); // Call modify function
        break;
    case 2:
        delete_rec(); // Call delete_rec function
        break;
    default:
        cout << "\n Wrong Choice.";
        break;
    }
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

// Function to check room availability
int check(int r) {
    ifstream mainFile("Main.txt");
    int room_no;
    string name, phone, rtype;
    long days, cost;
    while (mainFile >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            mainFile.close();
            return 1; // Room is booked
        }
    }
    if (r > 100) {
        mainFile.close();
        return 2; // Room does not exist
    }
    mainFile.close();
    return 0; // Room is vacant
}

// Function to modify customer information
void modify() {
    system("cls");
    int ch, r;
    cout << "\n MODIFY MENU";
    cout << "\n -----------";
    cout << "\n\n\n 1. Modify Name";
    cout << "\n 2. Modify Phone Number";
    cout << "\n 3. Modify Number of Days of Stay";
    cout << "\n Enter Your Choice: ";
    cin >> ch;
    system("cls");
    cout << "\n Enter Room Number: ";
    cin >> r;
    switch (ch) {
    case 1: modify_name(r); // Call modify_name function
        break;
    case 2: modify_phone(r); // Call modify_phone function
        break;
    case 3: modify_days(r); // Call modify_days function
        break;
    default: cout << "\n Wrong Choice";
        getchar();
        getchar();
        break;
    }
}

// Function to modify customer name
void modify_name(int r) {
    ifstream mainFile("Main.txt");
    ofstream tempMainFile("tempMain.txt");
    int room_no;
    string name, phone, rtype;
    long days, cost;
    bool modified = false;
    while (mainFile >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            cout << "\n Enter New Name: ";
            cin >> name;
            modified = true;
        }
        tempMainFile << room_no << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
    }
    if (!modified)
        cout << "\n Sorry, Room is vacant.";
    else
        cout << "\n Customer Name has been modified.";
    getchar();
    getchar();
    mainFile.close();
    tempMainFile.close();
    remove("Main.txt");
    rename("tempMain.txt", "Main.txt");
}

// Function to modify customer phone number
void modify_phone(int r) {
    ifstream mainFile("Main.txt");
    ofstream tempMainFile("tempMain.txt");
    int room_no;
    string name, phone, rtype;
    long days, cost;
    bool modified = false;
    while (mainFile >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            cout << "\n Enter New Phone Number: ";
            cin >> phone;
            modified = true;
        }
        tempMainFile << room_no << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
    }
    if (!modified)
        cout << "\n Sorry, Room is vacant.";
    else
        cout << "\n Customer Phone Number has been modified.";
    getchar();
    getchar();
    mainFile.close();
    tempMainFile.close();
    remove("Main.txt");
    rename("tempMain.txt", "Main.txt");
}

// Function to modify number of days of stay
void modify_days(int r) {
    ifstream mainFile("Main.txt");
    ofstream tempMainFile("tempMain.txt");
    int room_no;
    string name, phone, rtype;
    long days, cost;
    bool modified = false;
    while (mainFile >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            cout << " Enter New Number of Days of Stay: ";
            cin >> days;
            // Adjust cost based on room type
            if (room_no >= 1 && room_no <= 50) {
                rtype = "Deluxe";
                cost = days * 1000;
            }
            else {
                if (room_no >= 51 && room_no <= 80) {
                    rtype = "Executive";
                    cost = days * 1250;
                }
                else {
                    if (room_no >= 81 && room_no <= 100) {
                        rtype = "Presidential";
                        cost = days * 1500;
                    }
                }
            }
            modified = true;
        }
        tempMainFile << room_no << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
    }
    if (!modified)
        cout << "\n Sorry, Room is Vacant.";
    else
        cout << "\n Customer information is modified.";
    getchar();
    getchar();
    mainFile.close();
    tempMainFile.close();
    remove("Main.txt");
    rename("tempMain.txt", "Main.txt");
}

// Function to delete customer record
void delete_rec() {
    int r;
    cout << "\n Enter Room Number: ";
    cin >> r;
    ifstream mainFile("Main.txt");
    ofstream tempMainFile("tempMain.txt");
    int room_no;
    string name, phone, rtype;
    long days, cost;
    bool found = false;
    while (mainFile >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            found = true;
            cout << "\n Name: " << name;
            cout << "\n Phone Number: " << phone;
            cout << "\n Room Type: " << rtype;
            cout << "\n Your total bill is: Rs. " << cost;
            cout << "\n\n Do you want to check out this customer(y/n): ";
            char ch;
            cin >> ch;
            if (ch == 'n')
                tempMainFile << room_no << " " << name << " " << " " << phone << " " << days << " " << rtype << " " << cost << endl;
            else
                cout << "\n Customer Checked Out.";
        }
        else
            tempMainFile << room_no << " " << name << " " << " " << phone << " " << days << " " << rtype << " " << cost << endl;
    }
    mainFile.close();
    tempMainFile.close();
    if (!found)
        cout << "\n Sorry, Room is Vacant.";
    else {
        remove("Main.txt");
        rename("tempMain.txt", "Main.txt");
    }
    getchar();
    getchar();
}

// Main function
int main() {
    system("cls");
    main_menu(); // Call main menu function
    return 0;
}
