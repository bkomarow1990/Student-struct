#include <iostream>
#include <time.h>
#include <string>
#include<iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { 0, 0, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}
void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int menu(string menu_items[], int size) {

	int key = 0;
	int code;
	do {
	/*	cout << "===========================================================================" << endl;
		cout << "\t\tMENU" << endl;*/
		system("cls");
		key = (key + size) % size;
		for (int i = 0; i < size; i++)
		{
	
			SetPos(20, 10+ i);
			if (key == i)
			{

				
				cout << " "; SetColor(12); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}

		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
struct Date {
	int day;
	int month;
	int year;
	void print() 
	{
		cout << day<<"."<<month<<"."<<year<<endl;
	}
};
struct Students {
	string name;
	string surname;
	int marks[10];
	Date data;
	void print() {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Marks: " << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
		data.print();
	}
};
struct Teachers {
	string name;
	string surname;
	void print() {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
	}
};
struct Class {
	Students students_of_class[5];
	Teachers teachers_of_class;
	string name;
	void print() {
		cout << "Students: " << endl;
		for (size_t i = 0; i < 5; i++)
		{
			cout << students_of_class[i].name << " " << students_of_class[i].surname << endl;
		}
		cout << "Teacher: " << endl;
		cout << teachers_of_class.name <<" "<<teachers_of_class.surname<< endl;
		cout << "Name of group: " << endl;
		cout << name << endl;
	}
};
void CreateTeachers(Teachers* teachers, int& names_index) {
	string names[3] = { "Max","Serhii","Dasha"};
	string surnames[3] = {"Kovalchuk","Yakubec","Korolchuk"};
	teachers->name = names[names_index];
	teachers->surname = surnames[names_index];
	names_index += 1;
}
void CreateStudents(Students* student) {
	string names[15] = { "Boris","Anton","Dzherik","Leha","Gena","Zalupa","Bogdan","Andii","Jura","Vadim","Vadim","Roman","Vitya","Illia","Sanya" };
	string surnames[15] = { "Dulko","Yancevich","Albertovich","Mischuk","Giena","Illi","Gnidez","Svirida","Patriyuk","Chorny","Shostak","Pomianovsky","Pavlovskii","Gai","Kazah"};
	int names_index,surnames_index;
	names_index = rand() % 15;
	surnames_index = rand() % 15;
	student->name=names[names_index];
	student->surname=surnames[surnames_index];
	for (int i = 0; i < 10; i++)
	{
		student->marks[i] = rand() % 12 + 1;
	}
	student->data.day = rand() % 31 + 1;
	student->data.month = rand() % 12 + 1;
	student->data.year = rand() % 14+1990;
}
void CreateClass(Class* class_,Students* students,Teachers* teachers,int &score,int& names_index) {
	string names[3] = { "B1","B2","B3" };
	int teacher_index = rand() % 3;
	int students_index;
	for (size_t i = 0; i < 5; i++)
	{
		students_index = rand() % 15;
		class_->students_of_class[i]=students[i+score];
	}
	class_->teachers_of_class = teachers[teacher_index];
	class_->name = names[names_index];
	score += 5;
	names_index += 1;
}
void getExcellenters(Students* students) {
	cout << "Excellenters: " << endl;
for (size_t i = 0; i < 15; i++){
		int current = 0;
		for (size_t j = 0; j < 10; j++)
		{
			if (students[i].marks[j]>=9)
			{
				current++;
			}
			else {
				break;
			}
		}
		if (current==10)
		{
			cout << students[i].name << " " << students[i].surname << endl;
		}
		current = 0;
	}
}
string getTeacherWithBestMarks(Teachers* teachers, Students* students, Class* class__ ) {
	int summ[3];
	int average[3];
	const int count_of_students = 5;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int b = 0; b < 10; b++)
			{
				summ[i] += class__[i].students_of_class[j].marks[b];
			}
			
		}
		average[i] = summ[i] / count_of_students;
	
	}
	int maxIndex = 0;
	int max = average[0];
	for (int i = 0; i < 3; i++)
	{
		if (max<average[i])
		{
			max = average[i];
			maxIndex = i;
		}
	}
	return class__[maxIndex].teachers_of_class.name + " " + class__[maxIndex].teachers_of_class.surname;
}
string getClassWithWorstMarks(Teachers* teachers, Students* students, Class* class__) {
	int summ[3];
	int average[3];
	const int count_of_students = 5;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int b = 0; b < 10; b++)
			{
				summ[i] += class__[i].students_of_class[j].marks[b];
			}

		}
		average[i] = summ[i] / count_of_students;

	}
	int minIndex = 0;
	int min = average[0];
	for (int i = 0; i < 3; i++)
	{
		if (min > average[i])
		{
			min = average[i];
			minIndex = i;
		}
	}
	return class__[minIndex].name;
}
void showRelatives(Students* students) {
	cout << "=============showRelatives=============" << endl;
	string Realatives[15];
	int count=0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (students[i].surname == students[j].surname && i!=j)
			{
				Realatives[count] = students[i].name + " " + students[i].surname + " - " + students[j].name + " " + students[j].surname;
				count++;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << Realatives[i] << endl;
	}
}
//void showMenu(int& answer) {
//	cout << "===========================================================================" << endl;
//	cout << "\tMENU" << endl;
//	cout << "1.Show Students" << endl;
//	cout << "2.Show Teachers" << endl;
//	cout << "3.Show Classes" << endl;
//	cout << "4.Show Excelenters" << endl;
//	cout << "5.Show Teacher with best Class marks" << endl;
//	cout << "6.Show Class with worst Class marks" << endl;
//	cout << "7.Show Relatives" << endl;
//	cout << "8.Show Students what born in one day" << endl;
//	cout << "9.Show Oldest Student" << endl;
//	cout << "10.Show Count Student what have >8.5 average marks" << endl;
//	cout << "0.Exit" << endl;
//	cin >> answer;
//}
void printStudentsBornOneDay(Students* students) {
	cout << "=============printStudentsBornOneDay=============" << endl;
	int count = 0;
	string StudentsOneDayBorn[15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (students[i].data.day == students[j].data.day && i != j)
			{
				StudentsOneDayBorn[count] = students[i].name + " " + students[i].surname + " - " + students[j].name + " " + students[j].surname;
				count++;
			}
		}
		
	}
	for (int i = 0; i < count; i++)
	{
		cout<< StudentsOneDayBorn[i] << endl;
	}
}
void getOldestStudent(Students* students) {
	cout << "============getOldestStudent==============" << endl;
	float days[15];
	for (int i = 0; i < 15; i++)
	{
		days[i] = 0;
	}
	for (int i = 0; i < 15; i++)
	{
		days[i] += students[i].data.day;
		days[i] += students[i].data.month*30;
		days[i] += students[i].data.year*365.24;
	}
	int min = days[0];
	int minIndex = 0;
	for (int i = 0; i < 15; i++)
	{
		if (days[i]<min)
		{
			min = days[i];
			minIndex = i;
		}
	}
	cout << "OLDEST: " << students[minIndex].name <<" "<<students[minIndex].surname<< endl;
	cout << "WITH B-DAY : ";
	students[minIndex].data.print();
}
int countOfStudentsWith85PlusMarks(Students* students) {
	float average[15];
	float summ[15];
	int count = 0;
	for (int i = 0; i < 15; i++)
	{
		summ[i] = 0;
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			summ[i] += students[i].marks[j];
		}
		average[i] = summ[i] / 10;
	}
	for (int i = 0; i < 15; i++)
	{
		if (average[i]>8.5)
		{
			count++;
		}
	}
	return count;
}
int main() {
	srand(time(NULL));
	Size_Console(50, 50);
	string Menu[] = { "1.Show Students","2.Show Teachers","3.Show Classes","4.Show Excelenters" ,
	"5.Show Teacher with best Class marks","6.Show Class with worst Class marks",
	"7.Show Relatives","8.Show Students what born in one day","9.Show Oldest Student","10.Show Count Student what have >8.5 average marks",
	"0.Exit"
	};
	Students* students = new Students[15];
	Teachers* teachers = new Teachers[3];
	Class* class__ = new Class[3];
	for (int i = 0; i < 15; i++)
	{
		CreateStudents(&students[i]);
	}
	int names_index = 0;
	for (int i = 0; i < 3; i++)
	{
		CreateTeachers(&teachers[i],names_index);
	}
	int score = 0;
	names_index = 0;
	for (int i = 0; i < 3; i++)
	{
		CreateClass(&class__[i],students,teachers,score,names_index);
	}
	
	int answer= menu(Menu, size(Menu));
		switch (answer)
		{
		case 0:
			break;
		case 1:
			cout << "=============Students:=============" << endl;
			for (int i = 0; i < 15; i++)
			{
				students[i].print();
				cout << endl;
			}
			break;
		case 2:
			cout << "=============Teachers:=============" << endl;
			for (int i = 0; i < 3; i++)
			{
				teachers[i].print();
				cout << endl;
			}
			break;
		case 3:
			cout << "=============Classes:=============" << endl;
			for (int i = 0; i < 3; i++)
			{
				class__[i].print();
			}
			break;
		case 4:
			cout << "=============getExcellenters=============" << endl;
			getExcellenters(students);
			break;
		case 5:
			cout << "=============getTeacherWithBestMarks=============" << endl;
			cout << getTeacherWithBestMarks(teachers,students,class__) << endl;
			break;
		case 6:
			cout << "=============getClassWithWorstMarks=============" << endl;
			cout << getClassWithWorstMarks(teachers, students, class__) << endl;
			break;
		case 7:
			showRelatives(students);
			break;
		case 8:
			printStudentsBornOneDay(students);
			break;
		case 9:
			getOldestStudent(students);
			break;
		case 10:
			cout << "=============countOfStudentsWith8.5PlusMarks=============" << endl;
			cout << countOfStudentsWith85PlusMarks(students) << endl;
			break;
		default:
			break;
		}
	return 0;
}