# Ready-To-Use Test Files

- The provided test files are intended to verify the Hotel Room Reservation System's functionality to confirm that the program operates correctly in various situations.

## Test 1: Booking a room

- **Input in console:**
```
1
10
Aidana
999555111
5
5
```

- **Output:**
```
                         *********************************
                         **HOTEL ROOM RESERVATION SYSTEM**
                         *********************************
                                1. Book A Room
                                2. Customer Information
                                3. Rooms Allotted
                                4. Edit Customer Details
                                5. Exit
                                Enter Your Choice: 1
                         +-----------------------+
                         | Rooms  |   Room Type  |
                         +-----------------------+
                         |   1-50 |    Deluxe    |
                         |  51-80 |   Executive  |
                         | 81-100 | Presidential |
                         +-----------------------+

 ENTER CUSTOMER DETAILS:

 Room Number: 10
 Name: Aidana
 Phone Number: 999555111
 Number of Days: 5

 Room has been booked.
 Press any key to continue.

                         *********************************
                         **HOTEL ROOM RESERVATION SYSTEM**
                         *********************************
                                1. Book A Room
                                2. Customer Information
                                3. Rooms Allotted
                                4. Edit Customer Details
                                5. Exit
                                Enter Your Choice: 5

--------------------------------
Process exited after 339.4 seconds with return value 0
```
- **Output File:**
```
10 Aidana 999555111 5 Deluxe 50000
```
## Test 2: Editing Information

- **Input in Console:**
```
4
1
1
10
Erika
5
```
- **Output:**
```
                         *********************************
                         **HOTEL ROOM RESERVATION SYSTEM**
                         *********************************
                                1. Book A Room
                                2. Customer Information
                                3. Rooms Allotted
                                4. Edit Customer Details
                                5. Exit
                                Enter Your Choice: 4
 EDIT MENU
 ---------


 1. Modify Customer Information.
 2. Customer Check Out.
 Enter your choice: 1
 MODIFY MENU
 -----------


 1. Modify Name
 2. Modify Phone Number
 3. Modify Number of Days of Stay
 Enter Your Choice: 1

 Enter Room Number: 10

 Enter New Name: Erika

 Customer Name has been modified.

 Press any key to continue.

                         *********************************
                         **HOTEL ROOM RESERVATION SYSTEM**
                         *********************************
                                1. Book A Room
                                2. Customer Information
                                3. Rooms Allotted
                                4. Edit Customer Details
                                5. Exit
                                Enter Your Choice: 5

--------------------------------
Process exited after 250.1 seconds with return value 0
```
- **Output File:**
```
10 Erika 999555111 5 Deluxe 50000
```

## Test 3: Deleting a reservation

- **Input in Console:**
```
4
2
10
y
```
- **Output:**
```
                         *********************************
                         **HOTEL ROOM RESERVATION SYSTEM**
                         *********************************
                                1. Book A Room
                                2. Customer Information
                                3. Rooms Allotted
                                4. Edit Customer Details
                                5. Exit
                                Enter Your Choice: 4
 EDIT MENU
 ---------


 1. Modify Customer Information.
 2. Customer Check Out.
 Enter your choice: 2
 Enter Room Number: 10

 Name: Erika
 Phone Number: 999555111
 Room Type: Deluxe
 Your total bill is: Rs. 50000

 Do you want to check out this customer(y/n): y

 Customer Checked Out.
  
 Press any key to continue.
                         *********************************
                         **HOTEL ROOM RESERVATION SYSTEM**
                         *********************************
                                1. Book A Room
                                2. Customer Information
                                3. Rooms Allotted
                                4. Edit Customer Details
                                5. Exit
                                Enter Your Choice: 5

--------------------------------
Process exited after 250.1 seconds with return value 0
```
## Expected Output
- Confirm that the program's behavior aligns with the expected output outlined in each test case after running each test file. Validate that rooms are reserved or vacant as specified and that the program gracefully exits once the test scenario is completed.

