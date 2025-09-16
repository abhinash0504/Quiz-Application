#include <iostream>
#include <string>
using namespace std;

// Structure for each quiz question
struct Question {
    string question;
    string options[4];
    int correctAnswer; // index of correct option (1–4)
};

// Function to run the quiz
int runQuiz(Question quiz[], int totalQuestions) {
    int score = 0;
    int answer;

    cout << "=============================" << endl;
    cout << "     Welcome to the Quiz     " << endl;
    cout << "=============================" << endl << endl;

    for (int i = 0; i < totalQuestions; i++) {
        cout << "Q" << i + 1 << ": " << quiz[i].question << endl;

        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << quiz[i].options[j] << endl;
        }

        cout << "Your Answer (1-4): ";
        cin >> answer;

        if (answer == quiz[i].correctAnswer) {
            cout << "\u2705 Correct!" << endl << endl;
            score++;
        } else {
            cout << "\u274C Wrong! Correct answer: " 
                 << quiz[i].options[quiz[i].correctAnswer - 1] << endl << endl;
        }
    }

    return score;
}

int main() {
    // Quiz Questions
    Question quiz[] = {
        {"Who developed the C programming language?",
         {"Dennis Ritchie", "Bjarne Stroustrup", "James Gosling", "Guido van Rossum"}, 1},

        {"C++ was developed by?",
         {"Bjarne Stroustrup", "Dennis Ritchie", "Ken Thompson", "James Gosling"}, 1},

        {"Which of the following is not a data structure?",
         {"Array", "Linked List", "Tree", "Compiler"}, 4},

        {"Which operator is used to allocate memory dynamically in C++?",
         {"malloc", "alloc", "new", "create"}, 3},

        {"DSA stands for?",
         {"Data Structure & Algorithm", "Database System Analysis", 
          "Digital Signal Application", "None of the above"}, 1}
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score = runQuiz(quiz, totalQuestions);

    cout << "=============================" << endl;
    cout << "Quiz Completed!" << endl;
    cout << "Your Final Score: " << score << " / " << totalQuestions << endl;
    cout << "=============================" << endl;

    return 0;
}
