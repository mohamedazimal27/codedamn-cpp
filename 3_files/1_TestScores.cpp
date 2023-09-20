/*
Test Scores
Create a program that reads a text file containing a list of student names and their corresponding test scores.
The program should output the highest score and the name of the student who received that score.

The text file should have the following format:

Alex Brenton 80
Jane Smith 90
Bob Johnson 70
The program should read in the file, determine the highest score, and output the corresponding student name.

To complete this assignment, you will need to use the ifstream and ofstream classes in C++ to read and write 
files respectively. You will also need to use string manipulation functions to extract the student names and 
scores from the input file.

Stuck? Check Verified Solu
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Open the input file.
  ifstream input_file("test_scores.txt");
  if (!input_file.is_open()) {
    cout << "Error opening input file." << endl;
    return 1;
  }

  // Read the student names and scores from the input file.
  string student_name;
  int score;
  int highest_score = 0;
  string highest_score_student;
  while (input_file >> student_name >> score) {
    if (score > highest_score) {
      highest_score = score;
      highest_score_student = student_name;
    }
  }

  // Close the input file.
  input_file.close();

  // Print the highest score and the name of the student who received it.
  cout << "The highest score is " << highest_score << " and was received by " << highest_score_student << "." << endl;

  return 0;
}
