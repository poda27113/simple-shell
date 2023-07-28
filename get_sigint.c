#include "main.h"

/**
 *  * get_sigint - Handle the ctrl + c call in the prompt
 *   * @sig: Signal handler
 *    */
void get_sigint(int sig)
{
	    (void)sig; /* Unused parameter*/
	        write(STDOUT_FILENO, "\n^-^ ", 5);
}

int main()
{
	/* Declare variables before the code block*/
	    int loop = 1;
	        char buffer[100];

	    /* Register the signal handler*/
	    signal(SIGINT, get_sigint);
        /* Your code can go here*/
		        while (loop)
				    {
					            printf("Type something: ");
						            fflush(stdout);

							            /* Use the declared buffer*/
							            if (fgets(buffer, sizeof(buffer), stdin) != NULL)
									            {
											                /* Do something with the input
													 *              Here, we'll just print it back*/
											                printf("You typed: %s", buffer);
													        }
								            else
										            {
												                loop = 0;
														        }
									        }

			    return (0);
}
