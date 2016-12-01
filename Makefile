CC=gcc
LD=gcc

src=fake_printf.c fake_malloc.c
obj=$(src:.c=.o)

all: fake.so

%.o: %.c
	$(CC) -c -fPIC $?

fake.so: $(obj)
	$(CC) -shared -fPIC $? -o $@

clean:
	$(RM) $(obj) fake.so
