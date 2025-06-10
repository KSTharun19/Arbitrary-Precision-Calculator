#include "check_Op.h"
#include "calculation.h"

Dlist *head1;
Dlist *head2;


int check_opreation_type(char *argv1, char *argv2, char *argv3)
{
    if(argv2[0] == '+')
    {

        if(argv1[0] == '-' && argv3[0] == '-')            //(- + -)
        {
            printf("res = -");
            return ADDITION;
        }
        else if(argv1[0] != '-' && argv3[0] == '-')        //(+ + -)
        {
            return SUBTRACTION;
        }
        else if(argv1[0] == '-' && argv3[0] != '-')        //(- + +)
        {
             
            return SUBTRACTION;
        }
        else       //if(argv1[0] != '-' && argv2[0] != '-')//(+ + +)
         {
            printf("res = ");
            return ADDITION;
         }
    }
    else if(argv2[0] == '-')
    {
        if(argv1[0] == '-' && argv3[0] == '-')              //(- - -)
        {
           
            return SUBTRACTION;
        }
        else if(argv1[0] != '-' && argv3[0] == '-')         //(+ + -)
        {
            printf("res = ");
            return ADDITION;
        }
        else if(argv1[0] == '-' && argv3[0] != '-')          //(- + +)
        {
            printf("res = -");
            return ADDITION;
        }
        else         //if(argv1[0] != '-' && argv2[0] != '-') //(+ - +)
         {
            return SUBTRACTION ;
         }
    }
    else if(argv2[0] == 'X' || argv2[0] == 'x')
    {
       if(argv1[0] == '-' && argv3[0] == '-')                 //(- - -)
        {
            printf("Res: ");
            return MULTIPLICATION;
        }
        else if(argv1[0] != '-' && argv3[0] == '-')           //(+ + -)
        {
            printf("Res: -");
            return MULTIPLICATION;
        }
        else if(argv1[0] == '-' && argv3[0] != '-')           //(- + +)
        {
            printf("Res: -");
            return MULTIPLICATION;
        }
        else
        { 
            printf("Res: ");
            return MULTIPLICATION;
        }
    }
    else
    {
     if(argv2[0] == '/')
     {
       if(argv1[0] == '-' && argv3[0] == '-')                 //(- - -)
        {
            printf("Res: -");
            return DIVISION;
        }
        else if(argv1[0] != '-' && argv3[0] == '-')           //(+ + -)
        {
            printf("Res: -");
            return DIVISION;
        }
        else if(argv1[0] == '-' && argv3[0] != '-')            //(- + +)
        {
            printf("Res: -");
            return DIVISION;
        }
        else
        {
            printf("Res: ");
            return DIVISION;
        } 
     }
    }
}
