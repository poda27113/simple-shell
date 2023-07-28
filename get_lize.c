#include "main.h"

/* Function prototype */

ssize_t my_getline(int fd, char **line, size_t *len, ssize_t bytes_read) {
	        char current_char;
}

/* Static buffer for reading */
static char read_buffer[READ_BUF_SIZE];
static size_t read_buffer_index = 0;
static size_t read_buffer_size = 0;

/* Custom getline function */
ssize_t my_getline(int fd, char **line, size_t *len, ssize_t bytes_read) {
	char current_char;

	    if (fd < 0 || line == NULL || len == NULL) {
		            return (-1);
			        }
}

		        while (1) {
				        /* If the read buffer is empty, read new data into it*/
				        if (read_buffer_index >= read_buffer_size) {
						            /* Fix comparison type to avoid "sign-compare" warning*/
						            if (read_buffer_index >= read_buffer_size) {
								                    read_buffer_size = read(fd, read_buffer, READ_BUF_SIZE);
										                    if (read_buffer_size <= 0) {
													                        break; /* End of file or error occurred*/
																                }
												                    read_buffer_index = 0;
														                }
							            }

					        current_char = read_buffer[read_buffer_index++];

						        /* If the current character is a newline or end of file, terminate the line*/
						        if (current_char == '\n' || current_char == EOF) {
								            (*line)[*len] = '\0';
									                return bytes_read + 1;
											        }

							        /* Check if the line buffer needs to be expanded*/
							        if (*len + 1 >= READ_BUF_SIZE) {
									            char *new_line = (char *)realloc(*line, *len + READ_BUF_SIZE);
										                if (new_line == NULL) {
													                return (-1);
															            }
												            *line = new_line;
													            }

								        (*line)[(*len)++] = current_char;
									        bytes_read++;
										    }

			    /* If we reach here, it means we have reached the end of the file*/
			    if (bytes_read > 0) {
				            (*line)[*len] = '\0'; /* Terminate the line*/
					            return bytes_read;
						        }

			        return (-1); /* No more data to read or an error occurred*/
}
