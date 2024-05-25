#include <stdio.h>

int main() {
	printf("Memory Size of Different Data Types in This Computer (in byte)\n");
	printf("Size of %-40s: %-10zu\n","signed char",sizeof(signed char));
	printf("Size of %-40s: %-10zu\n","unsigned char",sizeof(unsigned char));
	printf("Size of %-40s: %-10zu\n","short int",sizeof(short int));
	printf("Size of %-40s: %-10zu\n","unsigned short int",sizeof(unsigned short int));
	printf("Size of %-40s: %-10zu\n","int",sizeof(int));
	printf("Size of %-40s: %-10zu\n","unsigned int",sizeof(unsigned int));
	printf("Size of %-40s: %-10zu\n","long int",sizeof(long int));
	printf("Size of %-40s: %-10zu\n","unsigned long int",sizeof(unsigned long int));
	printf("Size of %-40s: %-10zu\n","float",sizeof(float));
	printf("Size of %-40s: %-10zu\n","long long int",sizeof(long long int));
	printf("Size of %-40s: %-10zu\n","unsigned long long int",sizeof(unsigned long long int));
	printf("Size of %-40s: %-10zu\n","double",sizeof(double));
	printf("Size of %-40s: %-10zu\n","long double",sizeof(long double));
}
