#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Question {
private:
    string questionText;
    vector<string> options;
    int correctAnswer;

public:
    Question(string text, vector<string> opts, int correct) {
        questionText = text;
        options = opts;
        correctAnswer = correct;
    }

    void displayQuestion() {
        cout << questionText << endl;
        for (int i = 0; i < options.size(); i++) {
            cout << char('a' + i) << ") " << options[i] << endl;
        }
    }

    bool checkAnswer(char answer) {
        int answerIndex = answer - 'a';
        return answerIndex + 1 == correctAnswer;
    }
};

class Quiz {
private:
    vector<Question> questions;
    int score;

public:
    Quiz() {
        score = 0;
        initializeQuestions();
    }

    void initializeQuestions() {
        questions.push_back(Question("Which of the following is not a programming language?", 
                                    {"Python", "HTML", "Java", "C++"}, 2));
        
        questions.push_back(Question("What does 'OOP' stand for in programming?", 
                                    {"Object Oriented Programming", "Open Oriented Program", 
                                     "Optional Object Process", "Object Operating Program"}, 1));
        
        questions.push_back(Question("Which keyword is used to define a function in Python?", 
                                    {"func", "function", "def", "define"}, 3));
        
        questions.push_back(Question("In C++, which symbol is used to access members of a class through an object?", 
                                    {". (dot)", "-> (arrow)", ":: (scope resolution)", "#"}, 1));
        
        questions.push_back(Question("Which of the following is used to style web pages?", 
                                    {"HTML", "CSS", "JavaScript", "Python"}, 2));
        
        questions.push_back(Question("What will 5 / 2 output in C++?", 
                                    {"2.5", "2", "2.0", "Error"}, 2));
        
        questions.push_back(Question("Which of the following is used for version control?", 
                                    {"Git", "Python", "React", "SQL"}, 1));
    }

    void startQuiz() {
        score = 0;
        for (int i = 0; i < questions.size(); i++) {
            cout << "\nQuestion " << i + 1 << ":" << endl;
            questions[i].displayQuestion();
            
            char answer;
            cout << "Your answer (a-d): ";
            cin >> answer;

            if (questions[i].checkAnswer(answer)) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Wrong!" << endl;
            }
        }
        displayScore();
    }

    void displayScore() {
        cout << "\nYour final score: " << score << "/" << questions.size() << endl;
        double percentage = (double)score / questions.size() * 100;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Quiz quiz;
    int choice;

    while (true) {
        cout << "\n1. Start Quiz\n2. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                quiz.startQuiz();
                break;
            case 2:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}