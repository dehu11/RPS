#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    string move, moveShort, history, lastFour;
    string counter[3] = {"rock", "paper", "scissors"}, result[3] = {"We tied!", "I win!", "You win!"};
    int counterVal,  losses = 0, wins = 0, ties = 0, turn = 0;

    while (1) {
        cout << "rock, paper or scissors?" << endl;
        int moveVal = 0;

        while (moveVal == 0) {
            cin >> move;

            if (move == "rock") {
                moveShort = 'r';
                moveVal = 5;
            } else if (move == "paper") {
                moveShort = 'p';
                moveVal = 4;
            } else if (move == "scissors") {
                moveShort = 's';
                moveVal = 3;
            } else if (move == "stop") {
                return 0;
            } else
                cout << "Try again." << endl;
        }

        reverse(history.begin(), history.end());
        int i = 1, j = 0, r = 0, p = 0, s = 0;
        srand (time(NULL));

        if (turn < 5) {
                counterVal = rand() % 3 + 1;
        } else {
                lastFour = history.substr(0,4);
                while (i < turn && j < 4) {
                    if (history.find(lastFour.substr(0, 4 - j), i)){
                        if (history[history.find(lastFour.substr(0, 4 - j), i) - 1] == 'r')
                            r++;
                        else if (history[history.find(lastFour.substr(0, 4 - j), i) - 1] == 'p')
                            p++;
                        else if (history[history.find(lastFour.substr(0, 4 - j), i) - 1] == 's')
                            s++;
                        i = history.find(lastFour.substr(0, 4 - j), i) + 1;
                    } else if ((r + p + s) == 0)
                        j++;
					else
						break;
                }

                if (r > p) {
                    if (r > s)
                        counterVal = 2;
                    else
                        counterVal = 1;
                } else if (p > s)
                    counterVal = 3;
                else if ((r + p + s) == 0)
                    counterVal = rand() % 3 + 1;
                else
                    counterVal = 1;
        }

        cout << "\nYou chose " << move << ", I chose " << counter[counterVal - 1] << ". " << result[(moveVal + counterVal)%3] << endl;

        switch ((moveVal + counterVal)%3) {
            case 0 :
                ties++;
                break;
            case 1 :
                wins++;
                break;
            case 2 :
                losses++;
                break;
        }

        cout << "Score: You: " << losses << " Ties: " << ties << " Me: " << wins << endl << endl;

        reverse(history.begin(), history.end());
        history += moveShort;
        turn++;
    }

    return 0;
}