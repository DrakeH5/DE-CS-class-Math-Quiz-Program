#include <iostream>
#include <cstdlib>
#include <ctime> 
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

int main() {    
   cout << "MATH QUIZ" << endl;

    int diff;

   cout << "What is your prefered difficulty?" << endl << " 1) Beginner \n 2) Intermediant \n 3) Advanced \n";
   cin >> diff;

   srand(time(0));

   int score;

   for(int i=0; i<10; i++){

        if(PromptQuestion(RandNmb(diff), RandNmb(diff))){
            score++;
        }

   }

   cout << "Your Score was: " << score << endl;

   return 0;
}
