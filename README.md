# KingFsSystem

In this program I am triying to implement a simple UNIX-like file system simulator in order
to understand the hierarchical directory and inode structures. By this program will be able to
browse the disk information, file and directory list, create and delete files and
directories, read and write files. The functionality of the file system is similar to
UNIX file systems, but it does not include per-process open file table, permission and
user management.


# Compile

The program can be compiled using commad 
"make all"

# Execution

The program can be executed by command "fs_sim diskname" . This will create a filesystem with name "diskname". If "diskname" already created before then it will load the same file system into program.
