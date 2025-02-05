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

int input;


string redText = "\033[0;31m";
string greenText = "\033[0;32m";
string yellowText = "\033[0;33m";
string blueText = "\033[0;34m";
string whiteText = "\033[0m";

vector<string> deck = {};

vector<string> pHiddenCard = {};
vector<string> bHiddenCard = {};

vector<string> pDeckCard = {};
vector<string> bDeckCard = {};

vector<string> pHandCard = {};
vector<string> bHandCard = {};

int pCritNumber, bCritNumber;


void printIntroScreen(int introSelect);

void printGameScreen();
void printAchievementsScreen();
void printQuitScreen();


void shuffle();

void printIntroScreen(int introSelect) {
    string top =                   "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    string empty =                 "┃                                                                    ┃\n";
    vector<string> intro =        {"┃                              Welcome!                              ┃\n",
                                   "┃                               Rules:                               ┃\n",
                                   "┃    Use number cards ("+yellowText+"yellow"+whiteText+") to create combos against the enemy    ┃\n",
                                   "┃         Use face cards ("+blueText+"blue"+whiteText+") to reduce the enemy's damage         ┃\n",
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

void shuffle() {
    for(int i = 0; i < deck.size(); i++) {
        int j = i + rand()%(deck.size()-i);
        swap(deck[i], deck[j]);
    }
}

int main() {
    //cout << "Hello World!" << endl;
    
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), CP_UTF8);
    cout << fixed << setprecision(2);
    srand(time(0));


    int introSelect = 1;
    printIntroScreen(introSelect);
    input = getch();
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
    if(introSelect == 1) {
        printGameScreen();
    } else if(introSelect == 2) {
        printAchievementsScreen();
    } else if(introSelect == 3) {
        printQuitScreen();
    }

    vector<string> cards = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    for(int i = 0; i < 13; i++) for(int j = 0; j < 4; j++) deck.push_back(cards[i]);
    shuffle();
    for(string s : deck) cout << s << " ";
    cout << endl;
    for(int i = 0; i < 5; i++) {
        pHiddenCard.push_back(deck.back());  deck.pop_back();
        bHiddenCard.push_back(deck.back());  deck.pop_back();
    }
    for(int i = 0; i < 5; i++) {
        pDeckCard.push_back(deck.back());  deck.pop_back();
        bDeckCard.push_back(deck.back());  deck.pop_back();
    }
    for(int i = 0; i < 5; i++) {
        pHandCard.push_back(deck.back());  deck.pop_back();
        bHandCard.push_back(deck.back());  deck.pop_back();
    }
    
    cout << "Player's hidden hand: ";
    for(string s: pHiddenCard) cout << s << " ";
    cout << endl;

    cout << "Bot's hidden hand: ";
    for(string s: bHiddenCard) cout << s << " ";
    cout << endl;

    cout << "Player's shown hand: ";
    for(string s: pDeckCard) cout << s << " ";
    cout << endl;
    
    cout << "Bot's shown hand: ";
    for(string s: bDeckCard) cout << s << " ";
    cout << endl;
    

    cout << "Player's hand: ";
    for(string s: pHandCard) cout << s << " ";
    cout << endl;

    cout << "Bot's hand: ";
    for(string s: bHandCard) cout << s << " ";
    cout << endl;

    pCritNumber = rand()%9+1, bCritNumber = rand()%9+1;

    cout << "Player's crit number: " << pCritNumber << endl;
    cout << "Bot's crit number: " << bCritNumber << endl;
    for(string s : deck) cout << s << " ";
    cout << endl << endl;

    //Initally, player can switch between shown hand and hand
    
    cout << "Choose cards you want to switch between hand cards and deck cards." << endl;
    cout << "1. Select a hand card using [1-5]." << endl;                                      // [1] = 49, [5] = 53
    cout << "2. Select a deck card using [1-5]." << endl;
    cout << "3. Hit [Enter] to confirm switch, or hit [Esc] to cancel switch." << endl;                 // [Enter] = 13, [Esc] = 27
    cout << "4. To stop switching, confirm/cancel current operation, then hit [C] to move on." << endl; // [c] = 99, [C] = 67
    
    cout << "Hand: ";
    for(int i = 0; i < 5; i++) cout << pHandCard[i] << " ";
    cout << endl;
    cout << "Deck: ";
    for(int i = 0; i < 5; i++) cout << pDeckCard[i] << " ";
    cout << endl;

    input = getch();
    int op = 1;
    int handPos = -1;
    int deckPos = -1;
    int successfulSwitchHandPos = -1;
    int successfulSwitchDeckPos = -1;
    bool successfulSwitch = false;
    bool moveSuccess = false;
    while(input != 99 && input != 67) {
        if(op == 1) {
            if(input >= 49 && input <= 53) {    //input selecting between 1 and 5, inclusive [49]-[53]
                handPos = input-49;
                op = 2;
                moveSuccess = true;
            }
        } else if(op == 2) {
            if(input >= 49 && input <= 53) {    //input selecting between 1 and 5, inclusive [49]-[53]
                deckPos = input-49;
                op = 3;
                moveSuccess = true;
            }
        } else if(op == 3) {
            if(input == 13) {
                string temp = pHandCard[handPos];
                pHandCard[handPos] = pDeckCard[deckPos];
                pDeckCard[deckPos] = temp;
                successfulSwitchHandPos = handPos;
                successfulSwitchDeckPos = deckPos;
                handPos = -1;
                deckPos = -1;
                op = 1;
                moveSuccess = true;
                successfulSwitch = true;
            } else if(input == 27) {
                deckPos = -1;
                handPos = -1;
                op = 1;
                moveSuccess = true;
            }
        }
        
        if(moveSuccess) {
            cout << "\033[2J\033[1;1H";
            if(op-1 == 1) {
                cout << "Selected hand card #" << (handPos+1) << endl;
            } else if(op-1 == 2) {
                cout << "Selected Deck card #" << (deckPos+1) << endl;
            } else if(op+2 == 3) {
                if(input == 13) {
                    cout << "Switch successful." << endl;
                } else {
                    cout << "Cancelled switch." << endl;
                }
            }
            cout << "Hand: ";
            for(int i = 0; i < 5; i++) cout << ((successfulSwitch&&successfulSwitchHandPos==i)?blueText:((handPos==i)?redText:"")) << pHandCard[i] << whiteText << " ";
            cout << endl;
            cout << "Deck: ";
            for(int i = 0; i < 5; i++) cout << ((successfulSwitch&&successfulSwitchDeckPos==i)?blueText:((deckPos==i)?redText:"")) << pDeckCard[i] << whiteText << " ";
            cout << endl;
            successfulSwitchHandPos = -1;
            successfulSwitchDeckPos = -1;
            successfulSwitch = false;
            moveSuccess = false;
        }

        input = getch();
    }
    cout << "Switching fi"
    cout << input;

    return 0;
}