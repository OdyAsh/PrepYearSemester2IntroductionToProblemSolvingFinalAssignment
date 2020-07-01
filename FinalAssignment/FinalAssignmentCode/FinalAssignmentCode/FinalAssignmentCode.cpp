//Q1) a) Array - Element Allocation

int arr[5] = { 1, 2, 3, 4, 5 };
cout << arr << endl;              //Output : 001EF9A4
cout << arr + 1 << endl;          //Output : 001EF9A8
cout << arr[0] << endl;           //Output : 1
cout << arr[1] << endl;           //Output : 2
cout << *(arr) << endl;           //Output : 1
cout << *(arr + 1) << endl;       //Output : 2

//Q1) a) Linked List - Element Allocation

struct node
{
    int data;
    node* next;
};
int main()
{
    node* LinkedListHead = new node;
    LinkedListHead->data = 1;
    node* SecondElement = new node;
    LinkedListHead->next = SecondElement;
    SecondElement->data = 2;
    cout << LinkedListHead << endl;               //Output : 00604590
    cout << LinkedListHead->data << endl;         //Output : 1
    cout << SecondElement << endl;                //Output : 004A4220
    cout << SecondElement->data << endl;          //Output : 2
    cout << LinkedListHead->next << endl;         //Output : 004A4220 , same as SecondElement

    return 0;
}

//Q1) b) Array - Extenstion of number of elements - Increasing the size

int arr[5] = { 1, 2, 3, 4, 5 }; //The array has 0-based index, so the elemnts'   indexes are 0,1,2,3,4
arr[5] = 6;
cout << arr[5]; //Compile time error

//Alternative

const int aSize = 5;
int arr[aSize] = { 1, 2, 3, 4, 5 };
cout << "Enter new element: ";
int x; cin >> x; //Input 6
int arrBig[aSize + 1] = { 0 };
int i;
for (i = 0; i < aSize; i++) //This will loop till i == 5
    arrBig[i] = arr[i];    //arrBig change: {1,0,0,0,0,0} -> {1,2,0,0,0,0} -> {1,2,3,0,0,0} -> {1,2,3,4,0,0} -> {1,2,3,4,5,0}
arrBig[i] = x;            //{1,2,3,4,5,6}

///***Another method using dynamic memory allocation***\\\

const int aSize = 2;
int arr[aSize] = { 1, 2 };
cout << "Enter the size of your new array: ";
int bigSize; cin >> bigSize; //Input 4
int* arrBig = new int[bigSize]; //"new" allocates memory to the heap of size sizeof(int) * n bytes and return the address of the memory where it's stored to the variable (pointer) arrBig, this why it can accept variables which are not const
int i;

for (i = 0; i < aSize; i++) //This will loop till i == 2 (it will assign till arrBig[1], but will exit the loop with i == 2)
    arrBig[i] = arr[i];    //arrBig change: {1,0,0,0} -> {1,2,0,0}

for (i = i; i < bigSize; i++) //This will loop till i == 4
{
    cout << "Enter the value to be inserted at position: " i + 1 << " : ";
    int x; cin >> x;           //Input: 3 4 5 6
    arrBig[i] = x;            //{1,2,3,0} -> {1,2,3,4}
}
delete[]arrBig; //Since the memory is dynamically allocated to the heap using new, we have to deallocate it manually by writing this line (when we don't need anymore, of course):

//Q1) b) Array - Extenstion of number of elements - Decreasing the size

const int aSize = 3;
int arr[aSize] = { 1, 2, 3 };
cout << "Enter the value of the element that you want to delete: ";
int x; cin >> x; //Input 2
for (int i = 0; i < aSize; i++)
    if (arr[i] == x)
    {
        arr[i] = 0;         //arr change: {1,0,3}
        break;
    }
int arrSmall[aSize - 1] = { 0 };
for (int i = 0, j = 0; i < aSize; i++) //This will loop till i == 3, then j == 2
    if (arr[i] != 0)
    {
        arrSmall[i] = arr[j];    //arrSmall change: {1,3}
        j++;
    }

///***Another method using dynamic memory allocation***\\\

const int aSize = 5;
int arr[aSize] = { 1, 2, 3, 4, 5 };
cout << "Enter the size of your new array: ";
int smallSize; cin >> smallSize; //Input 3
int numOfDeletedElements = aSize - smallSize;
int* valsToBeDeleted = new int[numOfDeletedElements]; //Creates a dynamically allocated array with size of the difference between the original and the smaller arrays
int* arrSmall = new int[smallSize]; //New dynamically allocated smaller array

