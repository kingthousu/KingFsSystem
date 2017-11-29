#define BLOCK_SIZE 512
#define MAX_BLOCK 4096

extern char disk[MAX_BLOCK][BLOCK_SIZE];

int disk_read(int block, char *buf);
int disk_write(int block, char *buf);

int disk_mount(char *name);
int disk_umount(char *name);

