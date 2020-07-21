/*
 -------------------------------------
 File:    markstats.h
 Project: cp264a7_iahn3130
 file description
 -------------------------------------
 Author:  Alan Iahnis
 ID:      180723130
 Email:   iahn3130@mylaurier.ca
 Version  2020-03-06
 -------------------------------------
 */

#ifndef MARKSTATS_H
#define MARKSTATS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bst.h"

typedef struct marks_stats {
    TNODE *bst;
    int count;
    float mean;
    float stddev;
} MARKS;

/* add a record (name, score) into the bst and update the stats info incrementally */
void add_data(MARKS *dsp, char *name, float score);

/* delete a record of name from the bst and update the stats info incrementally */
void remove_data(MARKS *dsp, char *name);


void import_data(MARKS *dsp, char *filename);
void report_data(MARKS *dsp, char *filename);
void print_to_file_inorder(TNODE *root, FILE *filename);
void display_marks(MARKS *dsp);
void clean_marks(MARKS *dsp);
char letter_grade(float score);

#endif

