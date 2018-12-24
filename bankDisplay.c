#include "bankDisplay.h"
#include <stdio.h>
#include <string.h>
// TODO: Figure out the array sizes - maybe do it dynamically

void clearScreen(void) {
  printf(CLEAR_SCREEN);
}

static void centerString(char *buffer, int columnMidPoint, char *string) {
    int mid = strlen(string) / 2;
    memcpy(buffer + columnMidPoint - mid, string, strlen(string));
    return;
}

int buildHeader(char *GUI, winSize *screen, char *state) {
  char temp[1024];
  memset(temp, ' ', 1024);

  char headerState[256];
  sprintf(headerState, "%s%s", HEADER, state);

  centerString(temp, screen->ws_col/2, headerState);
  temp[0] = '*';
  temp[screen->ws_col-1] = '*';
  temp[screen->ws_col] = '\0';

  char banner[300];
  memset(banner, BANNER, screen->ws_col - 1);
  banner[0] = ' ';
  banner[screen->ws_col-1]=' ';
  banner[screen->ws_col] = '\0';

  return sprintf(GUI, PRINT_HEADER, banner, temp, banner);
}

int buildLogin(char *GUI, winSize *screen) {
  char temp[1024];
  memset(temp, ' ', screen->ws_col/3);
  temp[screen->ws_col/3] = '\0';
  return sprintf(GUI, "%s%s", temp, "User Name: ");
}

void updateScreen(displayStates state, winSize *screen) {
  static char screenOutput[4096];
  memset(screenOutput, ' ', 4096);
  screenOutput[4095] = 0;
  int index = 0;

  switch (state) {
    case overview:
      index += buildHeader(screenOutput, screen, OVERVIEW);
      break;
    case login:
      index += buildHeader(screenOutput, screen, LOGIN);
      index += buildLogin(screenOutput + index, screen);
      break;
    case checking:
      index += buildHeader(screenOutput, screen, CHECKING);
      break;
    case savings:
      index += buildHeader(screenOutput, screen, SAVINGS);
      break;
    case withdraw:
      index += buildHeader(screenOutput, screen, WITHDRAW);
      break;
    case newAccount:
      index += buildHeader(screenOutput, screen, NEW_ACCOUNT);
    default:
      break;
  }
  index = 0;

  clearScreen();
  printf("%s", screenOutput);
  return;
}
