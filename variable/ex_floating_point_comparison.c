/* === Example of floeating-point comparison ===
 * The float type data is converted to a double type data.
 * And warning shows that "floating-point comparison is 
 * always false."
 * */

#include <stdio.h>

int main(){
	float f = 0.1;
	if (f == 0.1)
		printf("True\n");
	else
		printf("False\n");
}
