
#include "calculation.h"
#include "check_Op.h"
#include "globals.h"

// VALIDATION OF CMD LINE ARGUMENTS
int validat_input(char *argv);
int neg_flag = 0;

//Function to check the sign of operand
int check_sign(char argv);

//VARIABLES TO USE AS EXTERN
int neg1 = 0;
int neg2 = 0; 

int main(int argc, char *argv[])
{
   
    Dlist *head1 = NULL,*tail1 = NULL,*head2 = NULL,*tail2 = NULL,*res_h = NULL,*res_t = NULL;
    
    //Valid the Command line(VALID NO OF COMMAND)
    if(argc != 4)
    {
        printf("Emter valid Expresiion like (a + b)\n");
        return FAILURE;
    } 

    //GLOBAL EXTERN VARIABLES TO USE IN SUBTRACTION FUNCTION TO FINALISE SIGN
        neg1 = check_sign(argv[1][0]);
        neg2 = check_sign(argv[3][0]);

    int neg3 = check_sign(argv[1][0]);
    int neg4 = check_sign(argv[3][0]);

    // validate and store first argument(OPERAND1)
    if(validat_input(argv[1]) == FAILURE)
    {
        printf("Argument %d: '%s' is Invalid (only digits 0-9)\n", 1, argv[1]);
        printf("Try with valid OPERANDS...\n");
        return FAILURE;
    }
    if(neg3 == 1)
    {
       store_to_flag_list(argv[1], &head1, &tail1); 
       neg3 = 0;
    }
    else
    {
       store_to_list(argv[1], &head1, &tail1);
    }

    // validate and store third argument(OPERAND2)
    if(validat_input(argv[3]) == FAILURE)
    {
        printf("Argument %d: '%s' is invalid (only digits 0-9)\n", 3, argv[3]);
        printf("Try with valid OPERANDS...\n");
        return FAILURE;
    }

    if(neg4 == 1)
    {
       store_to_flag_list(argv[3], &head2, &tail2); 
       neg4 = 0;
    }
    else
    {
    store_to_list(argv[3], &head2, &tail2);
    }

    
    // validate and store second argument(OPERATOR)
    if(argv[2][0] != '+' && argv[2][0] != '-' &&argv[2][0] != 'x' && argv[2][0] != 'X' && argv[2][0] != '/')
    {
        printf("Please Enter valid Operator,(+, - , X, /)\n");
        return FAILURE;
    }
    
    // Debug input lists
    if(neg1 == 1)
    {
    printf("First Number: -");
    }
    else
    {
    printf("First Number: ");
    }
    print_list(head1);

    if(neg2 == 2)
    {
      printf("\nSecond Number: -");  
    }
    else
    {
    printf("\nSecond Number: ");
    }
    print_list(head2);
    printf("\n");
   
   //calling function to finalise operation
   int opration = check_opreation_type(argv[1], argv[2], argv[3]);
   switch (opration)
   {
    case ADDITION:
        
       addition(head1, tail1, head2, tail2, &res_h, &res_t);
       break;
      
    case SUBTRACTION:
        Assign_sign(head1, head2);
        //swap(&head1, &head2);
        Subtraction(head1, tail1, head2, tail2, &res_h, &res_t);
        break;

    case MULTIPLICATION:
        multiplication(head1, tail1, head2, tail2, &res_h, &res_t);
        break;

    case DIVISION:
       division(&head1, &tail1, &head2, &tail2, &res_h, &res_t);
        break;    
   
   default:
        printf("Invalid operator\n");
        return FAILURE;
   } 

    print_list(res_h);
}

//Function to check the sign of operand
int check_sign(char argv)
{
    if(argv == '-')
    {
        return 1;
    }
    return 0;
}

// VALIDATION OF CMD LINE ARGUMENTS
int validat_input(char *argv)
{
    // Check for empty input
    if (argv == NULL || argv[0] == '\0')
    {
        return FAILURE;
    }

    if(argv[0] == '-')
    {
      neg_flag = 1;
           
    }
    for(int i = neg_flag; argv[i] != '\0'; i++)
    {
    
        if(isdigit(argv[i]) == 0)
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}
    


    
    
   





    
