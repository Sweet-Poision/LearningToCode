void makeList(int len, int size, int * value, int * list) {

    /*
    PROCEDURE:
    This function makes two pinters. First pointer points to base address of frequency
    array second pointer points to the basr address of list array.
    This function iterates over the list array.
    for each iteration, it first checks if the pointer pointing at the frequency array
    has non-zero element.
        if yes, it stores array index of frequency array in the list array, 
        decrements the value at the current index of frequency array and increments both the pointers.

        else, the pointer ar frequency array is incremented.
    If the pointer for frequency array overflows, it is reset to initial position.
    */

    int i, j, k;
    for(i = 0, j = 0; i < size; ++i) {

        if(j==len) {

            j = 0;  //  resets position of j to 0 in overflow condition
        }

        if(value[j]) {

            list[i] = j+1;  //  since indexing starts from 0 we increment it by 1
            value[j]--;
            i++;
        }
    }
}


void randomize(int len, int size, int * arr) {

    int i, *arr_value, *list, sum = 0;
    char answer = 'y';

    arr_value = (int *)malloc(sizeof(int)*len); //  array for value of weightage
    list = (int *)malloc(sizeof(int)*size);     //  array for intial sequence

    // calculating and storing weightage value (number of repition of each key value)

    for(i = 0; i < len; ++i) {

        sum += arr_value[i];
    }
    if(sum != size) {

        printf("Frequency distribution error!!!\n");
        return;
    }

    // creating the initial list
    makeList(len, size, arr_value, list);

    // loop asking user's choice to print next permutation ('y' means Yes)

    do {
        // jumps to nextPermuation function (Fischer-Yates algorithm and shuffling)
        printNextPermutation(size, list);
        fflush(stdin);
        printf("\nEnter \'y\" for next permutation: ");
        scanf("%c", &answer);
    }
    while (answer=='y');
}