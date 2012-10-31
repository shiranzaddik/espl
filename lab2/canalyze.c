  
  #include <stdio.h>
  #include <stdlib.h>
  #include "fgetname.h"
    
  int main(int argc, char **argv) {
	  FILE *ret;
	  int i, isEqual=0;
	  
	 
	  char tempWord[64];
	  char *saveWords[] = {"auto", "double", "int", "long", "break", "else", "long", "switch", "case", "enum", "register", "typedef" ,"char", "extern", 
	  "return", "union", "const", "float", "short", "unsigned", "continue",
	  "for","signed", "void", "default", "goto", "sizeof" ,"volatile",
	  "do",	"if" ,"static" ,"while"};
	  
	  ret = fopen( argv[1], "r"); /*ret is a pointer to the file*/
	  
	  while( fgetname(tempWord, 64, ret)){
	    isEqual = 0; 
	    for(i=0; i<32; ++i){
	     
	      
	      if(strcmp(tempWord, saveWords[i])!=0){
		isEqual = isEqual+1;
	      }
	      if(isEqual==32){  /*tempWord not equal to any of the key words*/
		printf("%s\n", tempWord);
	      }
	    }

	  }
	  
		  
	  


	 
	  fclose (ret);

	  return 0;
    }
