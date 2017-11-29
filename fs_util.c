#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fs.h"

int rand_string(char *str, size_t size)
{
		if(size < 1) return 0;
		int n, key;
		const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		for (n = 0; n < size; n++) {
				key = rand() % (int) (sizeof charset - 1);
				str[n] = charset[key];
		}
		str[size] = '\0';
		return size+1;
}

void toggle_bit(char *array, int index)
{
		array[index/8] ^= 1 << (index % 8);
}

char get_bit(char *array, int index)
{
		return 1 & (array[index/8] >> (index % 8));
}

void set_bit(char *array, int index, char value)
{
		if(value != 0 && value != 1) return;
		array[index/8] ^= 1 << (index % 8);
		if(get_bit(array, index) == value) return;
		toggle_bit(array, index);
}

int get_free_inode()
{
		int i = 0;
		for(i = 0; i < MAX_INODE; i++)
		{
				if(get_bit(inodeMap, i) == 0) {
						set_bit(inodeMap, i, 1);
						superBlock.freeInodeCount--;
						return i;
				}
		}

		return -1;
}

int get_free_block()
{
		int i = 0;
		for(i = 0; i < MAX_BLOCK; i++)
		{
				if(get_bit(blockMap, i) == 0) {
						set_bit(blockMap, i, 1);
						superBlock.freeBlockCount--;
						return i;
				}
		}

		return -1;
}

int format_timeval(struct timeval *tv, char *buf, size_t sz)
{
		ssize_t written = -1;
		struct tm *gm;
		gm = gmtime(&tv->tv_sec);

		if (gm)
		{
				written = (ssize_t)strftime(buf, sz, "%Y-%m-%d %H:%M:%S", gm);
				if ((written > 0) && ((size_t)written < sz))
				{
						int w = snprintf(buf+written, sz-(size_t)written, ".%06dZ", tv->tv_usec);
						written = (w > 0) ? written + w : -1;
				}
		}
		return written;
}
