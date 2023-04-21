#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <vector>
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

bool PromptQuestion(int x, int y){
    cout << x << "+" << y << endl;
    int answer;
    cin >> answer;
    if(answer == x+y) {
        return true;
    } else {
        return false;
    }
}

void quiz(vector<string>& highscores){

    difficulty diff;

   cout << "What is your prefered difficulty?" << endl << " 1) Beginner \n 2) Intermediant \n 3) Advanced \n";
   int in;
   cin >> in;
   if(in == 1){
        diff = EASY;
   } else if(in == 2){
        diff = MEDIUM;
   } else if(in == 1){
        diff = HARD;
   }

   srand(time(0));

   int score = 0;

   for(int i=0; i<10; i++){

        if(PromptQuestion(RandNmb(diff), RandNmb(diff))){
            score++;
        }

   }

   cout << "Your Score was: " << score << endl;

   if(score > 0){
        string username;
        cout << "What is your name \n";
        cin >> username;
        highscores.push_back(username);
   }

   cout << "Highscore List: ";

    for(int i=0; i<highscores.size(); i++){
        cout << i+1 << ") " << highscores.at(i) << endl;
    }
}

int main() {    
   cout << "MATH QUIZ" << endl;

   vector<string> highscores;

    char response;

    do{
        quiz(highscores);
        cout << "Shall we play a game? \n y for yes \n n for no \n";
        cin >> response;
    } while(response == 'y');

   return 0;
}
