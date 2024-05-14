# Documentation

## Purpose
The Hotel Room Reservation System is designed to manage bookings, customer information, and room allotments for a hotel. It allows hotel staff to perform various tasks such as adding new bookings, displaying customer information, editing customer details, and checking out customers.

## Design Decisions
- **Modular Design**: The codebase is divided into functions and modules to enhance readability and maintainability.
- **File-based Storage**: Customer and booking information is stored in a text file (`output.txt`). This approach simplifies data management and persistence.
- **User Interface**: The user interface is text-based, utilizing the console for input and output. This design choice ensures ease of use.

## Algorithms Used
- **Room Availability Check**: When adding a new booking, the system checks if the specified room is available by reading through the booking records.
- **Searching and Modifying Records**: Functions like `display`, `modify`, and `delete_rec` utilize file input/output operations to search, modify, and delete customer records efficiently.

## Data Structures
- **File Format**: The system stores booking records in a structured format within the text file (`output.txt`). Each record contains room number, customer name, phone number, days of stay, room type, and cost.
- **Variables**: Simple variables are used to store room numbers, customer names, phone numbers, days of stay, room types, and costs.

## Functions/Modules
1. **`main_menu()`**: Displays the main menu and handles user input to navigate through different functionalities.
2. **`add()`**: Allows users to add a new booking by specifying customer details and room number.
3. **`display()`**: Displays customer information for a specified room number.
4. **`rooms()`**: Displays all allotted rooms and their corresponding customer information.
5. **`edit()`**: Provides options to edit customer details or check out customers.
6. **`check()`**: Allows to check room availability.
7. **`modify()`**: Sub-menu for modifying customer information, such as name, phone number, or days of stay.
8. **`modify_name()`**: Modifies the customer name for a specified room.
9. **`modify_phone()`**: Modifies the customer phone number for a specified room.
10. **`modify_days()`**: Modifies the number of days of stay for a specified room.
11. **`delete_rec()`**: Deletes customer record.


## How to Use
1. **Compilation**: Compile the source code using a C++ compiler.
2. **Execution**: Run the compiled executable file.
3. **Main Menu**: Upon execution, the main menu will be displayed, providing various options.
4. **Navigation**: Use numeric input to select desired options from the main menu.
5. **Input**: Follow the prompts to input necessary information for adding, displaying, editing, or checking out customer bookings.
6. **Exit**: Choose the exit option from the main menu to close the program.