cout << "Enter the values that you want to delete with spaces between each value: ";
for (int j = 0; j < numOfDeletedElements; j++) //Puts all the values to be deleted in an array
    cin >> valsToBeDeleted[j];                //Input: 2 4

for (int i = 0; i < aSize; i++)
    for (int j = 0; j < numOfDeletedElements; j++)
        if (arr[i] == valsToBeDeleted[j])
        {
            arr[i] = 0;
            valsToBeDeleted[j] = 0;     //arrSmall change: {1,0,3,4,5} -> {1,0,3,0,5}
            break;
        }

for (int i = 0, j = 0; i < aSize; i++) //This will loop till i == 5, then j == 2
    if (arr[i] != 0)
    {
        arrSmall[i] = arr[j];    //arrSmall change: {1,3,5}
        j++;
    }
delete[]arrSmall;

//Q1) b) Linked List - Extenstion of number of elements - Increasing && Decreasing the size

struct node
{
    int data;
    node* next = nullptr;
};
int main()
{
    int uData;
    cout << "enter data to be inserted at the first node: ";
    cin >> uData;                         //Input : 1
    node* LinkedListHead = new node;      //Address 00604590 is chosen at runtime to insert uData value to it
    LinkedListHead->data = uData;         //Assigns uData to first node
    cout << "enter data to be inserted at the second node: ";
    cin >> uData;                         //Input : 2
    node* SecondElement = new node;       //the linked list size increases as Address 004A4220 is chosen to insert uData value to it
    LinkedListHead->next = SecondElement; //Assigns 004A4220 as the address of the node that follows the node with address 00604590
    SecondElement->data = uData;          //Assigns uData to second node
    node* ptr = LinkedListHead;           //Initializes pointer ptr to the head of the linked list (its first node)
    while (ptr != nullptr)                //Pointer ptr loops through and outputs the whole linked list
    {
        cout << ptr->data << " ";         //Output : 1 2
        ptr = ptr->next;                  //Makes ptr point to the next node in the linked list, note that after the loop finishes, the linked list contains 2 nodes, so its size increased during runtime
    }
    delete SecondElement;                //Deletes second node
    LinkedListHead->next = nullptr;      //Makes the first node point to null again
    ptr = LinkedListHead;
    while (ptr != nullptr)                //Pointer ptr loops through the linked list again
    {
        cout << ptr->data << " ";         //Output : 1  
        ptr = ptr->next;                  //Note that now the linked lists contains only 1 node, so its size decreased during runtime
    }

    return 0;
}

//Q1) c) Array - Accessibility by adding, modifying, and deleting elements

//1. Access

int arr[5] = { 1,2,3,4,5 };
cout << "Enter the postition you position of the value you want to access: ";
int pos; cin >> pos; //Input: 3
cout << "The value at " << pos << " is: " << arr[pos - 1]; //pos -1 as index is 0-based, Output: 3

//2. Addition

//*********************Case 1*********************//
const int s = 5;   //Array size = s = 5
int inVal = 0;    //Initial value for array elements = inVal = 0
int arr[s] = { inVal };
arr[0] = 1, arr[1] = 2, arr[2] = 3;     //Array now equals { 1, 2, 3, 0, 0 }
int lastE;

for (lastE = s - 1; arr[lastE] == inVal; lastE--);  //Loop that will stop at index 2

for (int i = lastE; i >= 0; i--)
arr[i + 1] = arr[i];                   //{ 1, 2, 3, 3, 0 } -> { 1, 2, 2, 3, 0 } -> { 1, 1, 2, 3, 0 }

cin >> arr[0];   //Input: 4 -> { 4, 1, 2, 3, 0 }
//*********************Case 2*********************//
const int s = 5;    //Array size = s = 5
int inVal = 0;     //Initial value for array elements = inVal = 0
int arr[s] = { inVal };
arr[0] = 1, arr[1] = 2, arr[2] = 3;   //Array now equals { 1, 2, 3, 0, 0 }
int lastE;

for (lastE = s - 1; arr[lastE] == inVal; lastE--); //Loop that will stop at index 2

cin >> arr[lastE + 1];        //Input: 4 -> { 1, 2, 3, 4, 0 }

