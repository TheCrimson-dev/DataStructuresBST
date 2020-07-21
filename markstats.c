/*
 -------------------------------------
 File:    markstats.c
 Project: cp264a7_iahn3130
 file description
 -------------------------------------
 Author:  Alan Iahnis
 ID:      180723130
 Email:   iahn3130@mylaurier.ca
 Version  2020-03-06
 -------------------------------------
 */

#include "markstats.h"
#include "bst.h"


void add_data(MARKS *dsp, char *name, float score) {

	TNODE **rnode = &(dsp->bst);

	insert(rnode, name, score);
	int counter = dsp->count;
	float i = dsp->mean;
	float j = dsp->stddev;

	dsp->count += 1;
	dsp->mean = (dsp->mean * counter + score) / dsp->count;
	dsp->stddev =
			sqrt(
			((counter * (pow(j, 2) + pow(i, 2)) + pow(score, 2))
							/ dsp->count) - pow(dsp->mean, 2));
}

void remove_data(MARKS *dsp, char *name) {

	TNODE *p = search(dsp->bst, name);

	float i = p->data.score;
	TNODE **root_node = &(dsp->bst);
	delete(root_node, name);

	int counter = dsp->count;
	float j = dsp->mean;
	float k = dsp->stddev;

	dsp->count -= 1;
	dsp->mean = (dsp->mean * counter - i) / dsp->count;
	dsp->stddev = sqrt(
			((counter * (pow(k, 2) + pow(j, 2)) - pow(i, 2)) / dsp->count)
					- pow(dsp->mean, 2));
}

void display_marks(MARKS *dsp) {
  printf("grade report\n");
  display_inorder(dsp->bst);
  printf("\nstatistics summary\n");
  printf("%-15s%d\n", "count", dsp->count);
  printf("%-15s%3.1f\n", "mean", dsp->mean);
  printf("%-15s%3.1f\n", "stddev", dsp->stddev);
}

void clean_marks(MARKS *dsp) {
  clean_tree(&dsp->bst);
  dsp->count = 0;
  dsp->mean = 0;
  dsp->stddev = 0;
}

void import_data(MARKS *ds, char *filename) {
	char s[40], p[20];
	char *final = NULL;
	char end[] = ",\n";
	FILE *file = fopen(filename, "r");
	float count = 0;

	if (file == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

	while (fgets(s, sizeof(s), file) != NULL) {

		final = strtok(s, end);
		if (final) {

			strcpy(p, final);
			final = strtok(NULL, end);
			count = atof(final);
			add_data(ds, p, count);
    }
  }
	fclose(file);
}

void print_to_file_inorder(TNODE *root, FILE *fp) {
  if (root){
    if (root->left) print_to_file_inorder(root->left, fp);
    fprintf(fp, "%-15s%3.1f%4c\n", root->data.name, root->data.score, letter_grade(root->data.score));
    if (root->right) print_to_file_inorder(root->right, fp);
  }
}

void report_data(MARKS *dsp, char *filename) {
	FILE *file = fopen(filename, "w");
	fprintf(file, "grade report\n");
	print_to_file_inorder(dsp->bst, file);
	fprintf(file, "\nstatistics summary\n");
	fprintf(file, "%-15s%d\n", "count", dsp->count);
	fprintf(file, "%-15s%3.1f\n", "mean", dsp->mean);
	fprintf(file, "%-15s%3.1f\n", "stddev", dsp->stddev);
	fclose(file);
}

char letter_grade(float s){
	char letter = 'F';
	if (s >= 85)
		letter = 'A';
	else if (s >= 70)
		letter = 'B';
	else if (s >= 60)
		letter = 'C';
	else if (s >= 50)
		letter = 'D';
	else
		letter = 'F';
	return letter;
}
