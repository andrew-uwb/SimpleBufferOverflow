//Turn off stack checking 
#pragma check_stack(off)

#include <string.h>
#include <stdio.h> 

//This function has no direct call. It's the function we will try to reach via a Buffer Overflow.
int hiddenFunction()
{
	printf("You are in the secret function!\n");
	printf("This function is never called.\n");
}

//This function prints the program's input out to the screen.
void printInput(char* progInput)
{
	//Set an 8-character string
	char outputString[8];
	
	//Display the stack contents before the attack
	printf("Stack:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");	
    
	//Copy the program input into the string (this is where the buffer overflow attack occurs)
	strcpy(outputString, progInput);
	//Output the string to the screen
	printf("The program input was %s\n", outputString);
	
	//Display the stack contents after the attack
	printf("Stack After Overflow Attack:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");	
    	
}

//Main function
int main(int argc, char* argv[])  
{  
	//Call the function to output the first program argument to the screen
	printInput(argv[1]);
	
	return 0;	
}  