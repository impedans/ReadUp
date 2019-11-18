/*
 * Adds error to list
 */
void addError(char* filename, struct line QandA){ 
    // Init variables
    FILE *fp;
    char current[MAX_LENGTH];

    // Open file, and check if path is correct
    fp = fopen(filename, "a");
    if(fp == NULL){
        printf("Kunne ikke åbne fil på sti \"%s\"\n", filename);
    }

    // Appends to file
    fputs(QandA.question, fp);
    fputs(QandA.answer, fp);
    fputs("\n", fp);

    // Close file
    fclose(fp);
}