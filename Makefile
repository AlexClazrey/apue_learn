INCL=-I./

.SUFFIXES:.c

.c.o:
	gcc -Wall ${INCL} -c $< -o $@

all: ls tee_unbuf tee_buf pid_print sh_basic

sh_basic: sh_basic.o apue.o
	gcc -o $@.exe $^

pid_print: pid_print.o
	gcc -o $@.exe $^

tee_buf: tee_buffered.o apue.o
	gcc -o $@.exe $^

tee_unbuf: tee_unbuffered.o apue.o
	gcc -o $@.exe $^

ls: ls.o apue.o
	gcc -o $@.exe $^

