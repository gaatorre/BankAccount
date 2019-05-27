#include "bankDisplay.h"
#include <stdio.h>
#include <string.h>

void clearScreen(void) {
  printf(CLEAR_SCREEN);
}

static void centerString(char *buffer, int columnMidPoint, char *string) {
    int mid = strlen(string) / 2;
    memcpy(buffer + columnMidPoint - mid, string, strlen(string));
    return;
}

int buildHeader(char *GUI, char *state) {
  char temp[1024];
  memset(temp, ' ', 1024);

  temp[0] = '*';
  temp[58] = '*';
  temp[59] = '\0';

  char headerState[60];
  sprintf(headerState, "%s%s", HEADER, state);

  centerString(temp, 60/2, headerState);

  return sprintf(GUI, PRINT_HEADER, BANNER, temp, BANNER);
}

int buildLogin(char *GUI) {
  return sprintf(GUI, "%s%s", PADDING, "User Name: ");
}

int buildOverview(char *GUI) {
  int runningTotal = 0;
  char[120] temp;
  sprintf(temp, "")

  runningTotal +=

  return runningTotal;
}

void updateScreen(displayStates state, checkingAccount *account) {
  static char screenOutput[4096];
  memset(screenOutput, ' ', 4096);
  screenOutput[4095] = 0;
  int index = 0;

  switch (state) {
    case overview:
      index += buildHeader(screenOutput, OVERVIEW);
      index += buildOverview();
      break;
    case login:
      index += buildHeader(screenOutput, LOGIN);
      index += buildLogin(screenOutput + index);
      break;
    case checking:
      index += buildHeader(screenOutput, CHECKING);
      break;
    case savings:
      index += buildHeader(screenOutput, SAVINGS);
      break;
    case withdraw:
      index += buildHeader(screenOutput, WITHDRAW);
      break;
    case newAccount:
      index += buildHeader(screenOutput, NEW_ACCOUNT);
    default:
      break;
  }
  index = 0;

  clearScreen();
  printf("%s", screenOutput);
  return;
}
