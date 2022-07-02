#ifndef _RADAR_H_
#define _RADAR_H_

//  allocates memory to the arrays and calls the next permutation function
void randomize(int len, int size, int * arr);   

//  makes original array with calculated data frequency
void makelist(int len, int size, int * value, int * list);

//  Implements Fischer-Yates algorithm and shuffles the list
void printNextPermutation(int size, int * list);

void shuffle(int * list, int size);

void swap(int * a, int * b);

//  threading
DWORD WINAPI jam(LPVOID lpParam);


#endif 