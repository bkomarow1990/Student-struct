#include <iostream>
#include <time.h>
#include <string>
using namespace std;
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
			if (students[i].marks[j]>=10)
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
void showMenu(int& answer) {
	cout << "==========================" << endl;
	cout << "\tMENU" << endl;
	cout << "1.Show Students" << endl;
	cout << "2.Show Teachers" << endl;
	cout << "3.Show Classes" << endl;
	cout << "4.Show Excelenters" << endl;
	cout << "0.Exit" << endl;
	cin >> answer;
	cout << "==========================" << endl;
}
int main() {
	srand(time(NULL));
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
	int answer;
	do
	{
		showMenu(answer);
		switch (answer)
		{
		case 0:
			break;
		case 1:
			for (int i = 0; i < 15; i++)
			{
				students[i].print();
				cout << endl;
			}
			break;
		case 2:
			for (int i = 0; i < 3; i++)
			{
				teachers[i].print();
				cout << endl;
			}
			break;
		case 3:
			for (int i = 0; i < 3; i++)
			{
				class__[i].print();
			}
			break;
		case 4:
			getExcellenters(students);
		default:
			break;
		}
	} while (answer != 0);
	return 0;
}