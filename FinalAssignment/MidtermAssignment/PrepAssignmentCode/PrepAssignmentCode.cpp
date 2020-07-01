#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int maxStudentsNum = 20;

enum yearOfStudy { prep, year1, year2, year3};

class student {
private:
	string name = "";
	int id;
	bool gender;
	string* major;
	double grades[5];
	yearOfStudy year;
public:
	//student() { name = ""; id = NULL; gender = NULL; major = NULL; grades[0] = NULL; }
	void setName(string userName) { name = userName; }
	void setId(int userId) { id = userId; }
	void setGender(bool userGender) { gender = userGender; }
	void setMajor(string* userMajor) { major = userMajor; }
	void setGrades(double userGrades[]) { for (int i = 0; i < 5; i++) { grades[i] = userGrades[i]; } }
	void setYear(yearOfStudy userYear) { year = userYear; }
	string getName() { return name; }
	int getId() { return id; }
	bool getGender() { return gender; }
	string *getMajor() { return major; }
	double *getGrades() { return grades; }
	yearOfStudy getYear() { return year; }

	double getAverageGrade()
	{
		double sum = 0, n = 5; 
		double average = 0;
		for (int i = 0; i < n; i++)
		{
			sum += grades[i];
		}
		average = double(sum) / n;
		return average;
	}
};

void displayOptions()
{
	cout << endl;
	cout << "|**********************************************************\n";
	cout << "|1) Delete a student										\n";
	cout << "|2) Edit the information of a student						\n";
	cout << "|3) Add a new student										\n";
	cout << "|4) Print the number of students in a specific major		\n";
	cout << "|5) Print the number of students in a specific year		\n";
	cout << "|6) Exit													\n";
	cout << "|**********************************************************\n";
	cout << "				   *********************					\n";
	cout << "				   *Choose Your Option!*					\n";
	cout << "				   *********************					\n";
	cout << endl;
}

void deleteStudent(student students[], int id)
{
	int studentsNum = 0, delStudentLoc = 0;
	bool found = false;
	for (int i = 0; i < maxStudentsNum; i++)
	{
		if (students[i].getId() == id)
		{
			found = true;
			delStudentLoc = i;
		}
		if (students[i].getName() == "")
		{
			break;
		}
		++studentsNum;
	}
	if (found)
	{
		for (int i = delStudentLoc; i < studentsNum; i++)
		{
			students[i] = students[i + 1];
		}
		cout << "Deleted student successfully, returning to option menu...\n";
	}
	else
	{
		cout << "missing id, returning to option menu...\n\n";
	}
}

void editStudent(student students[], int id)
{
	int studentsNum = 0, editStudentLoc = 0;
	bool found = false, again = false;
	int againCounter = 0;
	do
	{
		for (int i = 0; i < maxStudentsNum; i++)
		{
			if (students[i].getId() == id)
			{
				found = true;
				editStudentLoc = i;
			}
			if (students[i].getName() == "")
			{
				break;
			}
			++studentsNum;
		}
		if (found)
		{
			cout << "What do you want to change?\n";
			cout << "1) Name\n";
			cout << "2) Year\n";
			cout << "3) Gender\n";
			cout << "4) Major\n\n";
			int cho; cin >> cho; cin.ignore();
			string major1 = "cs", major2 = "is", major3 = "it", major4 = "se";
			string ans;
			switch (cho)
			{
			case 1:
				cout << "Enter the new name: ";
				getline(cin, ans);
				students[editStudentLoc].setName(ans);
				break;
			case 2:
				cout << "Enter the new Year (0 for prep, 1 for year 1, 2 for year 2, 3 for year 3): ";
				int yCho; cin >> yCho; cin.ignore();
				switch (yCho)
				{
				case 0:
					students[editStudentLoc].setYear(prep);
					break;
				case 1:
					students[editStudentLoc].setYear(year1);
					break;
				case 2:
					students[editStudentLoc].setYear(year2);
					break;
				case 3:
					students[editStudentLoc].setYear(year3);
					break;
				default:
					cout << "Invalid choice...\n";
				}
				break;
			case 3:
				cout << "Enter the new gender (0 for male, 1 for female): ";
				bool cho; cin >> cho; cin.ignore();
				students[editStudentLoc].setGender(cho);
				break;
			case 4:

				cout << "Enter the new major (0 for cs, 1 for is, 2 for it, 3 for se): ";
				int choI; cin >> choI; cin.ignore();
				switch (choI)
				{
				case 0:
					students[editStudentLoc].setMajor(&major1);
					break;
				case 1:
					students[editStudentLoc].setMajor(&major2);
					break;
				case 2:
					students[editStudentLoc].setMajor(&major3);
					break;
				case 3:
					students[editStudentLoc].setMajor(&major4);
					break;
				default:
					cout << "Invalid choice...\n";
				}
				break;
			default:
				cout << "Invalid choice...";
			}
			++againCounter;
		}
		else
		{
			cout << "missing id, do you want to try again? (1 for yes, 0 for no): \n";
			cin >> again;
		}
		if (!again || againCounter) 
		{
			cout << "Do you want to change another student record? (1 for yes, 0 for no): \n";
			cin >> again;
		}
	} while (again);
	cout << "Records were edited successfully, returning to option menu...\n";
}

