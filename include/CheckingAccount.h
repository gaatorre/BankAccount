#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "account.h"
#include "SavingsAccount.h"

typedef struct checkingAccount_t checkingAccount;
struct checkingAccount_t {
  char name[ACCOUNT_NAME_LENGTH];
  double balance;
  savingsAccount *savings[MAX_SAVING_ACCOUNTS];
};

checkingAccount * CheckingAccountInit(char *, double);

void CheckingAccountDestruct(checkingAccount *);

int CheckingAccountDeposit(checkingAccount *, double);

int CheckingAccountWithDraw(checkingAccount *, double);

#endif
