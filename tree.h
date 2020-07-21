/*
 -------------------------------------
 File:    tree.h
 Project: cp264a7_iahn3130
 file description
 -------------------------------------
 Author:  Alan Iahnis
 ID:      180723130
 Email:   iahn3130@mylaurier.ca
 Version  2020-03-06
 -------------------------------------
 */

#ifndef TREE_H
#define TREE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node {
  int data;
  struct tree_node *left;
  struct tree_node *right;
} TNODE;

void insert_tree(TNODE **root, int val);

/*  creates a TNODE node and sets the data to value and returns the pointer */
TNODE *new_node(int value);

/* this computes and returns the number of node count of the tree passed by root.*/
int get_count(TNODE *root);

/* this computes and returns the number of the tree passed by root. */
int get_height(TNODE *root);

/* this cleans the tree passed by rootp. */
void clean_tree(TNODE **rootp);

/* this displays the node data of the tree by pre-order. */
void display_preorder(TNODE *root);

/* this displays the node data of the tree by in-order. */
void display_inorder(TNODE *root);

/* this displays the node data of the tree by post-order. */
void display_postorder(TNODE *root);

/* this displays the tree in 2D text format */
void display_tree(TNODE *root, int prelen);

/* this displays the tree in breadth-first order using additional queue data structure */
void iterative_bf_display(TNODE *root);

/* this does the breadth-first search */
TNODE *iterative_bf_search(TNODE *root, int val);

/* this does the depth-first search */
TNODE *iterative_df_search(TNODE *root, int val);

/* queue data structure for breadth-first traversal/search */
typedef struct queue_node {
  void *data;
  struct queue_node *next;
} QNODE;
typedef struct queue {
  QNODE *front, *rear;
} QUEUE;
void enqueue(QUEUE *qp, void *data);
void *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

/* stack data structure for depth-first traversal/search */
typedef struct stack_node {
  void *data; // pointer data
  struct stack_node *next;
} SNODE;
typedef struct stack {
  SNODE *top;
} STACK;
void push(STACK *sp, void *data);
void pop(STACK *sp);
void *peek(STACK *sp);
void clean_stack(STACK *sp);

#endif