string major1 = "cs", major2 = "is", major3 = "it", major4 = "se"; // used as a reference for setMajor() when called outside of main function
void addStudent(student students[], int addPos)
{
	int studentsNum = 0;
	for (int i = 0; i < maxStudentsNum; i++)
	{
		if (students[i].getName() == "")
		{
			break;
		}
		++studentsNum;
	}
	if (addPos == -1 || addPos >= studentsNum )
	{
		addPos = studentsNum;
	}
	for (int i = studentsNum; i >= 0 && i >= addPos; i--)
	{
		students[i + 1] = students[i];
	}
	cout << "Enter the data of the new student\n";
	cout << "1) Name: "; string uName; getline(cin, uName);
	students[addPos].setName(uName);
	cout << "2) ID: "; int uId; cin >> uId; cin.ignore();
	students[addPos].setId(uId);
	cout << "3) Gender (0 for male, 1 for female): "; bool uG; cin >> uG;
	students[addPos].setGender(uG);
	cout << "4) Major (0 for cs, 1 for is, 2 for it, 3 for se): ";
	int uM; cin >> uM; cin.ignore();
	switch (uM)
	{
	case 0:
		students[addPos].setMajor(&major1);
		break;
	case 1:
		students[addPos].setMajor(&major2);
		break;
	case 2:
		students[addPos].setMajor(&major3);
		break;
	case 3:
		students[addPos].setMajor(&major1);
		break;
	default:
		cout << "Invalid choice...\n";
	}
	cout << "Enter your grades: "; 
	double uGr[5];
	for (int j = 0; j < 5; j++)
	{
		cin >> uGr[j];
	}
	students[addPos].setGrades(uGr);
	cout << "5) Year (0 for prep, 1 for year 1, 2 for year 2, 3 for year 3): "; int uY; cin >> uY; cin.ignore();
	switch (uY)
	{
	case prep:
		students[addPos].setYear(prep);
		break;
	case year1:
		students[addPos].setYear(year1);
		break;
	case year2:
		students[addPos].setYear(year2);
		break;
	case year3:
		students[addPos].setYear(year3);
		break;
	default:
		cout << "Invalid input....\n";
	}
	cout << "New student added successfully\n\n";
}

int countStudents(student students[], string* majorP, yearOfStudy yearP)
{
	if (majorP != NULL)
	{
		int studentsNum = 0, mCount = 0;
		for (int i = 0; i < maxStudentsNum; i++)
		{
			if (students[i].getMajor() == majorP)
			{
				++mCount;
			}
			if (students[i].getName() == "")
			{
				break;
			}
			++studentsNum;
		}
		return mCount;
	}
	else if (yearP >= prep && yearP <= year3)
	{
		int studentsNum = 0, yCount = 0;
		for (int i = 0; i < maxStudentsNum; i++)
		{
			if (int(students[i].getYear()) == (int)yearP)
			{
				++yCount;
			}
			if (students[i].getName() == "")
			{
				break;
			}
			++studentsNum;
		}
		return yCount;
	}
	else
	{
		cout << "You entered invalid data...returning to option menu\n";
		return 0;
	}
}

