#ifndef BANK_DISPLAY
#define BANK_DISPLAY

#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <sys/ioctl.h> // Needed for getting the size of the terminal

#define BANNER '*'
// #define BANNER_LENGTH 60
#define PRINT_HEADER "%s\n%s\n%s\n"
#define PADDING " "
#define HEADER "Bank Account Manager - "
#define OVERVIEW "Overview"
#define LOGIN "Login"
#define DEPOSIT "Deposit Into "
#define WITHDRAW "Withdraw"
#define CHECKING "Checking"
#define SAVINGS "Savings"
#define NEW_ACCOUNT "New Account"
#define CLEAR_SCREEN "\033\143"

typedef enum displayStates {overview, login, checking, savings, withdraw, newAccount, quit} displayStates;
typedef struct winsize winSize;

void clearScreen(void);

// Returns the size of the header
int buildHeader(char *, winSize *, char *);

<<<<<<< HEAD:include/bankDisplay.h
int buildLogin(char *);

int buildOverview(char *);

void updateScreen(displayStates, checkingAccount *);
=======
int buildLogin(char *, winSize *);

int buildOverview(char *, winSize *, checkingAccount *);

void printOverviewOptions();

void updateScreen(displayStates, winSize *, checkingAccount *);
>>>>>>> 33df31c6e8d84d2181510e993288c7f2d32766f7:bankDisplay.h

#endif
