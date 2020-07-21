/*
 -------------------------------------
 File:    bst.c
 Project: cp264a7_iahn3130
 file description
 -------------------------------------
 Author:  Alan Iahnis
 ID:      180723130
 Email:   iahn3130@mylaurier.ca
 Version  2020-03-06
 -------------------------------------
 */

#include "bst.h"

TNODE* search(TNODE *root, char *name) {
	while (root != NULL && strcmp(name, (root)->data.name) != 0) {
		if (strcmp(name,(root)->data.name) > 0) {

			if (root->right) {
				root = (root->right);
			}
		}
		else if (strcmp(name, root->data.name) < 0) {

			if (root->left) {
				root = root->left;
			}
		}
	}
    return root;
}

void insert(TNODE **rootp, char *name, float score) {

	TNODE *p = NULL;
	p = &(**rootp);
	TNODE *node = (TNODE *) malloc(sizeof(TNODE));

	strcpy(node->data.name, name);

	node->data.score = score;
	node->left = NULL;
	node->right = NULL;

	if(*rootp == NULL) {
		*rootp = node;

	} else {

		while (p != NULL && strcmp(name, (p)->data.name) != 0) {
			if (strcmp(name, (p)->data.name) > 0) {

				if (p->right) {
					p = p->right;

				} else {
					p->right = node;
					return;
				}

			} else if (strcmp(name, p->data.name) < 0) {

				if (p->left) {

					p = p->left;

				} else {

					p->left = node;
					return;
				}
			}
			else return;
		}
		return;
	}
}

void delete(TNODE **rootp, char *name) {

    if (rootp == NULL) return;
	TNODE *p = *rootp;
	if (strcmp(name, p->data.name) == 0) {

		if (p->left == NULL && p->right == NULL) {
            *rootp = NULL;
			free(p);

		} else if (p->left == NULL && p->right != NULL) {
			*rootp = p->right;
			free(p);

		} else if (p->left != NULL && p->right == NULL) {
			*rootp = p->left;
			free(p);

		} else {
			TNODE *tnode = extract_smallest_node(&p->right);
			tnode->left = p->left;
			tnode->right = p->right;
			p = tnode;
			free(p);
        }

	} else {
		(strcmp(name, p->data.name) < 0) ?
				delete(&p->left, name) : delete(&p->right, name);
    }
}

TNODE *extract_smallest_node(TNODE **rootp) {

    if(!(rootp)) return NULL;

	TNODE *new_node = *rootp, *p = NULL;

	while (new_node->left) {
		p = new_node;
		new_node = new_node->left;
    }

	if (new_node == *rootp) {
		if (!(new_node->right))
            *rootp = NULL;
        else
			*rootp = new_node->right;

	} else {
		p->left = new_node->right;

    }
	return new_node;
}

void display_inorder(TNODE *root) {

    if (root != NULL) {

        if (root->left) display_inorder(root->left);
        printf("%-15s%3.1f\n", root->data.name, root->data.score);
        if (root->right) display_inorder(root->right);
    }
}

void clean_tree(TNODE **rootp) {
    if (*rootp == NULL) return;
    clean_tree(&(*rootp)->left);
    clean_tree(&(*rootp)->right);
    free(*rootp);
}

