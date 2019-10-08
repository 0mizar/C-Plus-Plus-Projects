/*
 * Project Title:
 * - The Mayan Temple Game
 * Description: The User will spawn outside of a mayan temple.  They will need to find a lamp and use it to find the entrance to the temple.
 * The user will need to beat a guardian of the temple in rock paper scissors.
 * They will then pick a choice of a bow, sword, or wand to fight with.
 * They will then fight a second mayan guardian, and after that the boss Kukulkan.  After defeating these enemies they will be returned home and complete the game.
 * This program does.......
 *
 * Developers:
 * - Omar Ahmouda - ahmoudot@mail.uc.edu
 *
 * Help Received:
 * - None
 * - None
 * - None
 *
 * Special Instructions: // optional
 * - How to compile
 * - How to run it
 *
 * Developer comments: // Not optional
 * Developer 1:
 * I coded all tasks by myself with no help from anyone.
 * I learned alot about how functions interact with each other and how I can make my main function clean by using many other functions.
 * I also learned about how to use functions inside of functions to maximize code reusability(my weapon attacks).
 * I learned how to allow the user to explore an area(walking around the pyramid to find entrance).
 */


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int SwordAttack(int health){
    bool err = 1;
    int choice;
    while (err!=0){
   cout<<"Your sword is ready at your side\n"
         "[1] Attack\n"
         "[2] Do nothing\n";
   cin>>choice;
   if(choice==1){
       err=0;
       cout<<"You lunge at the enemy with your sword for 3 damage."<<endl;
       return health-3;
   }
   else if (choice==2){
       cout<<"You do nothing."<<endl;
       err=0;
       return health;
   }
   else{
       cout<<"Error, please choose a valid option."<<endl;
       err=1;
   }
}
}

int BowAttack(int health){
    int choice;
    bool err = 1;
    while (err!=0){
        cout<<"Your bow is drawn, what will you do?\n"
              "[1] Shoot your bow\n"
              "[2] Do nothing\n";
        cin>>choice;
        if (choice==1){
        cout<<"You shoot your arrow at the enemy."<<endl;
            int Atk;
            Atk=((rand()%5)+1);
            if (Atk==1){
                cout<<"Your arrow hit for 2 damage"<<endl;
                return health-2;
                      }
            else if ((Atk>=2)&(Atk<=3)){
                cout<<"Your arrow hits its mark for 3 damage."<<endl;
                return health-3;
            }
            else{
                cout<<"Nice Shot! Your arrow hits its mark for 4 damage!"<<endl;
                return health-4;}
        }
        else if (choice==2){
            cout<<"You do nothing."<<endl;
            err=0;
            return health;
        }
        else{
            cout<<"Error, please choose a valid option."<<endl;
        }
    }
}
int WandAttack(int health){
    int AtkChoice;
    bool err=1;
    int Atk;
    while (err!=0){
        cout<<"What spell do you with to cast?\n"
              "[1] Spell of Burning Flames(High Hit Chance(2 damage))\n"
              "[2] Spell of Instant Death(Low Hit Chance(Infinity damage))\n"<<endl<<endl;
        cin>>AtkChoice;
        if (AtkChoice==1){
            cout<<"Your Flames burn the enemy for 3 damage."<<endl;
            err=0;
            return health-3;
        }
        else if (AtkChoice==2){
            Atk=((rand()%5)+1);
            if(Atk>=4){
                cout<<"Your spell was Successful!"<<endl;
                err=0;
                return 0;
            }
            else{
                cout<<"Your spell was unsuccessful."<<endl;
                return health;
            }
        }
    }
}

string startSeq(){

    int startDecision;
    bool startDecSuccess=0;

    while (startDecSuccess!=1){
        cout<<   "You see a faint glow on the ground.\n"
           "What will you do?\n"
           "[1] Investigate the glow.\n"
           "[2] Sit and Cry.\n"<<endl<<endl;
        cin>>startDecision;
        if (startDecision == 1){
            cout<<"You find a lamp on the ground.\n"
                  "You turn the lamp on and see a note attached to it that reads,\n"
                  "'Your key to getting home is in the temple.  Find the Entrance.'"<<endl;
            return "South";
        }
        else if (startDecision==2){
            cout<< "You sit and cry for a bit until you realize that being a crybaby won't help you."<<endl;
        }
        else{
            cout<<"Error, enter a valid choice."<<endl;
        }
    }
}

