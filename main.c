#include <stdio.h>
#include <stdlib.h>

double member1, member2; //global variables

//I used a structure(the keyword is struct) to declare members which are public
struct BankAccount
{
    char *Name;
    double m_interestRate;
    double m_interest;
    int m_numberMounths;
    double m_loanSum;
    double totalSum;
};

//function prototype
double readLoanSum(struct BankAccount *i);
double TotalSum(struct BankAccount *i);
void printSum(struct BankAccount *i);

int main()
{
    struct BankAccount bka;
    struct BankAccount *ptrBka = &bka;

    ptrBka->Name = (char *) malloc(30 * sizeof(char));

    if(ptrBka == NULL)
        exit(-1);

    readLoanSum(ptrBka);
    
    TotalSum(ptrBka);
    
    printSum(ptrBka);

    free(ptrBka->Name);

    return 0;
}

//function definition
//the function reads the members of the structure, then calculates the loan sum and returns it
double readLoanSum(struct BankAccount *i)
{
    printf("Enter the name: ");
    scanf("%s", i->Name);

    printf("Input the interest rate: ");
    scanf("%lf", &i->m_interestRate);

    printf("Input the interest(in percentages): ");
    scanf("%lf", &i->m_interest);

    printf("Input the number fo mounths: ");
    scanf("%d", &i->m_numberMounths);

    i->m_loanSum = (i->m_interestRate * 100) / i->m_interest;

    return i->m_loanSum;
}

//function definition
//the function calculates the total sum based on the interest rate, the number of months, the loan sum and returns the total sum
double TotalSum(struct BankAccount *i)
{
    member1 = i->m_interestRate / (double)i->m_numberMounths;
    member2 = i->m_loanSum / (double)i->m_numberMounths;

    i->totalSum = (member1 + member2);

    return i->totalSum;
}

void printSum(struct BankAccount *i)
{
    //display
    printf("The loaned sum is %.2lf", i->m_loanSum);
    printf("\nThe total sum per month is %.2lf", i->totalSum);
}