void updateStudentsRec(student students[], fstream& sRecords)
{
	sRecords.open("PrepAssignment.txt", ios::out);
	int studentsNum = 0;
	for (int i = 0; i < maxStudentsNum; i++)
	{
		if (students[i].getName() == "")
		{
			break;
		}
		++studentsNum;
	}
	if (studentsNum)
		sRecords << "******************************students records******************************\n\n";
	for (int i = 0; i < studentsNum; i++)
	{

		sRecords << "Student " << i + 1 << "\n";
		sRecords << "Name: " << students[i].getName() << endl;
		sRecords << "ID: " << students[i].getId() << endl;
		sRecords << "Gender: " << (students[i].getGender() ? "Female" : "Male") << endl;
		sRecords << "Major: " << *(students[i].getMajor()) << endl;
		sRecords << "Grade: ";

		for (int j = 0; j < 5; j++)
		{
			if (j == 4)
				sRecords << *(students[i].getGrades() + j) << endl;
			else
				sRecords << *(students[i].getGrades() + j) << " ";
		}
		sRecords << "Average grade -> " << students[i].getAverageGrade() << endl;
		sRecords << "Year: ";
		switch (students[i].getYear())
		{
		case prep:
			sRecords << "Prep" << "\n\n";
			break;
		case year1:
			sRecords << "Year 1" << "\n\n";
			break;
		case year2:
			sRecords << "Year 2" << "\n\n";
			break;
		case year3:
			sRecords << "Year 3" << "\n\n";
			break;
		default:
			sRecords << "Error reading year of this student...";
		}
	}
	sRecords.close();
}

