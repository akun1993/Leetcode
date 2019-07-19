
all: \
	clean standard

standard:
	make -f Makefile.mk

clean:
	make -f Makefile.mk clean

