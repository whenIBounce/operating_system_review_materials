#include <stdlib.h>
#include <stdio.h>
int main(){
    /* 
    This invocation of malloc() uses the
    sizeof() operator to request the right amount of space; in C, this is
    generally thought of as a compile-time operator, meaning that the actual
    size is known at compile time and thus a number (in this case, 8, for a
    double) is substituted as the argument to malloc().
    */
    int *x = malloc(10*sizeof(int)); //How does both stack and heap allocation occur? 
    printf("%d\n", sizeof(*x)); //What does this line return? (dunno yet)
    printf("%d\n", sizeof(x)); //What does this line return?

    /* In this case, there is enough static information for the compiler*/
    int y[10];
    printf("%d\n", sizeof(y));  //What does this line return?

    *x = &y;
    free(x);

    /* 
    In some cases, it may seem like not calling free() is reasonable. 
    
    For example, your program is short-lived, and will soon exit; in this case,
    when the process dies, the OS will clean up all of its allocated pages and
    thus no memory leak will take place per se. 
    
    While this certainly “works”, it is probably a bad habit to develop, so be wary
    of choosing such a strategy. 
    
    In the long run, one of your goals as a programmer is to develop good habits; 
    one of those habits is understanding how you are managing memory, 
    and (in languages like C), freeing the blocks you have allocated. 
    
    Even if you can get away with not doing so,
    it is probably good to get in the habit of freeing each and every byte you
    explicitly allocate.
    */
}