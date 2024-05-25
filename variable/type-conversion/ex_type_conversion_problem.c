/* === Example of Type Conversions: Implicit Type Conversions ===
 * If more than one data type are present in an expression, type
 * conversion will be executed automatically to avoid loss of data,
 * where the "smaller" data type will be converted to the "larger"
 * one.
 *
 * The types with size from small to large are sorted as
 * bool -> char -> short int -> int -> unsigned int -> long -> 
 * unsigned long -> long long -> float -> double -> long double.
 * 
 * Detail info refers to GNU C Language Manual / Type Conversions.
 * ---
 * "sizeof()" operator returns a result of type "size_t", which is
 * the unsigned integer type. When sizeof() is compared with -1,
 * the signed integer -1 will be converted into unsigned integer as
 * (assume 2's complement is used for storing data)
 *     signed integer -1: 1111 1111 1111 1111
 *     unsigned integer -1 -> 65535
 * Therefore, sizeof(int) must be less than 65535. The condition in
 * if statement is false.
 * */
#include <stdio.h>
int main(){
	if (sizeof(int) > -1)
        	printf("True\n");
	else
		printf("False\n");
}
