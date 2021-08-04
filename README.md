# Hospital-Management
Manage and search hospital patient records using queue and stack data structures in C language

# Features 

1)	Add Patient Record: One can add patient details such as patient number, name, age, gender, date of admission, problem, address, mobile number, doctor assigned, bill details.

2)	Update Patient Records: One can update patient record using patient number and bill status.

3)	Search Patient Records: Search and display patient records on the basis of :
·	Patient number
·	Name
·	Date of admission
·	Mobile Number
·	Doctor Assigned
·	Bill number
·	Problem
·	Bill status

4)     Delete Patient Record: One can delete patient record on the basis of Patient number.

5)    Patient, doctor,bill have been declared as a separate structure.

6)    All Structures and strings are dynamically allocated.

7)    Bills are initially assigned NA values and later can be updated using issuebill() function. 

8) A token system for patients who are assigned to General physician using queues.


# Functions Included

1)	Create()            : To assign NULL values before insertion.
2)	isEmpty()          : To check for undeclared record.
3)	insert()              : To insert patient records.
4)	updatepno()      : To update record using patient number.
5)	issuebill()          : To issue and update bill details.
6)	updatebs()        : To update bill status.
7)	searchpno()      : Search and display records using patient number.
8)	searchdoa()      : Search and display records using date of admission.
9)	searchname()   : Search and display records using name.
10)	searchmn()       : Search and display records using mobile number.
11)	searchda ()       : Search and display records using doctor assigned.
12)	searchbn()        : Search and display records using bill number.
13)	searchprob()     : Search and display records using problem.
14)	searchbs()        : Search and display using bill status. 
15)	deletepno()       : Delete patient record using patient number.
16)	gettoken()         : Token number is assigned to visit the General Physician.


# Structures Used

Linked list is used to store patient records.
Queue is used as a token system to visit the General Physician.