string SouthSideOfTemple(){
    int move;
    bool NoErr=1;
    while (NoErr!=0){
        cout<<"You are on the South side of the pyramid currently and see no Entrance.\n"
        "What will you do?\n"
        "[1] Investigate West Side of Temple.\n"
        "[2] Investigate East Side of Temple.\n"<<endl<<endl;
        cin>>move;
        if (move==1){
            return "West";
        }
        else if (move==2){
            return "East";
        }
        else{
            NoErr=1;
        }
    }
}

string EastSideOfTemple(){
    int move;
    bool NoErr=1;
    while (NoErr!=0){
        cout<<"You are on the East side of the pyramid currently and see no Entrance.\n"
        "What will you do?\n"
        "[1] Investigate South Side of Temple.\n"
        "[2] Investigate North Side of Temple.\n"<<endl<<endl;
        cin>>move;
        if (move==1){
            return "South";
        }
        else if (move==2){
            return "North";
        }
        else{
            NoErr=1;
        }
    }
}

string WestSideOfTemple(){
    int move;
    bool NoErr=1;
    while (NoErr!=0){
        cout<<"You are on the West side of the pyramid currently and see no Entrance.\n"
        "What will you do?\n"
        "[1] Investigate North Side of Temple.\n"
        "[2] Investigate South Side of Temple.\n"<<endl<<endl;
        cin>>move;
        if (move==1){
            return "North";
        }
        else if (move==2){
            return "South";
        }
        else{
            NoErr=1;
        }
    }
}

string NorthSideOfTemple(){
    int move;
    bool NoErr=1;
    while (NoErr!=0){
        cout<<"You are on the North side of the pyramid currently and you see a small door into the Pyramid.\n"
        "What will you do?\n"
        "[1] Enter the small door into the Pyramid.\n"
        "[2] Investigate East Side of Temple.\n"
        "[3] Investigate West Side of Temple.\n"<<endl<<endl;
        cin>>move;
        if (move==1){
            return "EntranceToTemple";
        }
        else if (move==2){
            return "East";
        }
        else if (move==3){
            return "West";
        }
        else{
            NoErr=1;
        }
    }
}

void GameInstructions(){
    cout<<"Welcome to my text-based adventure game.\n"
          "In this game you will be given information and choice options.\n"
          "To select a choice, simply type the corresponding number and hit enter.\n"
          "In a battle, you will have 5 hearts which replenish after each battle.\n"
          "If your hearts run out in battle, it will be game over and you will have to restart\n"
          "Thank you for playing my game, enjoy. ~ Omar Ahmouda"<<endl<<endl<<endl;
}