//*********************Case 3*********************//

const int s = 5         //Array size = s = 5
int inVal = 0;          //Initial value for array elements = inVal = 0
int arr[s] = { inVal };
arr[0] = 1, arr[1] = 2, arr[2] = 3;//Array now equals {1, 2, 3, 0, 0}
int lastE, n;
cout << "Enter the position where you want to enter your value from 1 to " << s << ": ";
cin >> n;    	       //Input: 2   
n--;                   //makes n 0 based (1)

for (lastE = s - 1; arr[lastE] == inVal; lastE--); //Loop that will stop at index 2

for (int i = lastE; i >= n; i--)
arr[i + 1] = arr[i];   //{ 1, 2, 3, 3, 0 } -> { 1, 2, 2, 3, 0 }

cout << "Enter your value: ";
cin >> arr[n];         //Input: 4 -> { 1, 4, 2, 3, 0 }

for (int i = 0; i < s; i++)
    cout << arr[i] << " ";

//3. Modification

const int s = 5;   //Array size = s = 5
int inVal = 0;     //Initial value for array elements = inVal = 0
int arr[s] = { inVal };
arr[0] = 1, arr[1] = 2, arr[2] = 3;          //Array now equals { 1, 2, 3, 0, 0 }
cin >> arr[0] >> arr[3]; //Input: 4 5 -> { 4, 2, 3, 5, 0}

//4. Deletion

//First Definition

const int s = 5;   //Array size = s = 5
int inVal = 0;     //Initial value for array elements = inVal = 0
int pos;
int arr[s] = { inVal };
arr[0] = 1, arr[1] = 2, arr[2] = 3;         //Array now equals { 1, 2, 3, 0, 0 }
cin >> pos; //Input: 1 -> { 0, 2, 3, 0, 0}

//Second Definition

//********************Delete first********************//
const int s = 5;//Array size = s = 5
int inVal = 0;  //Initial value for array elements = inVal = 0
int arr[s] = { inVal };
arr[0] = 1, arr[1] = 2, arr[2] = 3;   //Array now equals { 1, 2, 3, 0, 0 }
for (int i = 1; i < s; i++)
    arr[i - 1] = arr[i];     //{ 2, 2, 3, 0, 0 } -> { 2, 3, 3, 0, 0} -> { 2, 3, 0, 0, 0} -> remains the same till i == s-1

//********************Delete last********************// 
const int s = 5;   //Array size = s = 5
int inVal = 0;     //Initial value for array elements = inVal = 0
int arr[s] = { inVal };
arr[0] = 1, arr[1] = 2, arr[2] = 3;  					    //Array now equals { 1, 2, 3, 0, 0 }
int lastE, n;

for (lastE = s - 1; arr[lastE] == inVal; lastE--);        	     //Loop that will stop at index 2

arr[lastE] = 0;    //{ 1, 2, 0, 0, 0 }

  //********************Delete nth*********************//
const int s = 5;  //Array size = s = 5
int inVal = 0, n; //Initial value for array elements = inVal = 0
int arr[s] = { inVal };
arr[0] = 1, arr[1] = 2, arr[2] = 3;  					    //Array now equals { 1, 2, 3, 0, 0 }
cout << "Enter the position of the value you want to delete: ";
cin >> n;       //Input: 2
n--;            //Makes n 0-based (1)
for (int i = n; i < s - 1; i++)
    arr[i] = arr[i + 1];             						   //{ 1, 3, 3, 0, 0 } -> { 1, 3, 0, 0, 0} -> remains the same till i == s-1
for (int i = 0; i < s; i++)
    cout << arr[i] << " ";

//Q1) c) Linked List - Accessibility by adding, modifying, and deleting elements

//1. Access 2. Addition 3. Modification 4. Deletion

class node // created a class in order to efficiently hold all the manipulations of the linked list inside one class
{
protected: //This is done as the singleNode struct won't be accessed outside of node class, so there is no need to put it in public. Also, we put it as protected in order to be available for usage by public functions.
	struct singleNode
	{
		int data;
		singleNode* next;
		singleNode(int d, singleNode* n = nullptr) //second parameter here sets next to nullptr if no second argument is inserted in main function
		{
			data = d;
			next = n;
		}
	};
	singleNode* head;

public:
	node() { head = nullptr; }
	~node()						//Destructor that iterates through all nodes and deletes them, as we don't want remaining space in the heap
	{
		singleNode* ptr = head;
		while (ptr != nullptr)
		{
			singleNode* garbage = ptr;
			ptr = ptr->next;
			delete garbage;
		}
	}

