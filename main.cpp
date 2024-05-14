#include<iostream>
#include<iomanip>
#include<fstream>

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

// Function to display the main menu
void main_menu() {
    int choice = 0;
    // Loop until the user chooses to exit
    while (choice != 6) {
        system("cls"); // Clear the screen
        // Display the menu options
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
        // Perform actions based on user's choice
        switch (choice) {
        case 1: add(); // Add a new booking
            break;
        case 2: display(); // Display customer information
            break;
        case 3: rooms(); // Display rooms allotted
            break;
        case 4: edit(); // Edit customer details
            break;
        case 5: return; // Exit the program
        default:
            {
                cout << "\n\n\t\tWrong choice.";
                cout << "\n\t\tPress any key to continue.";
                getchar();
            }
        }
    }
}

// Function to add a new booking
void add() {
    system("cls"); // Clear the screen
    int r, flag;
    ofstream fout("output.txt", ios::app); // Open file for appending
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
    // Check if the room is available or not
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
            // Determine room type and cost based on room number
            if (r >= 1 && r <= 50) {
                rtype = "Deluxe";
                cost = days * 10000;
            }
            else {
                if (r >= 51 && r <= 80) {
                    rtype = "Executive";
                    cost = days * 12500;
                }
                else {
                    if (r >= 81 && r <= 100) {
                        rtype = "Presidential";
                        cost = days * 15000;
                    }
                }
            }
            // Write booking details to file
            fout << r << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
            cout << "\n Room has been booked.";
        }
    }
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
    fout.close(); // Close the file
}

// Function to display customer information for a specific room
void display() {
    system("cls"); // Clear the screen
    ifstream fin("output.txt"); // Open file for reading
    int r, room_no; 
    cout << "\n Enter Room Number: ";
    cin >> r;
    bool found = false;
    string name, phone, rtype;
    long days, cost;
    // Read data from file and search for the specified room
    while (fin >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (r == room_no) {
            found = true;
            // Display customer details
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
    fin.close(); // Close the file
}

// Function to display all allotted rooms and customer information
void rooms() {
    system("cls"); // Clear the screen
    ifstream fin("output.txt"); // Open file for reading
    cout << "\n\t\t\t    LIST OF ROOMS ALLOTED";
    cout << "\n\t\t\t   -----------------------";
    cout << "\n\n +---------+-----------------+---------------+-------------+";
    cout << "\n | Room No.|   Guest Name    |  Room Type    | Contact No. |";
    cout << "\n +---------+-----------------+---------------+-------------+";
    int r;
    string name, phone, rtype;
    long days, cost;
    // Read data from file and display room allotments
    while (fin >> r >> name >> phone >> days >> rtype >> cost) {
        cout << "\n | " << setw(7) << left << r << " | " << setw(15) << left << name << " | " << setw(13) << left << rtype << " | " << setw(11) << left << phone << " |";
    }
    cout << "\n +---------+-----------------+---------------+-------------+";
    cout << "\n\n\n\t\t\tPress any key to continue.";
    getchar();
    getchar();
    fin.close(); // Close the file
}

// Function to edit customer details
void edit() {
    system("cls"); // Clear the screen
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
        modify(); // Modify customer information
        break;
    case 2:
        delete_rec(); // Check out customer
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
    ifstream fin("output.txt"); // Open file for reading
    int room_no;
    string name, phone, rtype;
    long days, cost;
    while (fin >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            fin.close(); // Close the file
            return 1; // Room is booked
        }
    }
    if (r > 100) {
        fin.close(); // Close the file
        return 2; // Room does not exist
    }
    fin.close(); // Close the file
    return 0; // Room is vacant
}

// Function to modify customer information
void modify() {
    system("cls"); // Clear the screen
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
    case 1: modify_name(r); // Modify customer name
        break;
    case 2: modify_phone(r); // Modify customer phone number
        break;
    case 3: modify_days(r); // Modify number of days of stay
        break;
    default: cout << "\n Wrong Choice";
        getchar();
        getchar();
        break;
    }
}

// Function to modify customer name
void modify_name(int r) {
    ifstream fin("output.txt"); // Open file for reading
    ofstream fout("input.txt"); // Open file for writing
    int room_no;
    string name, phone, rtype;
    long days, cost;
    bool modified = false;
    while (fin >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            cout << "\n Enter New Name: ";
            cin >> name;
            modified = true;
        }
        fout << room_no << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
    }
    if (!modified)
        cout << "\n Sorry, Room is vacant.";
    else
        cout << "\n Customer Name has been modified.";
    getchar();
    getchar();
    fin.close(); // Close the file
    fout.close(); // Close the file
    remove("output.txt"); // Delete old file
    rename("input.txt", "output.txt"); // Rename new file
}

// Function to modify customer phone number
void modify_phone(int r) {
    ifstream fin("output.txt"); // Open file for reading
    ofstream fout("input.txt"); // Open file for writing
    int room_no;
    string name, phone, rtype;
    long days, cost;
    bool modified = false;
    while (fin >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            cout << "\n Enter New Phone Number: ";
            cin >> phone;
            modified = true;
        }
        fout << room_no << " " << name << " " << " " << phone << " " << days << " " << rtype << " " << cost << endl;
    }
    if (!modified)
        cout << "\n Sorry, Room is vacant.";
    else
        cout << "\n Customer Phone Number has been modified.";
    getchar();
    getchar();
    fin.close(); // Close the file
    fout.close(); // Close the file
    remove("output.txt"); // Delete old file
    rename("input.txt", "output.txt"); // Rename new file
}

// Function to modify number of days of stay
void modify_days(int r) {
    ifstream fin("output.txt"); // Open file for reading
    ofstream fout("input.txt"); // Open file for writing
    int room_no;
    string name, phone, rtype;
    long days, cost;
    bool modified = false;
    while (fin >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            cout << " Enter New Number of Days of Stay: ";
            cin >> days;
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
        fout << room_no << " " << name << " " << " " << phone << " " << days << " " << rtype << " " << cost << endl;
    }
    if (!modified)
        cout << "\n Sorry, Room is Vacant.";
    else
        cout << "\n Customer information is modified.";
    getchar();
    getchar();
    fin.close(); // Close the file
    fout.close(); // Close the file
    remove("output.txt"); // Delete old file
    rename("input.txt", "output.txt"); // Rename new file
}

// Function to delete customer record
void delete_rec() {
    int r;
    cout << "\n Enter Room Number: ";
    cin >> r;
    ifstream fin("output.txt"); // Open file for reading
    ofstream fout("input.txt"); // Open file for writing
    int room_no;
    string name, phone, rtype;
    long days, cost;
    bool found = false;
    while (fin >> room_no >> name >> phone >> days >> rtype >> cost) {
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
                fout << room_no << " " << name << " " << " " << phone << " " << days << " " << rtype << " " << cost << endl;
            else
                cout << "\n Customer Checked Out.";
        }
        else
            fout << room_no << " " << name << " " << " " << phone << " " << days << " " << rtype << " " << cost << endl;
    }
    fin.close(); // Close the file
    fout.close(); // Close the file
    if (!found)
        cout << "\n Sorry, Room is Vacant.";
    else {
        remove("output.txt"); // Delete old file
        rename("input.txt", "output.txt"); // Rename new file
    }
    getchar();
    getchar();
}

// Main function
int main() {
    system("cls"); // Clear the screen
    main_menu(); // Display the main menu
    return 0;
}