int RockPaperScissors(){
    int rpsnum;
    srand(time(nullptr));
    string rpsname;
    string enemyrpsname;
    int enemyrpsnum;
    bool win=0;
    while(win!=1){
        bool RpsErr = 1;
        enemyrpsnum= ((rand()&3)+1);
        if (enemyrpsnum==1){
            enemyrpsname="Rock";
        }
        else if(enemyrpsnum==2  ){
            enemyrpsname="Paper";
        }
        else{
            enemyrpsname="Scissors";
        }
        while (RpsErr !=0){
            cout<<"You are challenged by temple guardian to the sacred game of rock,paper,scissors.\n"
                  "Which will you choose?\n"
                  "[1] Rock\n"
                  "[2] Paper\n"
                  "[3] Scissors\n"<<endl<<endl;
            cin>>rpsnum;
            if(rpsnum==1){
                rpsname="Rock";
                RpsErr=0;
            }
            else if (rpsnum==2){
                rpsname="Paper";
                RpsErr=0;
            }
            else if (rpsnum==3){
                rpsname="Scissors";
                RpsErr=0;
            }
            else{
                cout<<"Error, please select a valid choice."<<endl;
            }
        }
        cout<<"You Chose: "<<rpsname<<". The Temple Guardian Chose: "<<enemyrpsname<<"."<<endl;
        if((rpsname=="Rock"&&enemyrpsname=="Scissors")||(rpsname=="Paper"&&enemyrpsname=="Rock")||(rpsname=="Scissors"&&enemyrpsname=="Paper")){
            cout<<"Congratulations!  You've beaten the Temple Guardian!"<<endl;
            win=1;
        }
        else{
            cout<<"Sorry, you lost to the temple Guardian.\n"
                  "Please try again."<<endl;
        }
    }

    bool weaponErr = 1;
    int weaponChoice;
    while(weaponErr!=0){
        cout<<"Since you've beaten me I will give you the key to the temple AND your choice of weapon.\n"
              "Which weapon will you chose?\n"
              "[1] Bow and Arrow\n"
              "[2] Sword\n"
              "[3] Magic Wand"<<endl<<endl<<endl;
        cin>>weaponChoice;
        if (weaponChoice!=1&&weaponChoice!=2&&weaponChoice!=3){
            cout<<"Error, please enter valid weapon choice."<<endl;
            weaponErr=1;
        }
        else{
            weaponErr=0;
        }
    }

      return weaponChoice;

}

int EntranceToTemple(){
    bool error=1;
    int AcceptChallenge;
    int WeaponChoice;
    cout<<"As you touch the door to enter the temple you are thrown back!\n"
          "'I am the guardian of the temple, you will have to beat me in a sacred game to pass!'"<<endl;
    while(error!=0){
        cout<<"What will you do?\n"
        "[1]Accept the Guardian Temple's Challenge.\n"
        "[2]Reject the Guargian Temple's Challenge.\n"<<endl<<endl;
        cin>>AcceptChallenge;
        if (AcceptChallenge==1){
            error = 0;
            cout<<"That's the spirit!"<<endl;
            WeaponChoice=RockPaperScissors();
        }
        else if(AcceptChallenge==2){
            error = 0;
            cout<<"You really thought you had a choice?"<<endl;
            WeaponChoice=RockPaperScissors();

        }
        else{
            cout<<"Error, please enter valid choice option."<<endl;
            error=1;
        }
    }
    return WeaponChoice;
}

int FirstEnemyAttack(int health){
    cout<<"The Enemy lunges at you, striking you for 1 damage."<<endl;
    return health-1;
}


bool FirstRoomFight(bool bow,bool sword){
   int PlayerHealth = 5;
   int EnemyHealth = 5;
   cout<<"You enter the Temple and you see a large statue start to move.\n"
         "'I am the Mayan Brawler! YOU SHALL NOT PASS'\n"
         "The Mayan charges at you and you're forced into a battle!"<<endl;

   while ((PlayerHealth>0)&&(EnemyHealth>0)){
       cout<<"Your current health is "<<PlayerHealth<<" hearts.  The Enemy's health is "<<EnemyHealth<<"."<<endl;
       if(PlayerHealth<=0){
           cout<<"Oh no! You've been defeated.  GAME OVER"<<endl;
           return 0;
       }
       if (bow==1){
           EnemyHealth = BowAttack(EnemyHealth);
       }
       else if (sword==1){
           EnemyHealth = SwordAttack(EnemyHealth);
       }
       else{
           EnemyHealth = WandAttack(EnemyHealth);
       }

       if(EnemyHealth<=0){
           cout<<"Congratulations!  You've beaten the Mayan Brawler!\n"
                 "He disintegrates to dust, leaving behind a key.\n"
                 "You use the key to open the next door of the temple.\n\n";
           return 1;

       }

       PlayerHealth = FirstEnemyAttack(PlayerHealth);
   }

}

int BossAttack(int PlayerHealth){
   int BossAttChoice;
   BossAttChoice=((rand()%8)+1);
   if (BossAttChoice<7){
       cout<<"Kukulkan uses his powers to slam you into the cave wall, dealing 2 damage!"<<endl;
       return PlayerHealth-2;
   }
   else{
       cout<<"Kukulkan strikes you with lightning! Dealing a massive 3 Damage!"<<endl;
       return PlayerHealth-3;
   }

}

