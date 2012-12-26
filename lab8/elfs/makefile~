

CFLAGS=-m32 


all: secret1 secret2

secret1: secret-elf-a secret-elf-c
	gcc $(CFLAGS) -o $@ $^
secret2: secret-elf-b secret-elf-c
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
