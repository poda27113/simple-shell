#include "main.h"

/* Concatenate the message for cd error*/
char *strcat_cd(const char *command, int line_count, const char *arg) {
	    char *error_msg;
	        int length = strlen(command) + 12 + strlen(arg) + 1;

		    error_msg = (char *)malloc(length);
		        if (error_msg == NULL) {
				        fprintf(stderr, "Memory allocation error\n");
					        exit(EXIT_FAILURE);
						    }

			    snprintf(error_msg, length, "%s: %d: can't cd to %s", command, line_count, arg);
			        return (error_msg);
}

int main() {
	    /*Sample usage of error handling functions*/
	    const char *command = "sample_command";
	        int line_count = 10;
		    const char *arg = "example_argument";

		        char *error_msg_cd = strcat_cd(command, line_count, arg);
			    printf("%s\n", error_msg_cd);
			        free(error_msg_cd);

				    char *error_msg_not_found = error_get_cd(command, line_count, arg);
				        printf("%s\n", error_msg_not_found);
					    free(error_msg_not_found);


					        char *error_msg_exit = error_exit_shell(command, line_count, arg);
						    printf("%s\n", error_msg_exit);
						        free(error_msg_exit);

							    return (0);
}


/* Error message for "cd" command*/
char *error_get_cd(const char *command, int line_count, const char *arg) {
	    char *error_msg;
	        int length = strlen(command) + 15 + strlen(arg) + 1;

		    error_msg = (char *)malloc(length);
		        if (error_msg == NULL) {
				        fprintf(stderr, "Memory allocation error\n");
					        exit(EXIT_FAILURE);
						    }

			    snprintf(error_msg, length, "%s: %d: %s: not found", command, line_count, arg);
			        return (error_msg);
}


/* Error message for "exit" command*/
char *error_exit_shell(const char *command, int line_count, const char *arg) {
	    char *error_msg;
	        int length = strlen(command) + 21 + strlen(arg) + 1;

		    error_msg = (char *)malloc(length);
		        if (error_msg == NULL) {
				        fprintf(stderr, "Memory allocation error\n");
					        exit(EXIT_FAILURE);
						    }

			    snprintf(error_msg, length, "%s: %d: %s: Illegal number: %s", command, line_count, command, arg);
			        return (error_msg);
}

/* Error message for command not found*/
char *error_not_found(const char *command, int line_count, const char *arg) {
	    char *error_msg;
	        int length = strlen(command) + 21 + strlen(arg) + 1;

		    error_msg = (char *)malloc(length);
		        if (error_msg == NULL) {
				        fprintf(stderr, "Memory allocation error\n");
					        exit(EXIT_FAILURE);
						    }

			    snprintf(error_msg, length, "%s: %d: %s: Illegal number: %s", command, line_count, command, arg);
			        return (error_msg);
}
