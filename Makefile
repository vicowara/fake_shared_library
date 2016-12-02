CC=gcc
LD=gcc

CFLAGS=-fPIC -ldl -W -Wall -D_GNU_SOURCE

src=fake_printf.c fake_malloc.c
obj=$(src:.c=.o)

all: fake.so

%.o: %.c
	$(CC) $(CFLAGS) -c $<

fake.so: $(obj)
	$(CC) -shared $(CFLAGS) $^ -o $@

clean:
	$(RM) $(obj) fake.so
