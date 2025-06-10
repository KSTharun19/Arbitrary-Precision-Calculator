#include "calculation.h"
#include "globals.h"

 
//ADDITION FUNCTION
int addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)
{
    Dlist *t1 = tail1;
    Dlist *t2 = tail2;
    
    int num1,num2,carry=0;
    while (t1 != NULL || t2 != NULL || carry != 0)
    {
        
        if(t1 != NULL)
        {
            num1 = t1->data;
            t1 = t1->prev;
        }
        else
        {
           num1 = 0;
        }
        if(t2 != NULL)
        {
            num2 = t2->data;
            t2 = t2->prev;
        }
        else
        {
           num2 = 0;
        }
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        
        inser_first(res_h, res_t, sum);

    }
    
    //print_list(*res_h);
}


//FUnction TO SUBTRACT THE NUMBERS
int Subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)
{
    

    Dlist *H1 = head1;
    Dlist *H2 = head2;
    
    if (compare_ARG1(H1, H2) == 1) {  
        swap(&head1, &head2);
        swap(&tail1, &tail2);
    }

    int num1, num2, borrow = 0;
    Dlist *t1 = tail1;
    Dlist *t2 = tail2;

    while (t1 != NULL || t2 != NULL) {
        num1 = (t1 != NULL) ? t1->data : 0;
        num2 = (t2 != NULL) ? t2->data : 0;

        if (borrow == 1) num1--;

        if (num1 < num2) {
            num1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        int diff = num1 - num2;

        if (inser_first(res_h, res_t, diff) != SUCCESS) {
            printf("Failed to insert into result list\n");
            return FAILURE;
        }

        t1 = t1 ? t1->prev : NULL;
        t2 = t2 ? t2->prev : NULL;
    }

    // Debug print
    // printf("Subtraction Result: ");
    // print_list(*res_h);
    // printf("\n");

    return SUCCESS;
}

     
int multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)
{
    int shift = 0; // To handle shifts for intermediate results
    Dlist *temp2 = tail2; // Start from the least significant digit of the second number

    while (temp2)
    {
        Dlist *temp1 = tail1; // Start from the least significant digit of the first number
        int product;
        int carry = 0;
        Dlist *inter_H = NULL, *inter_L = NULL; // To store intermediate results

        // Multiply the current digit of temp2 with all digits of temp1
        while (temp1)
        {
            product = (temp1->data * temp2->data) + carry; // Multiply and add carry
            carry = product / 10; // Extract carry
            product = product % 10; // Extract digit
            inser_first(&inter_H, &inter_L, product); // Insert the digit
            temp1 = temp1->prev; // Move to the next digit in the first number
        }

        // If there's a carry left, add it to the intermediate result
        if (carry)
        {
            inser_first(&inter_H, &inter_L, carry);
        }

        // Append zeros to the intermediate result based on the current shift
        for (int i = 0; i < shift; i++)
        {
            insert_at_last(&inter_H, &inter_L, 0);
        }
        shift++; // Increment the shift for the next digit

        // Add the intermediate result to the final result
        Dlist *res_ptr = *res_t;
        Dlist *inter_ptr = inter_L;
        carry = 0; // Reset carry for addition

        Dlist *temp_res_H = NULL, *temp_res_T = NULL; // Temporary list to store new results
        while (res_ptr || inter_ptr || carry)
        {
            int sum = carry;
            if (res_ptr)
            {
                sum += res_ptr->data;
                res_ptr = res_ptr->prev;
            }
            if (inter_ptr)
            {
                sum += inter_ptr->data;
                inter_ptr = inter_ptr->prev;
            }

            int digit = sum % 10;
            carry = sum / 10;

            inser_first(&temp_res_H, &temp_res_T, digit); // Insert into the temporary result list
        }

        // Update the final result list
        *res_h = temp_res_H;
        *res_t = temp_res_T;

        // Free the intermediate result list to avoid memory leaks
        while (inter_H)
        {
            Dlist *temp = inter_H;
            inter_H = inter_H->next;
            free(temp);
        }

        // Move to the next digit of the second number
        temp2 = temp2->prev;
    }
     
    // print_list(*res_h);

    return SUCCESS;
}

//FUNCTION FOR DIVISION 1
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_h, Dlist **res_t)
{
    unsigned long long int dividend = 0, divisor = 0, count = 0;
    
    //To store argv[1] in dividend variable
    while (*head1)
    {
        dividend = dividend * 10 + (*head1)->data; 
        (*head1) = (*head1)->next;
    }

    //To store argv[3] in divisor variable
    while (*head2)
    {
        divisor = divisor * 10 + (*head2)->data; 
        (*head2) = (*head2)->next;
    }
    if(divisor == 0)
    {
        return 1;
    }

    //To find the quotient
    while(dividend >= divisor && dividend != 0 )
    {
        dividend = dividend - divisor;
        count++;
    }

    inser_first(res_h, res_t, count);
   return SUCCESS;
}

//SIR I HAVE TRIED MANY WAYS TO SOLVE THROUGH DLL BUT I AM NOT GETTING SIR

