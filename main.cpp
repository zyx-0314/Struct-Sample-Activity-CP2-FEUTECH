/*  Note:
		I'm not using "using namespace std;".
		I'm using Prototype Function
*/

/* Rules & Principles:
		Naming Conventions:
			constant variable - Upper Snake Case
				ex. const int VARIABLE_NAME = 0;
			variable - Camel Case
				ex. int variableName;
					int variableNameThisIs;
			user defined functions - Pascal Case
				ex. void FunctionName(){};
    			struct - Pascal Case
       				ex. struct Student{};
		Naming - Name should make sense on what it should do;
		DRY - Don't Repeat Yourself
		Single Responsibility Principle - One function must do one job
		Contruction of Code:
			struct StructName
   			{
				contant variable

				variable

    				constructor

				functions
      			}
     
			return_type FunctionName()
			{
				contant variable

				variable

				code
			}
		Don't use Global Variable
*/

#include <iostream>
#include <ctime>
#include <string>

// struct sample 1
struct Student {
	// public elements - it can be used anywhere. as long as you use to reference the name and use dot (.) operator

	// local variable - it can only be used inside the local(struct Student) scope
	// in struct Student (the name of the struct) scope
	int id;
	std::string name;

	// constructor
		// preventing empty initialization
			// empty initialization can cause error
	Student() {
		// this stands for or declaring that it uses the local variable
		this->id = 0;
		this->name = "No Name";
	}

	// local function - it can only be used inside the local(struct Student) scope
	void Calling() {
		std::cout << this->id << " - " << this->name << std::endl;
	}

	void AskForName() {
		std::cout << "Enter Name: ";
		std::cin >> this->name;
	}

	// in the parameter or inside the function the variable is called local variable in function askForID(which is the name of the function)
	void AskForID(int id) {

		// code snippet on using time
		// start
		time_t date;
		date = std::time(0);
		struct tm local_date;

		localtime_s(&local_date, &date);
		// end

		// the local variable id in struct Student stores the value of the local variable id in function askForID
		this->id = std::stoi(std::to_string(local_date.tm_year).append(std::to_string(id)));
	}
};

void CallAllStudents(Student []);

int main() {

	// Sample 1
	/*
		Student cayme;
		cayme.id = 1;
		cayme.name = "Kaizer";

		// you can call the variable element/member
		std::cout << cayme.id << " - " << cayme.name << std::endl;

		// you can call the function element/member
		cayme.Calling();
	*/

	// Sample 2
	/*
		Student aguas, delabajan;

		std::cout << "Aguas" << std::endl;
		aguas.AskForName();
		aguas.AskForID(1);

		std::cout << "Delabajan" << std::endl;
		delabajan.AskForName();
		delabajan.AskForID(2);

		system("cls");

		std::cout << "We Have Students" << std::endl;
		aguas.Calling();
		delabajan.Calling();
	*/

	// Sample 3
	Student students[3];

	for (int i = 0; i < 3; i++) {
		std::cout << "Student " << i + 1 << std::endl;
		students[i].AskForName();
		students[i].AskForID(i);
	}

	system("cls");

	/*
		std::cout << "We Have Students" << std::endl;
		for (int i = 0; i < 3; i++) {
			students[i].Calling();
		}
	*/

	CallAllStudents(students);
}

void CallAllStudents(Student students[]) {
	std::cout << "We Have Students" << std::endl;
	for (int i = 0; i < 3; i++) {
		students[i].calling();
	}
}
