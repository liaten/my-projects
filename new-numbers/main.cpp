#include <stdio.h>
#include <string.h>
#include <iostream>
#define BUFFERSIZE 1000
using namespace std;

int main(void)
{
    int f;//variable to take number
    int count=0;
    char save;
    char buffer[BUFFERSIZE];
    char cChar;
    metka1:
    printf("Enter a message (You can stop program from working by pressing \"Enter\" button): \n");
    while(*(fgets(buffer, BUFFERSIZE, stdin)) != '\n')
    {
        cout<<buffer;
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
                cout<<endl;
        }
        //here my code continues
        cout<<"Enter value to search a number: ";
        cin >> f;
    for(int i=0;i<strlen(buffer);i++){
        if(buffer[i]>='0' && buffer[i]<='9' && count!=f)count++;
        if(count==f){
            save=buffer[i];
            break;
        }
    }
    if(count!=0)cout<<endl<<save;
    else    {   cout<<"You entered wrong number to search or there is no number in string!\nGoing back...\n";
                free(buffer);
                goto metka1;
            }
    }
    return 0;
}