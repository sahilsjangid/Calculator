// including important libraries
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

// main function takes command line arguments for numbers and oprands
int main(int argc, char *argv[])
{
    // must be atleast 4 arguments (./a.out (number) (oprand) (number))
    // ./a.out 1 + 2
    if (argc <= 3){
        // tell user how to use it
        printf("Use: ./a.out (int) (arithmetic oprand) (int)\n");
        // return 1 as exit code
        return 1;
    }
   
    // if command line arguments ends with any oprand, then return error and tell user   
    if (*argv[argc - 1] == '+' || *argv[argc - 1] == '-' || *argv[argc - 1] == '*' || *argv[argc - 1] == '/'){
        // error massage
        printf("Arguments Should not end with Arithmetic oprand(+,-,x(alphabatic x for product),/)\n");
        // error code
        return 2;
    }

    // if any oprands does not support
    for (int i = 2; i <= (argc - 2); i += 2){
        printf("%d\n", i);
        printf("argv[%i]: %s\n", i, argv[i]);
        if (argv[i][0] != '+' && argv[i][0] != '-' && argv[i][0] != 'x' && argv[i][0] != '/'){
            // error massage
            printf("oprands must be from (+, -, x, /)\n");
            // error code
            return 3;
        }
    }
    
    
    // we will create two different arrays
    // one contain all numbers, other contain all operators
    int num_count = argc / 2;           
    double numbers[num_count];          
    char operators[num_count - 1];

    for (int i = 1, n = 0, o = 0; i < argc; i++){
        // if argv[i] a digit then it goes into numbers else if it is an oprand, it goes into operators
        if (i % 2 == 1){
            // using atof() function, we can change digit charactor to a number
            numbers[n] = atof(argv[i]);
            n++;
        }

        else {
            operators[o] = argv[i][0];
            o++;
        }
    }

    // printf("[");
    // for (int i = 0; i < num_count; i++){
    //     if (i == num_count - 1){
    //         printf("%f", numbers[i]);
    //     }
    //     else {
    //         printf("%f, ", numbers[i]);
    //     }
    // }
    // printf("]\n");

}
