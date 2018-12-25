#include "account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "bankDisplay.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

checkingAccount * CreateBankingAccount() {
  char name[ACCOUNT_NAME_LENGTH];
  char userName[ACCOUNT_NAME_LENGTH];
  double startingBalance = 0.0;
  // char password[25];

  printf("%sName: ", PADDING);
  fgets(name, ACCOUNT_NAME_LENGTH, stdin);
  name[strlen(name) - 1] = '\0';

  printf("%sUser Name: ", PADDING);
  fgets(userName, ACCOUNT_NAME_LENGTH, stdin);

  printf("%sStarting Balance: ", PADDING);
  fprintf(stdin, "%f\n", startingBalance);
  // printf("Password: ");
  // printf("Confirm Password: ");
  return CheckingAccountInit(name, startingBalance);
}

int main() {
  static displayStates state = login;
  char selection = 0;
  checkingAccount *account;
  winSize screenInfo;

  char userName[ACCOUNT_NAME_LENGTH];
  // int userInput = open();

  while(selection != 'q') {
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &screenInfo);

    updateScreen(state, &screenInfo);
    // printf("Screen size is %dx%d\n", screenInfo.ws_row, screenInfo.ws_col);
    switch (state) {
      case overview:
        break;
      case login:
        fgets(userName, ACCOUNT_NAME_LENGTH, stdin);
        userName[strlen(userName) - 1] = '\0';
        if (*userName == 0) {
          state = newAccount;
          continue;
        }
        break;
      case checking:
        break;
      case savings:
        break;
      case withdraw:
        break;
      case newAccount:
        account = CreateBankingAccount();
        if (account == NULL) {
          printf("Allocating memory for account failed.\n");
          exit(-1);
        }
        state = overview;
        break;
      default:
        break;
    }

    // selection = getchar();
    // getchar();
  }

  (void) account;
  clearScreen();
  CheckingAccountDestruct(account);
  return 0;
}
