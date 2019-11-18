#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LENGTH 512 // Maximum allowed length of one line (question + answer)
#include "read.h"
#include "write.h"
 /* Status på moduler:
 * Submodul 1 - Skrevet ind (Bjørn)
 * Submodul 2 - Skrevet ind (Bjørn + Aagaard)
 * Submodul 3 - Slået sammen med 2 (Bjørn + Aagaard)
 * Submodul 4 - Skrevet ind (Møller)
 * Submodul 5 - Skrevet ind (Færdigt)(Bjørn + Schneider + Møller)
 * Submodul 6 - Skrevet ind (Møller)
 * Submodul 7 - Skrevet ind (Bjørn)
 * Submodul 8 - Skrevet ind (Mik)
 * Submodul 9 - Ikke skrevet ind (Møller)
 * Submodul 10 - Skrevet ind + Asgers greatest (Mik + Møller)
 * Submodul 11 - Asgers greatest tastet ind (Møller)
 * Submodul 12 - Skrevet ind (Bjørn)
 * Submodul 13 - Skrevet ind + Asgers greatest (Mik + Møller)
 * Submodul 14 - Skrevet ind (Møller)
 * Submodul 15 - Skrevet ind (Møller)
 * Submodul 16 - Skrevet ind (Mads Johansen)
 * Submodul 17 - Ikke skrevet ind
 * Submodul 18 - Skrevet ind, ej rettet (Møller)
 * Submodul 19 - Skrevet ind, ej rettet(Møller)
 * Submodul 20 - Skrevet ind, ej rettet (Møller)
 * Submodul 21 - Skrevet ind, ej rettet (Møller)
 * Modul 15 - Skrevet ind(Kjersgaard + Møller)
 *       Fjernet fra alle spørgsmål
 * Status updates:
 * - Tag spørgsmål i ikke tilfældig rækkefølge - Implemented!
 * - Rigtigt svar vises hvis der svares forkort - Implemented!
 * - Der vises hvor mange spørgsmål bruger har besvaret, hvis de ikke er i tilfældig rækkefølge - Implemented!
 * - Der kan startes fra et brugerspecificeret spørgsmål - Implemented!
 * - Lad alle redigere error filen - Not implemented
 * - Generate allQuestions.txt from other files - Not implemented
 * - Clean up code - Running process
 */

void mainGame(char* user, int gameMode);

int main(){
    // Variable init
    char name[MAX_LENGTH];
    int gameMode = -1;
    int input;
    
    // Get user
    //printf("Hvad er dit brugernavn?\n");
    //fgets(name, MAX_LENGTH, stdin);
    //printf("\n\n"); // Sweep for next

    while(1){
        // Main menu
        printf("Vælg en handling:\n");
        printf("Læs op med svarmuligheder(1)\n");
        printf("Læs op uden svarmuligheder(2)\n");
        //printf("High score(3)\n");
        printf("Sluk programmet(9)\n");

        // Get input
        scanf("%d", &input);

        // Process input
        if(input == 1){ // Med svarmuligheder
            // Hvordan skal der spiller?
            printf("\nVælg game mode:\n");
            printf("Alle spørgsmål(1)\n");
            printf("Tidligere fejl(2)\n");
            scanf("%d", &input);
            printf("\n\n"); // Sweep for next

            if(input == 1){ // Alle spørgsmål
                mainGame(name, 1);
            } else if (input == 2){ // Tideligere fejl
                mainGame(name, 2);
            } else {
                printf("Ugyldgigt input."); // Ugyldigt input
                printf("\n\n"); // Sweep for next
            }
        } else if(input == 2){ // Uden svarmuligheder
            // Hvordan skal der spiller?
            printf("\nVælg game mode:\n");
            printf("Alle spørgsmål(1)\n");
            printf("Tideligere fejl(2)\n");
            scanf("%d", &input);
            printf("\n\n"); // Sweep for next

            if(input == 1){ // Alle spørgsmål
                mainGame(name, 3);
            } else if (input == 2){ // Tideligere fejl
                mainGame(name, 4);
            } else {
                printf("Ugyldgigt input."); // Ugyldigt input
                printf("\n\n"); // Sweep for next
            }
        } else if(input == 3){ // High score
            printf("Endnu ikke implementeret!\n");
        } else if(input == 9){ // Sluk
            break;
        } else{
            printf("Forkert input.\n\n");
        }
    }

    return 0;
}

