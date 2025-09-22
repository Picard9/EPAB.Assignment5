// Assignment 5 - Math Quiz
// Emilien Aboula

#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>


using namespace std;

int main()
{
    string ReadMemory = "C:\\Projects\\C++\\EPAB.Assignment5\\Temp\\memory.txt";
    string WriteQuizResults = "C:\\Projects\\C++\\EPAB.Assignment5\\Temp\\QuizResults.txt";
    string line;

    ifstream ifs(ReadMemory);

    ofstream ofs;
    ofs.open(WriteQuizResults);

    // store all questions from the file
    vector<string> questions;

    while (getline(ifs, line)) {
      questions.push_back(line);
    }
    ifs.close();

    cout << "Welcome to the Math Quiz!\n\n";
 

    // initialize random number generator
    srand((time(NULL)));

    string result;
    // Ask 3 random questions
    for (int i = 0; i < 3; i++) {
        int randomNumber = rand() % 10 + 1;
        cout << "Question " << (i + 1) << ": " << questions[randomNumber] << " =" "\n";
        cout << "Enter your answer: ";
        cin >> result;
        ofs << questions[randomNumber] << " = " << result << "\n";
        cout << "\n";
    }

    cout << "Results saved to QuizResults.txt ";

    (void)_getch();
    return 0;
}
