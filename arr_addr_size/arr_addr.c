#include <stdio.h>

int main()
{
/*    long unsigned int arr[5] = {0x10, 0x20, 0x30, 0x40, 0x50};

    printf ("%l %ll \n", arr, &arr);
    printf ("%ul %ul \n", arr+1, &arr+1);

    printf ("%d %d \n", arr, *arr);
    printf ("%d %d \n", arr+1, *arr+1);

    return 0;
*/
    int arr[5] = {0x10, 0x20, 0x30, 0x40, 0x50};
    int i;

    printf("%u %u\n", arr, &arr); //print what is "arr" and print address of arr
    for (i = 0; i < 5; i++) {
        printf("%lu %u\n", arr + i, &arr + i); //do the above but increment by 1
    }

    printf("%d %d\n", arr, *arr); //print value of arr and value of arr[i]
    for (i = 0; i < 5; i++) {
        printf("%d %d\n", arr + i, *(arr + i)); //print value of arr[i] and value of arr[i]
    }
    
    return 0;
}