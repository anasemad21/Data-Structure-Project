## Data-Structure-Project
#Part I research Library management system
A. Library management system is a project which aims in developing a system to maintain a 
specific work of library like adding a new book in book linked list adding book copies in 
copies queue, Adding book borrow )استعارة ,)adding book return )المستعار الكتاب اعادة ,)show 
borrow statistics (المستعارة الكتب عدد ,(Library inventory)المكتبة جرد , )search about book ( البحث فى المكتبة عن كتاب معين وتحديد هل هو متاح ام معار)
![image](https://user-images.githubusercontent.com/61062282/187527527-20b23664-58e4-4f6b-98b9-e6ce96710257.png)


Example after adding number of copies for each book 3 for DS 2 for FS and 1 for AL be 
noted that book copy is a queue FIFO
![image](https://user-images.githubusercontent.com/61062282/187528016-6aa5fc77-507c-4bc2-8ae4-49547fd99edf.png)
3. Adding book borrow (استعارة)
Update book copies with borrower name and update borrow date and number of days to 
return the book copy
4. Adding book return (اعادة الكتاب المستعار)
clear borrower and borrow date and number of days to return of the book copy 
5.Library inventory لكل كتاب عرض عدد النسخ االجمالية وعدد المستعارة (جرد المكتبة)
__________________________________________________________________________________________________________________________________________________
#part2


![image](https://user-images.githubusercontent.com/61062282/187529052-f315f248-cd26-44bb-b4b6-4fdbd15d0f4e.png)
![image](https://user-images.githubusercontent.com/61062282/187529131-2211f1c2-6026-408c-9e22-10381529c45c.png)

It is required to add the following functions to the linked list class:
1. Insert in linked list
Write member insert method in class linked list that takes the value to be inserted as a 
parameter and inserts the value to the linked list.Make sure to handle insertion in 
head/tail/middle.
Function signature : void insert(T n)
2. Insert in Linked list at certain position 
Write member insertPos method in class linked list that takes the value to be inserted 
and position as parameters and inserts the value to the linked list at the given position. 
Make sure to handle insertion in head/tail/middle and out of bound cases.
Function signature : void insertPos(int data, int position)
3. Delete from linked list
Write member delete method in class linked list that takes the value to be deleted as a 
parameter and deletes the value from the linked list.Make sure to handle deletion from 
head/tail/middle.
Function signature : void deleteVal(T value)
4. delete from Linked list at certain position 
Write member deletePos method in class linked list that takes the value to be deleted 
and position as parameters and deletes the value from the linked list at the given 
position. Make sure to handle deletion from head/tail/middle and out of bound cases.
Function signature : void deletePos(int position)
5. Concatenate Linked list 
Write a static concatenate method that takes the head node of two lists as parameters 
and adds the second linked list to the first one. 
Function signature : static void concatenate(node<T> *a, node<T> *b)
6. Print Linked list 
Write a static print method that takes the head node as a parameter and prints the 
linked list recursively 
Function signature : static void printLL(node<T> *head)
III. Sort Binary array in linear time.
Given a binary array, sort it in linear time and constant space. Output should print 
contain all zeroes followed by all ones.
For Example Input:{1,0,1,0,1,0,0,1,0} Output :{0,0,0,0,0,1,1,1,1}
You must solve this problem by three different algorithms .
