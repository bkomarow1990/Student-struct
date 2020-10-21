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
	return key+1;
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
	int count;
	Students* students_of_class;
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
	string names[5] = { "Max","Serhii","Dasha","Boris","Dzherik"};
	string surnames[5] = {"Kovalchuk","Yakubec","Korolchuk","Kaban","Dulko"};
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
void CreateClass(Class* class_,Students* students,Teachers* teachers,int &score,int& names_index,int& count_students,int &count_class) {
	string names[10];
	for (int i = 0; i < 10; i++)
	{
		names[i] = "A" + i;
	}
	int count;
	cin >> count;
	class_->count = count;
	int teacher_index = rand() % count_class;
	int students_index=rand()%count_students;
	
	class_->students_of_class = new Students[count];
	for (int i = 0; i < class_->count; i++)
	{
		CreateStudents(&class_->students_of_class[i]);
		/*students_index = rand() % count_students;
		class_->students_of_class[i]=students[i+score];*/
	}
	class_->teachers_of_class = teachers[teacher_index];
	class_->name = names[names_index];
	score += 5;
	names_index += 1;
}
void getExcellenters(Students* students,int &count_students) {
	cout << "Excellenters: " << endl;
for (int i = 0; i < count_students; i++){
		int current = 0;
		for (int j = 0; j < 10; j++)
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
string getTeacherWithBestMarks(Teachers* teachers, Students* students, Class* class__ , int& count_class) {
	int *summ=new int[count_class];
	int *average=new int[count_class];
	const int count_of_students = 5;
	for (int i = 0; i < count_class; i++)
	{
		summ[i] = 0;
	}
	for (int i = 0; i < count_class; i++)
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
string getClassWithWorstMarks(Teachers* teachers, Students* students, Class* class__,int& count_class) {
	int *summ=new int[count_class];
	int *average=new int[count_class];
	const int count_of_students = 5;
	for (int i = 0; i < count_class; i++)
	{
		summ[i] = 0;
	}
	for (int i = 0; i < count_class; i++)
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
void showRelatives(Students* students,int& count_students) {
	cout << "=============showRelatives=============" << endl;
	string* Realatives=new string[count_students];
	int count=0;
	for (int i = 0; i < count_students; i++)
	{
		for (int j = 0; j < count_students; j++)
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
void printStudentsBornOneDay(Students* students, int& count_students) {
	cout << "=============printStudentsBornOneDay=============" << endl;
	int count = 0;
	string* StudentsOneDayBorn = new string[count_students];
	for (int i = 0; i < count_students; i++)
	{
		for (int j = 0; j < count_students; j++)
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
void getOldestStudent(Students* students,int& count_students) {
	cout << "============getOldestStudent==============" << endl;
	float* days=new float[count_students];
	for (int i = 0; i < count_students; i++)
	{
		days[i] = 0;
	}
	for (int i = 0; i < count_students; i++)
	{
		days[i] += students[i].data.day;
		days[i] += students[i].data.month*30;
		days[i] += students[i].data.year*365.24;
	}
	int min = days[0];
	int minIndex = 0;
	for (int i = 0; i < count_students; i++)
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
	float* average=new float[15];
	float* summ = new float[15];
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
	Size_Console(50, 30);
	string Menu[] = { "1.Show Students","2.Show Teachers","3.Show Classes","4.Show Excelenters" ,
	"5.Show Teacher with best Class marks","6.Show Class with worst Class marks",
	"7.Show Relatives","8.Show Students what born in one day","9.Show Oldest Student","10.Show Count Student what have >8.5 average marks",
	"0.Exit"
	};
	int count_students = 0;
	int count_class = 0;
	cout << "ENTER COUNT STUDENTS (max 15)" << endl;
	cin >> count_students;
	cout << "ENTER COUNT CLASSES (max 5)" << endl;
	cin >> count_class;
	Students* students = new Students[count_students];
	Teachers* teachers = new Teachers[count_class];
	Class* class__ = new Class[count_class];
	for (int i = 0; i < count_students; i++)
	{
		CreateStudents(&students[i]);
	}
	int names_index = 0;
	for (int i = 0; i < count_class; i++)
	{
		CreateTeachers(&teachers[i],names_index);
	}
	int score = 0;
	names_index = 0;
	for (int i = 0; i < count_class; i++)
	{
		CreateClass(&class__[i],students,teachers,score,names_index,count_students,count_class);
	}
	
	int answer= menu(Menu, size(Menu));
		switch (answer)
		{
		case 0:
			break;
		case 1:
			cout << "=============Students:=============" << endl;
			for (int i = 0; i < count_students; i++)
			{
				students[i].print();
				cout << endl;
			}
			break;
		case 2:
			cout << "=============Teachers:=============" << endl;
			for (int i = 0; i < count_class; i++)
			{
				teachers[i].print();
				cout << endl;
			}
			break;
		case 3:
			cout << "=============Classes:=============" << endl;
			for (int i = 0; i < count_class; i++)
			{
				class__[i].print();
			}
			break;
		case 4:
			cout << "=============getExcellenters=============" << endl;
			getExcellenters(students,count_students);
			break;
		case 5:
			cout << "=============getTeacherWithBestMarks=============" << endl;
			cout << getTeacherWithBestMarks(teachers,students,class__,count_class) << endl;
			break;
		case 6:
			cout << "=============getClassWithWorstMarks=============" << endl;
			cout << getClassWithWorstMarks(teachers, students, class__,count_class) << endl;
			break;
		case 7:
			showRelatives(students, count_students);
			break;
		case 8:
			printStudentsBornOneDay(students,count_students);
			break;
		case 9:
			getOldestStudent(students,count_students);
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