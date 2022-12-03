/*

  Word Count using dedicated lists,
  modified for Kinneret College on the Sea of Galile

*/

/*
Copyright © 2019 University of California, Berkeley

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <assert.h>
#include <getopt.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "word_count.h"
/* Global data structure tracking the words encountered */
int num_words(FILE* infile);
WordCount *word_counts = NULL;
int num_words2 = 0;

/* The maximum length of each word in a file */
#define MAX_WORD_LEN 64


/////////////////////////////////////////////
/*
 * Total Word Count
 *
 * Returns the total amount of words found in infile.
 * Useful functions: fgetc(), isalpha().
 */  
 int num_words(FILE* infile) {
  int num_words=0;
  char cha;
  
  bool whitespace=true;
  //printf("h%c\n",cha2);

  
  while ((cha = fgetc(infile)) !=EOF) { 
 
  if (whitespace&&!isspace(cha)) {
  num_words++;
  whitespace=false;
  }
  else if(!whitespace&&isspace(cha)){
    whitespace=true;
  }
  }
  fclose(infile);

  printf("%d",num_words);
  return num_words;
}
/////////////////////////////////////////////////
/*
 * Word Frequency Count
 *
 * Given infile, extracts and adds each word in the FILE to `wclist`.
 * Useful functions: fgetc(), isalpha(), tolower(), add_word().
 */
void count_words(WordCount **wclist, FILE *infile) {
}

/*
 * Comparator to sort list by frequency.
 * Useful function: strcmp().
 */
static bool wordcount_less(const WordCount *wc1, const WordCount *wc2) {
  return 0;
}

/*
 * Comparator to reverse sort list by frequency.
 * Useful function: strcmp().
 */
static bool wordcount_more(const WordCount *wc1, const WordCount *wc2) {
  return 0;
}


// In trying times, displays a helpful message.
static int display_help(void) {
	printf("Flags:\n"
	    "-c: Count the total amount of words in the file, or STDIN if a file is not specified.\n"
	    "-f: Count the frequency of each word in the file, or STDIN if a file is not specified.  Display words sorted by count (ascending), then alphabetically (A->Z)\n"
		  "-r: Count the frequency of each word in the file, or STDIN if a file is not specified.  Display words sorted by count (descending), then reverse alphabetically (Z->A)\n"
	    "-h: Displays this help message.\n");
	return 0;
}

/*
 * Handle command line flags and arguments.
 */
  //////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////

  // Count Mode (default): outputs the total amount of words counted
  bool count_mode = true;
  int total_words = 0;

  // Freq Mode: outputs the frequency of each word
  bool freq_mode = false;
  bool reverse_mode = false;

int main (int argc, char *argv[]) {


  FILE *infile;
  char *str[50];
  int totalWordCount=0;
  for (int i=2; i<argc; i++) {
    str[i]=argv[i];
  }
  for (int j=2; j<argc; j++) {
  char name[100]="/home/tamir/vsCode/HW/Micheal/HW2/assignment1-sleman-and-tamir/tests/";
  char totalname[200];
  strcpy(totalname,strcat(name, str[j]));
  infile = fopen(name, "r");
  if (!infile) {
        for (int i=1; i<argc; i++) {
      total_words++;
      printf("\n%s\n",argv[i]);
    }
    printf("Hello");
    //printf("\n%d\n",num_words2);

    exit(0);
  }  

    totalWordCount=num_words(infile);
  }
    printf("\nyou have %d words.\n",totalWordCount);
  /*
  char name[100]="/home/tamir/vsCode/HW/Micheal/HW2/assignment1-sleman-and-tamir/tests/";
  char totalname[200];
  strcpy(totalname,strcat(name, "words2.txt"));
  infile = fopen(name, "r");
  if (!infile) {
    exit(0);
  }
  */

  
    


  // Variables for command line argument parsing
  int i;
  static struct option long_options[] =
  {
      {"count", 1, 0, 'c'},
      {"frequency", no_argument, 0, 'f'},
	    {"reverse", no_argument, 0, 'r'},
      {"help", no_argument, 0, 'h'},
      {0, 0, 0, 0}
  };

  // Sets flags
  while ((i = getopt_long(argc, argv, "cfrh", long_options, NULL)) != -1) {
      switch (i) {
          case 'c':
              count_mode = true;
              freq_mode = false;
     		  reverse_mode = false;
              break;
          case 'f':
              	count_mode = false;
              	freq_mode = true;
		reverse_mode = false;
              	break;
	  case 'r':
		count_mode = false;
		freq_mode = false;
		reverse_mode = true;
		break;
          case 'h':
              	return display_help();
		break;
      }
  }

  if (!count_mode && !freq_mode && !reverse_mode) {
    printf("Please specify a mode.\n");
    return display_help();
  }

  /* Create the empty data structure */
  init_words(&word_counts);

  if ((argc - optind) < 1) {
    // No input file specified, instead, read from STDIN instead.
    infile = stdin;
  } else {
    // At least one file specified. Useful functions: fopen(), fclose().
    // The first file can be found at argv[optind]. The last file can be
    // found at argv[argc-1].
  }

  if (count_mode) {
    	printf("The total number of words is: %i\n", total_words);
  }  else if (freq_mode) {
    	wordcount_sort(&word_counts, wordcount_less);
    	printf("The frequencies of each word are: \n");
    	fprint_words(word_counts, stdout);
   }  else if (reverse_mode) {
	    wordcount_sort(&word_counts, wordcount_more);
	    printf("The reverse frequencies of each word are: \n");
	    fprint_words(word_counts, stdout);
	}
  return 0;
}
