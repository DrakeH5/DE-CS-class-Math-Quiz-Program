#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <vector>
#include <cassert>
using namespace std;


enum Difficulty { D_EASY, D_MEDIUM, D_HARD };

enum mode {M_ADDITION, M_SUBTRACTION, M_MULTIPLICATION, M_DIVISION };

int RandNmb(Difficulty diff){
    if(diff == D_EASY){
        return rand() % 9;
    } else if(diff == D_MEDIUM){
        return (rand() % 89) + 10;
    } else {
        return (rand() % 199) - 99;
    }
}


void findNbmsThatMultiplyToBeUnderAValue(int& y, int& x, int midTop, int midLower){
    y = rand() % midTop + midLower;
    int max = 0;
    while( abs(y * max) < ((midTop + midLower) * 2) ){
        max++;
    }
    x = (rand() % max) * y;
}

void DivisonNmbs(Difficulty diff, int& x, int& y){
    if(diff == D_EASY){
        findNbmsThatMultiplyToBeUnderAValue(y, x, 4, 1);
    } else if(diff == D_MEDIUM){
        findNbmsThatMultiplyToBeUnderAValue(y, x, 40, 10);
    } else {
        findNbmsThatMultiplyToBeUnderAValue(y, x, 99, -49);
    }
}

char operationSign(mode selectedMode){
    if(selectedMode == M_SUBTRACTION){
        return '-';
    } else if(selectedMode == M_MULTIPLICATION){
        return '*';
    } else if(selectedMode == M_DIVISION){
        return '/';
    } else {
        return '+';
    }
}

int calcAnswer(mode selectedMode, int x, int y){
    if(selectedMode == M_SUBTRACTION){
        return x - y;
    } else if(selectedMode == M_MULTIPLICATION){
        return x * y;
    } else if(selectedMode == M_DIVISION){
        return x / y;
    } else {
        return x + y;
    }
}

bool PromptQuestion(int x, int y, int& score, mode selectedMode){
    cout << x << operationSign(selectedMode) << y << endl;
    int answer;
    cin >> answer;
    if(answer == calcAnswer(selectedMode, x, y)) {
        score++;
        return true;
    } else {
        return false;
    }
}

void MathProblem(Difficulty diff, int& score, mode selectedMode){

    int nmb1;
    int nmb2;

    if(selectedMode == M_DIVISION){
        DivisonNmbs(diff, nmb1, nmb2);
    } else {
        nmb1 = RandNmb(diff);
        nmb2 = RandNmb(diff);
    }

    if(PromptQuestion(nmb1, nmb2, score, selectedMode) == false){
        cout << "Sorry, that is incorrect. \nTry Again \n";
        if(PromptQuestion(nmb1, nmb2, score, selectedMode) == false) {
            cout << "Correct answer: " << calcAnswer(selectedMode, nmb1, nmb2) << endl;
        }
    }
}

Difficulty getDifficulty(){
    cout << "What is your prefered difficulty?" << endl << " 1) Beginner \n 2) Intermediant \n 3) Advanced \n";
    int in;
    cin >> in;
    return Difficulty(in-1); //learned from https://stackoverflow.com/questions/321801/enum-c-get-by-index
}

void sortHighscores(vector<string>& highscoreNames, vector<int>& highscorePoints){
    for (int i = 0; i < highscorePoints.size() - 1; i++) {

        int maxIndex = i;
        for (int j = i + 1; j < highscorePoints.size(); j++) {
            if (highscorePoints.at(j) > highscorePoints.at(maxIndex)) {
                maxIndex = j;
            }
        }
                 
        swap(highscoreNames.at(maxIndex), highscoreNames.at(i));
        swap(highscorePoints.at(maxIndex), highscorePoints.at(i));
    }
}

