Title: 
Triple H 

Description: 
This is an automated inventory tracking system for a local movie rental store called Triple H. 

How to run the program:
g++ HashTable.cpp CustomerHistory.cpp CustomerInfo.cpp Movie.cpp MovieClassics.cpp StoreManager.cpp main.cpp

Assumptions and edge cases: 
-Some employees may enter invalid inputs such as invalid media type, invalid customer ID, or invalid movie data type. This will result in an error message. 
-Assume input data is formatted correctly, but codes might be invalid
-Assume the input for the customer data input file is formatted correctly and no need for handling any exception
-Assume the input of “data4commands.txt”  is formatted correctly, but need to handle an invalid action code. 
-If there is any incorrect command, the program needs to handle the exception. 

Files:
- main.cpp
- StoreManager.h
- StoreManager.cpp
- HashTable.h
- HashTable.cpp
- CustomerInfo.h
- CustomerInfo.cpp
- CustomerHistory.h
- CustomerHistory.cpp
- Movie.h
- Movie.cpp 
- MovieClassics.h
- MovieClassics.cpp

- data4movies.txt
- data4customers.txt
- data4commands.txt

Contribution:
Tyson: Movie, MovieClassics, buildMovieLibrary(), inventory(), borrow(), ret(), main.cpp
Helen: CustomerInfo, CustomerHistory, HashTable, borrow(), ret(), history()
Kevin: HashTable, buildCustomerDatabase(), processCommands(), borrow(), ret(), history()
All: comments, debugging, test cases

Changelog:
(Tue)2nd Mar:
Tyson: *movie, *movieclassics, main.cpp, ~buildMovieLibrary, !help Helen (pending)
Kevin: ~StoreManager, ~buildCustomerDatabase, ~processCommands
Helen: ~Hashtable, !customerInfo 

(Thur)4th Mar: 8p-9p

(Fri)5th Mar: 6-8p - plan on a working hashTable, customerInfo, movie, movieClassics, and driver file to test basic functionality
Helen: customInfo/customHistory now working
Tyson: Movie class and driver mostly done. Almost able compile movieClassics
Kevin: customerInfo/CustomHistory and making sure that worked.
future plans for end of Sunday session:
Tyson: have Movie and movieClassics done along with driver done. Jumping into buildMovieLibrary
Helen: Hash table working
Kevin: Hash table working

(Sun)7th Mar: 2p-4p

(Mon)8th Mar: 8p-10p
Tyson: completed movie and movieClassics. Helped Helen with Hash table. Next time, work with Helen on Hash table, completing buildMovieLibrary
Helen: work with Tyson on HashTable and HashTableDriver.cpp, help with others on StoreManager or main.cpp
Kevin: completed buildCustomerDatabase, except for adding to hashTable (BLOCKED pending hashTable). Process commands is complete. next up, work on 4 actions of borrow, return, inventory, and history. 

(Tue)9th Mar: 6p-8p
Kevin: finish up inventory portion
Tyson: Help other with w/e else they need help on.
Helen: Add some functions to Hashtable and update the functions on .cpp and driver file pointer problem in buildCustomerDatabase

(Wed)10th Mar: 8-11p
Kevin: work on hashTable stuff
Tyson: work on inventory, borrow(pseudo), and ret(pseudo) function. 
Helen: Make StoreManager workable with HashTable with borrow/return/hist

(Thur)11 Mar: 8-11pm
All: finish up borrow (other two genres). work on ret. Work on History.
Left over TODOs: read over instructions again to meet all requirements.
                  make comments/clean up code
                  testing for more edge cases

(Fri)12 Mar 6p-8p
    TODOs: read over instructions againt to meet all requirements
    Make comments/clean up code
    testing for more edge cases
    Simplify code areas, hackish areas?

(Mon)15 Mar
    Self-work: testing for edge cases, simplify code areas

(Tue)16 Mar 7pm
    Meet up, final check over and address any problems that arose during self-work
    finalize contributions 

(Wed)17 Mar
    Last questions and submit