	void displayList()		//Display the values inside the linked list
	{
		singleNode* ptr = head;
		while (ptr != nullptr)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}

	int accessPos(int num)   //returns position of a node that contains data num which could then be displayed with cout
	{
		singleNode* ptr = head;
		int pos = 1;
		while (ptr->data != num)
		{
			ptr = ptr->next;
			pos++;
		}
		return pos;
	}

	int accessVal(int pos) //returns data of a node at position pos which could then be displayed with cout
	{
		singleNode* ptr = head;
		for (int i = 0; i < pos; i++)
			ptr = ptr->next;
		return ptr->data;
	}

	void modify(int newNum, int pos) //takes newNum value and makes it replace the value in the node with position pos
	{
		singleNode* ptr = head;
		for (int i = 0; i < pos; i++)
			ptr = ptr->next;
		ptr->data = newNum;
	}

	void addBegNode(int num)  //Adds new node at the beginning of the linked list
	{
		if (head = nullptr)
			head = new singleNode(num);
		else
			head = new singleNode(num, head);	//Note that since the compiler reads from right to left, this line is saying : create a new node with data passed in the parameter and next pointing to the previous head, then assign the head pointer to this node
	}

	void addEndNode(int num)  //Adds new node at the end of the linked list
	{
		if (head = nullptr)
			head = new singleNode(num);
		else
		{
			singleNode* ptr = head;
			while (ptr->next != nullptr)
				ptr = ptr->next;
			ptr->next = new singleNode(num);
		}
	}

	void addNthNode(int num, int pos) //Adds new node at the nth position of the linked list
	{
		singleNode* ptr = head, * prev;
		if (pos == 1)
			head = new singleNode(num, head);
		else
		{
			for (int i = 1; i < pos; i++)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			ptr = new singleNode(num, ptr);
			prev->next = ptr;
		}
	}

	void removeVal(int num)   //Deletes node that contains data inserted by the user
	{
		singleNode* ptr, * prev;
		if (head == nullptr)
			return;
		if (head->data == num)
		{
			ptr = head;
			head = head->next;
			delete ptr;
		}
		else
		{
			ptr = head;
			while (ptr != nullptr && ptr->data != num)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			if (ptr != nullptr)
			{
				prev->next = ptr->next;
				delete ptr;
			}
		}
	}
	void removePos(int pos)   //Deletes node that contains position inserted by the user
	{
		pos--;
		singleNode* ptr, * prev;
		if (head == nullptr)
			return;
		if (pos == 0)
		{
			ptr = head;
			head = head->next;
			delete ptr;
		}
		else
		{
			for (int i = 0; i < pos; i++)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			if (ptr != nullptr)
			{
				prev->next = ptr->next;
				delete ptr;
			}
		}
	}
};

//Q2) sortArray()  &&  sortLinked()

//a) sortArray() function

class Data                                         //1
{
private:
    int id;                                        //2
    string name;                                   //3
public:
    int getId() { return id; }                     //4
    string getName() { return name; }              //5
};

void sortArray(Data dataArray[], int arraySize)    //6
{
    for (int i = 0; i < arraySize - 1; i++)        //7
        for (int j = i + 1; j < arraySize; j++)    //8
            if (dataArray[j].getId() < dataArray[i].getId()) //9
            {
                Data temp = dataArray[i];          //10
                dataArray[i] = dataArray[j];       //11
                dataArray[j] = temp;               //12
            }
}

//c) sortLinked() function

class dataLL      //1
{
public:
    Data dataInLL; //2
    dataLL* next;  //3
};

void sortLinked(dataLL* dataLinked, int linkedListSize)          //4
{
    dataLL* iptr, * jptr;                                        //5
    for (iptr = dataLinked; iptr != nullptr; iptr = iptr->next)  //6
        for (jptr = iptr->next; jptr != nullptr; jptr = jptr->next)//7
            if (jptr->dataInLL.getId() < iptr->dataInLL.getId()) //8
            {
                Data temp = iptr->dataInLL;                      //9
                iptr->dataInLL = jptr->dataInLL;                 //10
                jptr->dataInLL = temp;                           //11
            }
}

