This project is a demonstration of a buffer overflow attack. The project contains the following:

1) BufferOverflow.c - The source code for the program that is suspectible to a buffer overflow attack
2) AttackScript.py - A short python script that calls BufferOverflow.exe.
3) Screenshot_objdump.png -
4) Screenshot_AttackSuccess.png

To successfully carry out this attack, I compiled BufferOverflow.c and then ran the following command:

objdump -d BufferOverflow.exe

This displayed the assembler code, and memory addresses, of the program, as seen in Screenshot_objdump.png. The key addresses are:

1004010e0 (yellow underline): the location of hiddenFunction in memory, which we are trying to call via the buffer overflow attack.
10041117c (pink underline): the location in the main function that the program returns to after calling printInput.

When printInput is called, 10041117c is pushed on to the stack, and our goal in the attack is to overwrite that part of the stack with 1004010e0. Then,
instead of returning back to the main function, the program will call hiddenFunction instead.

In Screenshot_AttackSuccessful.png, the state of the stack before the attack, with 10041117c on the stack, can be seen. To carry out the attack, I used AttackScript.py to call the program with a string that would overflow its buffer and overwrite that address with the address of hiddenFunction.

When this program is recompiled and/or run on a different machine, you will need to follow the same steps to find the appropriate addresses, and modify the scriptInput variable in AttackScript.py as needed to overwrite the main return address with the address of hiddenFunction.

