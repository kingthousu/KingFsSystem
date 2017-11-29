#include <stdio.h>
#include <string.h>
#include "disk.h"

char disk[MAX_BLOCK][BLOCK_SIZE];

int disk_read(int block, char *buf)
{
		if(block < 0 || block >= MAX_BLOCK) {
				printf("disk_read error\n");
				return -1;
		}
		memcpy(buf, disk[block], BLOCK_SIZE);

		return 0;
}

int disk_write(int block, char *buf)
{
		if(block < 0 || block >= MAX_BLOCK) {
				printf("disk_write error\n");
				return -1;
		}
		memcpy(disk[block], buf, BLOCK_SIZE);

		return 0;
}

int disk_mount(char *name)
{
		FILE *fp = fopen(name, "r");
		if(fp != NULL) {
				fread(disk, BLOCK_SIZE, MAX_BLOCK, fp);
				fclose(fp);
				return 1;
		}
		return 0;
}

int disk_umount(char *name)
{
		FILE *fp = fopen(name, "w");
		if(fp == NULL) {
				fprintf(stderr, "disk_umount: file open error! %s\n", name);
				return -1;
		}

		fwrite(disk, BLOCK_SIZE, MAX_BLOCK, fp);
		fclose(fp);
		return 1;
}

