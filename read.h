/*
 * Struct type to hold a line containing a question and an answer
 */
struct line {   // Struct to return and send question and answer
    char question[MAX_LENGTH/2];
    char answer[MAX_LENGTH/2];
};

/*
 * Returns random number between two bounds
 */
int randomNum(int lower, int upper){
    int num;

    return num = (rand() % (upper - lower + 1)) + lower;
}

/*
 * File initializer
 * Returns total number of lines
 */
int initFile(char* filename){ 
    // Variable init
    int totalLines = 0;
    FILE *fp;
    char current[MAX_LENGTH];
    // Initializes random generator
    srand(time(0)); 

    // Open file, and check if path is correct
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Kunne ikke åbne fil på sti \"%s\"\n", filename);
        return totalLines = -1;
    }

    // Opens and reads file, line by line
    while(fgets(current, MAX_LENGTH ,fp) != NULL){  // Line by line
        for(int i = 0; current[i] != EOF; i++){     // Char by char
            if(current[i] == '\n'){
                totalLines++;
                break;
            }
        }
    }
    fclose(fp);

    // Return number of lines 
    return totalLines;    
}

/*
 * Returns struct containing one question and one answe
 */
struct line chooseLine(char* filename, int totalLines, int lineNum) {
    // Variable init
    struct line QandA; 
    char current[MAX_LENGTH];
    int lineIndex = 0;
    int lineCounter = 0;
    FILE *fp;

    // Open file, and check if path is correct (should never happen, since this is checked in init)
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Kunne ikke åbne fil på sti \"%s\"\n", filename);
    }

    // See if line whould be found at random
    if(lineNum == -1){
        lineIndex = randomNum(1, totalLines);
    } else{
        lineIndex = lineNum;
    }

    // Opens and reads file, line by line
    short int stop = 0;
    while(fgets(current, MAX_LENGTH ,fp) != NULL){  // Line by line
        for(int i = 0; current[i] != EOF; i++){     // Char by char
            if(current[i] == '\n'){
                lineCounter++;
                if(lineCounter == lineIndex){
                    stop = 1; // Token to break while loop
                }
                break;
            }
        }

        // Break if correct line is found
        if(stop == 1)
            break;
    }
    fclose(fp);

    // Find and save question and answer
    short int a = 0;    // Tells if answer has been found
    int offset = 0;
    for(int i = 0; i < MAX_LENGTH; i++){
        if(a != 1){
            QandA.question[i] = current[i];
            if(current[i] == '?'){
                a = 1;                      // Flag to show question is done
                offset = i+1;               // Offset for index in answer
                QandA.question[i+1] = '\0'; // Set to show end of question
            }
        } else if(current[i] != '\n'){
            QandA.answer[i-offset] = current[i];
        } else{
            QandA.answer[i-offset] = '\0';
            break;
        }
    }

    return QandA;
}