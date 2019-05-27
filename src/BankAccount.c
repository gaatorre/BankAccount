#include "account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "bankDisplay.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int isValidBalance(char *balance) {
  for (int x = 0; balance[x] != '\0'; x++) {
    char num = balance[x];
    if ((num >= '0' && num <= '9') || num == '.' || num == '\n') {
      continue;
    } else {
      return 0;
    }
  }

  return 1;
}

// TODO: move the text to 2/3 of the screen
// Move to bankDisplay
checkingAccount * CreateBankingAccount() {
  char name[ACCOUNT_NAME_LENGTH];
  char userName[ACCOUNT_NAME_LENGTH];
  char balance[20];
  double startingBalance = 0.0;
  // char password[25];
  char *temp;

  printf("%sName: ", PADDING);
  fflush(stdin);
  fgets(name, ACCOUNT_NAME_LENGTH, stdin);
  name[strlen(name) - 1] = '\0';

  printf("%sUser Name: ", PADDING);
  fgets(userName, ACCOUNT_NAME_LENGTH, stdin);

  printf("%sStarting Balance: ", PADDING);
  fgets(balance, 20, stdin);
  while (!isValidBalance(balance)) {
    printf("A valid balance can only contain numbers and a decimal\n");
    printf("%sStarting Balance: ", PADDING);
    fgets(balance, 20, stdin);
  }

  startingBalance = strtof(balance, &temp);
  // printf("Password: ");
  // printf("Confirm Password: ");
  return CheckingAccountInit(name, startingBalance);
}

char getSelection(int maxOptions) {
  while (1) {
    char selection = getchar();
    if (isdigit(selection)) {
      int num = atoi(&selection);
      if (num <= maxOptions) {
        return num;
      }
    }
    while(getchar() != '\n');
    printf("    Invalid input\n");
    printf("    Please enter a valid selection\n");
    printf("    Selection: ");
  }

  return 0;
}

int main() {
  static displayStates state = login;
  char selection = 0;
  checkingAccount *account;
  winSize screenInfo;

  char userName[ACCOUNT_NAME_LENGTH];
  // int userInput = open();

  while(selection != 'q') {
<<<<<<< HEAD:src/BankAccount.c
    updateScreen(state, account);
=======
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &screenInfo);

    updateScreen(state, &screenInfo, account);
    // printf("Screen size is %dx%d\n", screenInfo.ws_row, screenInfo.ws_col);
>>>>>>> 33df31c6e8d84d2181510e993288c7f2d32766f7:BankAccount.c
    switch (state) {
      case overview:
        // Print name, total balance, uncommited money
        printOverviewOptions();
        selection = getSelection(3);
        switch (selection) {
          case 1:
            break;
          case 2:
            break;
          case 3:
            state = quit;
            break;
          default:
            break;
        }
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

    if (state == quit) {
      printf("    GoodBye!\n");
      usleep(2000000);
      break;
    }
    // selection = getchar();
    // getchar();
  }

  clearScreen();
  CheckingAccountDestruct(account);
  return 0;
}
