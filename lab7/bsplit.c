#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h> 
#include <string.h>
#include "xsum.h" 

  

int main (int argc, char **argv){

  FILE *originalFile;
  char* fileName = argv[argc-1];
  int maxNumOfChildProcess;
  
  originalFile = fopen( fileName, "r"); /*opens the original file */

  optIdent(argc, argv);

  createNewFiles(fileName);
  fclose (originalFile);   
  return 0;
}  



void optIdent(int argc, char **argv,int maxSizeFromUser){
  char * sumOfOptions = "usage: bsplit [-b SIZE] [-h] [-x] [-p SIZE] FILE";
  unsigned int originalFileCksum = 0;
  int c;
  
  while ((c = getopt (argc, argv, "xhb:")) != -1){
	  switch (c)
	    {
	    case 'x': 
	      originalFileCksum = cksum(originalFile);
	      printf("%d\n", originalFileCksum );
	      
	      break;
	    
	    case 'h':
	    
	      printf("%s\n", sumOfOptions );
	      exit(0);
	      
	      break;
	      
	    case 'b':
	    
	      maxSizeFromUser = atoi(optarg);

	      
	      break;
	    
	    case 'p':
	      
	      maxNumOfChildProcess = atoi(optarg);
	      
	      break;
	      
	    default:
	      abort ();
	      }   
  }
}





//makom bekovez, godel hakovez, shemHakovaz, meeifoMaatika

void gets(int placeInFile,int sizeNewFile, string nameNewFile, FILE* original ){
  
  
}  


void createNewFiles(char* fileName){
  
  int numOfBytesRead=1;
  char numOfFileStr[50];
  int numOfFile=1;
  unsigned int currCksum = 0;
  FILE *fileToWrite;
  int maxSizeFromUser=1024;
  unsigned int arrayForNewFile [(1027)/4] ;
  int sizeOfOriginal;
 
  fseek(originalFile, 0 , SEEK_END);
  sizeOfOriginal= ftell(originalFile);
  fseek( originalFile,0 , SEEK_SET);
 
  int nchunks = (sizeOfOriginal + maxSizeFromUser-1)/maxSizeFromUser;
 
  while(numOfBytesRead){
    
    numOfBytesRead = fread(arrayForNewFile, 1, maxSizeFromUser, originalFile); /*reads maxSizeFromUser at most bytes- 1 byte each time and saves it in arrayForNewFile*/

    if(numOfBytesRead!=0){
    
      if(numOfFile<10){
	sprintf(numOfFileStr , "%s.0%d", fileName, numOfFile); /*adds the numOfFile into "FILE.0%d" and saves the resulting string in numOfFileStr */
      
      }else{
	sprintf(numOfFileStr , "%s.%d", fileName, numOfFile); /*adds the numOfFile into "FILE.%d" and saves the resulting string in numOfFileStr */
    
      } 
      /* printf ("Characters: %c %d \n", 'a', 65);*/
      
      fileToWrite = fopen( numOfFileStr, "w+"); /*creates a new file to write&read to, called numOfFileStr*/
      
      fwrite ( &currCksum, sizeof(currCksum), 1, fileToWrite);/*write 4 bytes of "0" into the beggining of the new file*/
    
      fwrite ( arrayForNewFile, 1, numOfBytesRead, fileToWrite); /*write into the new file all the chunk data from the arrayForNewFile*/
      
      fseek( fileToWrite, sizeof(currCksum) , SEEK_SET ); /*Sets the position indicator associated with the stream to a new position- 4 bytes after the beggining of the file */
      
      currCksum = cksum(fileToWrite); /*calculates the cksum of the new file */
      
      rewind ( fileToWrite ); /* Set position of stream to the beginning */
      
      fwrite ( &currCksum, sizeof(currCksum), 1, fileToWrite); /*write the currCksum in the beggining of the fileToWrite- override the "0" that was there */
      
      currCksum = 0; 
    
      ++numOfFile;
      
      fclose(fileToWrite);
    }
  }
}
