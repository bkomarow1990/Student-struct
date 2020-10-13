#include <iostream>
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
struct teacher {
	
};
struct Group {
	
};
void CreateStudents(Students* student) {
	string names[15] = { "Boris","Anton","Dzherik","Leha","Gena","Zalupa","Bogdan","Andii","Jura","Vadim","Vadim","Roman","Vitya","Illia","Sanya" };
	string surname[15] = { "Dulko","Yancevich","Albertovich","Mischuk","Giena","Illi","Gnidez","Svirida","Patriyuk","Chorny","Shostak","Pomianovsky","Pavlovskii","Gai","Kazah"};
	
	student->name=names[];
}
int main() {
	Students* students = new Students[15];
	for (int i = 0; i < 15; i++)
	{
		CreateStudents();
	}
	return 0;
}