/*
 *
 * author name(s), date, and other info here
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "list.h"

void process_data(FILE *input_file) {
    // !! your code should start here.  the input_file parameter
    // is an already-open file.  you can read data from it using
    // the fgets() C library function.  close it with the fclose()
    // built-in function
	//1) pass pointer to a function to parse input, expect a pointer to a line in return
	//2) pass the pointer to the line which will check the data and pass it onto the list
	//		in a sorted manner, expect a pointer to the head of the list in return
	//3) call the function to print the list (pass in pointer)
	//4) call the function to print user stats (IDK what to pass in)
	//5) end function 
	struct rusage usage;
	struct timeval user_s, user_f, system_s, system_f;
	float user1, user2, system1, system2;
	getrusage(RUSAGE_SELF, &usage);
	user_s = usage.ru_utime;
	system_s = usage.ru_stime;

		get_input(input_file);

	getrusage(RUSAGE_SELF, &usage);
	user_f = usage.ru_utime;
	system_f= usage.ru_stime;
	user1= user_f.tv_sec-user_s.tv_sec;
	user2= user_f.tv_usec-user_s.tv_usec;
	system1 = (system_f.tv_sec)-(system_s.tv_sec);
	system2 = (system_f.tv_usec)-(system_s.tv_usec);

	printf("User time: %f s %f ms\n", user1, user2);
	printf("System time: %f s %f ms\n", system1, system2);
return;




}


void usage(char *program) {
    fprintf(stderr, "usage: %s [<datafile>]\n", program);
    exit(1);
}

#ifndef AUTOTEST
int main(int argc, char **argv) {
    FILE *datafile = NULL;

    /* find out how we got invoked and deal with it */
    switch (argc) {
        case 1:
            /* only one program argument (the program name) */ 
            /* just equate stdin with our datafile */
            datafile = stdin;        
            break;

        case 2:
            /* two arguments: program name and input file */
            /* open the file, assign to datafile */
            datafile = fopen(argv[1], "r");
            if (datafile == NULL) {
                printf("Unable to open file %s: %s\n", argv[1], strerror(errno));
                exit(-1);
            }
            break;

        default:
            /* more than two arguments?  throw hands up in resignation */
            usage(argv[0]);
    }

    /* 
     * you should be able to just read from datafile regardless 
     * whether it's stdin or a "real" file.
     */
    process_data(datafile);
    fclose(datafile);
    return 0;
}
#endif
