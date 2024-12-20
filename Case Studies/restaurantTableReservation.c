//       ======== 2. MANAGING TABLE RESERVATION FOR A RESTAURANT ========

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_TABLES 10

typedef struct {
  int tableNumber;
  char name[50];
  bool isAvailable;
} Table;

void initializeTables(Table tables[], int size) {
  for (int i = 0; i < size; i++) {
    tables[i].tableNumber = i + 1;
    tables[i].isAvailable = true;
    strcpy(tables[i].name, "\0");
  }
}

void displayTables(Table tables[], int size) {
  printf("Table Status:\n");
  printf("---------------------------\n");
  for (int i = 0; i < size; i++) {
    printf("Table %d:\t", tables[i].tableNumber);
    if (tables[i].isAvailable == true) {
      printf("Available\n");
    } else {
      printf("Reserved by %s\n", tables[i].name);
    }
  }
}

void reserveTable(Table tables[], int size, int tableNumber, char name[]) {
  if (tableNumber > 0 && tableNumber <= size) {
    if (tables[tableNumber - 1].isAvailable) {
      tables[tableNumber - 1].isAvailable = false;
      strcpy(tables[tableNumber - 1].name, name);
      printf("Table %d has been reserved.\n", tableNumber);
    } else {
      printf("Table %d is already reserved.\n", tableNumber);
    }
  } else {
    printf("Invalid table number.\n");
  }
}

void cancelReservation(Table tables[], int size, int tableNumber) {
  if (tableNumber > 0 && tableNumber <= size) {
    if (!tables[tableNumber - 1].isAvailable) {
      tables[tableNumber - 1].isAvailable = true;
      printf("Reservation for Table %d has been canceled.\n", tableNumber);
    } else {
      printf("Table %d is not reserved.\n", tableNumber);
    }
  } else {
    printf("Invalid table number.\n");
  }
}

void changeReservation(Table tables[], int size, int oldTable, int newTable) {
  if (oldTable > 0 && oldTable <= size && newTable > 0 && newTable <= size) {
    if (!tables[oldTable - 1].isAvailable && tables[newTable - 1].isAvailable) {
      tables[oldTable - 1].isAvailable = true;
      tables[newTable - 1].isAvailable = false;
      strcpy(tables[newTable - 1].name, tables[oldTable - 1].name);
      strcpy(tables[oldTable - 1].name, "\0");
      printf("Reservation moved from Table %d to Table %d.\n", oldTable,
             newTable);
    } else if (tables[oldTable - 1].isAvailable) {
      printf("Table %d is not currently reserved.\n", oldTable);
    } else {
      printf("Table %d is not available.\n", newTable);
    }
  } else {
    printf("Invalid table numbers.\n");
  }
}

int main() {
  int choice, tableNumber, oldTable, newTable;
  char name[50];
  Table tables[MAX_TABLES];
  initializeTables(tables, MAX_TABLES);
  do {
    printf("\n=== Restaurant Reservation System ===\n1. Display Tables\n2. "
           "Reserve Table\n3. Cancel Reservation\n4. Change Reservation\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      displayTables(tables, MAX_TABLES);
      break;
    case 2:
      printf("Enter table number to reserve: ");
      scanf("%d", &tableNumber);
      printf("Enter your name: ");
      scanf(" %[^\n]", name);
      reserveTable(tables, MAX_TABLES, tableNumber, name);
      break;
    case 3:
      printf("Enter table number to cancel reservation: ");
      scanf("%d", &tableNumber);
      cancelReservation(tables, MAX_TABLES, tableNumber);
      break;
    case 4:
      printf("Enter current reserved table number: ");
      scanf("%d", &oldTable);
      printf("Enter new table number to reserve: ");
      scanf("%d", &newTable);
      changeReservation(tables, MAX_TABLES, oldTable, newTable);
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Try again.\n");
      break;
    }
  } while (choice != 5);
  return 0;
}