//Q3) Students program + getStudent() function

  //******************************************\\
 //Author: Ashraf Adel  ID: 196280  Group: A-6 \\
//**********************************************\\

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
//Q3
const int sNum = 10; //Number of students
struct student
{
    int number = 0;
    string name = "";
    float grade = 0.0;
};
struct studentRecordLocation //Created this as the problem didn't specify whether we should return the name or the grade of the chosen number, so instead, getStudent() returns an object containing his information
{
    int numLocation = 0; //This is the location of the number in the text file
    string name = "";
    float grade = 0.0;
};
student sArray[sNum + 1]; //sNum + 1 as counting starts from 1 in the loops
studentRecordLocation chosenStudent[sNum + 2]; //sNum + 2 just for extra space and to assure that the array won't go out of bounds
fstream sRecords("FinalAssignment.txt", ios::in | ios::out);

void saveDataFromFile(fstream& sRecords, student sArray[], studentRecordLocation chosenStudent[]) //This function is used in case the file already has data written in it and the user doesn't want to update it, so it stores these data in sArray[], and chosenStudent[]
{
    sRecords.open("FinalAssignment.txt", ios::in | ios::beg);
    if (!(sRecords.is_open())) //check if file is not valid
    {
        cout << "sorry but the file is not valid..." << endl;
        sRecords.close();
        return;
    }
    else
    {
        string notNeeded = ""; //this is created to store unrequired data in the text file, just to move the cursor (offset) to the relevant data
        for (int i = 1; i <= sNum && !(sRecords.eof()); i++)
        {
            sRecords >> notNeeded >> sArray[i].number >> notNeeded >> sArray[i].name >> notNeeded;

            if (notNeeded != "Grade:")
            {
                sArray[i].name = sArray[i].name + " " + notNeeded;
                sRecords >> notNeeded >> sArray[i].grade;
            }
            else
                sRecords >> sArray[i].grade;
            chosenStudent[i].name = sArray[i].name, chosenStudent[i].grade = sArray[i].grade;
            sRecords.ignore(100, '\n');        //ignores rest of characters in the line until reaching a new line (thus the offset of the file stops at the new line
            int endLineLoc = sRecords.tellg(); //Stores the length of the line to know where to start seekg() in getStudent()
            if (i != sNum)
            {
                chosenStudent[i + 1].numLocation = endLineLoc;
                chosenStudent[i + 1].numLocation += 7;        //The +7 is done as every line starts with Number:
            }
            if (i == 1)
                chosenStudent[i].numLocation = 7;  //In the first number only, store location of number in text file as 7 (which is after Number:)
        }
    }
}

void saveToFileAndArray(fstream& sRecords, student sArray[]) //if the file is empty, then enter new data and save it in text file, sArray[], and chosenStudent[] simultaneously. If not, call saveDataFromFile()
{
    sRecords.open("FinalAssignment.txt", ios::out); //In here we made ios::out, because if we don't, and the user decides to update the data, the function will recurse and then sRecords.tellg() will still not be equal to zero, so the file won't be updated if we remove ios::out
    if (!(sRecords.is_open())) //check if file is not valid
    {
        cout << "sorry but the file is not valid..." << endl;
        sRecords.close();
        return;
    }
    else
    {
        sRecords.close();
        sRecords.open("FinalAssignment.txt", ios::in | ios::ate);
        if (sRecords.tellg() == 0) //check if file is empty, then create the first record of students
        {
            sRecords.close();
            sRecords.open("FinalAssignment.txt", ios::out | ios::app); //Write to file
            int snum; string sname; float sgrade;
            cout << "Enter the data for " << sNum << (sNum == 1 ? " student." : " students.") << endl;
            for (int i = 1; i <= sNum; i++)
            {
                cout << "Enter the number of student " << i << ": ";
                cin >> snum; cin.ignore();
                cout << "Enter the name of student " << i << ": ";
                getline(cin, sname);
                cout << "Enter the grade of student " << i << ": ";

                bool loop = 0;  
                do            //loops if grade is invalid
                {
                    if (loop)
                    {
                        cout << "Enter a grade from 0 to 100: ";
                        cin >> sgrade;
                    }
                    else
                        cin >> sgrade;
                    loop = 1;
                }while(sgrade < 0 || sgrade > 100)
                cin.ignore();

                sArray[i].number = snum, sArray[i].name = sname, sArray[i].grade = sgrade; //Store in sArray[]
                sRecords << "Number: " << setw(15) << left << snum << "\t"  //Store in text file
                    << "Name: " << setw(15) << left << sname << "\t"
                    << "Grade: " << sgrade << endl;
                sRecords.seekg(0, ios::end); //Using seekg() function to reach the end of line, so the next number that we will get will be at that location +7
                int endLineLoc = sRecords.tellg();
                if (i != sNum) //In these lines, we will store only the location of students' numbers as to not fill the chosenStudents with useless information (as we will only access 1 element of it)
                    chosenStudent[i + 1].numLocation = endLineLoc + 7; //The +7 is done as every line starts with Number:
                if (i == 1)
                    chosenStudent[i].numLocation = 7;  //In the first number only, store location of number in text file as 7 (which is after Number:)
            }
            cout << "Records were saved successfully..." << endl;
        }
        else
        {
            sRecords.close();
            bool choice = 0;
            cout << "Sorry but the file already contains records of students, would you like to update the file? (0 for no, 1 for yes): ";
            cin >> choice;
            if (choice)
                saveToFileAndArray(sRecords, sArray); //Recurse the function again to update file with new data
            else
            {
                saveDataFromFile(sRecords, sArray, chosenStudent); //Calls a function to store the data of text file to sArray[] and chosenStudent[]
                cout << "Returning..." << endl;
            }
        }
    }
    sRecords.close(); //This is important to do after modifying text
}

