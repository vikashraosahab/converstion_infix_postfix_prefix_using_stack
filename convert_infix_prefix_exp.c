// PROGRAM THAT CONVERT INFIX TO POSTFIX AND PREFIX EXPRESSION RESPECTIVELY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 40 // SYMBOLIC CONSTANT DEFINE MAXISZE AS 40 SO ARRAY CAN STORE ONLY 40 CHARACTER A TIME
typedef int TOP;
typedef char STACK;
STACK stack [MAXSIZE]; // DECLARATION OF THE STACK
TOP top = -1; // TOP OF THE STACK
void push (STACK [], STACK);
STACK pop ();
int getPriority (char ch);
void infix_postfix (STACK *,STACK *);
void postfix_prefix (STACK *,STACK *);

// MAIN FUNCTION OF THE PROGRAM
void main (int argc, char *argv[])
{
 char infix [MAXSIZE],postfix[MAXSIZE], prefix [MAXSIZE];
 printf ("\nEnter infix expression : ");
 fgets (infix,MAXSIZE,stdin); // TAKE INPUT VALUE
 infix [strcspn (infix,"\n")] = '\0'; // REMOVE NEW LINE CHARACTER BY NULL OPERATOR
 // CONVERT INFIX TO POST
 infix_postfix (infix,postfix);
 printf ("\nPostfix expression are : %s",postfix); // POSTFIX CONVERSION 
 postfix_prefix (postfix,prefix); // POSTFIX TO PREFIX CONVERSION
 printf ("\nPrefix expression are : %s",prefix); //PREFIX CONVERSION
}
void push (STACK stack [], STACK value)
{
  if (top == MAXSIZE - 1)
  {
    printf ("\nStack is empty");
    exit (1); // TERMINATE AFTER STACK IS FULLED 
  }
  else 
  {
   stack [++top] = value; // INSERT VALUE IN STACK 
  }
}
char pop ()
{
 if (top == -1) // WHEN STACK IS EMPTY
 {
   return -1;
   exit (1); // TERMINATE AFTER STACK IS EMPTY
 }
 else 
 {
  return stack [top--]; // RETURN TOP MOST ELEMENT OF THE STACK
 }
}
void infix_postfix (STACK *infix, STACK *postfix)
{
 int i = 0, j = 0; // DELCARATION OF THE VARAIBLE
 while (infix [i] != '\0' && infix [i] != '\n')
 {
   if (infix [i] == '(')
   {
     push (stack,infix[i]);
   }
   else if (infix [i] == ')')
   {
     while (top != -1 && stack [top] != '(')
     {
       postfix [j++] = pop ();
     }
     // PARENTHESIS MISMATCHED `
     if (top == -1)
     {
      printf ("\nStack is empty !");
      exit (1); // TERMINATE
     }
     push (stack,infix[i]); // PUSH ELEMENT IN THE TOP OF THE STACK
   }
   else if (isdigit (infix [i]) || isalpha (infix [i]))
   {
      postfix [j++] = infix [i];
   }
   else if (infix [i] == '+' || infix [i] == '-' || infix [i] == '*' || infix [i] == '/')
   {
     while (top != -1 && stack [top] != '(' && getPriority (stack [top]) > getPriority (infix [i]))
     {
      postfix [j++] = pop ();
     }
     push (stack,infix [i]); // INSERT ELEMENT AT THE TOP OF THE STACK
   }
   i = i + 1; // INCREMENT THE LOOP BY 1 
 } // END OF THE LOOP
 // POP REST OF THE OPERATOR IN THE STACK 
 while (top != -1 && stack [top] != ')')
 {
   postfix [j++] = pop ();
 }
 postfix [j] = '\0'; // INSERT NULL OPERATOR AT THE END OF THE 
}
int getPriority (char ch) // GET PRIORITY ACCORDING PRECEDENCE OF THE OPERATOR 
{
  if (ch == '*' || ch == '/')
 {
  return 2;
 }
 else if (ch == '+' || ch == '-')
 {
  return 1;
 }
 else 
 {
  return 0;
 }
}
void postfix_prefix (STACK *postfix,STACK *prefix)
{
  int i = strlen (postfix) - 1, j = 0;
  while (i >= 0)
  {
    prefix [j++] = postfix [i--];
  }
  prefix [j] = '\0'; // INSERT NULL OPERATOR AT THE END OF THE PREFIX STRING 
}
