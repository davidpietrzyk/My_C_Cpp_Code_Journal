/////////////////////////////////////////////////////
/// File Name: clearinputstream.c
/// Purpose: Investigate clearing input stream in C
/// Author: David Pietrzyk
/// Date Created {YYYY/MM/DD}: 2026/02/08
/// Last Modified {YYYY/MM/DD}: 2026/02/08
///
/// Comments:   I don't understand what fflush 
///             does apparently
/////////////////////////////////////////////////////

#include <stdio.h> // include Standard Input/Output
#include <stdlib.h> // for use of system()

// function prototype
void Menu(); // Show menu

// main function
int main()
{
	char command = 'a'; // make a char variable for user input

	while(command != 'Q') // only exit loop if character input is 'Q' 
	{		
        Menu(); // Show menu
		command = getchar(); // get user input (only obtain first character)

		// this does nothing....
		fflush(stdin); // flush input buffer of any other characters or newline escape character ("\n")
                       // no? is that not right?

		// fflush(stdin) is not formally defined commonly... 

		//* USE THIS INSTEAD */
		// Read characters one by one until a newline or EOF is found
		int c;
    	while ((c = getchar()) != '\n' && c != EOF);

		if(command == '<') // if user selects left arrow command
		{
			printf("left arrow\n\n");
		}
		else if(command == '>') // if user selects left arrow command
		{
			printf("right arrow\n\n");
		}
		else
		{
			// system("cls");  // else, invalid input, clear the screen (seems to be very aggressive)
                            // would have to look into other methods
		}
	}
	
	return 0; // return 0 if program is successful
}

void Menu()
{
    // print simple menu using printf statements
	printf("Press < for Rotation Leftward \n");
	printf("Press > for Rotatin Rightward \n");
	printf("Press Q to Quit (Case Sensitive) \n\n");
	printf("Type your command here: ");  // prompt user
}