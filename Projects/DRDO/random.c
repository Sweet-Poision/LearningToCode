void swap(int * a, int * b) {
    
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}


void shuffle(int * list, int size) {

    /*
    PROCEDURE:
    Swapping elements after selecting two random indices random number of times. Random
    number will always be less than size of the list
    */

    int i, a, b, n;

    n = rand() % size;

    for(i = 0; i < n; ++i) {
        a = rand() % size;  //  selecting first random index
        b = rand() % size;  //  selecting second random index
        swap(&list[a], &list[b]);   //  swapping the elements at selected indices
    }
}

void printNextPermutation(int size, int * list) {

    /*
    PROCEDURE:
    Makes a list of same size as of permutated array and initializes it with -1.
    Iterates over the original array and find a random position in the newly created list for
    each index of original array and places the elements therre and finally prints the list aftet shuffling
    */

    int *newList, i, b, j;
    newList = (int *)malloc(sizeof(int)*size);
    for(i = 0; i < size; ++i) {

        newList[i] = -1;
    }

    srand(time(0));
    for(i = size-1; i < size; --i) {
        b = rand() % size;
        
        //  finding a new position if the position is already occupied
        while(newList[b] != -1) {

            b = rand() % size;
        }

        newList[b] = list[i];
    }

    //  for shuffling
    shuffle(newList, size);

    // prints the list
    for( i = 0; i < size; ++i) {

        printf("%d ", newList[i]);
    }

    printf("\n");

    // visually appealing code just for fun
    Sleep(2000);
    CLEAR_SCREEN;
    printf("Radar Jamming intitializing");

    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 5; ++j) {
            Sleep(100);
            printf(".");
        }
        CLEAR_SCREEN;
    }
    //  fun stuff ends here

    //  sends as radar
    radar_jam(list, size);
}

