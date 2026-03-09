#include <iostream>

using namespace std;

class GradedActivity { // Base class

private:
    double score;   // Numeric score

public:
    // Default constructor

    GradedActivity() { score = 0.0; }

    // Constructor

    GradedActivity(double s) { score = s; }

    // Mutator

    void setScore(double s) { score = s; }

    // Accessors

    double getScore() const { return score; }

    char getLetterGrade() const {

        if (score > 89) return 'A';

        else if (score > 79) return 'B';

        else if (score > 69) return 'C';

        else if (score > 59) return 'D';

        else return 'F';

    }

};

class FinalExam : public GradedActivity { // Derived class

private:
    int numQuestions;     // Number of questions
    double pointsEach;    // Points for each question
    int numMissed;        // Number missed

public:
    FinalExam() {
        numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0;
    }

    FinalExam(int questions, int missed) {
        set(questions, missed);
    }

    void set(int questions, int missed) {

        double numericScore;

        numQuestions = questions;

        numMissed = missed;

        pointsEach = 100.0 / numQuestions;        // Calculate points for each question

        numericScore = 100.0 - (missed * pointsEach);        // Calculate numeric score

        // Call inherited function to set score
        setScore(numericScore);  // Inherited from GradedActivity

    }

    double getPointsEach() const { return pointsEach; }

    int getNumMissed() const { return numMissed; }

};

int main() {
    FinalExam test(20, 3);  // 20 questions, 3 missed

    cout << "Score: " << test.getScore() << endl;        // Inherited
    cout << "Grade: " << test.getLetterGrade() << endl;  // Inherited
    cout << "Points each: " << test.getPointsEach() << endl;  // FinalExam's

    return 0;
}