int main()
{
	string major1 = "cs", major2 = "is", major3 = "it", major4 = "se";
	student students[maxStudentsNum];
	fstream sRecords("PrepAssignment.txt", ios::in | ios::out | ios::app);
	int studentsNum = 0;

	if (sRecords.is_open()) //check if file is valid
	{
		ifstream sRecords("PrepAssignment.txt", ios::ate); //Convert to ifstream to be able to check if text is blank
		if (sRecords.tellg() == 0) //check if file is empty, then create first record of students
		{
			cout << "Enter the number of Students: ";
			cin >> studentsNum;
			cin.ignore();
			ofstream sRecords("PrepAssignment.txt", ios::app);
			sRecords << "******************************students records******************************\n\n";
			for (int i = 0; i < studentsNum; i++) 
			{
				sRecords << "Student " << i + 1 << "\n";
				cout << "Please enter data of student " << i + 1 << endl;

				cout << "Name: "; 
				string nameTogl; 
				getline(cin, nameTogl);
				students[i].setName(nameTogl);
				sRecords << "Name: " << students[i].getName() << endl;

				cout << "ID: "; 
				int sId; 
				cin >> sId;
				students[i].setId(sId);
				cin.ignore();
				sRecords << "ID: " << students[i].getId() << endl;

				cout << "Gender (enter 0 for male, 1 for female): "; 
				bool sGender; 
				cin >> sGender;
				students[i].setGender(sGender);
				cin.ignore();
				sRecords << "Gender: " << (students[i].getGender() ? "Female" : "Male") << endl;

				cout << "Major (enter 1 for cs, 2 for is, 3 for it, 4 for se): ";
				int referMajor; cin >> referMajor; cin.ignore();
				switch (referMajor) 
				{
				case 1:
					students[i].setMajor(&major1);
					break;
				case 2:
					students[i].setMajor(&major2);
					break;
				case 3:
					students[i].setMajor(&major3);
					break;
				case 4:
					students[i].setMajor(&major1);
					break;
				default:
					cout << "Invalid major, try again...\n";
				}
				sRecords << "Major: " << *(students[i].getMajor()) << endl;

				cout << "Grades of your 5 modules: ";
				sRecords << "Grades: ";
				double sGrade[5];
				for (int j = 0; j < 5; j++)
				{
					cin >> sGrade[j];
				}
				students[i].setGrades(sGrade);
				for (int j = 0; j < 5; j++)
				{
					if (j == 4)
					{
						sRecords << sGrade[j] << " \n";
					}
					else
					{
						sRecords << sGrade[j] << " ";
					}
				}

				sRecords << "Average grade -> " << students[i].getAverageGrade() << endl;

				cout << "Year of Study (Enter " 
					 << prep << " for prep, " 
					 << year1 << " for year 1, " 
					 << year2 << " for year 2, " 
					 << year3 << " for year 3: ";
				int sYear;
				cin >> sYear;
				cin.ignore();
				switch (sYear)
				{
				case prep:
					students[i].setYear(prep);
					break;
				case year1:
					students[i].setYear(year1);
					break;
				case year2:
					students[i].setYear(year2);
					break;
				case year3:
					students[i].setYear(year3);
					break;
				default:
					cout << "Invalid year, try again...\n";
				}
				sRecords << "Year: ";
				switch (students[i].getYear())
				{
				case prep:
					sRecords << "Prep";
					break;
				case year1:
					sRecords << "Year 1";
					break;
				case year2:
					sRecords << "Year 2";
					break;
				case year3:
					sRecords << "Year 3";
					break;
				default:
					sRecords << "Error in identifying the year...";
				}
				sRecords << "\n\n";
				cout << "\n\n";
			}

		}
		else // Put data from text file to students[] classes
		{
			ifstream sRecords("PrepAssignment.txt"); //read the data in the filled file
			sRecords.seekg(0, ios::beg);
			int dataCounter = 0;
			string line;
			string data[maxStudentsNum * 6];

			while (getline(sRecords, line)) 
			{
				if (line.find(':') != -1)
				{
					data[dataCounter] = line;
					data[dataCounter] = data[dataCounter].substr(data[dataCounter].find(':') + 2);
					++dataCounter;
				}
			}

			studentsNum = dataCounter / 6;

			for (int i = 0, j = 0, dss = 0; i < dataCounter && dss < dataCounter; i++)
			{
				if (i % 6 == 0)
				{
					j = i / 6;
					students[j].setName(data[dss]);
					++dss;
				}
				if (i % 6 == 1)
				{
					int rId = stoi(data[dss]);
					students[j].setId(rId);
					++dss;
				}
				else if (i % 6 == 2)
				{
					students[j].setGender((data[dss].at(0) == 'M' ? 0 : 1));
					++dss;
				}
				else if (i % 6 == 3)
				{
					if (data[dss].at(0) == 'c')
					{
						students[j].setMajor(&major1);
						++dss;
					}
					else if (data[dss].at(0) == 's')
					{
						students[j].setMajor(&major4);
						++dss;
					}
					else if (data[dss].at(0) == 'i' && data[dss].at(0) == 's')
					{
						students[j].setMajor(&major2);
						++dss;
					}
					else
					{
						students[j].setMajor(&major3);
						++dss;
					}
				}
				else if (i % 6 == 4)
				{
					string cutGrades = data[dss];
					double gradesArr[5];
					for (int k = 0; k < 5; k++)
					{

						if (k == 0)
						{
							int spacePosition = cutGrades.find(' ');
							string individualGradeString = data[dss].substr(0, spacePosition);
							double individualGrade = stoi(individualGradeString);
							gradesArr[k] = individualGrade;
						}
						else
						{
							int spacePosition = cutGrades.find(' ');
							cutGrades = cutGrades.substr(spacePosition + 1);
							spacePosition = cutGrades.find(' ');
							string individualGradeString = cutGrades.substr(0, spacePosition);
							double individualGrade = stoi(individualGradeString);
							gradesArr[k] = individualGrade;
						}
					}
					students[j].setGrades(gradesArr);
					++dss;
				}
				else if (i % 6 == 5)
				{
					if (data[dss].at(0) == 'P')
					{
						students[j].setYear(prep);
						++dss;
					}
					else if (data[dss].back() == '1')
					{
						students[j].setYear(year1);
						++dss;
					}
					else if (data[dss].back() == '2')
					{
						students[j].setYear(year2);
						++dss;
					}
					else if (data[dss].back() == '3')
					{
						students[j].setYear(year3);
						++dss;
					}
				}
			}
		
		}
	}
	else
	{ 
	cout << "The File is corrupt, can't open the data, so program will close...";
	return 0;
	}

	sRecords.close();
	int choice;
	
	do
	{
		displayOptions();
		cin >> choice;
		int choiceId = 0, choiceMajor = 0;
		int studentPos = 0;
		int studentsMajorNum = 0, studentsYearNum = 0;
		yearOfStudy filler = prep, choiceYear = prep;
		switch (choice)
		{
		case 1:								//1) Remove Student
			cout << "Enter the id of the student that you want to remove from the records: ";
			choiceId; cin >> choiceId;
			deleteStudent(students, choiceId);
			break;
		case 2:								//2) Edit Student
			cout << "Enter the id of the student that you want to update their data: ";
			choiceId; cin >> choiceId;
			editStudent(students, choiceId);
			break;
		case 3:								// 3) Add Student At N Position
			cout << "Enter the position of the student that you want to add: ";
			cin >> studentPos;
			cin.ignore();
			if (studentsNum < maxStudentsNum)
			{
				addStudent(students, studentPos);
			}
			else
				cout << "We cannot process your request as the file is full, we apologize for the inconvenience\n";
			break;
		case 4:							// 4) Num Of Students In Selected Major
			cout << "Enter the major that you are requiring: \n";
			cout << "1) " << major1 << "\n";
			cout << "2) " << major2 << "\n";
			cout << "3) " << major3 << "\n";
			cout << "4) " << major4 << "\n";
			choiceMajor; cin >> choiceMajor;
			filler = prep;
			switch (choiceMajor) 
			{
			case 1:
				studentsMajorNum = countStudents(students, &major1, filler);
				cout << "The number of students in " << major1
					 << (studentsMajorNum == 0 || studentsMajorNum == 1 ? " is " : " are ")
					 << studentsMajorNum << (studentsMajorNum == 0 || studentsMajorNum == 1 ? " student" : " students")
					 << endl;
				break;
			case 2:
				countStudents(students, &major2, filler);
				cout << "The number of students in " << major2
					 << (studentsMajorNum == 0 || studentsMajorNum == 1 ? " is " : " are ")
					 << studentsMajorNum << (studentsMajorNum == 0 || studentsMajorNum == 1 ? " student" : " students")
					 << endl;
				break;
			case 3:
				countStudents(students, &major3, filler);
				cout << "The number of students in " << major3
					 << (studentsMajorNum == 0 || studentsMajorNum == 1 ? " is " : " are ")
					 << studentsMajorNum << (studentsMajorNum == 0 || studentsMajorNum == 1 ? " student" : " students")
					 << endl;
				break;
			case 4:
				countStudents(students, &major4, filler);
				cout << "The number of students in " << major4
					 << (studentsMajorNum == 0 || studentsMajorNum == 1 ? " is " : " are ")
					 << studentsMajorNum << (studentsMajorNum == 0 || studentsMajorNum == 1 ? " student" : " students")
					 << endl;
				break;
			default:
				cout << "Invalid choice. Returning to selection menu...\n";
			}
			break;
		case 5:							// 5) Num Of Students In Selected Year
			cout << "Enter the year that you are requiring: \n";
			cout << "0) " << "Prep" << "\n";
			cout << "1) " << "Year 1" << "\n";
			cout << "2) " << "Year 2" << "\n";
			cout << "3) " << "Year 3" << "\n";
			int choiceYearInt;
			studentsYearNum = 0;
			cin >> choiceYearInt;
			switch (choiceYearInt)
			{
			case prep:
				studentsYearNum = countStudents(students, NULL, prep );
				cout << "The number of students in " << "prep "
					<< (studentsYearNum == 0 || studentsYearNum == 1 ? " is " : " are ")
					<< studentsYearNum << (studentsYearNum == 0 || studentsYearNum == 1 ? " student" : " students")
					<< endl;
				break;
			case year1:
				studentsYearNum = countStudents(students, NULL, year1);
				cout << "The number of students in " << "Year 1 "
					<< (studentsYearNum == 0 || studentsYearNum == 1 ? " is " : " are ")
					<< studentsYearNum << (studentsYearNum == 0 || studentsYearNum == 1 ? " student" : " students")
					<< endl;
				break;
			case year2:
				studentsYearNum = countStudents(students, NULL, year2);
				cout << "The number of students in " << "Year 2 "
					<< (studentsYearNum == 0 || studentsYearNum == 1 ? " is " : " are ")
					<< studentsYearNum << (studentsYearNum == 0 || studentsYearNum == 1 ? " student" : " students")
					<< endl;
				break;
			case year3:
				studentsYearNum = countStudents(students, NULL, year3);
				cout << "The number of students in " << "Year 3 "
					<< (studentsYearNum == 0 || studentsYearNum == 1 ? " is " : " are ")
					<< studentsYearNum << (studentsYearNum == 0 || studentsYearNum == 1 ? " student" : " students")
					<< endl;
				break;
			default:
				cout << "Invalid choice. Returning to selection menu...\n";
			}
			break;
		case 6:							// 6) Exit Otion Menu
			cout << "Saving and closing students records... Goodbye!\n";
			sRecords.open("PrepAssignment.txt", ios::trunc);
			updateStudentsRec(students, sRecords);
			break;
		default:
			cout << "Invalid choice, please enter one of the choices presented to you...\n";
		}
	} while (choice != 6);

	return 0;
}