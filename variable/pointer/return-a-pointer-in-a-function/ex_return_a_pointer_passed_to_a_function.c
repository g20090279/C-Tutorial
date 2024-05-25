/* Two ways for a function returning an object (pointer):
 * 
 *  1. create a pointer inside the function and return it.
 *  [2]. pass a pointer to the function and return it.  
 *
 * In this file, we will analyze the second way.
 *
 * It is noted that when a pointer is passed to a function,
 * it is passed by value. In other words, it is a copy of 
 * the passed pointer. If we modify the pointer inside the
 * function, what we modify is only the copy but not the
 * original pointer.
 *
 * If you want to modify the passed pointer, you need to
 * pass the pointer to that pointer. Therefore, the value
 * of the copied pointer is the pointer we want to modify.
 * */

#include <stdio.h>
#include <stdlib.h>

void createArray(int **res, int size, int value){
    /* [CORRECT] passing a pointer to a pointer
     * The passed pointer itself is a copy. But the change
     * of the content of the passed pointer is valid.
     * */
    *res = (int*)malloc(size * sizeof(int));
    if(*res != NULL){
        for(size_t i=0; i<size; i++){
	    *(*res+i) = value+i;
	}
    }
} 

void createArray2(int *res, int size, int value){
    /* [WRONG] The pointer is passed by value. Every
     * modification of the passed value inside a function
     * is local to that copy.
     * */
    res = (int*)malloc(size * sizeof(int));
    if(res != NULL){
        for(size_t i=0; i<size; i++){
	    res[i] = value+i;
	}
    }
}

int main(){
    /* With the given size and initial integer, we want to
     * create an array of increasing integers, where the
     * first element is the initial integer, and the length
     * of the array is the size.
     * */
    int size = 5;
    int initVal = 23;

    int *res = NULL;  // the result is stored here
    int *res2 = NULL;  // the result is stored here

    printf("Pass a pointer to a pointer:\n");
    createArray(&res,size,initVal);
    for(size_t i=0; i<size; i++){
        printf("%d ", res[i]);
    }
    printf("\n");

    printf("Pass a pointer:\n");
    createArray2(&res2, size, initVal);
    for(size_t i=0; i<size; i++){
        printf("%d ", res2[i]);
    }
    printf("\n");

    return 0;
}
