/* === sizeof() operator ===
 * There is one important thing for sizeof() that is the expression inside sizeof()
 * is not variable length array (VLA), the expression will not evaluated and the
 * result is determined at the compiling time. Otherwise, it will determine in the
 * runtime and returns the true size of the VLA.
 *
 * The clangd language server shows waring about expression
 * inside sizeof() will not be evaluated.
 * */

#include <stdio.h>

int main(){
	int a,b=1, c=1;
	a=sizeof(c=++b+1); //c=++b+1 is not evalued
	printf("a=%d, b=%d, c=%d\n",a,b,c); // a=4,b=1,c=1
}
