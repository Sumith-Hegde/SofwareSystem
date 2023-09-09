/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description : Write a program to execute an executable program.
 a. use some executable program
 b. pass some input to an executable program. (for example execute an executable of $./a.out name)
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main()
{
	char* arg[]={"/home/sumithhegde/SoftwareSystem/LabExercises/fileInfo","/home/sumithhegde/order.cpp",NULL};
	execv("/home/sumithhegde/SoftwareSystem/LabExercises/fileInfo",arg);
//	execlp("fileInfo","fileInfo","/home/sumithhegde/order.cpp",NULL);
	return 0;
}
