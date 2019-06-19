#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	Student() {
		cout << "Student(), constructor called." << endl;
	}
	explicit Student(string stuName) : stuName(stuName) {
		cout << "Student(stuName), constructor called." << endl;
	}
	~Student() {
		cout << "~Student(), destructor called." << endl;
	}
	string getName() {
		return this->stuName;
	}
	virtual void sayHi() {
		cout << "Student: Hi!" << endl;
	}
	void sayHello() {
		cout << "Student: Hello!" << endl;
	}
private:
	string stuName{ "Student" };
};

class CSStudent : public Student {
public:
	CSStudent() {}
	explicit CSStudent(string stuName) : Student() {}
	void sayHello() {
		cout << "CSStudent: Hello!" << endl;
	}
};

class CSStudent340 : public CSStudent {
public:
	CSStudent340() {
		cout << "CSStudent340(), constructor called." << endl;
	}
	explicit CSStudent340(string stuName) : CSStudent(stuName) {
		cout << "CSStudent340(stuName), constructor called." << endl;
	}
	~CSStudent340() {
		cout << "~CSStudent340(), destructor called." << endl;
	}
	void sayHi() {
		cout << "CSStudent340: Hi!" << endl;
	}
};

int main() {
	CSStudent340 stuM{ "Mickey" };
	cout << "Stu: " << stuM.getName() << endl;
	unique_ptr<Student> stu{ make_unique<CSStudent340>("Minnie") };
	// stu->sayHi();
	// stu->sayHello();
	// return 0;
}