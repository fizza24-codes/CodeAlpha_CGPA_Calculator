#include <iostream>
#include <iomanip> // Outputs ko 2 decimal places tak set precision dene ke liye

using namespace std;

// Function to convert letter grades into numeric grade points
double getGradePoints(char grade) {
    grade = toupper(grade); // Convert lower-case input to upper-case automatically
    
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default:  return -1.0; // Return -1 for invalid grade inputs
    }
}

int main() {
    int totalCourses;
    
    cout << "====================================" << endl;
    cout << "      STUDENT CGPA CALCULATOR       " << endl;
    cout << "====================================" << endl << endl;

    // Prompt user for total number of courses taken
    cout << "Enter the number of courses: ";
    cin >> totalCourses;

    // Standard arrays to store course details (Max 100 courses)
    char grades[100];
    int creditHours[100];
    double points[100];

    double totalGradePoints = 0;
    int totalCreditHours = 0;

    // Loop through each course to gather input from the user
    for (int i = 0; i < totalCourses; i++) {
        cout << "\n--- Course " << (i + 1) << " ---" << endl;
        
        // Input Grade
        cout << "Enter Grade (A, B, C, D, F): ";
        cin >> grades[i];

        // Input validation loop for grades
        while (getGradePoints(grades[i]) == -1.0) {
            cout << "Invalid grade! Please enter A, B, C, D, or F: ";
            cin >> grades[i];
        }

        // Input Credit Hours
        cout << "Enter Credit Hours (e.g., 3): ";
        cin >> creditHours[i];

        // Perform calculations for individual courses
        points[i] = getGradePoints(grades[i]);
        totalGradePoints += (points[i] * creditHours[i]);
        totalCreditHours += creditHours[i];
    }

    // Calculate final CGPA (preventing division by zero)
    double cgpa = (totalCreditHours > 0) ? (totalGradePoints / totalCreditHours) : 0.0;

    // Display formatted final semester report
    cout << "\n====================================" << endl;
    cout << "           SEMESTER REPORT          " << endl;
    cout << "====================================" << endl;
    cout << "Course\tGrade\tCredit Hours\tGrade Points" << endl;
    cout << "------------------------------------" << endl;

    for (int i = 0; i < totalCourses; i++) {
        cout << (i + 1) << "\t  " << grades[i] << "\t    " << creditHours[i] << "\t\t    " << points[i] << endl;
    }

    cout << "------------------------------------" << endl;
    cout << "Total Credit Hours: " << totalCreditHours << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    
    // Set decimal precision to 2 digits for CGPA display
    cout << fixed << setprecision(2);
    cout << "Final CGPA        : " << cgpa << endl;
    cout << "====================================" << endl;

    return 0;
}
