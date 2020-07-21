/*
 -------------------------------------
 File:    bst.h
 Project: cp264a7_iahn3130
 file description
 -------------------------------------
 Author:  Alan Iahnis
 ID:      180723130
 Email:   iahn3130@mylaurier.ca
 Version  2020-03-06
 -------------------------------------
 */

#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct rec {
  char name[40];
  float score;
} RECORD;

typedef struct node {
    RECORD data;
    struct node *left;
    struct node *right;
} TNODE;

/* search bst by data.name */
TNODE *search(TNODE *root, char *name);

/* insert record (name, score) into bst using data.name as key */
void insert(TNODE **rootp, char *name, float score);

/* delete node of data.name from bst */
void delete(TNODE **rootp, char *name);

/* get and return and delete the node of the smallest data.name node from the bst */
TNODE *extract_smallest_node(TNODE **rootp);

/* display bst tree data by in-order */
void display_inorder(TNODE *root);

/* clean the tree */
void clean_tree(TNODE **rootp);
#endif