void UnitTest(){

    //unit tests for sorting
    vector<string> HighscoreNamesTest = {"Drake", "Richard", "Jim Bob Joe", "Zachias", "Ron Burgandy", "Shrek"};
    vector<int> HighscoreScoresTest = {1, 10, 2, 5, 5, 7};
    
    sortHighscores(HighscoreNamesTest, HighscoreScoresTest);

    vector<string> HighscoreNamesTestSORTED = {"Richard", "Shrek", "Zachias", "Ron Burgandy", "Jim Bob Joe", "Drake"};
    vector<int> HighscoreScoresTestSORTED = {10, 7, 5, 5, 2, 1};

    assert(HighscoreNamesTest == HighscoreNamesTestSORTED && HighscoreScoresTest == HighscoreScoresTestSORTED);


    HighscoreNamesTest = {"Frankenstein", "Ricky Bobby", "LEROY JENKINS", "Elvis", "Waylon Jennings"};
    HighscoreScoresTest = {0, 10, -1, 4, 5};
    
    sortHighscores(HighscoreNamesTest, HighscoreScoresTest);

    HighscoreNamesTestSORTED = {"Ricky Bobby", "Waylon Jennings", "Elvis", "Frankenstein", "LEROY JENKINS"};
    HighscoreScoresTestSORTED = {10, 5, 4, 0, -1};

    assert(HighscoreNamesTest == HighscoreNamesTestSORTED && HighscoreScoresTest == HighscoreScoresTestSORTED);

    
    //unit tests for getting right sign
    assert(operationSign(M_ADDITION) == '+');
    assert(operationSign(M_SUBTRACTION) == '-');
    assert(operationSign(M_MULTIPLICATION) == '*');
    assert(operationSign(M_DIVISION) == '/');


    //unit tests for calculating answer
    assert(calcAnswer(M_ADDITION, 2, 2) == 4);
    assert(calcAnswer(M_ADDITION, 4, 2) == 6);
    assert(calcAnswer(M_ADDITION, 2, 4) == 6);
    assert(calcAnswer(M_ADDITION, 1, 9) == 10);
    assert(calcAnswer(M_ADDITION, -40, 97) == 57);
    assert(calcAnswer(M_MULTIPLICATION, 2, 2) == 4);
    assert(calcAnswer(M_MULTIPLICATION, 1, 2) == 2);
    assert(calcAnswer(M_MULTIPLICATION, 30, 20) == 600);
    assert(calcAnswer(M_SUBTRACTION, 2, 2) == 0);
    assert(calcAnswer(M_SUBTRACTION, 0, 2) == -2);
    assert(calcAnswer(M_SUBTRACTION, 98, 12) == 86);
    assert(calcAnswer(M_SUBTRACTION, 98, -12) == 110);
    assert(calcAnswer(M_DIVISION, 99, 9) == 11);
    assert(calcAnswer(M_DIVISION, -99, 9) == -11);
    assert(calcAnswer(M_DIVISION, -99, -9) == 11);
    assert(calcAnswer(M_DIVISION, 9, 3) == 3);



}


mode getMode(){
    cout << "Which gamemode would you prefer? \n 1) ADDITION \n 2) SUBTRACTION \n 3) MULTIPLICATION \n 4) DIVISION \n";
    int answer;
    cin >> answer;
    return mode(answer-1); //learned from https://stackoverflow.com/questions/321801/enum-c-get-by-index
}


void endingScore(int score, vector<string>& highscoreNames, vector<int>& highscorePoints){

    cout << "Your Score was: " << score << endl;

   if(score > 0){
        string username;
        cout << "What is your name? \n";
        cin >> username;
        highscoreNames.push_back(username);
        highscorePoints.push_back(score);
   }

}

void displayHighscores(const vector<string>& highscoreNames, const vector<int>& highscorePoints){

   cout << "Highscore List: \n";

    for(int i=0; i<highscoreNames.size(); i++){
        cout << i+1 << ") " << highscoreNames.at(i) << " --- " << highscorePoints.at(i) << endl;
    }

}


void quiz(vector<string>& highscoreNames, vector<int>& highscorePoints){

    mode selectedMode = getMode();

    Difficulty diff = getDifficulty();

   srand(time(0));

   int score = 0;

   for(int i=0; i<10; i++){
        MathProblem(diff, score, selectedMode);
   }

   endingScore(score, highscoreNames, highscorePoints);

   sortHighscores(highscoreNames, highscorePoints);

    displayHighscores(highscoreNames, highscorePoints);

}


int main() {    

    UnitTest();

   cout << "MATH QUIZ" << endl;

   vector<string> highscoreNames;
   vector<int> highscorePoints;

    char response;

    do{
        quiz(highscoreNames, highscorePoints);
        cout << "Shall we play a game? \n y for yes \n n for no \n";
        cin >> response;
    } while(response == 'y');

   return 0;
}
