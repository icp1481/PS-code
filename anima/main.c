#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node_utils.h"

#define BOOL int
#define TRUE 1
#define FALSE 0

NODE *root = NULL;
FILE *datafile;

// Returns true if user types "yes" or "y" (upper or lower case)
// and returns false if user types "no" or "n". Keeps
// prompting otherwise.

BOOL yes_response()
{

  //Fill in the code
  //Hint: You might consider using the C library function strcasecmp()

  char response[10];
  fgets(response, sizeof(response), datafile);

  int i;
  if (strcasecmp(response, "yes") == 0)
    i = 0;
  else if (strcasecmp(response, "y") == 0)
    i = 0;

  if (i == 0)
    return TRUE;
  else
    return FALSE;

}

// This procedure creates a new NODE and copies
// the contents of string s into the
// question_or_animal field.  It also initializes
// the left and right fields to NULL.
// It should return a pointer to the new node

NODE *new_node(char *s)
{

  //Fill in the code

  NODE* new_node;

  strcpy(new_node->question_or_animal, s);
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

// This is the procedure that performs the guessing.
// If the animal is not correctly guessed, it prompts
// the user for the name of the animal and inserts a
// new node for that animal into the tree.

void guess_animal()
{
  char response[200];
  BOOL yes_or_no;
  NODE* curr_node;

  // If the root is NULL, then there are no animals in
  // the tree. Prompt the player for the name of an
  // animal, create a node for that animal, and make
  // that node the root of the tree.

  //FILL IN CODE HERE
  if (root == NULL) {
    printf("I give up! What animal is it? > ");
    fgets(response, sizeof(response), datafile);
    printf("%s\n", response);
    root = new_node(response);
    curr_node = root;
    printf("%p\n", curr_node);
    printf("%p\n", root);
    printf("%s\n", root->question_or_animal);
    return;
  }
    /*
      Otherwise (i.e. if the root is not NULL)
      Then descend down the tree. At each node encountered:

      If the left and right fields of the node are not NULL, i.e. the node
      is an interior node and must contain a question, then:
      - print the question_or_answer field, which will be a yes/no question.
      - read the response from the user
      - If the response is yes, follow the left field to the next node. Otherwise,
        follow the right field.
    */

  //FILL IN CODE HERE
  if (root != NULL) {
    printf("reach1\n");
    while ((curr_node->left != NULL) && (curr_node->right != NULL)){
      printf("reach2\n");
      printf("%s > ", curr_node->question_or_animal);
      yes_or_no = yes_response();

      if (yes_or_no == TRUE)
        curr_node = curr_node->left;
      else
        curr_node = curr_node->right;
    }
  }




  /*
      Otherwise, if the left and right fields are NULL (i.e. the node is a leaf),
      then the question_or_animal field contains an animal. Print the
      the question_or_animal field as the guess and prompt the user
      if the guess was correct. If the guess was correct, then
      return. Otherwise, do the following:
           - prompt the user for the name of the new animal she was thinking of
           - prompt the user for a yes or no question distinguishing the new animal from the guessed animal
	   - ask the user what the answer for the new animal would be (yes or no)
           - create a new node with the new animal in the question_or_animal field
	   - create another new node that has the guessed animal in the question_or_animal field
           - make the two new nodes the children of the current node, where the animal for which the
             answer to the question is "yes" is the left child and the other animal is the right child.
           - overwrite the question_or_animal field of the current node with the new question.

      Note that the tree is a stricly binary tree, i.e. left and right fields of each node are either both NULL or
      both valid pointers to child nodes (in other words, each node is a leaf or has exactly two children).
    */

  //FILL IN CODE HERE
  if ((curr_node->left == NULL) && (curr_node->right == NULL)) {
    printf("reach3\n");
    printf("I'm guessing: %s\nAm I right? > ", curr_node->question_or_animal);
    yes_or_no = yes_response();

    if (yes_or_no == TRUE) {
      printf("I win!\n");
      return;
    }
    else {
      char new_animal[200];
      char new_question[200];

      printf("oops.  What animal were you thinking of? > ");
      fgets(response, sizeof(response), datafile);
      strcpy(new_animal, response);

      printf("Enter a yes/no question to distinguish between a %s and a %s > ", new_animal, curr_node->question_or_animal);
      fgets(response, sizeof(response), datafile);
      strcpy(new_question, response);

      printf("What is the answer for a %s (yes or no) > ", new_animal);
      yes_or_no = yes_response();
      if (yes_or_no == TRUE) {
        printf("reach5");
        curr_node->left = new_node(new_animal);
        curr_node->right = new_node(curr_node->question_or_animal);
      } else {
        printf("reach6");
        curr_node->left = new_node(curr_node->question_or_animal);
        curr_node->right = new_node(new_animal);
      }
      printf("reach7");
      strcpy(curr_node->question_or_animal, new_question);
      printf("reach8");
    }
  }


}



//This code is complete. Just add comments where indicated.

int main()
{ int i;
  BOOL done = FALSE;

  //insert comment here
  datafile = fopen("data.dat", "r");

  if (datafile == NULL) {
    printf("data.dat not found\n");
    exit(1);
  }

  //insert comment here
  FILE *backupfile = fopen("data.dat.bak", "w");

  //insert comment here
  root = read_tree(datafile);

  //call write_tree() to write the initial tree to the
  //backup file (i.e. to backup the tree data)
  write_tree(root,backupfile);

  //close both files (for now)
  fclose(backupfile);
  fclose(datafile);

  printf("Welcome to the animal guessing game (like 20 questions).\n");
  do {
    printf("\nThink of an animal...\n");
    guess_animal();  //insert comment here
    printf("\nDo you want to play again? (yes/no) >");
  } while (yes_response());  //insert comment here


  //now open the "data.dat" file for writing
  datafile = fopen("data.dat", "w");

  //insert comment
  write_tree(root, datafile);

  //close the data.dat file
  fclose(datafile);

}

