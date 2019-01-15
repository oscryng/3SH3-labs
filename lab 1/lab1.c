#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int loopEnd = 1;

// user - defined signal handler for alarm .
void sig_handler (int signo){
	switch(signo){
		case SIGALRM: // Alarm
			printf("Alarm\n");
			alarm(2);
			break;
		case SIGINT: // CTRL+C
			printf("CTRL+C pressed!\n");
			break;
		case SIGTSTP: // CTRL+Z
			printf("CTRL+Z pressed!\n");
			loopEnd = 0;
			break;
	}
}
int main ( void ){
	// register the signal handlers
	if (signal(SIGALRM,sig_handler) == SIG_ERR ){
		printf (" failed to register alarm handler .") ;
		exit (1);
	}
	else if (signal(SIGINT,sig_handler) == SIG_ERR ){
		printf (" failed to register alarm handler .") ;
		exit (1);
	}
	else if (signal(SIGTSTP,sig_handler) == SIG_ERR ){
		printf (" failed to register alarm handler .") ;
		exit (1);
	}

	alarm (2) ; // set alarm to fire in 2 seconds .
	
	while (loopEnd) {
		sleep (1);
		alarm (2);
	} // wait until alarm goes off\
	
	return 0;
}