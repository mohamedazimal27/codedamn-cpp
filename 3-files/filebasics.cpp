#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Open the input file.
  ifstream inputFile("test_scores.txt");
  if (!inputFile.is_open()) {
    cout << "Error opening input file." << endl;
    return 1;
  }

  // Initialize variables to store the highest score and the corresponding student name.
  int highestScore = 0;
  string highestScoreStudentName = "";

  // Read each line of the input file.
  string line;
  while (getline(inputFile, line)) {
    // Split the line into two parts: the student name and the test score.
    string studentName = line.substr(0, line.find(" "));
    int testScore = stoi(line.substr(line.find(" ") + 1));

    // If the test score is higher than the highest score, update the highest score and student name.
    if (testScore > highestScore) {
      highestScore = testScore;
      highestScoreStudentName = studentName;
    }
  }

  // Close the input file.
  inputFile.close();

  // Output the highest score and the name of the student who received that score.
  cout << "The highest score is " << highestScore << ", and it was received by " << highestScoreStudentName << "." << endl;

  return 0;
}
