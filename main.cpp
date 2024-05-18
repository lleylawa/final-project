#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

// Struct to represent customer data
struct Customer {
    int room_no;
    string name;
    string phone;
    long days;
    string rtype;
    long cost;
};

// Global vector to store customer data
vector<Customer> customers;

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
void load_data();
void save_data();

// Function to load data from file to vector
void load_data() {
    ifstream fin("output.txt");
    customers.clear();
    Customer customer;
    while (fin >> customer.room_no >> customer.name >> customer.phone >> customer.days >> customer.rtype >> customer.cost) {
        customers.push_back(customer);
    }
    fin.close();
}

// Function to save data from vector to file
void save_data() {
    ofstream fout("output.txt");
    for (const auto& customer : customers) {
        fout << customer.room_no << " " << customer.name << " " << customer.phone << " " << customer.days << " " << customer.rtype << " " << customer.cost << endl;
    }
    fout.close();
}

// Function to display the main menu
void main_menu() {
    int choice = 0;
    load_data(); // Load data when the program starts
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
        case 1: add(); break;
        case 2: display(); break;
        case 3: rooms(); break;
        case 4: edit(); break;
        case 5: save_data(); return;
        default:
            cout << "\n\n\t\tWrong choice.";
            cout << "\n\t\tPress any key to continue.";
            getchar();
            getchar();
        }
    }
}

// Function to add a new booking
void add() {
    system("cls"); // Clear the screen
    int r, flag;
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
    else if (flag == 2)
        cout << "\n Sorry, Room does not exist.\n";
    else {
        Customer customer;
        customer.room_no = r;
        cout << " Name: ";
        cin >> customer.name;
        cout << " Phone Number: ";
        cin >> customer.phone;
        cout << " Number of Days: ";
        cin >> customer.days;
        if (r >= 1 && r <= 50) {
            customer.rtype = "Deluxe";
            customer.cost = customer.days * 10000;
        } else if (r >= 51 && r <= 80) {
            customer.rtype = "Executive";
            customer.cost = customer.days * 12500;
        } else if (r >= 81 && r <= 100) {
            customer.rtype = "Presidential";
            customer.cost = customer.days * 15000;
        }
        customers.push_back(customer);
        cout << "\n Room has been booked.";
    }
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

// Function to display customer information for a specific room
void display() {
    system("cls"); // Clear the screen
    int r;
    cout << "\n Enter Room Number: ";
    cin >> r;
    bool found = false;
    for (const auto& customer : customers) {
        if (customer.room_no == r) {
            found = true;
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n\n Room Number: " << customer.room_no;
            cout << "\n Name: " << customer.name;
            cout << "\n Phone Number: " << customer.phone;
            cout << "\n Staying for " << customer.days << " days.";
            cout << "\n Room Type: " << customer.rtype;
            cout << "\n Total cost of stay: " << customer.cost;
            break;
        }
    }
    if (!found)
        cout << "\n Room is Vacant.";
    cout << "\n\n Press any key to continue.";
    getchar();
    getchar();
}

// Function to display all allotted rooms and customer information
void rooms() {
    system("cls"); // Clear the screen
    cout << "\n\t\t\t    LIST OF ROOMS ALLOTED";
    cout << "\n\t\t\t   -----------------------";
    cout << "\n\n +---------+-----------------+---------------+-------------+";
    cout << "\n | Room No.|   Guest Name    |  Room Type    | Contact No. |";
    cout << "\n +---------+-----------------+---------------+-------------+";
    for (const auto& customer : customers) {
        cout << "\n | " << setw(7) << left << customer.room_no
             << " | " << setw(15) << left << customer.name
             << " | " << setw(13) << left << customer.rtype
             << " | " << setw(11) << left << customer.phone << " |";
    }
    cout << "\n +---------+-----------------+---------------+-------------+";
    cout << "\n\n\n\t\t\tPress any key to continue.";
    getchar();
    getchar();
}

// Function to edit customer details
void edit() {
    system("cls"); // Clear the screen
    int choice;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n\n 1. Modify Customer Information.";
    cout << "\n 2. Customer Check Out.";
    cout << "\n Enter your choice: ";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 1: modify(); break;
    case 2: delete_rec(); break;
    default:
        cout << "\n Wrong Choice.";
        cout << "\n Press any key to continue.";
        getchar();
        getchar();
    }
}

// Function to check room availability
int check(int r) {
    for (const auto& customer : customers) {
        if (customer.room_no == r) {
            return 1; // Room is booked
        }
    }
    if (r > 100) {
        return 2; // Room does not exist
    }
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
    case 1: modify_name(r); break;
    case 2: modify_phone(r); break;
    case 3: modify_days(r); break;
    default:
        cout << "\n Wrong Choice";
        getchar();
        getchar();
    }
}

// Function to modify customer name
void modify_name(int r) {
    bool modified = false;
    for (auto& customer : customers) {
        if (customer.room_no == r) {
            cout << "\n Enter New Name: ";
            cin >> customer.name;
            modified = true;
            break;
        }
    }
    if (!modified)
        cout << "\n Sorry, Room is vacant.";
    else
        cout << "\n Customer Name has been modified.";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

// Function to modify customer phone number
void modify_phone(int r) {
    bool modified = false;
    for (auto& customer : customers) {
        if (customer.room_no == r) {
            cout << "\n Enter New Phone Number: ";
            cin >> customer.phone;
            modified = true;
            break;
        }
    }
    if (!modified)
        cout << "\n Sorry, Room is vacant.";
    else
        cout << "\n Customer Phone Number has been modified.";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

// Function to modify number of days of stay
void modify_days(int r) {
    bool modified = false;
    for (auto& customer : customers) {
        if (customer.room_no == r) {
            cout << " Enter New Number of Days of Stay: ";
            cin >> customer.days;
            if (r >= 1 && r <= 50) {
                customer.rtype = "Deluxe";
                customer.cost = customer.days * 10000;
            } else if (r >= 51 && r <= 80) {
                customer.rtype = "Executive";
                customer.cost = customer.days * 12500;
            } else if (r >= 81 && r <= 100) {
                customer.rtype = "Presidential";
                customer.cost = customer.days * 15000;
            }
            modified = true;
            break;
        }
    }
    if (!modified)
        cout << "\n Sorry, Room is Vacant.";
    else
        cout << "\n Customer information is modified.";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

// Function to delete customer record
void delete_rec() {
    int r;
    cout << "\n Enter Room Number: ";
    cin >> r;
    bool found = false;
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->room_no == r) {
            found = true;
            cout << "\n Name: " << it->name;
            cout << "\n Phone Number: " << it->phone;
            cout << "\n Room Type: " << it->rtype;
            cout << "\n Your total bill is: Rs. " << it->cost;
            cout << "\n\n Do you want to check out this customer(y/n): ";
            char ch;
            cin >> ch;
            if (ch == 'y') {
                customers.erase(it);
                cout << "\n Customer Checked Out.";
            }
            break;
        }
    }
    if (!found)
        cout << "\n Sorry, Room is Vacant.";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

// Main function
int main() {
    system("cls"); // Clear the screen
    main_menu(); // Display the main menu
    return 0;
}
