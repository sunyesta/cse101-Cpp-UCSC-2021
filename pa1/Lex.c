#include"List.h"

#include <errno.h> //used for checking if files are valid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 300

int main(int argc, char **argv){

  //--------------------- open files --------------------- 
  FILE *infile, *outfile;

  //check command line for correct number of arguments
  if(argc != 3){
    printf("Usage: %s <input file> <output file>\n", argv[0]);
    exit(1);
  }

  //open files for reading and writing
  infile = fopen(argv[1], "r");
  if (infile == NULL || errno == EINVAL) {
    printf("Unable to open file %s for reading\n", argv[1]);
    exit(1);
  }

  outfile = fopen(argv[2], "w");
  if (infile == NULL || errno == EINVAL) {
    printf("Unable to open file %s for writing\n", argv[2]);
    fclose(infile);
    exit(1);
  }


  //--------------------- read files --------------------- 

  // count the lines in the file
  int lineCount = 0;
  char linebuf[MAX_LEN];
  while( fgets(linebuf, MAX_LEN, infile) != NULL)  {
    lineCount+=1;
  }
  
  //fill a string array with a line in each index
  rewind(infile);
  char lines[lineCount][MAX_LEN];
  for(int curLine = 0; fgets(lines[curLine], MAX_LEN, infile) != NULL; curLine++){}
  fclose(infile);

  //--------------------- make list of ordered indicies --------------------- 
  
  List orderedIndexes = newList();
  
  //order the indexes of the line array in alphebetical order 
  //by storing them in the correct order in a list
  prepend(orderedIndexes, 0);
  
  //itterate through all the lines
  for(int i=1; i<lineCount; i++){
    char *curWord = lines[i];

    //place curWord's index in correct spot in list
    moveBack(orderedIndexes);
    while(true){
      char *cmpWord = lines[get(orderedIndexes)];
      
      //insert the curWord at the first spot where it is behind something less than it
      if(strcmp(curWord, cmpWord)>0){
        insertAfter(orderedIndexes,i);
        break;
      }
      
      //insert the current word at the start if all words are greater than it
      if(index(orderedIndexes) == 0){
        prepend(orderedIndexes, i);
        break;
      }

      movePrev(orderedIndexes);
    }
    
    
  }

  //--------------------- print array in correct order --------------------- 
  
  //print the ordered array
  moveFront(orderedIndexes);
  for(int i=0; i<length(orderedIndexes); i++){
    int lineIndex = get(orderedIndexes);
    fprintf(outfile, "%s",lines[lineIndex]);
    moveNext(orderedIndexes);
  }
  
  freeList(&orderedIndexes);
  fclose(outfile);
  
  return 0;
}