studentRecordLocation getStudent(int num) //The required function that gets the information of the student with the number in the parameter in the form of an object
{
    sRecords.open("FinalAssignment.txt");
    if (!(sRecords.is_open())) //check if file is not valid
    {
        cout << "sorry but the file is not valid..." << endl;
        sRecords.close();
        return chosenStudent[0]; //Empty, as entry in this array starts from chosenStudent[1]
    }
    else
    {
        sRecords.close();
        sRecords.open("FinalAssignment.txt", ios::in | ios::ate);
        if (sRecords.tellg() == 0) //check if file is empty, then create the first record of students
            saveToFileAndArray(sRecords, sArray); //Calls saveToFIleAndArray() which gets the locations of the numbers in the text file as required by seekg() as required in the problem
        bool again = 0;
        do
        {
            sRecords.open("FinalAssignment.txt");
            if (!(sRecords.is_open())) //check if file is not valid
            {
                sRecords.close();
                return chosenStudent[0];
            }
            else
            {
                sRecords.close();
                sRecords.open("FinalAssignment.txt", ios::in | ios::ate);
                if (sRecords.tellg() == 0) //check if file is empty, then call SaveToFileAndArray()
                    saveToFileAndArray(sRecords, sArray);
                sRecords.close();
                sRecords.open("FinalAssignment.txt", ios::in | ios::beg);
                int numTest;
                string lNameTest = "";
                for (int i = 1; i <= sNum && !(sRecords.eof()); i++)
                {
                    int loc = chosenStudent[i].numLocation; //Note that seekg() was used (as required) and it has been included in both the next line, and in the saveToFileAndArray() function
                    sRecords.seekg(loc, ios::beg); //sets the offset of seekg to the location of student i's number in the text file
                    sRecords >> numTest;
                    if (numTest == num)
                    {
                        sRecords >> chosenStudent[i].name >> chosenStudent[i].name >> lNameTest;
                        //The reason why this is done 3 times can be explained by visualizing the text file:
                        //Number: num       Name: Ashraf Adel       Grade: 55
                        //    sRecords >> 1 ^^^^ 2^^^^^^ ^^^^3
                        //the next if statement checks whether the name has last name or not
                        if (lNameTest != "Grade:")
                        {
                            chosenStudent[i].name = chosenStudent[i].name + " " + lNameTest;
                            sRecords >> lNameTest;
                            sRecords >> chosenStudent[i].grade;
                        }
                        else
                            sRecords >> chosenStudent[i].grade;

                        return chosenStudent[i];
                    }
                }
                sRecords.close();
                cout << "Invalid number. Would you like to try again? (0 for no, 1 for yes): ";
                cin >> again;
                if (again)
                {
                    cout << "Enter the number of the student to get his/her name: ";
                    cin >> num;
                }
            }
        } while (again);
        if (!again)
        {
            sRecords.close();
            return chosenStudent[0];
        }
    }
}

