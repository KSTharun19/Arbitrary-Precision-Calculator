#ifndef CALCULATION_C
#define CALCULATION_C
#define FAILURE   -2
#define SUCCESS    1


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Dlist
{
    struct Dlist *prev;
    struct Dlist *next;
    int data;
}Dlist;

extern int neg1;
extern int neg2;

void store_to_list(char arr[], Dlist **head, Dlist **tail);
int insert_at_last(Dlist **head, Dlist **tail, int data);
int inser_first(Dlist **res_h, Dlist **res_l, int data);
//int validat_input(char *argv);
// int compare_ARG(Dlist *head1, Dlist *head2);
void swap(Dlist **head1, Dlist **head2);
void print_list(Dlist *head);
void store_to_flag_list(char arr[], Dlist **head, Dlist **tail);
void Assign_sign(Dlist *head1, Dlist *head2);
int compare_ARG1(Dlist *head1, Dlist *head2);


int addition(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **res_h,Dlist **res_t);
int Subtraction(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **res_h,Dlist **res_t);
int multiplication(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **res_h,Dlist **res_t);
//int Division(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **res_h,Dlist **res_t);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_h, Dlist **res_t);


#endif