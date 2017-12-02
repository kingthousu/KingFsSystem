#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "fs.h"
#include "disk.h"

bool command(char *comm, char *comm2)
{
		if(strlen(comm) == strlen(comm2) && strncmp(comm, comm2, strlen(comm)) == 0) return true;
		return false;
}

int main(int argc, char **argv)
{
		char input[64+16+16+16+LARGE_FILE];
		char comm[64], arg1[16], arg2[16], arg3[16], arg4[LARGE_FILE];
		
		//Inode inot;
		srand(time(NULL));
		
		//printf("size %d, %d\n", sizeof(TYPE), sizeof(inot));  //commented by KingThousu
		
		if(argc < 2) {
				fprintf(stderr, "usage: ./fs disk_name\n");
				return -1;
		}
		srand (time(NULL));	

		fs_mount(argv[1]);
		printf("%% ");
		while(fgets(input, 256, stdin))
		{
				bzero(comm,64); bzero(arg1,16); bzero(arg2,16); bzero(arg3,16); bzero(arg4, LARGE_FILE);
				int numArg = sscanf(input, "%s %s %s %s %s", comm, arg1, arg2, arg3, arg4);
				if(command(comm, "fquit")) break;
				else if(command(comm, "fexit")) break;
				else execute_command(comm, arg1, arg2, arg3, arg4, numArg - 1);

				printf("%% ");
		}
		
		fs_umount(argv[1]);
		return 0;
}

