/*

  LAB PROGRAM 10

  Given a File of N employee records with a set K of Keys(4-
  digit) which uniquely determine the records in file F.
  Assume that file F is maintained in memory by a Hash
  Table (HT) of m memory locations with L as the set of
  memory addresses (2-digit) of locations in HT. Let the keys
  in K and addresses in L are integers.
  Design and develop a Program in C that uses Hash
  function H: K -> L as H(K)=K mod m (remainder method),
  and implement hashing technique to map a given key K to
  the address space L.
  Resolve the collision (if any) using linear probing.

*/

#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

/* Hash function */
int hashFunction(int key) { return key % m; }

/* Insert key using Linear Probing */
void insert(int key) {
  int index = hashFunction(key);
  int startIndex = index;

  while (hashTable[index] != -1) {
    index = (index + 1) % m;

    if (index == startIndex) {
      printf("Hash table is full. Cannot insert %d\n", key);
      return;
    }
  }

  hashTable[index] = key;
  printf("Key %d inserted at address %d\n", key, index);
}

/* Display Hash Table */
void display() {
  printf("\nHash Table Contents:\n");
  for (int i = 0; i < m; i++) {
    if (hashTable[i] == -1)
      printf("HT[%d] : EMPTY\n", i);
    else
      printf("HT[%d] : %d\n", i, hashTable[i]);
  }
}

int main() {
  int n, key;

  printf("Enter size of hash table (m): ");
  scanf("%d", &m);

  /* Initialize hash table */
  for (int i = 0; i < m; i++) {
    hashTable[i] = -1;
  }

  printf("Enter number of employee records: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter 4-digit employee key: ");
    scanf("%d", &key);
    insert(key);
  }

  display();
  return 0;
}

/*

  OUTPUT

  Enter size of hash table (m): 10
  Enter number of employee records: 5
  Enter 4-digit employee key: 1234
  Key 1234 inserted at address 4
  Enter 4-digit employee key: 2345
  Key 2345 inserted at address 5
  Enter 4-digit employee key: 3456
  Key 3456 inserted at address 6
  Enter 4-digit employee key: 4567
  Key 4567 inserted at address 7
  Enter 4-digit employee key: 5678
  Key 5678 inserted at address 8

  Hash Table Contents:
  HT[0] : EMPTY
  HT[1] : EMPTY
  HT[2] : EMPTY
  HT[3] : EMPTY
  HT[4] : 1234
  HT[5] : 2345
  HT[6] : 3456
  HT[7] : 4567
  HT[8] : 5678
  HT[9] : EMPTY

*/
