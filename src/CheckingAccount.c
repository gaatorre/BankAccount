#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

<<<<<<< HEAD:src/CheckingAccount.c
struct checkingAccount_t {
  char name[ACCOUNT_NAME_LENGTH];
  double balance;
  savingsAccount *savings[MAX_SAVING_ACCOUNTS];
  char numSavings;
};

=======
>>>>>>> 33df31c6e8d84d2181510e993288c7f2d32766f7:CheckingAccount.c
checkingAccount *CheckingAccountInit(char *name, double balance) {
  checkingAccount *temp = calloc(1, sizeof(checkingAccount));
  if (temp == NULL) {
    return NULL;
  }

  if (memcpy(temp->name, name, strlen(name)) == NULL) {
    CheckingAccountDestruct(temp);
    return NULL;
  }

  temp->balance = balance;

  for (int x = 0; x < MAX_SAVING_ACCOUNTS; x++) {
    temp->savings[x] = SavingsAccountInit();
    if (temp->savings[x] == NULL) {
      CheckingAccountDestruct(temp);
      return NULL;
    }
  }

  temp->numSavings = 0;

  return temp;
}

void CheckingAccountDestruct(checkingAccount *account) {
  for (int x = 0; x < MAX_SAVING_ACCOUNTS; x++) {
    SavingsAccountDestruct(account->savings[x]);
  }
  free(account);
}

int CheckingAccountDeposit(checkingAccount *account, double deposit) {
  account->balance += deposit;
  return DEPOSIT_SUCCESS;
}

int CheckingAccountWithDraw(checkingAccount *account, double withdrawAmount) {
  account->balance -= withdrawAmount;
  return WITHDRAW_SUCCESS;
}
