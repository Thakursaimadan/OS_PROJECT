# Makefile for custom_ls

CC = gcc
CFLAGS = -Wall
TARGETS = custom_ls custom_wc custom_cp custom_rm custom_grep shell custom_cat custom_mv
INSTALL_DIR = /usr/local/bin

all: $(TARGETS)

custom_ls: custom_ls.c
	$(CC) $(CFLAGS) -o custom_ls custom_ls.c 

custom_wc: custom_wc.c
	$(CC) $(CFLAGS) -o custom_wc custom_wc.c

custom_cp: custom_cp.c
	$(CC) $(CFLAGS) -o custom_cp custom_cp.c

custom_cat: custom_cat.c
	$(CC) $(CFLAGS) -o custom_cat custom_cat.c

custom_rm: custom_rm.c
	$(CC) $(CFLAGS) -o custom_rm custom_rm.c

custom_mv: custom_mv.c
	$(CC) $(CFLAGS) -o custom_mv custom_mv.c

custom_grep: custom_grep.c
	$(CC) $(CFLAGS) -o custom_grep custom_grep.c

shell: shell.c
	$(CC) $(CFLAGS) -o shell shell.c

# Rule to install the custom_ls program to /usr/local/bin
install: $(TARGETS)
	sudo mv $(TARGETS) $(INSTALL_DIR)

# Rule to clean up compiled files
clean:
	rm -f $(TARGETS)