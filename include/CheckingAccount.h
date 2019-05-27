#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "account.h"

typedef struct checkingAccount_t checkingAccount;

checkingAccount * CheckingAccountInit(char *, double);

void CheckingAccountDestruct(checkingAccount *);

int CheckingAccountDeposit(checkingAccount *, double);

int CheckingAccountWithDraw(checkingAccount *, double);

#endif
