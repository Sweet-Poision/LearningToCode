int TECHNIQUES[4] = {32, 8, 16, 8}; //  count of each technique
int CURRENT;    //  stores technique id for each thread

//  Thread Function
DWORD WINAPI jam(LPVOID lpParam) {

    int cur;
    cur = CURRENT;  //  saves technique id for future use
    TECHNIQUES[arr-1]--;    // decrementing count of respective technique by 1 since it will be alloted
    Sleep(5);   //  waits for interval of pulse_width
    TECHNIQUES[arr-1]++;    //  increments the technique as the radar jamming technique will be free
    return 0;
}


void radar_jam(int * arr, int len) {

    int i, j;
    HANDLE * array;
    DWORD id;
    // since each thread requires to be closed therefore we need to store "len" amount of thread
    // ids in an arrray

    array = (HANDLE*)malloc(len*sizeof(HANDLE));

    // printing current radar array
    printf("Radar: \n");
    for(i = 0; i < len; ++i) {

        printf("%d ", arr[i]);
    }
    printf("\n");

    // loop to create thread for each array element
    for(i = 0; i < len; ++i) {

        // checks if jamming technique is available for the current radar
        if(TECHNIQUES[arr[i]-1] > 0) {

            // if yes then thread is created
            CURRENT = arr[i];
            // since we don't know how to pass parameter in thread function, we will assign the
            // value to a global variable

            array[i] = CreateThread(NULL, 0, jam, 0, 0, &id);
        }
        else {

            // if no we print the statement below
            printf("No %d radar technique free for radar #%d\n", arr[i], i+1);
        }
    }
    // joining the thread
    WaitForMultipleObjects(len, aray, TRUE, INFINTE);
    for(i = 0; i < len; ++i) {

        CloseHandle(array[i]);
    }
    system("PAUSE");
}