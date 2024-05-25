/*   === Various Ways to Create A String in C Language ===
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    /* VARIABLES IN STACK REGION */
    char a[] = "Strawberry Family";  // stored in stack
    char b[20] = "Strawberry Family";
    char c[] = {'S','t','r','a','w','b','e','r','r','y',' ','F','a','m','i','l','y','\0'};
    char d[18] = {'S','t','r','a','w','b','e','r','r','y',' ','F','a','m','i','l','y','\0'};
    
    /* VARIABLES IN STATIC CODE REGION (String Literal Pool)
     * Note that this region of memory is read-only.
     * */ 
    char *e = "Strawberry Family"; 

    /* VARIABLES IN HEAP REGION */
    char *f = malloc(sizeof(char)*18);
    strcpy(f, "Strawberry Family");


    printf("%s\n%s\n%s\n%s\n%s\n",a,b,c,d,e);


    a[2] = 'R';
    *(e+2)='R';
    printf("%s\n%s\n%s\n%s\n%s\n",a,b,c,d,e);

    return 0;
}