/*
 * Runs the choosen game
 * gameMode = 1:    all questions with options
 * gameMode = 2:    previous errors with options
 * gameMode = 3:    all questions without options
 * gameMode = 4:    previous errors without options
 */
void mainGame(char* user, int gameMode){
    // File paths and pointer
    char* allQuestions="/home/runner/assets/allQuestions.txt";
    char* errorQuestions="/home/runner/assets/errorQuestions.txt";
    char* submodul1="/home/runner/assets/submodul1.txt";
    char* submodul2="/home/runner/assets/submodul2.txt";
    char* submodul3="/home/runner/assets/submodul3.txt";
    char* submodul4="/home/runner/assets/submodul4.txt";
    char* submodul5="/home/runner/assets/submodul5.txt";
    char* submodul6="/home/runner/assets/submodul6.txt";
    char* submodul7="/home/runner/assets/submodul7.txt";
    char* submodul8="/home/runner/assets/submodul8.txt";
    char* submodul9="/home/runner/assets/submodul9.txt";
    char* submodul10="/home/runner/assets/submodul10.txt";
    char* submodul11="/home/runner/assets/submodul11.txt";
    char* submodul12="/home/runner/assets/submodul12.txt";
    char* submodul13="/home/runner/assets/submodul13.txt";
    char* submodul14="/home/runner/assets/submodul14.txt";
    char* submodul15="/home/runner/assets/submodul15.txt";
    char* submodul16="/home/runner/assets/submodul16.txt";
    char* submodul17="/home/runner/assets/submodul17.txt";
    char* submodul18="/home/runner/assets/submodul18.txt";
    char* submodul19="/home/runner/assets/submodul19.txt";
    char* submodul20="/home/runner/assets/submodul20.txt";
    char* submodul21="/home/runner/assets/submodul21.txt";
    char* modul15="/home/runner/assets/modul15.txt";
    char* qp;                                   // Question pointer. Points to path of choosen file
    int numLines = -1;                          // Holds number of lines in choosen file
    int random = -1;                            // Token for getting questions in random order
    int lineNum = 1;                            // Used to itterate through questions in order
    int totalNumLines = initFile(allQuestions); // Used to generate answers. Holds total number of questions
    int token = 0;                              // For random location of right answers
    int input = -1;                             // For users inputs
    struct line QandA;                          // Holds question and correct answer
    struct line wrong;                          // Allocated for wrong answer options

    // Open file containing right questions
    if(gameMode == 1 || gameMode == 3){
        // Present option to train specific submodule
        printf("Hvilket modul/submodul vil du træne?\n");
        printf("(0) Alle\n");
        printf("(1) Aerodynamik\n");
        printf("(2) Flystruktur\n");
        printf("(3) ?Rorflader\n");
        printf("(4) Air conditioning\n");
        printf("(5) Instrumenter og avionic\n");
        printf("(6) Elektriske energisystemer\n");
        printf("(7) Equipment and furnishing\n");
        printf("(8) Fire protection\n");
        printf("(9) Flight controls\n");
        printf("(10) Fuel systems\n");
        printf("(11) Hydraulik\n");
        printf("(12) Ice and rain protection\n");
        printf("(13) Landing gear\n");
        printf("(14) Lights\n");
        printf("(15) Oxygen\n");
        printf("(16) Pneumatic og vacuum\n");
        printf("(17) Water/waste\n");
        printf("(18) On board maintenance\n");
        printf("(19) Integral modular avionics\n");
        printf("(20) Cabin systems\n");
        printf("(21) Information systems\n");
        printf("(22) Modul 15 - Motor\n");
        scanf("%d", &input);
        if(input == 0){
            qp = allQuestions;
        }else if(input == 1){
            qp = submodul1;
        }else if(input == 2){
            qp = submodul2;
        }else if(input == 3){
            qp = submodul2; // Submodule 3 og 2 slås sammen
            printf("Slået sammen med submodul 2.\n");
        }else if(input == 4){
            qp = submodul4;
        }else if(input == 5){
            qp = submodul5;
        }else if(input == 6){
            qp = submodul6;
        }else if(input == 7){
            qp = submodul7;
        }else if(input == 8){
            qp = submodul8;
        }else if(input == 9){
            qp = submodul9;
        }else if(input == 10){
            qp = submodul10;
        }else if(input == 11){
            qp = submodul11;
        }else if(input == 12){
            qp = submodul12;
        }else if(input == 13){
            qp = submodul13;
        }else if(input == 14){
            qp = submodul14;
        }else if(input == 15){
            qp = submodul15;
        }else if(input == 16){
            qp = submodul16;
        }else if(input == 17){
            qp = submodul17;
        }else if(input == 18){
            qp = submodul18;
        }else if(input == 19){
            qp = submodul19;
        }else if(input == 20){
            qp = submodul20;
        }else if(input == 21){
            qp = submodul21;
        }else if(input == 22){
            qp = modul15;
        } else{
            printf("Forkert input\n\n\n");
            return;
        }
    } else{
        qp = errorQuestions;
    }
    input = -1; // Reset input

    // Check for enough questions and answers, and if file exsists:
    numLines = initFile(qp);
    if(numLines == -1){ // File wasn't found
        printf("\n");
        return;
    }else if(numLines < 3){
        printf("Du har ikke nok spørgsmål. Beklager!!\n\n");
        return;
    }

       // Ask if user wants to run questions in random order:
    printf("Ønsker du spørgsmål i tilfældig rækkefølge?\n"); 
    printf("(1) Ja\n");
    printf("(2) Nej\n");
    scanf("%d", &input);
    if(input == 1){
        random = 1;
    } else if(input == 2){
        random = 0;

        // Give option to start from specific question index
        input = -1; // Reset input
        printf("\nVil du starte fra et specifikt spørgsmål?\n");
        printf("(1) Ja\n");
        printf("(2) Nej\n");
        scanf("%d", &input);
        if(input == 1){
            printf("Intast spørgsmålsnummer:\n");
            scanf("%d", &lineNum);
        } else if(input != 2){
            printf("Forkert input.\n");
            input = -1;
            return;
        }
    } else{
        printf("Forkert input.\n");
        input = -1;
        return;
    }
    input = -1; // Reset input

    // Run game if enough errors
    while(1){
        token = randomNum(1,3);
        if(random == 1){ // Get random question
            QandA = chooseLine(qp, numLines, -1); // Get question and answer
        } else{ // Get questions in order
            if(lineNum < numLines){
                printf("Du er på spørgsmål %d/%d\n", lineNum, numLines);
                QandA = chooseLine(qp, numLines, lineNum); // Get question and answer
                lineNum++;
            } else{
                // Valgt (sub)modul gennemført
                printf("Du har nået sidste spørgsmål i det valgte modul/submodul! Godt arbejde!!!\n\n\n");
                lineNum = 1;
                return;
            }
        }

        // Post question
        printf("%s\n", QandA.question);
        // Post answer options
        if(gameMode > 2){ // Check if gameMode is with or without options
            printf("Indtast et tal for at fortsætte.\n");
            scanf("%d", &input);
            input = -1; // Reset input variable
        }
        for(int i = 1; i <= 3; i++){
            if(i == token){ // Puts correct answer at space indicated by token
                printf("(%d)%s\n", token, QandA.answer);
            } else {
                while(1){ // Finds two random answers, that are not the same as the correct answer
                    // Mikes method
                    // If less than 25 Q's in file. Get options from all questions
                    if(numLines < 25){
                        wrong = chooseLine(allQuestions, totalNumLines, -1); // -1 = choosen at random
                    }else{
                        wrong = chooseLine(qp, numLines, -1); // -1 = choosen at random
                    }

                    if(strcmp(wrong.answer, QandA.answer) != 0){
                        break ;
                    }
                }
                printf("(%d)%s\n", i, wrong.answer);
            }
        }
        printf("---------------------------------\n");
        printf("(4) Tilbage til hovedmenu.\n\n");

        scanf("%d", &input);

        // Determine if correct answer was given:
        if(input == token){
            printf("Rigtigt!\n\n\n");
        } else if(input == 4){
            printf("(4) Hovedmenu.\n\n\n");
            break;
        } else{
            printf("Forkert!\n");

            // Print correct answer
            printf("Det rigtige svar var: %s\n\n\n", QandA.answer);

            // Add wrong question to log
            if(gameMode == 1 || gameMode == 3){
                addError(errorQuestions, QandA);
            }
        }
        input = -1; // Reset input variable
    }

    numLines = 1; // Reset line number
    return;
}