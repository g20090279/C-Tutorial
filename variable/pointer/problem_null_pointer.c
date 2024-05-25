/* === Null Pointer ===
 * A `NULL` pointer points to memory that doesn't exist, can be
 * such as 0x00000000, aor any other value. This address is not
 * a real address, and therefore dereferencing it will try to
 * access an illegal memory address, which returns an error.
 * */

#include <stdio.h>

int main(){
	char *pt = NULL;
	*pt = 'A'; //error here, access null memory address
	printf("Value at address %p is %c\n", pt,*pt);
}
