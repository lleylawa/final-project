# Documentation

## Purpose
The Hotel Room Reservation System is designed to manage bookings, customer information, and room allotments for a hotel. It allows hotel staff to perform various tasks such as adding new bookings, displaying customer information, editing customer details, and checking out customers.

## Design Decisions
- **Data Persistence**: Customer data is stored in a file `(output.txt)` to ensure that the information is retained between program runs.
- **Data Structure**: A vector is used to store customer records in memory due to its dynamic size and ease of use for sequential data.
- **Modular Design**: The program is divided into functions that handle specific tasks, making the code more organized and easier to maintain.
  
## Algorithms and Data Structures
- **Struct Customer**: This struct represents the customer data, encapsulating room number, name, phone, days of stay, room type, and cost.
- **Vector customers**: A global vector that holds all customer records, allowing efficient addition, deletion, and modification of records.
- **File Operations**: Functions load_data and save_data handle reading from and writing to the file, respectively, ensuring data persistence.

## Functions/Modules
1. **`load_data()`**: Loads customer data from the file into the global customers vector.
2. **`save_data()`**: Writes customer data from the customers vector to the file. Ensures data is saved before the program exits.
3. **`main_menu()`**: Displays the main menu and handles user input. Calls appropriate functions based on user choices. Loads data at the start and saves data before exiting.
4. **`add()`**: Handles room booking. Prompts user for customer details and checks room availability using check(). Calculates the cost based on room type and number of days.
5. **`display()`**: Displays customer information for a specific room. Searches the customers vector for the specified room number.
6. **`rooms()`**: Displays all allotted rooms and corresponding customer information. Iterates through the customers vector and prints details.
7. **`edit()`**: Provides a menu for editing customer details or checking out. Calls modify() for editing and delete_rec() for checking out.
8. **`check(int r)`**: Checks the status of a room. Returns 1 if the room is booked, 2 if the room does not exist, and 0 if the room is vacant.
9. **`modify()`**: Provides options to modify name, phone number, or number of days of stay. Calls corresponding modify functions based on user choice.
10. **`modify_name(int r)`**: Modifies the name of the customer in the specified room.
11. **`modify_phone(int r)`**: Modifies the phone number of the customer in the specified room.
12. **`modify_days(int r)`**: Modifies the number of days of stay and recalculates the cost for the customer in the specified room.
13. **`delete_rec()`**: Deletes the customer record for the specified room number, effectively checking them out.Confirms the check-out action with the user before deletion.

## How to Use
1. **Compilation**: Compile the source code using a C++ compiler.
2. **Execution**: Run the compiled executable file.
3. **Main Menu**: Upon execution, the main menu will be displayed, providing various options.
4. **Navigation**: Use numeric input to select desired options from the main menu.
5. **Input**: Follow the prompts to input necessary information for adding, displaying, editing, or checking out customer bookings.
6. **Exit**: Choose the exit option from the main menu to close the program.
