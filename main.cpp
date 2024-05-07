#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to represent a hotel room
struct Room {
    int number;
    bool available;
    string guestName;
};

// Function prototypes
void displayMenu();
void createReservation(vector<Room>& rooms);
void readReservation(const vector<Room>& rooms);
void updateReservation(vector<Room>& rooms);
void deleteReservation(vector<Room>& rooms);
void saveToFile(const vector<Room>& rooms);
void loadFromFile(vector<Room>& rooms);
void generateReport(const vector<Room>& rooms);

int main() {
    vector<Room> rooms;
    loadFromFile(rooms); // Load existing reservations from file

    char choice;
    do {
        displayMenu(); // Display menu options
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case '1':
                createReservation(rooms);
                break;
            case '2':
                readReservation(rooms);
                break;
            case '3':
                updateReservation(rooms);
                break;
            case '4':
                deleteReservation(rooms);
                break;
            case '5':
                generateReport(rooms);
                break;
            case '6':
                saveToFile(rooms); // Save reservations to file
                cout << "Data saved successfully.\n";
                break;
            case '7':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '7');

    return 0;
}

// Function to display menu options
void displayMenu() {
    cout << "Hotel Room Reservation System\n";
    cout << "1. Create Reservation\n";
    cout << "2. Read Reservation\n";
    cout << "3. Update Reservation\n";
    cout << "4. Delete Reservation\n";
    cout << "5. Generate Report\n";
    cout << "6. Save Data\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

// Function to create a new reservation
void createReservation(vector<Room>& rooms) {
    Room room;
    cout << "Enter room number: ";
    cin >> room.number;

    // Check if the room is already reserved
    for (Room& r : rooms) {
        if (r.number == room.number && !r.available) {
            cout << "Room already reserved.\n";
            return;
        }
    }

    // Set room as available and capture guest name
    room.available = true;
    cin.ignore(); // Clear input buffer
    cout << "Enter guest name: ";
    getline(cin, room.guestName);

    rooms.push_back(room); // Add reservation to vector
    cout << "Reservation created successfully.\n";
}

// Function to read reservation details
void readReservation(const vector<Room>& rooms) {
    cout << "Room Number\tGuest Name\n";
    for (const Room& room : rooms) {
        if (room.available) {
            cout << room.number << "\t\t" << room.guestName << endl;
        }
    }
}

// Function to update an existing reservation
void updateReservation(vector<Room>& rooms) {
    int roomNumber;
    cout << "Enter room number to update: ";
    cin >> roomNumber;

    for (Room& room : rooms) {
        if (room.number == roomNumber && room.available) {
            cout << "Enter new guest name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, room.guestName);
            cout << "Reservation updated successfully.\n";
            return;
        }
    }

    cout << "Room not found or already reserved.\n";
}

// Function to delete an existing reservation
void deleteReservation(vector<Room>& rooms) {
    int roomNumber;
    cout << "Enter room number to delete: ";
    cin >> roomNumber;

    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->number == roomNumber && it->available) {
            rooms.erase(it); // Remove reservation from vector
            cout << "Reservation deleted successfully.\n";
            return;
        }
    }

    cout << "Room not found or already reserved.\n";
}

// Function to save reservation data to file
void saveToFile(const vector<Room>& rooms) {
    ofstream outFile("reservations.txt");
    if (outFile.is_open()) {
        for (const Room& room : rooms) {
            outFile << room.number << " " << room.available << " " << room.guestName << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to save data to file.\n";
    }
}

// Function to load reservation data from file
void loadFromFile(vector<Room>& rooms) {
    ifstream inFile("reservations.txt");
    if (inFile.is_open()) {
        Room room;
        while (inFile >> room.number >> room.available) {
            inFile.ignore(); // Ignore space
            getline(inFile, room.guestName);
            rooms.push_back(room); // Add loaded reservation to vector
        }
        inFile.close();
    }
}

// Function to generate report based on user-specified criteria
void generateReport(const vector<Room>& rooms) {
    int availableRooms = 0;
    for (const Room& room : rooms) {
        if (room.available) {
            availableRooms++;
        }
    }

    cout << "Total Rooms: " << rooms.size() << endl;
    cout << "Available Rooms: " << availableRooms << endl;
    cout << "Occupied Rooms: " << rooms.size() - availableRooms << endl;
}
