# 2022win343d-movies-tammyhkle
2022win343d-movies-tammyhkle created by GitHub Classroom

Description of Movies Project:

A local movie rental store wishes to automate their inventory tracking system. Currently there are three types of movies/videos (in DVD media) to be tracked:

Comedy (denoted as ‘F’ for funny)
Drama (denoted as ‘D’)
Classics (denoted as ‘C’)
Borrows and returns of items by customers are also to be tracked. Four types of actions are desired in the system:

Borrow (denoted as ‘B’): (stock – 1) for each item borrowed  
Return (denoted as ‘R’): (stock + 1) for each item returned
Inventory (denoted as ‘I’): outputs the inventory of all the items in the store
History (denoted as ‘H’): outputs all the transactions of a customer 
 

You will design and implement a program that will initialize the contents of the inventory from a file (data4movies.txt), the customer list from another file (data4customers.txt), 
and then process an arbitrary sequence of commands from a third file (data4commands.txt).

---

If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions:

Compilation warnings:
initialize privtates in constructor - I ignore the warning because I do need the privates and did implement them as well.

- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

A lot of the clang-tidy warnings repeats itself on the virtual and overrides, however, it is necessary for my program for the polymorphism on item, movie, and children classes.

Also there are a lot of clang-tidy warnings repeats on having a default next to the constructor, I also ignored this. 