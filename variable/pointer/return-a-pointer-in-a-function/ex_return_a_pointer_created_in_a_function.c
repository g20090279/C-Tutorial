/*      === Create a Pointer inside A Function and Return it ===
 * This file is to show how to return a pointer. There are mainly two ways to
 * return a pointer
 *
 *     1. create a pointer inside the called function,
 *     2. pass a pointer to the function where the pointer content can be modified.
 *
 * We fo     cus on the first type here.
 *
 * We will examine three ways to return a pointer
 *
 *     1. use "malloc" to create a pointer,
 *     2. create a local pointer variable,
 *     3. create a local but static pointer variable.
 *
 * ---
 * Zekai Liang, last revised on May 11, 2024.
 * */

#include <stdio.h>
#include <stdlib.h>

int* allocArray1(int len, int initValue){
    /* [CORRECT] 
     * Using "malloc" to allocate a memory located in the heap instead
     * of stack. Therefore, this memory pointed by this pointer will still 
     * remain in the heap and will not be deleted as the stack frame.
     * */	
    int* res = (int*)malloc(len * sizeof(int));
    if(res != NULL){
        for(size_t i=0; i<len; i++){
            res[i] = initValue++;
	}
    }
    return res;
}

int* allocArray2(int len, int initValue){
    /* [WRONG]
     * Return a pointer of an automatic variable. This leads to errors, since
     * the "local" variables are freed when the function is return and the 
     * stack frame is freed. Although the memory may be still there, it will
     * be overwritten for the next function calls.
     * */
    int res[len];
    for(size_t i=0; i<len; i++){
        res[i] = initValue++;
    }
    return res;
    /* [Clangd warning]
     * Address of stack memory associated with local variable 'res' returned. 
     * */
}

// int* allocArray3(int len, int initValue){
//     /* [WRONG]
//      * Return a pointer of an static automatic variable. This is grammarly
//      * correct. The static variable is stored in the static and global
//      * variable area (code area), and hence it is not destroyed.
//      * However, the static variable will be replaced with the new data. The
//      * memory of static variable is also fixed size.
//      * */
//     static int res[len];
//     /* [Clangd Error]
//      * Variable length array declaration cannot have "static" storage duration.
//      * */
// 
//     for(size_t i=0; i<len; i++){
//         res[i] = initValue++;
//     }
//     return res;
// }

int main(){
    int arrLen = 5;
    int arrInit = 28;

    printf("Pointer in heap:\n");
    int* res = allocArray1(arrLen, arrInit);
    for(size_t i=0; i<arrLen; i++){
        printf("%d ", res[i]);
    }
    printf("\n");

    printf("Pointer in stack:\n");
    int* res2 = allocArray2(arrLen, arrInit);
    for(size_t i=0; i<arrLen; i++){
        printf("%d ", res2[i]);
    }
    printf("\n");
}
