CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99 -g
OBJECTS = SavingsAccount.o CheckingAccount.o bankDisplay.o BankAccount.o

BankAccount: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o BankAccount

BankAccount.o: BankAccount.c
	$(CC) $(CFLAGS) -c BankAccount.c

CheckingAccount.o: CheckingAccount.c
	$(CC) $(CFLAGS) -c CheckingAccount.c

SavingsAccount.o: SavingsAccount.c
	$(CC) $(CFLAGS) -c SavingsAccount.c

bankDisplay.o: bankDisplay.c
	$(CC) $(CFLAGS) -c bankDisplay.c

.Phony: clean
clean:
	rm -f $(OBJECTS) BankAccount
