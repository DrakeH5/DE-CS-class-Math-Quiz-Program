#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <vector>
#include <cassert>
using namespace std;


enum difficulty { EASY, MEDIUM, HARD };

enum mode {ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION };

int RandNmb(difficulty diff){
    if(diff == EASY){
        return rand() % 9;
    } else if(diff == MEDIUM){
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

void DivisonNmbs(difficulty diff, int& x, int& y){
    if(diff == EASY){
        findNbmsThatMultiplyToBeUnderAValue(y, x, 4, 1);
    } else if(diff == MEDIUM){
        findNbmsThatMultiplyToBeUnderAValue(y, x, 40, 10);
    } else {
        findNbmsThatMultiplyToBeUnderAValue(y, x, 99, -49);
    }
}

char operationSign(mode selectedMode){
    if(selectedMode == SUBTRACTION){
        return '-';
    } else if(selectedMode == MULTIPLICATION){
        return '*';
    } else if(selectedMode == DIVISION){
        return '/';
    } else {
        return '+';
    }
}

int calcAnswer(mode selectedMode, int x, int y){
    if(selectedMode == SUBTRACTION){
        return x - y;
    } else if(selectedMode == MULTIPLICATION){
        return x * y;
    } else if(selectedMode == DIVISION){
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

void MathProblem(difficulty diff, int& score, mode selectedMode){

    int nmb1;
    int nmb2;

    if(selectedMode == DIVISION){
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

difficulty getDifficulty(){
    cout << "What is your prefered difficulty?" << endl << " 1) Beginner \n 2) Intermediant \n 3) Advanced \n";
    int in;
    cin >> in;
    return difficulty(in-1);
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
    vector<string> HighscoreNamesTest = {"Drake", "Richard", "Jim Bob Joe", "Zachias", "Jordon", "Shrek"};
    vector<int> HighscoreScoresTest = {1, 10, 2, 5, 3, 7};
    
    sortHighscores(HighscoreNamesTest, HighscoreScoresTest);

    vector<string> HighscoreNamesTestSORTED = {"Richard", "Shrek", "Zachias", "Jordon", "Jim Bob Joe", "Drake"};
    vector<int> HighscoreScoresTestSORTED = {10, 7, 5, 3, 2, 1};

    assert(HighscoreNamesTest == HighscoreNamesTestSORTED && HighscoreScoresTest == HighscoreScoresTestSORTED);
}


mode getMode(){
    cout << "Which gamemode would you prefer? \n 1) ADDITION \n 2) SUBTRACTION \n 3) MULTIPLICATION \n 4) DIVISION \n";
    int answer;
    cin >> answer;
    return mode(answer-1);
}

void quiz(vector<string>& highscoreNames, vector<int>& highscorePoints){

    mode selectedMode = getMode();

    difficulty diff = getDifficulty();

   srand(time(0));

   int score = 0;

   for(int i=0; i<10; i++){

        MathProblem(diff, score, selectedMode);

   }

   cout << "Your Score was: " << score << endl;

   if(score > 0){
        string username;
        cout << "What is your name? \n";
        cin >> username;
        highscoreNames.push_back(username);
        highscorePoints.push_back(score);
   }

    sortHighscores(highscoreNames, highscorePoints);

   cout << "Highscore List: \n";

    for(int i=0; i<highscoreNames.size(); i++){
        cout << i+1 << ") " << highscoreNames.at(i) << " --- " << highscorePoints.at(i) << endl;
    }
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
