CC=gcc
LD=gcc

CFLAGS=-fPIC -ldl -W -Wall -D_GNU_SOURCE

src=fake_printf.c fake_malloc.c
obj=$(src:.c=.o)
target=libfake.so

all: $(target)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(target): $(obj)
	$(CC) -shared $(CFLAGS) $^ -o $@

clean:
	$(RM) $(obj) $(target)
