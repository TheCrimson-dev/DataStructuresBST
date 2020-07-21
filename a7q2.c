/*--------------------------------------------------
Project: cp264-a7q2
File:    a7q2.c
Description: test driver program
Author:  HBF
Version: 2020-02-26
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "markstats.h"

int main(int argc, char* args[]) {
  char infilename[40] = "marks.txt";
  char outfilename[40] = "report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }

  // load mark data to MARKS data structure
  MARKS ds = {0};
  import_data(&ds, infilename);
  display_marks(&ds);

  // testing add data operation
  add_data(&ds, "Moore", 92.0);
  add_data(&ds, "Fan", 88.0);
  display_marks(&ds);

  // testing add data operation
  TNODE *tp = search(ds.bst, "Moore");
  if (tp== NULL)
    printf("\nNot Fount\n");
  else
    printf("\nFound: (%s, %3.1f)\n", tp->data.name, tp->data.score);

  // testing remove data operation
  remove_data(&ds, "Wang");
  remove_data(&ds, "Chabot");

  //
  report_data(&ds, outfilename);
  clean_marks(&ds);

  FILE *fp =fopen(outfilename, "r");
  if ( fp == NULL ) {
    printf("output file does not exist\n");
    return 0;
  }
  char buf[100];
  while( !feof(fp) ) {
     fgets(buf, sizeof(buf), fp);
     printf("%s", buf);
     buf[0] = 0;
  }
  fclose(fp);

  return 0;
}

