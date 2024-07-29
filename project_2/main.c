#include <stdio.h>
#include <stdlib.h>
#include "shuffle.h"
#include "initial.h"
#include "showcard.h"
#include "playcard.h"
#include "defense.h"

int main() {
    printf("########################\n"
           "#                      #\n"
           "# Welcome to One Card! #\n"
           "#                      #\n"
           "########################\n\n"
           "---- Initial setup ----\n"
           "Number of rounds: 3\n"
           "Number of decks: 2\n"
           "Number of players: 3\n\n"
           "Please press enter to start the game.\n");
    system("read -p '...' var");
    system("clear");
    int poker[104];
    shuffle(poker);
    printf("shuffling result:\n");
    int player_1[104]={0};
    int player_2[104]={0};
    int player_3[104]={0};
    int player[104];
    for(int i=0;i<5;i++) {player_1[i]=poker[i];}
    for(int i=0;i<5;i++) {player_2[i]=poker[i+5];}
    for(int i=0;i<5;i++) {player_3[i]=poker[i+10];}
    int order=initial_order(poker[15],poker[16],poker[17]);
    printf("Please press enter to play!\n");
    system("read -p '...' var");
    system("clear");
    int last_card=poker[18];
    int top_card=19;
    int leftover[3]={5,5,5};
    int current_attack=0;
    int over=1;
    int reverse=-1;
    int temp[6]={0};
    int score[3]={0};
    int round=1;
    for (int r=0;r<3;r++) {
        while (over!=0) {
            switch (order % 3) {
                case 0:
                    for (int i = 0; i < leftover[0]; i++) { player[i] = player_1[i]; };
                    break;
                case 1:
                    for (int i = 0; i < leftover[1]; i++) { player[i] = player_2[i]; };
                    break;
                case 2:
                    for (int i = 0; i < leftover[2]; i++) { player[i] = player_3[i]; };
                    break;
            }
            if (current_attack == 0) {
                int k = show_card(order, last_card, leftover[(order % 3 + 3) % 3], current_attack, player);
                if (k == -1) {
                    player[leftover[(order % 3 + 3) % 3]] = poker[top_card];
                    leftover[(order % 3 + 3) % 3]++;
                    top_card++;
                } else {
                    playcard(current_attack, leftover[(order % 3 + 3) % 3], last_card, k, reverse, order, player, temp);
                    leftover[(order % 3 + 3) % 3] = temp[4];
                    current_attack = temp[0];
                    last_card = temp[1];
                    reverse = temp[2];
                    order = temp[3];
                }
            }
            else {
                defense(order, last_card, leftover[(order % 3 + 3) % 3], current_attack, reverse, top_card, player,
                        temp,
                        poker);
                leftover[(order % 3 + 3) % 3] = temp[2];
                order = temp[0];
                last_card = temp[1];
                current_attack = temp[3];
                reverse = temp[4];
                top_card = temp[5];
            }
            switch (order % 3) {
                case 0:
                    for (int i = 0; i < 104; i++) { player_1[i] = player[i]; };
                    break;
                case 1:
                    for (int i = 0; i < 104; i++) { player_2[i] = player[i]; };
                    break;
                case 2:
                    for (int i = 0; i < 104; i++) { player_3[i] = player[i]; };
                    break;
            }
            if (reverse == -1) { order++; }
            else { order--; }
            system("read -p '...' var");
            if (top_card == 104) { shuffle(poker); }
            if (leftover[0] * leftover[1] * leftover[2] == 0) { over = 0; }
            system("clear");
        }
        int winner;
        if (leftover[0] == 0) { winner = 1; }
        if (leftover[1] == 0) { winner = 2; }
        if (leftover[2] == 0) { winner = 3; }
        for (int i = 0; i < 3; i++) { score[i] = leftover[i]; }
        printf("Player %d win the round %d!\n\n", winner, round);
        printf("SCORE BOARD\n");
        for (int i = 0; i < 3; i++) { printf("player %d : %d"), i + 1, score[i]; }
        if (round<3) {system("read -p 'Press enter to start next round' var");}
        else {
            int final= score[0];
            if (score[1]<score[0]) {final=score[1];}
            if (score[2]<score[1]) {final=score[2];}
            printf("Congratulations!\n");
            if (score[0]==final) {printf("The final winner is player %d",1);}
            if (score[1]==final) {printf("The final winner is player %d",2);}
            if (score[2]==final) {printf("The final winner is player %d",3);}
        }
        round++;
    }
    return 0;
}
