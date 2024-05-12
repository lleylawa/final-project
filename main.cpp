#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

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

void main_menu() {
    int choice;
    while (choice != 6) {
        system("clear");
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
        case 1: add();
            break;
        case 2: display();
            break;
        case 3: rooms();
            break;
        case 4: edit();
            break;
        case 5: return;
        default:
            {
                cout << "\n\n\t\tWrong choice.";
                cout << "\n\t\tPress any key to continue.";
                getchar();
            }
        }
    }
}

void add() {
    system("clear");
    int r, flag;
    ofstream fout("Record.txt", ios::app);
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
            fout << r << " " << name << " " << phone << " " << days << " " << rtype << " " << cost << endl;
            cout << "\n Room has been booked.";
        }
    }
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
    fout.close();
}

void display() {
    system("clear");
    ifstream fin("Record.txt");
    int r;
    cout << "\n Enter Room Number: ";
    cin >> r;
    bool found = false;
    string name, phone, rtype;
    long days, cost;
    while (fin >> r >> name >> phone >> days >> rtype >> cost) {
        if (r == r) {
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
    fin.close();
}

void rooms() {
    system("clear");
    ifstream fin("Record.txt");
    cout << "\n\t\t\t    LIST OF ROOMS ALLOTED";
    cout << "\n\t\t\t   -----------------------";
    cout << "\n\n +---------+-----------------+---------------+-------------+";
    cout << "\n | Room No.|   Guest Name    |  Room Type    | Contact No. |";
    cout << "\n +---------+-----------------+---------------+-------------+";
    int r;
    string name, phone, rtype;
    long days, cost;
    while (fin >> r >> name >> phone >> days >> rtype >> cost) {
        cout << "\n | " << setw(7) << left << r << " | " << setw(15) << left << name << " | " << setw(13) << left << rtype << " | " << setw(11) << left << phone << " |";
    }
    cout << "\n +---------+-----------------+---------------+-------------+";
    cout << "\n\n\n\t\t\tPress any key to continue.";
    getchar();
    getchar();
    fin.close();
}


void edit() {
    system("clear");
    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n\n 1. Modify Customer Information.";
    cout << "\n 2. Customer Check Out.";
    cout << "\n Enter your choice: ";
    cin >> choice;
    system("clear");
    switch (choice) {
    case 1:
        modify();
        break;
    case 2:
        delete_rec();
        break;
    default:
        cout << "\n Wrong Choice.";
        break;
    }
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

int check(int r) {
    ifstream fin("Record.txt");
    int room_no;
    string name, phone, rtype;
    long days, cost;
    while (fin >> room_no >> name >> phone >> days >> rtype >> cost) {
        if (room_no == r) {
            fin.close();
            return 1; // Room is booked
        }
    }
    if (r > 100) {
        fin.close();
        return 2; // Room does not exist
    }
    fin.close();
    return 0; // Room is vacant
}

void modify() {
    system("clear");
    int ch, r;
    cout << "\n MODIFY MENU";
    cout << "\n -----------";
    cout << "\n\n\n 1. Modify Name";
    cout << "\n 2. Modify Phone Number";
    cout << "\n 3. Modify Number of Days of Stay";
    cout << "\n Enter Your Choice: ";
    cin >> ch;
    system("clear");
    cout << "\n Enter Room Number: ";
    cin >> r;
    switch (ch) {
    case 1: modify_name(r);
        break;
    case 2: modify_phone(r);
        break;
    case 3: modify_days(r);
        break;
    default: cout << "\n Wrong Choice";
        getchar();
        getchar();
        break;
    }
}

void modify_name(int r) {
    ifstream fin("Record.txt");
    ofstream fout("temp.txt");
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
    fin.close();
    fout.close();
    remove("Record.txt");
    rename("temp.txt", "Record.txt");
}

void modify_phone(int r) {
    ifstream fin("Record.txt");
    ofstream fout("temp.txt");
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
    fin.close();
    fout.close();
    remove("Record.txt");
    rename("temp.txt", "Record.txt");
}

void modify_days(int r) {
    ifstream fin("Record.txt");
    ofstream fout("temp.txt");
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
    fin.close();
    fout.close();
    remove("Record.txt");
    rename("temp.txt", "Record.txt");
}

void delete_rec() {
    int r;
    cout << "\n Enter Room Number: ";
    cin >> r;
    ifstream fin("Record.txt");
    ofstream fout("temp.txt");
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
    fin.close();
    fout.close();
    if (!found)
        cout << "\n Sorry, Room is Vacant.";
    else {
        remove("Record.txt");
        rename("temp.txt", "Record.txt");
    }
    getchar();
    getchar();
}

int main() {
    system("clear");
    main_menu();
    return 0;
}
