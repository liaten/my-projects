#include <stdio.h>
#include <string.h>
#include <iostream>

// The value BUFFERSIZE can be changed to customer's taste . Changes the
// size of the base array (string buffer )    
#define BUFFERSIZE 1000

int main(void)
{
    int f;//variable to take number
    int count=0;
    char save;
    char buffer[BUFFERSIZE];
    char cChar;
    printf("Enter a message (You can stop program from working by pressing \"Enter\" button): \n");
    while(*(fgets(buffer, BUFFERSIZE, stdin)) != '\n')
    {
        // For concatenation
        // fgets reads and adds '\n' in the string , replace '\n' by '\0' to 
        // remove the line break .
/*      if(buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0'; */
printf("%s", buffer);
        // Corrects the error mentioned by Alain BECKER.       
        // Checks if the string buffer is full to check and prevent the 
        // next character read by fgets is '\n' .
        if(strlen(buffer) == (BUFFERSIZE - 1) && (buffer[strlen(buffer) - 1] != '\n'))
        {
            // Prevents end of the line '\n' to be read in the first 
            // character (Loop Exit) in the next loop. Reads
            // the next char in stdin buffer , if '\n' is read and removed, if
            // different is returned to stdin 
            cChar = fgetc(stdin);
            if(cChar != '\n')
                ungetc(cChar, stdin);
            // To print correctly if '\n' is removed.
            else
                printf("\n");
        }
        //here my code continues
        std::cin >> f;
    for(int i=0;i<strlen(buffer);i++){
        if(buffer[i]>='0' && buffer[i]<='9' && count!=f)count++;
    }
    }
    return 0;
}