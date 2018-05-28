#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "account.h"
#include "SavingsAccount.h"

struct savingsAccount_t {
  char name[ACCOUNT_NAME_LENGTH];
  double saved;
  double goal;
  double savingPercentage;
};

// precondition - name must be the proper length;
savingsAccount* SavingsAccountInit(int goal, char * name, double percent) {
  savingsAccount * temp = calloc(1, sizeof(savingsAccount));
  if (temp == NULL) {
    return NULL;
  }

  if (memcpy(temp->name, name, strlen(name)) == NULL) {
    SavingsAccountDestruct(temp);
    return NULL;
  }

  temp->saved = 0.0;
  temp->goal = goal;
  temp->savingPercentage = percent;

  return temp;
}

void SavingsAccountDestruct(savingsAccount *account) {
  free(account);
}

// return the amount of money left over from a deposit
// a return value of -1 means the goal has not been met yet
double SavingsAccountDeposit(savingsAccount *account, double deposit) {
  double leftOver = SavingsAccountRemaining(account) - deposit;
  if (leftOver <= 0) {
    account->saved += deposit + leftOver;
    return -leftOver;
  } else {
    account->saved += deposit;
    return -1;
  }
}

void SavingsAccountPrintName(savingsAccount *account) {
  printf("Savings Account: %s\n", account->name);
}

static void printEverything(savingsAccount *account) {
  SavingsAccountPrintName(account);
  printf("Amount Saved: %.2f\n", account->saved);
  printf("Goal Amount: %.2f\n", account->goal);
  printf("Percent: %.2f\n\n", account->savingPercentage);
}

double SavingsAccountRemaining(savingsAccount *account) {
  return account->goal - account->saved;
}

int main(void) {
  savingsAccount *temp = SavingsAccountInit(500, "Gabe's Account", 0.25);
  printEverything(temp);

  SavingsAccountDeposit(temp, 485);
  printEverything(temp);

  printf("Left Over: %d\n", SavingsAccountDeposit(temp, 15) == 0);
  printEverything(temp);

  SavingsAccountDestruct(temp);
  return 0;
}
