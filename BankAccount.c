#include "account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

#include <stdio.h>

int main() {
  checkingAccount *check = CheckingAccountInit("Gabe's Account", 0.0);
  printf("%p\n", (void *) check);
  CheckingAccountDeposit(check, 5000.10);
  // printf("After deposit: %s\n", check->name);

  CheckingAccountDestruct(check);
  return 0;
}
