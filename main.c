#include <stdio.h>
#include "circular_buffer.h"

int main() {
    int size;

    printf("Buffer size:");
    if (scanf("%d", &size) != 1) {
        printf("Incorrect input");
        return 1;
    }

    if (size <= 0) {
        printf("Incorrect input data");
        return 2;
    }
    struct circular_buffer_t *bufptr;
    int err = circular_buffer_create_struct(&bufptr, size);
    if (err == 2) {
        printf("Failed to allocate memory");
        return 8;
    }

    while (1) {
        int choice;
        printf("What would you like to do?");
        if (scanf("%d", &choice) != 1) {
            printf("Incorrect input");
            circular_buffer_destroy_struct(&bufptr);
            return 1;
        }
        if (choice < 0 || choice > 6) {
            printf("Incorrect input data\n");
        }
        if (choice == 0) {
            circular_buffer_destroy_struct(&bufptr);
            return 0;
        }
        if (choice == 1) {
            int num;
            printf("Give a number:");
            if (scanf("%d", &num) != 1) {
                printf("Incorrect input");
                circular_buffer_destroy_struct(&bufptr);
                return 1;
            }

            circular_buffer_push_back(bufptr, num);
        }
        if (choice == 2) {
            int err1;
            int num = circular_buffer_pop_back(bufptr, &err1);
            if (err1 == 2) {
                printf("Buffer is empty\n");

            } else {
                printf("%d\n", num);
            }
        }
        if (choice == 3) {
            int err1;
            int num = circular_buffer_pop_front(bufptr, &err1);
            if (err1 == 2) {
                printf("Buffer is empty\n");

            } else {
                printf("%d\n", num);
            }
        }
        if (choice == 4) {
            if (circular_buffer_empty(bufptr) == 1) {
                printf("Buffer is empty\n");
            } else {
                circular_buffer_display(bufptr);
            }
        }
        if (choice == 5) {
            printf("%d\n", circular_buffer_empty(bufptr));
        }
        if (choice == 6) {
            printf("%d\n", circular_buffer_full(bufptr));
        }

    }
}
