
INC=-I../Include
CXXFLAGS += -Wall -std=c++11  -DDEBUG $(INC)

TARGET=build-in.o
SUBDIRS:=

ifeq (,$(PRO_DIR))
PRO_DIR =$(shell pwd)
endif

OPATH=$(PRO_DIR)/.obj

OBJ= $(addprefix $(OPATH)/,$(patsubst %.cpp,%.o,$(wildcard *.cpp)))

LIB=$(shell  libs=; for subdir in $(SUBDIRS); do libs+=$$(subdir)/build-in.o; done; echo $$libs)

all: $(OPATH) $(OBJ)
	$(AR) -r -c $(TARGET) $(OBJ) $(LIB)

$(OPATH):
	mkdir $(OPATH) 2> /dev/null

$(OPATH)/%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) -f $(OPATH)/*.o >& /dev/null;
	$(RM) -f ./*.o >& /dev/null;

	@for subdir in $(SUBDIRS);\
	do\
		make -C $$(subdir) clean;\
	done


