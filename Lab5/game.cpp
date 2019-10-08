#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int rollDie(){
    int roll = (rand()%6+1);
    return roll;
}

bool playOneGame(){
    int pointer = 0;
    bool pointerCheck = 1;
        while(pointerCheck==1){                                                         //checks for valid pointer
                cout<<"Enter Pointer: "<<endl;
                cin>>pointer;
                if (pointer>=1&&pointer<=6){
                    pointerCheck=0;
                }
                else{
                    cout<<"Error, enter a pointer from 1-6."<<endl;
                }}
                for(int i=0;i<3;++i){
                    int rolly = rollDie();
                    cout<<"You rolled "<<rolly<<endl;
                    if(rolly==pointer){
                       cout<<"*You've won!*"<<endl;
                       return true;
                    }
                    else if(i==2&&pointer!=rolly){
                        cout<<"Tough luck, no matches this time. You lose."<<endl;
                        return false;
                    }
                    else{
                        cout<<"No matches, rolling again."<<endl;
                    }
                }
                return 0;
            }






double winadd(double win){                                                              //increments wins
    return(win+1);
}

double loseadd(double lose){                                                            //increments losses
    return(lose+1);
}

double moneywin(double balance, double wager){                                          // calculates new balance on winning game
    balance= balance+wager;
    return(balance);

}

double moneylose(double balance, double wager){                                         //calculates new balance on losing game
    balance = balance-wager;
    return(balance);
}

double winPercent(double lose, double win){                                             //caluclates win percentage
    double totalgames = lose+win;
    return((win/totalgames)*100);


}

int main(){
    srand(time(0));                                                                     //seeding random rolls
    double wins = 0;
    double losses = 0;
    double balance = 100.0;
    double wager = 0.0;
    bool wagerCheck = 1;
    bool playAgain = 1;
    bool result;
    cout<<"In this game you will pick a pointer number from 1-6.\n"
          "A die will be rolled 3 times and you will start with $100 and wager on if the pointer number you pick gets rolled.\n"
          "If your number gets rolled once, you win, if not, you lose.\n"
          "The game goes until you choose to leave, or run out of money."<<endl;
   while(playAgain == 1){
    while(wagerCheck ==1){                                                              //checks for valid wager
        cout<<"You have $"<<balance<<". How much would you like to wager?"<<endl;
        cin>>wager;
        if(wager<=balance){
            break;
        }
        else{
            cout<<"Error, enter a valid wager."<<endl;
        }
    }

    result = playOneGame();
    if(result == true){
        wins=winadd(wins);
        balance=moneywin(balance, wager);
    }
    else{
        losses=loseadd(losses);
        balance=moneylose(balance,wager);
    }
    if(balance-0<0.01){                                                     //prevents user from getting a play again question even if out of money
        break;
    }
    cout<<"Wins: "<<wins<<endl;
    cout<<"Losses: "<<losses<<endl;
    cout<<"Balance: $"<<balance<<endl;
    cout<<"Would you like to play again(1-yes/0-no)?: "<<endl;
    cin>>playAgain;

}
   cout<<"Game over."<<endl;
   cout<<"Wins: "<<wins<<endl;
   cout<<"Losses: "<<losses<<endl;
   cout<<"Win percentage: "<<winPercent(losses,wins)<<"%"<<endl;
   cout<<"Final Balance: $"<<balance<<endl;

}
