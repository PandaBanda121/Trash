#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <unistd.h>
#include <sstream>


#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;


void printIntroScreen(int introSelect);

void printGameScreen();
void printAchievementsScreen();
void printQuitScreen();


void printIntroScreen(int introSelect) {
    string top =                   "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    string empty =                 "┃                                                                    ┃\n";
    vector<string> intro =        {"┃                              Welcome!                              ┃\n",
                                   "┃                               Rules:                               ┃\n",
                                   "┃    Use number cards (yellow) to create combos against the enemy    ┃\n",
                                   "┃         Use face cards (blue) to reduce the enemy's damage         ┃\n",
                                   "┃              Stack combos to make them more effective              ┃\n",
                                   "┃                             Good luck!                             ┃\n"};
    vector<string> butt1high =    {"┃                       ╭────────────────────╮                       ┃\n",
                                   "┃                       │   [1] Start Game   │                       ┃\n",
                                   "┃                       ╰────────────────────╯                       ┃\n"};
    vector<string> butt1 =        {"┃                                                                    ┃\n",
                                   "┃                           [1] Start Game                           ┃\n",
                                   "┃                                                                    ┃\n"};
    vector<string> butt2high =    {"┃                       ╭────────────────────╮                       ┃\n",
                                   "┃                       │  [2] Achievements  │                       ┃\n",
                                   "┃                       ╰────────────────────╯                       ┃\n"};
    vector<string> butt2 =        {"┃                                                                    ┃\n",
                                   "┃                          [2] Achievements                          ┃\n",
                                   "┃                                                                    ┃\n"};
    vector<string> butt3high =    {"┃                       ╭────────────────────╮                       ┃\n",
                                   "┃                       │   [3] Leave Game   │                       ┃\n",
                                   "┃                       ╰────────────────────╯                       ┃\n"};
    vector<string> butt3 =        {"┃                                                                    ┃\n",
                                   "┃                           [3] Leave Game                           ┃\n",
                                   "┃                                                                    ┃\n"};
    string controls =              "┃       [W][S]: Scroll through options  [Enter]: Select option       ┃\n";
    string bottom =                "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    cout << "\033[2J\033[1;1H";
    cout << top << empty;
    for(string line : intro) cout << line;
    cout << empty;
    if(introSelect == 1) for(string line : butt1high) cout << line;
    else for(string line : butt1) cout << line;
    if(introSelect == 2) for(string line : butt2high) cout << line;
    else for(string line : butt2) cout << line;
    if(introSelect == 3) for(string line : butt3high) cout << line;
    else for(string line : butt3) cout << line;

    cout << empty << empty << empty << empty << controls << empty << empty << bottom;

}


void printGameScreen() {
    cout << "\033[2J\033[1;1H";
    cout << "Game" << endl;
}

void printAchievementsScreen() {
    cout << "\033[2J\033[1;1H";
    cout << "Achievements" << endl;
}

void printQuitScreen(){
    cout << "\033[2J\033[1;1H";
    cout << "Quit" << endl;
}


int main() {
    //cout << "Hello World!" << endl;
    
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), CP_UTF8);
    cout << fixed << setprecision(2);
    srand(time(0));
    int introSelect = 1;
    printIntroScreen(introSelect);
    int input = getch();
    while(input != 13) {
        if(input == 87 || input == 119) { // W/w
            introSelect = (introSelect+1+3)%3+1;
            printIntroScreen(introSelect);
        } else if(input == 83 || input == 115) { // S/s
            introSelect = (introSelect)%3+1;
            printIntroScreen(introSelect);
        }
        input = getch();
    }
    if(introSelect == 1) printGameScreen();
    else if(introSelect == 2) printAchievementsScreen();
    else if(introSelect == 3) printQuitScreen();    

    return 0;
}