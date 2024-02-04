#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;


class COP3014 {
   
private:
    string firstName, lastName, zNumber;
    int quiz1, quiz2, quiz3, midterm, finalExam;
    double totalGrade;
    char letterGrade;

public:
    COP3014() {}
    COP3014(string fname, string lname, string znum)
        : firstName(fname), lastName(lname), zNumber(znum),
        quiz1(100), quiz2(100), quiz3(100), midterm(100), finalExam(100) {}

    void setFirstName(string fname) { firstName = fname; }
    void setLastName(string lname) { lastName = lname; }
    void setZNumber(string znum) { zNumber = znum; }
    void setQuiz1(int grade) { quiz1 = grade; }
    void setQuiz2(int grade) { quiz2 = grade; }
    void setQuiz3(int grade) { quiz3 = grade; }
    void setMidterm(int grade) { midterm = grade; }
    void setFinalExam(int grade) { finalExam = grade; }

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getZNumber() const { return zNumber; }
    int getQuiz1() const { return quiz1; }
    int getQuiz2() const { return quiz2; }
    int getQuiz3() const { return quiz3; }
    int getMidterm() const { return midterm; }
    int getFinalExam() const { return finalExam; }

    double getTotalGrade() const { return totalGrade; }
    char getLetterGrade() const { return letterGrade; }

    void computeTotalGrade() {
        totalGrade = (quiz1 + quiz2 + quiz3) / 3.0 + midterm * 0.3 + finalExam * 0.5;
    }

    void computeLetterGrade() {
        if (totalGrade >= 90) {
            letterGrade = 'A';
        }
        else if (totalGrade >= 80 && totalGrade <= 90) {
            letterGrade = 'B';
        }
        else if (totalGrade >= 70 && totalGrade <= 80) {
            letterGrade = 'C';
        }
        else if (totalGrade >= 60 && totalGrade <= 70) {
            letterGrade = 'D';
        }
        else {
            letterGrade = 'F';
        }
    }

    // check if there is absences during midterm would than get F
    void checkAbsences() {
        if (midterm < 0 || finalExam < 0)
            letterGrade = 'F';
    }

    // Output all the variables function
    void printInfo() const {
        cout << firstName << " " << lastName << " - " << zNumber << endl;
        cout << "Quiz 1: " << quiz1 << endl;
        cout << "Quiz 2: " << quiz2 << endl;
        cout << "Quiz 3: " << quiz3 << endl;
        cout << "Mid term: " << midterm << endl;
        cout << "Final: " << finalExam << endl;
        cout << "Total grade: " << totalGrade << endl;
        cout << "Final grade: " << letterGrade << endl;
    }
};

//main 
int main() {
    //sample to test 
    // ------------------Student 1 --------------

    COP3014 student1("Steve", "Jacobs", "Z12890249");
    student1.setQuiz1(20);
    student1.setQuiz2(20);
    student1.setQuiz3(10);

    // Set midterm and final exam grades
    student1.setMidterm(10);
    student1.setFinalExam(100);

    // Compute the total grade and letter grade
    student1.computeTotalGrade();
    student1.checkAbsences();
    student1.computeLetterGrade();

    // Print student information and grades
    student1.printInfo();

    cout << endl;

    // ------------------Student 2 --------------

    COP3014 student2("chaewon ", "Kim ", "Z97070212");
    student2.setQuiz1(20);
    student2.setQuiz2(20);
    student2.setQuiz3(20);

    // Set midterm and final exam grades
    student2.setMidterm(92);
    student2.setFinalExam(97);

    // Compute the total grade and letter grade
    student2.computeTotalGrade();
    student2.checkAbsences();
    student2.computeLetterGrade();

    // Print student information and grades
    student2.printInfo();

    return 0;
}