int main()
{
    saveToFileAndArray(sRecords, sArray);
    cout << "Enter the number of a student to get his/her name and grade: ";
    int num; cin >> num;
    if (getStudent(num).numLocation != 0)
        cout << "Name: " << getStudent(num).name << "\nGrade: " << getStudent(num).grade << "\n";
    else
        cout << "Closing program...\n";
    sRecords.close();
    return 0;
}

/*
//********************************************************\\
Final note: I never had this much fun while doing an 
assessment before. This is because in this assessment 
and the last one, I have learned so much more about C++ 
and I feel like the material of this course will greatly 
benefit me in future programming modules! I would like to
thank all the T.As for their continuous support and 
providing us with clear explanations of each lab and 
new concept, and thank Dr. Mostafa for providing us with
two assessments that truly expanded our knowledge!...... 
and for putting up with all my emails. 
Can’t wait to see you again in the Algorithms module! <3
//********************************************************\\
*/


int main()
{
    /*Testing
    Data dataArray[4] = { {4, "Hza"}, {3, "Zha"}, {2, "Azh"}, {1, "Ash"} }; //this will work when id and name are public
    dataLL* dataLinked = new dataLL;
    dataLinked->dataInLL.getId() = 4;
    dataLinked->dataInLL.getName() = "Hza";
    dataLinked->next = new dataLL;
    (dataLinked->next)->dataInLL.getId() = 3;
    (dataLinked->next)->dataInLL.getName() = "Zha";
    (dataLinked->next)->next = new dataLL;
    (dataLinked->next->next)->dataInLL.getId() = 2;
    (dataLinked->next->next)->dataInLL.getName() = "Azh";
    (dataLinked->next->next)->next = new dataLL;
    (dataLinked->next->next->next)->dataInLL.getId() = 1;
    (dataLinked->next->next->next)->dataInLL.getName() = "Ash";
    (dataLinked->next->next->next)->next = nullptr;
    sortArray(dataArray, 4);
    sortLinked(dataLinked, 4);
    for (int i = 0; i < 4; i++)
        cout << dataArray[i].getId() << " " << dataArray[i].getName() << endl;
    cout << endl;
    dataLL* ptr = dataLinked;
    for (int i = 0; i < 4; i++)
    {
        cout << ptr->dataInLL.getId() << " " << ptr->dataInLL.getName() << endl;
        ptr = ptr->next;
    }
    cout << endl;

    /*
    const int s = 5;                     //Array size = s = 5
    int inVal = 0;                       //Initial value for array elements = inVal = 0
    int arr[s] = { inVal };
    arr[0] = 1, arr[1] = 2, arr[2] = 3;  //Array now equals { 1, 2, 3, 0, 0 }
    int lastE, n;

    for (lastE = s - 1; arr[lastE] == inVal; lastE--);        //Loop that will stop at index 2

    arr[lastE] = 0;                     //{ 1, 2, 0, 0, 0 }
    for (int i = 0 ; i < s ; i++)
        cout << arr[i] << " ";
    /*
    int uData;
    cout << "enter data to be inserted at the first node: ";
    cin >> uData;                         //Input : 1
    node *LinkedListHead = new node;      //Address 00604590 is chosen at runtime to insert uData value to it
    LinkedListHead->data = uData;         //Assigns uData to first node
    cout << "enter data to be inserted at the second node: ";
    cin >> uData;                         //Input : 2
    node* SecondElement = new node;       //the linked list size increases as Address 004A4220 is chosen to insert uData value to it
    LinkedListHead->next = SecondElement; //Assigns 004A4220 as the address of the node that follows the node with address 00604590
    SecondElement->data = uData;          //Assigns uData to second node
    node* ptr = LinkedListHead;           //Initializes pointer ptr to the head of the linked list (its first node)
    while (ptr != nullptr)                //Pointer ptr loops through and outputs the whole linked list
    {
        cout << ptr->data << " ";         //Output : 1 2
        ptr = ptr->next;                  //Makes ptr point to the next node in the linked list
    }
    delete SecondElement;                //Deletes second node
    LinkedListHead->next = nullptr;      //Makes the first node point to null again
    ptr = LinkedListHead;
    while (ptr != nullptr)                //Pointer ptr loops through the linked list again
    {
        cout << ptr->data << " ";         //Output : 1
        ptr = ptr->next;                  //Note that now the linked lists contains only 1 node, so its size decreased during runtime
    }


    return 0;
}
*/