// //FUNCTION FOR DIVISION2   
// int Division(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **res_h,Dlist **res_t)
// {
//     int compare = compare_ARG1(head1, head2);
//     //printf("%d", compare);
   
//     if(compare == 1)  //head2 is larger
//     {
//         inser_first(res_h, res_t, 0);
//         return SUCCESS;
//     }
//     else if(compare == 0)
//     {
//         inser_first(res_h, res_t, 1);
//         return SUCCESS;
//     }
//     else// head1 is larger
//     {
//        int count = 0;
//        //Dlist *temp_h = NULL, *temp_t = NULL;

//        Subtraction(head1, tail1, head2, tail2, res_h, res_t);
//        count++;
      
//        int compare = compare_ARG1(*res_h, head1);
//        printf("uff %d\n", compare);
       
//          while(res_h != NULL && compare_ARG1(*res_h, head2) <= 0)
//           {
            
//             Subtraction(*res_h, *res_t, head2, tail2, res_h, res_t);
//             count++;
//           }
//           inser_first(res_h, res_t, count);
//         return SUCCESS;
//     }
// }
    


//FUNCTION TO SWAP THE ADDRESSES
void swap(Dlist **head1, Dlist **head2)
{
    // if(compare_ARG1(*head1, *head2) == 1)
    // {
      Dlist *temp = *head1;
            *head1 = *head2;
            *head2 = temp;
   //}
}

//To insert data to result list
int inser_first(Dlist **res_h, Dlist **res_l, int data)
{
    Dlist *new = (Dlist*)malloc(sizeof(Dlist));
    if(new == NULL)
    {
        printf("Memory allocation is Failed for sum NODE!...\n");
        return FAILURE;
    }
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if(*res_h == NULL)
    {
        *res_h = new;
        *res_l = new;
        return SUCCESS;
    }

    new->next = *res_h;
    (*res_h)->prev = new;
    *res_h = new;
    return SUCCESS;
   
}

//FUNCTION TO SKIP "-" AND STORE
void store_to_flag_list(char arr[], Dlist **head, Dlist **tail)
{
     int i = 1;
    while(arr[i] == '0')
    {
        i++;
    }

    while(arr[i] != '\0')
    {
       int num = arr[i]- '0';     //ASCII
       insert_at_last(head, tail, num);
       i++;
    }
}

//FUNCTION TO STORE VALUES
void store_to_list(char arr[], Dlist **head, Dlist **tail)
{
    int i = 0;
    while(arr[i] == '0')
    {
        i++;
    }

    while(arr[i] != '\0')
    {
       int num = arr[i]- '0';       //ASCII
       insert_at_last(head, tail, num);
       i++;
    }
}

int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = (Dlist*)malloc(sizeof(Dlist));
    if(new == NULL)
    {
        printf("Memory allocation if failes\n");
        return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
       *head = new;
       *tail = new;
       return SUCCESS;
    }

    Dlist *temp = *tail;

    new->prev = temp;
    temp->next = new;
    *tail = new;
    return SUCCESS;
    
}

void print_list(Dlist *head) 
{   
        //printf("res = ");
        Dlist *temp = head;
        while(temp != NULL)
        {
            printf("%d",temp->data);
            temp = temp->next;
        }
        printf("\n");
}

int compare_ARG1(Dlist *head1, Dlist *head2)
{
    int count1 = 0, count2 = 0;
    Dlist *temp1 = head1, *temp2 = head2;

    // Count length of first list
    while (temp1) {
        count1++;
        temp1 = temp1->next;
    }

    // Count length of second list
    while (temp2) {
        count2++;
        temp2 = temp2->next;
    }

    // Compare based on length
    if (count1 > count2) {
        return -1; // head1 is larger
    }
    else if (count1 < count2) {
        return 1;  // head2 is larger
    }
    else {
        // If lengths are the same, compare digit by digit
        while (head1 && head2) {
            if (head1->data > head2->data) {
                return -1; // head1 is larger
            }
            else if (head1->data < head2->data) {
                return 1;  // head2 is larger
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return 0; // Both lists are equal
    }
}

//FUNCTION TO FINALISE SIGN
void Assign_sign(Dlist *head1, Dlist *head2)
{
    int flag = 0;
   int compare = compare_ARG1(head1, head2);
    
    if(compare == -1)                 //head1 is larger
    {
        if(neg1 == 0 && neg2 == 0)    //(H1 > h2)
       {
        flag = 0;
       }
       else if(neg1 == 1 && neg2 == 0)
       {
        flag = 1;
       }
       else if(neg1 == 0 && neg2 == 1)
       {
        
        flag = 0;
       }
       else
       {
        flag = 1;
       }
       
    }
    else if(compare == 1)          //(H2 > H1)
    {
      if(neg1 == 1 && neg2 == 1)
      {
        flag = 0;
      }
      else if(neg1 == 1 && neg2 == 0)
      {
        flag = 0;
      }
      else if(neg1 == 0 && neg2 == 0)
      {
        flag = 1;
      }
      else
      {
         flag = 1;
      }
    }
    else
    {
       flag = 0;
    }
   if(flag == 1)
   {
    printf("res = -");
   }
   else
   {
    printf("res = ");
   }
}







 







