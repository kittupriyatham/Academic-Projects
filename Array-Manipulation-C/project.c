#include<stdio.h>
#include<stdlib.h>

// Global array to be used throughout the program
int arr[100];

// Function prototypes
void menu();
int insert(int *n);
int Delete(int *n);
int searching(int n);
int sorting(int n);
void clear_screen();
void display_array(int n);
void add_array_elements(int *n);

int main ()
{
    int c, s, n = 0;

    while (1)
    {
        menu();
        scanf("%d", &c);

        switch (c)
        {
            case 1: add_array_elements(&n);
                break;
            case 2: insert(&n);
                break;
            case 3: Delete(&n);
                break;
            case 4: searching(n);
                break;
            case 5: sorting(n);
                break;
            case 6: display_array(n);
                break;
            case 7: clear_screen();
                break;
            case 8: exit(1);
                break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
// Function to display menu.
void menu()
{
    printf("Enter choice\n");
    printf("1. Fill Array\n");
    printf("2. Insert\n");
    printf("3. Delete\n");
    printf("4. Search\n");
    printf("5. Sort\n");
    printf("6. Display array\n");
    printf("7. Clear screen\n");
    printf("8. Exit\n");
}
// Function to insert an element into the array
int insert(int *n)
{
    int p, i, k, x;

    printf("Enter the location where you wish to insert an element\n");
    scanf("%d", &p);

    if (p <= 0 || p > *n + 1) {
        printf("Invalid location. Please enter a location between 1 and %d.\n", *n + 1);
        return -1;
    }

    printf("Enter the value to insert\n");
    scanf("%d", &x);

    for (k = *n - 1; k >= p - 1; k--)
        arr[k + 1] = arr[k];

    arr[p - 1] = x;
    (*n)++;

    printf("Resultant array is\n");
    display_array(*n);

    return 0;
}

// Function to delete an element from the array
int Delete(int *n)
{
    int p, k;

    printf("Enter the location where you wish to delete element\n");
    scanf("%d", &p);

    if (p <= 0 || p > *n) {
        printf("Invalid location. Please enter a location between 1 and %d.\n", *n);
        return -1;
    }

    for (k = p - 1; k < *n - 1; k++)
        arr[k] = arr[k + 1];

    (*n)--;

    printf("Resultant array:\n");
    display_array(*n);

    return 0;
}

// Function to search for an element in the array
int searching(int n)
{
    int i, num, pos, found = 0;

    printf("Enter the number to be searched\n");
    scanf("%d", &num);

    for (i = 0; i < n; i++) {
        if (arr[i] == num) {
            found = 1;
            pos = i;
            printf("%d is found in array at position %d\n", num, i + 1);
            break;
        }
    }

    if (!found)
        printf("%d doesn't exist in array\n", num);

    return 0;
}

// Function to sort the array in ascending order
int sorting(int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("The array sorted in ascending order is:\n");
    display_array(n);

    return 0;
}

// Function to clear the screen in a platform-independent way
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
//menu();
}

// Function to display the array
void display_array(int n)
{
    if (n == 0)
        printf("there are no elements in the array");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to get user input for the array
void add_array_elements(int *n)
{
    printf("Enter number of elements in array\n");
    scanf("%d", n);

    if (*n <= 0 || *n > 100) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return;
    }

    printf("Enter %d elements\n", *n);
    for (int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}
