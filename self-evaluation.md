# Self-Evaluation

## Name: Tammy Le

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0
Yes, all functions have been implemented.

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full

<<<<<<< HEAD
Q: -1 for each compilation warning, min -3: 0
Refer to read me on compilation warnings.
=======
Q: -1 for each compilation warning, min -3: -3
>>>>>>> 0c2b65d467b5a7bc6b68fedf9558182810c2113f

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: -1
Refer to read me on compilation warnings.

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: -2

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0
Yes, every .h and .cpp are documented.

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: RentalManager.cpp /RentalManager - readCommands

invalid movie type: Storage.cpp/ retrieve 

invalid customer ID: Customer.cpp / customer - set data
 
invalid movie: Storage.cpp / retrieve

factory classes: TransFactory, MovieFactory, ItemFactory

hashtable: (explain what the hashtable is used for) RentalManager.cpp / Used for customer's information and organizing the Movie BSTrees by genre

container used for comedy movies: Storage.cpp

function for sorting comedy movies: BSTree.pp / bool insert(Item *)

function where comedy movies are sorted: BSTree.pp / bool insert(Item *)

functions called when retrieving a comedy movie based on title and year: Storage.cpp / bool retrieveItem(Item* item, Item*& retriever)

functions called for retrieving and printing customer history: History.cpp / void History::doTransaction(Storage& , HashMap& customerMap)

container used for customer history: Customer.h / vector<Transaction> history_

functions called when borrowing a movie: Borrow.setData() / Storage.retrieve() / BSTree.retrieve() / comparison operators / Movie.borrow() / Customer.addHistory()

explain borrowing a movie that does not exist: Will try to look up the movie and not find in the Movie genre BSTree so will say movie not found and not complete the transaction.

explain borrowing a movie that has 0 stock: Will get the movie from BSTree, check the available stock, and state that it is out of stock and not complete the transaction.

explain returning a movie that customer has not checked out: Will check customer history for a return transaction and will say not valid request if the movie is not valid to return if doesn't have a borrow.

any static_cast or dynamic_cast used: Used in children classes of Item and Movie in comparison operators


Q: Total points: 22 (max 25)