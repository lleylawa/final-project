**Project Title:** Hotel Room Reservation System

**Description:**
The Hotel Room Reservation System is a software application designed to streamline the process of booking and managing hotel room reservations. It allows hotel staff to add, view, modify, and delete customer reservations efficiently. The system categorizes rooms into different types (Deluxe, Executive, Presidential) and calculates the cost of the stay based on the room type and the number of days booked. Customers can also view their reservation details and make modifications if necessary.

**Project Purpose:**
The purpose of the Hotel Room Reservation System is to automate the process of booking rooms, managing customer information, and handling room check-ins and check-outs in a hotel. This system provides functionalities such as adding new customers, displaying customer information, displaying all allotted rooms, editing customer details, and checking out customers.

**Design Decisions:**
1. **File-Based Storage:** Customer information is stored in text files (`Main.txt`, `Deluxe.txt`, `Executive.txt`, `Presidential.txt`) for simplicity. Each file represents a room type, and customer details are appended to these files when a room is booked.
2. **Modular Design:** The system is divided into functions for different functionalities like booking a room, displaying customer information, modifying customer details, and checking out customers. This modular approach enhances code readability, maintainability, and reusability.
3. **Simple User Interface:** The user interface is text-based and presented in a console window, making it easy to interact with the system. Menu-driven navigation simplifies user interaction.

**Algorithms Used:**
1. **Linear Search:** Used to check if a room is already booked or vacant by searching through the text files containing customer information.
2. **File I/O Operations:** Reading from and writing to text files to store and retrieve customer information.
3. **Switch-Case Statements:** Employed for menu-driven user interface to execute different functionalities based on user input.

**Data Structures Employed:**
1. **File Streams:** Utilized to read from and write to text files for storing and retrieving customer information.
2. **Variables:** Used to store customer details such as room number, name, phone number, days of stay, room type, and total cost.

**Functions/Modules Created:**
1. **Main Menu Function (`main_menu`):** Displays the main menu and calls appropriate functions based on user input.
2. **Add Function (`add`):** Allows users to book a room by entering customer details and stores the information in respective text files based on room type.
3. **Display Function (`display`):** Displays customer information for a given room number.
4. **Rooms Function (`rooms`):** Displays all allotted rooms along with customer details.
5. **Edit Function (`edit`):** Provides options to modify customer details or check out a customer.
6. **Modify Function (`modify`):** Allows users to choose what information to modify (name, phone number, or days of stay).
7. **Modify Name Function (`modify_name`):** Modifies the name of the customer for a given room number.
8. **Modify Phone Function (`modify_phone`):** Modifies the phone number of the customer for a given room number.
9. **Modify Days Function (`modify_days`):** Modifies the number of days of stay for a given room number.
10. **Delete Record Function (`delete_rec`):** Allows users to check out a customer, removing their record from the system.

**How to Use the Software:**
1. Compile the source code file containing the program.
2. Run the compiled executable file.
3. Follow the prompts on the screen to navigate through different functionalities like booking a room, displaying customer information, modifying customer details, or checking out customers.
4. Input data as required and follow the on-screen instructions to interact with the system.


This documentation provides an overview of the project's purpose, design, implementation, and usage instructions, helping understand and utilize the Hotel Room Reservation System effectively.

**Objectives:**
1. Develop a user-friendly interface for hotel staff to manage room reservations.
2. Implement functionality for adding new reservations, including customer details, room selection, and duration of stay.
3. Enable hotel staff to view customer reservation details, including room number, guest name, room type, contact number, and total cost.
4. Allow hotel staff to modify customer information such as name, phone number, and duration of stay.
5. Implement a check-out feature to remove customers from the reservation system once they have checked out.
6. Categorize rooms into different types (Deluxe, Executive, Presidential) and calculate the cost of stay based on the room type and duration of stay.
7. Ensure data integrity and security by properly managing file operations and user input validation.

**Screenshots:**
- ![main menu](https://github.com/lleylawa/final-project/assets/150817035/0ad75fd9-46f0-4f88-8df9-8a5a5578efbf) :
   This screenshot showcases the main menu of the Hotel Room Reservation System, where users can choose various options such as booking a room, viewing customer information, and editing reservations.
  
- ![book a room](https://github.com/lleylawa/final-project/assets/150817035/d8c76c9c-658d-42e7-99f2-1f862ca7f125) :
   This screenshot demonstrates the process of adding a new reservation, including entering customer details, selecting a room, and specifying the duration of stay.
  
- ![show reservation](https://github.com/lleylawa/final-project/assets/150817035/1e850670-71fe-48ff-bca6-e6a129c1338e) :
  Here, users can view the details of a specific reservation, including the room number, guest name, room type, contact number, and total cost.
  
- ![rooms allotted](https://github.com/lleylawa/final-project/assets/150817035/92c4e883-0738-4167-abcc-ddfbd6718564) :
   This screenshot displays a list of all booked rooms, providing an overview of room availability in the hotel.
  
-  ![edit menu](https://github.com/lleylawa/final-project/assets/150817035/523056b4-95cb-4918-885f-6b7bda68d95b)
   ![edit menu(1)](https://github.com/lleylawa/final-project/assets/150817035/32a41d90-8cf8-4571-9faa-640f2321100e) :
  This screenshots illustrate the interface for modifying a reservation, allowing users to update customer information or change the duration of stay, or delete a reservation.
