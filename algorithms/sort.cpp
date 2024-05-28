#include    <algorithm>
#include    <iostream>
#include    <vector>
#include    <string>
#include    "print.cpp"
#include    "student.hpp"

int main() {
    student stu1("John Smith", 561234);
	student stu2("John Smith", 453811);
	student stu3("Jack Jones", 692837);

    std::vector<student> students = { stu1, stu2, stu3 };
	
	std::cout << "Vector before sorting:" << std::endl;
	for (auto student : students)
		student.print();
	
	// The "John Smith" students may be in either order
	sort(begin(students), end(students));           // Sort the elements using < operator
	
	std::cout << "Vector after sorting:" << std::endl;
	for (auto student : students)
		student.print();
}

