#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <vector>
using namespace std;

int RandNmb(int diff){
    if(diff == 1){
    return rand() % 9;
    } else if(diff == 2){
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

void quiz(){
    int diff;

   cout << "What is your prefered difficulty?" << endl << " 1) Beginner \n 2) Intermediant \n 3) Advanced \n";
   cin >> diff;

   srand(time(0));

   int score = 0;

   for(int i=0; i<10; i++){

        if(PromptQuestion(RandNmb(diff), RandNmb(diff))){
            score++;
        }

   }

   cout << "Your Score was: " << score << endl;

    vector<string> highscores;

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

    char response;

    do{
        quiz();
        cout << "Shall we play a game? \n y for yes \n n for no \n";
        cin >> response;
    } while(response == 'y');

   return 0;
}
