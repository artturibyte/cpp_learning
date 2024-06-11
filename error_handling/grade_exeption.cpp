#include <iostream>


class invalid_student_grade: public std::out_of_range {
    public:
    invalid_student_grade(const std::string s): std::out_of_range(s) {}
    invalid_student_grade(): std::out_of_range("Grade out of limit!") {}
    invalid_student_grade(const invalid_student_grade& other) = default;
};

class StudentGrade {
    int grade;
    public:
    StudentGrade(int grade): grade(grade) {
    if (grade < 0)
        throw invalid_student_grade("Invalid grade");
    if (grade > 100)
        throw invalid_student_grade();
    }
};

int main(int argc, char const *argv[])
{
    while (true)
    {
        int grade;
        try
        {
            std::cout<<"Give grade:\n";
            std::cin >> grade;
            StudentGrade s(grade);
            std::cout<<"Success\n";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            break;
        }
    }
    return 0;
}
