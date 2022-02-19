#include <stdio.h>
#include <stdlib.h>

struct BankAccount
{
    char *Name;
    double m_interestRate;
    double m_interest;
    int m_numberMounths;
    double m_loanSum;
};

double readLoanSum(struct BankAccount *i);

int main()
{
    struct BankAccount bka;
    struct BankAccount *ptrBka = &bka;

    ptrBka->Name = (char *) malloc(30 * sizeof(char));

    if(ptrBka == NULL)
        exit(-1);

    readLoanSum(ptrBka);

    free(ptrBka->Name);

    return 0;
}

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
