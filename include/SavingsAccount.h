#ifndef SAVING_ACCOUNT
#define SAVING_ACCOUNT

#include "account.h"
#define SAVINGS_ACCOUNT_GOAL_REACHED 1

// typedef struct savingsAccount_t savingsAccount;

typedef struct savingsAccount_t {
  char name[ACCOUNT_NAME_LENGTH];
  double saved;
  double goal;
  double savingPercentage;
} savingsAccount;


savingsAccount* SavingsAccountInit();

void SavingsAccountDestruct(savingsAccount *);

double SavingsAccountDeposit(savingsAccount *, double);

void SavingsAccountPrintName(savingsAccount *);

double SavingsAccountRemaining(savingsAccount *);

int CheckingAccountLoadSavings(savingsAccount *, double, char *, double);

#endif
