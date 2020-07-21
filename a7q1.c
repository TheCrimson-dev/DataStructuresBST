/*--------------------------------------------------
Project: cp264-a7q1
File:    a7q1.c
Description: test driver program
Author:  HBF
Version: 2020-02-26
--------------------------------------------------
 */

#include "tree.h"

int main() {
  // create nodes
  TNODE *a = new_node('A');
  TNODE *b = new_node('B');
  TNODE *c = new_node('C');
  TNODE *d = new_node('D');
  TNODE *e = new_node('E');
  TNODE *f = new_node('F');
  TNODE *g = new_node('G');

  // do linking
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;

  // set root
  TNODE *root = a;

  printf("display_tree\n");
  display_tree(root, 0);

  printf("\n%-22s%d", "node count:", get_count(root));
  printf("\n%-22s%d", "tree height:", get_height(root));

  printf("\n%-22s", "display_preorder:");
  display_preorder(root);

  printf("\n%-22s", "display_postorde:");
  display_postorder(root);

  printf("\n%-22s", "display_inorder:");
  display_inorder(root);

  printf("\n%-22s", "iterative_bf_display:");
  iterative_bf_display(root);

  char sc = 'F';
  printf("\n%-22s%c", "iterative_bf_search:", sc);
  TNODE *tnp = iterative_bf_search(root, sc);
  if (tnp)
    printf("\n%-22s%c", "found:", tnp->data);
  else
    printf("\n%-22s%c", "not found:", sc);

  sc = 'H';
  printf("\n%-22s%c", "iterative_bf_search:", sc);
  tnp = iterative_bf_search(root, sc);
  if (tnp)
    printf("\n%-22s%c", "found:", tnp->data);
  else
    printf("\n%-22s%c", "not found:", sc);

  sc = 'G';
  printf("\n%-22s%c", "iterative_df_search:", sc);
  tnp = iterative_df_search(root, 'G');
  if (tnp)
    printf("\n%-22s%c", "found:", tnp->data);
  else
    printf("\n%-22s%c", "not found:", sc);

  clean_tree(&root);
  return 0;

}