bool BossRoomFight(bool bow,bool sword){
   int PlayerHealth = 5;
   int EnemyHealth = 7;
   cout<<"As you enter the second room of the temple, you are surprised to see\n"
         "a large open area with a giant statue that looks like a snake with wings.\n"
         "The Serpent statue roars to life!\n"
         "'I am Kukulkan! Get ready for...A MIGHTY STORM!'\n"
         "You're lifted into a midair battle with Mayan God Kukulkan!\n\n\n";

   while ((PlayerHealth>0)&&(EnemyHealth>0)){
       cout<<"Your current health is "<<PlayerHealth<<" hearts.  The Enemy's health is "<<EnemyHealth<<"."<<endl;
       if (bow==1){
           EnemyHealth = BowAttack(EnemyHealth);
       }
       else if (sword==1){
           EnemyHealth = SwordAttack(EnemyHealth);
       }
       else{
           EnemyHealth = WandAttack(EnemyHealth);
       }

       if(EnemyHealth<=0){
           return 1;

       }


      PlayerHealth = BossAttack(PlayerHealth);

      if(PlayerHealth<=0){
          return 0;
              }
   }

}


int main(){
    srand(time(nullptr));
    bool Key1 = 0;
    bool Key2 = 0;
    bool Bossfight=0;
    bool Sword = 0;
    bool Bow = 0;
    bool Wand = 0;
    int weaponChoice = 0;
    string userName;

    GameInstructions();
    cout<<"Enter Username(No Spaces)"<<endl;
    cin>>userName;
    cout<<"You find yourself awake in front of what appears to be a large Mayan Pyramid.\n"
          "You are not sure where you are, but you know that you need to get back to Ohio.\n";

    string move=startSeq();
    while (move!="EntranceToTemple"){
        while(move=="South"){
            move=SouthSideOfTemple();
        }
        while(move=="East"){
            move=EastSideOfTemple();
        }
        while (move=="West"){
            move=WestSideOfTemple();
        }
        while (move=="North"){
            move=NorthSideOfTemple();
        }
    }

    if(move=="EntranceToTemple"){
        weaponChoice=EntranceToTemple();
        Key1=1;
    }
    if (weaponChoice==1){
        Bow=1;
    }
    else if (weaponChoice==2){
        Sword=1;
    }
    else {
        Wand=1;
    }
    if((Wand==1||Sword==1||Bow==1)||Key1==1){
        Key2=FirstRoomFight(Bow,Sword);
    }
    if (Key2==1){
        bool BossErr=1;
        int choiceBoss;
        while(BossErr!=0){
            cout<<"You obtain the key from the Mayan Brawler.  What will you do?\n"
                  "[1] Open the next door.\n"
                  "[2] Cry some more.\n"<<endl;
            cin>>choiceBoss;
            if(choiceBoss==1){
                BossErr=0;
                Bossfight=BossRoomFight(Bow,Sword);
                if (Bossfight==1){

            cout<<"You've Defeated Kukulkan!\n"
              "'You're very talented! Please allow me to help you get back home'\n\n\n"
                         "You follow Kukulkan into the a secret room and all of a sudden the pyramid opens up!\n"
                         "A UFO rises from within and Kukulkan places you inside of it.\n"
                         "You wake up in your bedroom in Ohio with no answer as to how you got there or any recollection of riding in the UFO.\n"
                         "You feel a weight in your right pocket.\n"
              "You see a beautiful Necklace and a Note that states 'For "<<userName<<" .  Never forget the time you met a god."<<endl;
            }
            else{
                cout<<"Oh no you died! GAME OVER!"<<endl;
                break;
            }
    }
            else if (choiceBoss==2){
                BossErr=1;
                cout<<"You sit and cry some more."<<endl;
            }
            else{
                cout<<"Error, please select a valid choice."<<endl;
                BossErr=1;
            }
         }


}
}
