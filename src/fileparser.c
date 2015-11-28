#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
#include <pebble.h>

card* parse (char* filename)
{
  
  card *cardfilled;          //struct with an array for words and an array for their definitions
  
  FILE * fp;                 //used for reading the file
  char * line = NULL;        //current line that is read from the file
  size_t len = 0;
  ssize_t read;
  
  int linelength;            //number of characters in the line
  
  //opens the file
  fp = fopen(filename, "r");
  
  //empty file or non-existent
  if(fp == NULL)
    exit(EXIT_FAILURE);
  
  //loop to read each line of the file
  while((read = getline(&line, &len, fp)) != -1){
    
    
    //line is the variable 'read'
    if
    
  }
  
  //close the file
  fclose(fp);
  
  //memory leak
  if(line)
    free(line);
  
  //return pointer to the struct with the words and their definitions
  return *cardfilled;
}
*/

int main()
{
  
  FILE *fp;                 //used for reading the file
  char *line = NULL;        //current line that is read from the file
  int linelength;           //number of characters in the line
  
  char *word = "";
  char *definition = "";
  bool wdone = false;       //end of word reached (\t)
  bool ddone = false;       //end of definition reached (\n)
  
  int count = 0;
  
  printf("Hi");
  char* file = "example.c";
  
  
  
  //opens the file
  fp = fopen(file, "r");
  
  //empty file or non-existent
  if(fp == NULL)
    exit(EXIT_FAILURE);
  
  
  
  //loop that reads the next line, up to 1000 characters
  while(fgets(line, 1000, fp) != NULL)
  {
    
    count = 0;
    char next;
    char *temp;
    
    linelength = strlen(line);
    
    
    
    //loop to read each character and add to the string for word until it reaches "\t"
    while((count <= linelength) && (wdone == false))
    {
      
      //set the next character from the line
      next = line[count+1];
      
      //check if the next character is "\t"
      if (next == '\t')
        wdone = true;
      //if not, adds the current character to the end of the string
      else
      {
        *temp = line[count];
        strcat(word, temp);
        count ++;  //move onto the next letter
      }
      
      count++;
    }
    
    
    //loop to read each character and add to the string for the definition until it reaches "\t"
    while((count <= linelength) && (ddone == false))
    {
      
      //set the next character from the line
      next = line[count+1];
      
      //check if the next character is "\n"
      if (next == '\n')
        ddone = true;
      //if not, adds the current character to the end of the string
      else
      {
        *temp = line[count];
        strcat(definition, temp);
        count ++;  //move onto the next letter
      }
      
      count++;
    }
    
    
    //**************************
    //TO DO:put the word string into the struct
    //TO DO:put the definition string into the struct
    
    //DEBUG
    printf("%s\n", word);
    printf("%s\n", definition);
    
    //reset for the next line in the file
    wdone = false;
    ddone = false;
    count = 0;
  }
  
  
  //close the file
  fclose(fp);
  
  //memory leak
  if(line)
    free(line);
  
  
}