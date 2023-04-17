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

void PromptQuestion(int x, int y){
    cout << x << "+" << y << endl;
    int answer;
    cin >> answer;
    if(answer == x+y) {
        cout << "Correct!" << endl;
    } else {
        cout << "YOU STUPID" << endl;
    }
}

int main() {    
   cout << "MATH QUIZ" << endl;

    int diff;

   cout << "What is your prefered difficulty?" << endl << " 1) Beginner \n 2) Intermediant \n 3) Advanced \n";
   cin >> diff;

   srand(time(0));

   PromptQuestion(RandNmb(diff), RandNmb(diff));

   return 0;
}
