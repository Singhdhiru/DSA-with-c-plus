#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Calculate the GPA from a given grade
double calculateGPA(double grade) {
    if (grade >= 90) {
        return 4.0;
    } else if (grade >= 80) {
        return 3.0;
    } else if (grade >= 70) {
        return 2.0;
    } else if (grade >= 60) {
        return 1.0;
    } else {
        return 0.0;
    }
}

// Calculate the CGPA from a list of grades and credits
double calculateCGPA(const vector<double>& grades, const vector<int>& credits) {
    double totalGradePoints = 0.0;
    int totalCredits = 0;
    for (size_t i = 0; i < grades.size(); i++) {
        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }
    return totalGradePoints / totalCredits;
}

int main() {
    vector<double> grades;
    vector<int> credits;
    double grade;
    int credit;
    char cont;
    do {
        cout << "Enter the grade (out of 100): ";
        cin >> grade;
        cout << "Enter the credit hours: ";
        cin >> credit;
        grades.push_back(calculateGPA(grade));
        credits.push_back(credit);
        cout << "Do you want to enter another course? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    double cgpa = calculateCGPA(grades, credits);
    cout << fixed << setprecision(2) << "Your CGPA is: " << cgpa << endl;

    return 0;
}
