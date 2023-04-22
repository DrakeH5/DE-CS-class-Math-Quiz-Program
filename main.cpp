#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <vector>
#include <cassert>
using namespace std;


enum difficulty { EASY, MEDIUM, HARD };

int RandNmb(difficulty diff){
    if(diff == EASY){
    return rand() % 9;
    } else if(diff == MEDIUM){
    return (rand() % 89) + 10;
    } else {
    return (rand() % 199) - 99;
    }
}

bool PromptQuestion(int x, int y, int& score){
    cout << x << "+" << y << endl;
    int answer;
    cin >> answer;
    if(answer == x+y) {
        score++;
        return true;
    } else {
        return false;
    }
}

void MathProblem(difficulty diff, int& score){
    int nmb1 = RandNmb(diff);
    int nmb2 = RandNmb(diff);

    if(PromptQuestion(nmb1, nmb2, score) == false){
        cout << "Sorry, that is incorrect. \nTry Again \n";
        if(PromptQuestion(nmb1, nmb2, score) == false) {
            cout << "Correct answer: " << nmb1 + nmb2 << endl;
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

void unitTest(){
    vector<string> HighscoreNamesTest = {"Drake", "Richard", "Jim Bob Joe", "Zachias", "Jordon", "Shrek"};
    vector<int> HighscoreScoresTest = {1, 10, 2, 5, 3, 7};
    
    sortHighscores(HighscoreNamesTest, HighscoreScoresTest);

    vector<string> HighscoreNamesTestSORTED = {"Richard", "Shrek", "Zachias", "Jordon", "Jim Bob Joe", "Drake"};
    vector<int> HighscoreScoresTestSORTED = {10, 7, 5, 3, 2, 1};

    assert(HighscoreNamesTest == HighscoreNamesTestSORTED && HighscoreScoresTest == HighscoreScoresTestSORTED);
}


void quiz(vector<string>& highscoreNames, vector<int>& highscorePoints){

    difficulty diff = getDifficulty();

   srand(time(0));

   int score = 0;

   for(int i=0; i<10; i++){

        MathProblem(diff, score);

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
