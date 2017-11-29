all: fs

fs: fs_sim.c fs.c fs.h fs_util.c disk.c disk.h
		gcc fs_sim.c fs.c disk.c fs_util.c -g -o fs_sim

clean:
		rm -f fs_sim
