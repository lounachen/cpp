#include <stdio.h>

int main(){
	printf("Please Enter a Character : ");
//	getchar();
	char a;
	scanf("%c", &a);
	
	printf("Please Enter an Integer Value : ");
	int b;
	scanf("%d", &b);
	
	printf("Please Enter Float Value : ");
	float c;
	scanf("%e", &c);
	
	printf("The variables you entered were: \n");
	printf("The Character value that you Entered is : %c", a);
	printf("\nThe Integer value that you Entered is : %d\n", b);
	printf("The Float value that you Entered is : %f\n", c);
	
} 
