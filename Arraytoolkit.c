#include <stdio.h>

int userChoice() {
     
    int choice = -1;

    do {
        printf("\n*** Array Tool Kit ***\n\n");
        printf("0. Display Array\n");
        printf("1. Calculate Sum\n");
        printf("2. Calculate Average\n");
        printf("3. Find Maximum and Minimum element\n");
        printf("4. Count odd and even elements\n");
        printf("5. Search element\n");
        printf("6. Sort array in ascending order\n");
        printf("7. Sort array in descending order\n");
        printf("8. Insert element\n");
        printf("9. Delete element\n");
        printf("10. Exit the program.\n\n");
        printf("Enter your choice : ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Enter correct choice.\n");
            while (getchar() != '\n');
            choice = -1;
        }

    } while (choice < 0 || choice > 10);

    return choice;

}

void displayArray(int arr[], int size) {
    printf("Array : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int sum(int arr[], int size) {

    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("Total sum : %d\n", sum);
    return sum;

}

void average(int arr[], int size) {
   
    int sum = 0;

    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    double avg = (double)sum / size;
    printf("Average : %.2f\n", avg);
    
}

void findMinMax(int arr[], int size) {

    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < size; i++) {
        
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }

    }

    printf("Minimum element : %d\n", min);
    printf("Maximum element : %d", max);

}

void countOddEven(int arr[], int size) {

    int total_odd = 0;
    int total_even = 0;

    for(int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            total_even++;
        } else {
            total_odd++;
        }
    }

    printf("Total odds : %d\n", total_odd);
    printf("Total even : %d", total_even);

}

int linearSearch(int arr[],int size, int target) {

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;

}

void searchElement(int arr[], int size) {

    printf("Enter element to search: ");
    int search_element;
    if (scanf("%d", &search_element) != 1) {
        printf("Invalid input! Enter correct value.");
        while (getchar() != '\n');
        return;
    }
    
    int index; 
    index = linearSearch(arr, size, search_element);

    if(index != -1) {
        printf("Element %d found at index %d.\n", search_element, index);
    } else {
        printf("Element %d not found in the array.", search_element);
    }

}

void sortArrayAscending(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    displayArray(arr, size);

}

void sortArrayDescending(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    displayArray(arr, size);

}

int insertElement(int arr[], int size) {
    
    if (size >= 100) {
        printf("Array is already full.");
        return size;
    }

    int element;
    int position;

    printf("\nEnter element and position : ");
    if (scanf("%d", &element) != 1 || scanf("%d", &position) != 1) {
        printf("Invalid input! Enter correct value.");
        while (getchar() != '\n');
        return size;
    }

    int index = position - 1;
    if (index < 0 || index > size) {
        printf("Invalid insertion!");
        return size;
    }

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = element;
    size++;

    printf("Numbers after inserting : ");

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return size;

}

int deleteElement(int arr[], int size) {

    int position;
   

    if (size <= 0) {
        printf("Array is empty. Nothing to delete.\n");
        return size;
    }

    printf("Enter position to delete (1 to %d): ", size);

    if (scanf("%d", &position) != 1) {
        printf("Invalid input!\n");

        while ((getchar()) != '\n');

        return size;
    }

    int index = position - 1;

    if (position < 1 || position > size) {
        printf("Invalid deletion position.\n");
        return size;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    printf("Resultant array is:\n");

    for (int j = 0; j < size; j++) {
        printf("%d ", arr[j]);
    }

    printf("\n");

    return size;
}

int main() {

    int size;
    int choice;

    printf("\nEnter size of the array : ");
    if (scanf("%d", &size) != 1 || size < 1 || size > 100) {
        printf("Invalid size! Enter a number between 1 and 100.\n");
        return 1;
    }

    int arr[100];

    for (int i = 0; i < size; i++) {
        printf("Enter array elements : ");
        scanf("%d", &arr[i]);
    }

    do {

        choice = userChoice();

        switch (choice)
        {
        
        case 0: 
            displayArray(arr, size);
            break;
        
        case 1: 
            sum(arr, size);
            break;
        
        case 2:
            average(arr, size);
            break;
        
        case 3:
            findMinMax(arr, size);
            break;

        case 4:
            countOddEven(arr, size);
            break;

        case 5:
            searchElement(arr, size);
            break;
        
        case 6:
            sortArrayAscending(arr, size);
            break;
        
        case 7:
            sortArrayDescending(arr, size);
            break;
            
        case 8:
            size = insertElement(arr, size);
            break;
        
        case 9:
            size = deleteElement(arr, size);
            break;

        case 10:
            printf("Exiting Array Toolkit...\n");
            break;
        }

    } while (choice != 10);

    return 0;
}