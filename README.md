# Report-Card-Management
Small C++ project that helps to create/edit/delete and manage report cards of senior secondary school students.

Project Description: 
This report card management system can keep the academic records of 30 students i.e. their marks, grades,percentage etc of 2 terms(Half yearly and Final) 
in 5 subjects namely:English,Physics,Chemistry,Maths and Computer science.This system models the real world very well as it is according to the marking system of Higher Secondary 
classes of CBSE/ICSE or various State Boards.

The teacher can make use of various functions like
* ADD RECORDS:-to add new records
* APPEND RECORDS:-to append records to current file
* SORT RECORDS:-to sort records in alphabetical manner
* SEARCH RECORDS:-to search records by name
* UPDATE RECORDS:-to give grace marks to failed students
* VIEW RECORDS:-to view all records
* LIST OF FAILURES:-to see the records of all failed students
These extensive features help the user(teacher) to make the best use of this system.

Project Based on: 
I used the concepts of Data File Handling and Basic Searching/Sorting for completing this project.

Pre-requisites: 
The source code is fully compatible with any version of TURBO C++.

However,for better User Interface,we have used Graphic.h header file and hence this code requires a certain file named "evaga.bgi" at
a certain location in the directory.Here the path of that file is set to "C:\\TurboC3\\BGI" on lines: 344 and 583.
However,the path of the file must be changed,if and when required ,else this code will not work.Also,note that this code will not work
on any other compiler except "TURBO C++".

Information Storage: 
The records are stored in the "BIN" folder of "TURBO C++" directory by default by the compiler itself.So,the records of TERM 1 are stored in "report-1" file and similarly, the
records of TERM 2 are stored in "report-2" file in "BIN" folder.
