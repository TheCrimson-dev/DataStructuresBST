/*
 -------------------------------------
 File:    tree.c
 Project: cp264a7_iahn3130
 file description
 -------------------------------------
 Author:  Alan Iahnis
 ID:      180723130
 Email:   iahn3130@mylaurier.ca
 Version  2020-03-06
 -------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include "tree.h"

TNODE *new_node(int value) {
	TNODE *t = (TNODE *) malloc(sizeof(TNODE));
	if (t == NULL)
		return NULL;
	t->data = value;
	t->left = NULL;
	t->right = NULL;
	return t;
}

int get_count(TNODE *root) {
	int i = 0;
	if (root != NULL) {
		i = get_count_aux(root);
	}
	return i;
}

int get_count_aux(TNODE *root) {
	int i = 1;
	if(root->left != NULL)
		i += get_count_aux(root->left);
	if(root->right != NULL)
		i += get_count_aux(root->right);
	return i;
}

int get_height(TNODE *root) {

	if (root == NULL) {
		return 0;
	}
	else {
		int update_height = get_height(root->left);
		int new_height = get_height(root->right);

		if (update_height > new_height) {
			return (update_height + 1);
		}
		else {
			return (new_height + 1);
		}
	}
}

void clean_tree(TNODE **rootp) {
	if (*rootp == NULL) return;
	clean_tree(&(*rootp)->left);
	clean_tree(&(*rootp)->right);
	free(*rootp);
}

void display_preorder(TNODE *root) {
	printf("%c ",root->data);
	if(root->left) display_preorder(root->left);
	if(root->right) display_preorder(root->right);
}

void display_inorder(TNODE *root) {
	if (root->left)display_inorder(root->left);
	printf("%c ",root->data);
	if (root->right)display_inorder(root->right);
}

void display_postorder(TNODE *root) {
	if (root->left) display_postorder(root->left);
	if (root->right) display_postorder(root->right);
	printf("%c ",root->data);
}

void display_tree(TNODE *root, int prelen) {
  if (root) {
		int node;
		for (node = 0; node < prelen; ++node)
      printf("%c", ' ');
    printf("%s", "|___");
    printf("%c\n", root->data);
    display_tree(root->right, prelen + 4);
    display_tree(root->left, prelen + 4);
  }
}


/* use auxiliary queue data structure for the algorithm */
void iterative_bf_display(TNODE *root) {
	if (root != NULL){

		TNODE *node;
		QUEUE p = { 0 };
		enqueue(&p, root);

		while (p.front) {
			node = dequeue(&p);
			root = node;
			printf("%c ", node->data);

			if (root->left != NULL)
				enqueue(&p, root->left);

			if (root->right != NULL)
				enqueue(&p, root->right);
		}
	}
}


/* use auxiliary queue data structure for the algorithm */
TNODE *iterative_bf_search(TNODE *root, int val) {
	if (root != NULL) {
		TNODE *node;
		QUEUE p = { 0 };

		enqueue(&p, root);

		while (p.front) {
			node = dequeue(&p);
			root = node;
			if (node->data == val) {
				return node;

			} else {
				if (root->left)
					enqueue(&p, root->left);

				if (root->right)
					enqueue(&p, root->right);
			}
		}
	}
	return NULL;
}

/* use auxiliary stack data structure for the algorithm */
TNODE *iterative_df_search(TNODE *root, int val) {

    if (root == NULL) return NULL;
	TNODE *node = NULL;
	TNODE *root_node = NULL;
	STACK i = { 0 };

	push(&i, root);
	while (i.top) {
		node = peek(&i);

		if (val == node->data) {
			clean_stack(&i);
			return node;
		} else if (root_node == NULL) {

			if (node->left != NULL) {
				push(&i, node->left);

			} else if (node->right != NULL) {
				push(&i, node->right);

			} else {
				root_node = node;
				pop(&i);
        	}

		} else if (root_node != NULL) {

			if (root_node == node->left && node->right != NULL) {
				root_node = NULL;
				push(&i, node->right);

			} else {
				root_node = node;
				pop(&i);
        	}
        }
    }
    return NULL;
}

// queue functions adapted and modified from a6
void enqueue(QUEUE *qp, void *data) {
	QNODE *node = (QNODE*) malloc(sizeof(QNODE));

	if (node == NULL)
		return;

   else {
		node->data = data;
		node->next = NULL;

     if (qp->front == NULL) {

			qp->front = node;
			qp->rear = node;
		}

		else {

			(qp->rear)->next = node;
			qp->rear = node;
    }
  }
}
void *dequeue(QUEUE *qp) {
	void *i = NULL;

  if (qp->front) {

		QNODE *node = qp->front;
		i = node->data;

    if (qp->front == qp->rear) {
      qp->front = NULL;
      qp->rear = NULL;

		}

		else {
			qp->front = node->next;
    }
		free(node);
		return i;
  }
  return NULL;
}
void clean_queue(QUEUE *qp) {
	QNODE *node;
	QNODE *new_node = qp->front;

	while (new_node != NULL) {

		node = new_node;
		new_node = new_node->next;
		free(node);
  }
}

// stack functions adapted and modified from a6
void push(STACK *sp, void *data) {

	SNODE *node = (SNODE*) malloc(sizeof(SNODE));

	node->data = data;
	node->next = NULL;

  if (sp->top == NULL) {
		sp->top = node;
	}

	else {
		node->next = sp->top;
		sp->top = node;
  }
}
void pop(STACK *sp) {
  if (sp->top != NULL) {

		SNODE *node = sp->top;
		sp->top = node->next;
		free(node);
  }
}
void *peek(STACK *sp) {
  if (sp->top != NULL) {
     return sp->top->data;
  }
  return NULL;
}
void clean_stack(STACK *sp) {
	SNODE *node;
	SNODE *new_node = sp->top;

	while (new_node) {

		node = new_node;
		new_node = new_node->next;
		free(node);
  }
  sp->top = NULL;
}
