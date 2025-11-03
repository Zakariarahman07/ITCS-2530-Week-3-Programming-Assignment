/*
Author: Zakaria Rahman
Date: November 2nd, 2025
Description: This program collects user inputs and validates if they enter the correct input.
             Also, it demonstrates file handling by writing to a file. Additionally, it shows the usage 
             of selection statements like if else statements and switch case statements.
Course: ITCS 2530 (C++ Programming 1)
*/

// header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // Welcome Message
    cout << left << setfill('-') << setw(133) << "" << endl;
    cout << "Welcome to the Math Aptitude Analyzer! Let's see how confident you are with math."
    << " Please enter the following information as prompted." << endl;;
    cout << left << setfill('-') << setw(133) << "" << endl << endl;


    // Declare Variables and Initializing some of them
    string name;
    string favoriteMathSubject;
    int problemsSolvedPerWeek= 0;
    int confidenceLevel = 0;
    double hoursSpentStudyingPerWeek = 1.0;
    double estimatedProblemsPerHour = 0.0;

    // variables for switch case and if/else demonstration 
    int num1 = 0;
    int num2 = 0;
    char mathOperator;
    int result = 0;
    int userAnswer;
    int noOfCorrectAnswers = 0;
    char grade;
    int testScore;

    // File handling
    ofstream outputFile;
    
    // Prompts for user inputs
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << endl;

    cout << "Enter your favorite Math subject: ";
    getline(cin, favoriteMathSubject); 
    cout << endl;


    cout << "Enter number of Math Problems you solved per week : ";
    // Input Validation
    if (!(cin >> problemsSolvedPerWeek)) {
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    cout << "On a scale of 1 to 10, how confident are you in Math? (1 being least and 10 being most): ";
    // Input Validation
    if (!(cin >> confidenceLevel)){
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    cout << "Enter number of hours you spend studying Math per week: ";
    // Input Validation
    if (!(cin >> hoursSpentStudyingPerWeek)){
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    // Calculations
    estimatedProblemsPerHour = static_cast<double> (problemsSolvedPerWeek) / hoursSpentStudyingPerWeek;

    // Asking user for inputs to demonstrate switch case
    cout << "Enter an integer: ";
    if (!(cin >> num1)){
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    cout << "Enter another integer: ";
    if (!(cin >> num2)){
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    cout << "Enter a math operator (+, -, *, /, %): ";
    cin >> mathOperator;
    cout << endl;


    // Switch case to perform math operations
    switch(mathOperator){
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            result = num1 / num2;
            cout << num1 << " / " << num2 << " = " << result << endl;
            break;
        case '%':
            result = num1 % num2;
            cout << num1 << " % " << num2 << " = " << result << endl;
            break;
        default:
            cout << "Invalid operator entered." << endl;
    }
    cout << endl;

    // 5 questions quiz to evaluate user's basic math knowledge
    cout << "Please answer this following math problems: \n" << endl;
    cout << "11 + 13 = ";
    cin >> userAnswer;
    cout << endl;

    if (userAnswer == (11 + 13)) {
        noOfCorrectAnswers++;
    }

    cout << "20 - 9 = ";
    cin >> userAnswer;
    cout << endl;

    if (userAnswer == (20 - 9)) {
        noOfCorrectAnswers++;
    }

    cout << "7 * 8 = ";
    cin >> userAnswer;
    cout << endl;

    if (userAnswer == (7 * 8)) {
        noOfCorrectAnswers++;
    }

    cout << "100 - 45 = ";
    cin >> userAnswer;
    cout << endl;

    if (userAnswer == (100 - 45)) {
        noOfCorrectAnswers++;
    }

    cout << "11 * 8 = ";
    cin >> userAnswer;
    cout << endl;

    if (userAnswer == (11 * 8)) {
        noOfCorrectAnswers++;
    }

    cout << "----- Quiz Feedback -----\n" << endl;

    // Using if/else blocks with compound boolean conditions
    if (noOfCorrectAnswers >= 4 && confidenceLevel >= 7) {
        cout << "Great! Your confidence matches your performance." << endl;
        cout << "You can try more advance problems!" << endl;
    }
    else if (noOfCorrectAnswers >= 3 && confidenceLevel >= 5) {
        cout << "Good work! Keep on practicing to improve." << endl;
        cout << "Solving more problems increases your confidence level." << endl;
    }
    else if (noOfCorrectAnswers >= 3 && confidenceLevel < 5) {
        cout << "Your performance is okay, but your confidence is low." << endl;
        cout << "Focus on building your confidence through consistent practice." << endl;
    }
    else if (noOfCorrectAnswers < 3 && confidenceLevel >=5) {
        cout << "You feel confident, but your performance shows the opposite." << endl;
        cout << "Practice fundamental concepts to match your confidence level." << endl;
    }
    else{
        cout << "Focus on basic concepts and fundamentals of Math." << endl;
        cout << "Practice regularly to improve your skills and confidence level." << endl;
    }

    cout << endl;
    
    // Building a report card for students from their teacher

    cout << "Please enter the student's grade (A, B, C, D, E): ";
    cin >> grade;
    cout << endl;

    cout << "Please enter the student's last test score: ";
    cin >> testScore;
    cout << endl;

    cout <<"----- Student Monthly Report Card Feedback -----\n" << endl;

    if (grade == 'A' || testScore >= 90){
        cout << "Excellent work! Keep up the high performance." << endl;
    }
    else if (grade == 'B' || testScore >= 80){
        cout << "Good job! You are doing well, but there is room for improvement." << endl;
    }
    else if (grade == 'C' || testScore >= 70) {
        cout << "Fair performance. Focus on improving weaker areas." << endl;
    }
    else {
        cout << "Needs improvement. Consider extra practice and studying." << endl;
        cout << "You can do the extra credit homework to boost your grade by a bit." << endl;
    }  
    cout << endl;
    // Opening the output file
    outputFile.open("report.txt");
    if (!outputFile.is_open()){
        cout << "Error opening the file." << endl;
        return -1;
    }

    // Writing to the output file with different foormatting styles
    outputFile << fixed << showpoint << setprecision(2);

    outputFile << left << setfill(' ') << setw(50) << "Name:" << right << setw(20) << setfill(' ') << name << endl;
    outputFile << left << setfill(' ') << setw(50) << "Favorite Math Subject:" << right << setw(20) << setfill(' ') << favoriteMathSubject << endl;
    outputFile << left << setfill(' ') << setw(50) << "Confidence Level:" << right << setw(20) << setfill(' ') << confidenceLevel << endl;
    outputFile << left << setfill(' ') << setw(50) << "# of Hours Studying Math:" << right << setw(20) << setfill(' ') << hoursSpentStudyingPerWeek << endl;
    outputFile << left << setfill(' ') << setw(50) << "Estimated Problems Solved Per Hour:" << right << setw(20) << setfill(' ') << estimatedProblemsPerHour << endl;

    outputFile.close();


    return 0;
}
