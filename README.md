# Circular Buffer Program
This is a C program that implements a circular buffer. It includes a main function that interacts with the user through the console to allow the user to perform various operations on the buffer.

## Usage
The program requires a circular_buffer.h header file, which is included in the program.

To run the program, compile the C code and then run the resulting executable file. The program will prompt the user to enter the buffer size. The user must enter a positive integer value.

If the buffer was created successfully, the program should loop and prompt the user to select an operation:

0 - Terminate the program.

1 - Add an element to the buffer. The program prompts the user to enter a value to be added to the buffer.

2 - Retrieve the most recently added element from the buffer. The program should display the value of the retrieved element. If the buffer is empty, the program should display the message "Buffer is empty."

3 - Retrieve the earliest added element from the buffer. The program should display the value of the retrieved element. If the buffer is empty, the program should display the message "Buffer is empty."

4 - Display the entire contents of the buffer. If the buffer is empty, the program should display the message "Buffer is empty."

5 - Check if the buffer is empty. The program should display:

1 if the buffer is empty, or
0 otherwise.

6 - Check if the buffer is full. The program should display:

1 if the buffer is full, or
0 otherwise.

If an invalid operation is selected, the program should display the message "Incorrect input data" and continue running.
## Functionality
The program implements the following functions:

circular_buffer_create_struct: creates a new circular buffer with the specified size.

circular_buffer_destroy_struct: frees the memory allocated for a circular buffer.

circular_buffer_push_back: adds an integer to the back of the buffer.

circular_buffer_pop_back: removes an integer from the back of the buffer and returns it.

circular_buffer_pop_front: removes an integer from the front of the buffer and returns it.

circular_buffer_empty: checks if the buffer is empty.

circular_buffer_full: checks if the buffer is full.

circular_buffer_display: displays the contents of the buffer.

## Error Handling
The program includes some basic error handling to prevent incorrect user input. If the user enters an invalid command or an incorrect input value, the program will print an error message and prompt the user to try again. If the program is unable to allocate memory for the buffer, it will print an error message and exit.
