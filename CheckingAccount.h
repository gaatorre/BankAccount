#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "account.h"

typedef struct checkingAccount_t checkingAccount

checkingAccount * checkingAccountInit(int);

void CheckingAccountDestruct();

int CheckingAccountDeposit(int);

int CheckingAccountWithDraw(int);

#endif
