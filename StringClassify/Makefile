
INC=-I../include
CXXFLAGS += -Wall -std=c++11 -DDEBUG $(INC)

TARGET=build-in.o
SUBDIRS:=

ifeq (,$(PRO_DIR))
PRO_DIR =$(shell pwd)
endif

Opath=$(PRO_DIR)

OBJ=solution_strings.o

LIB=$(shell  libs=; for subdir in $(SUBDIRS); do libs+=$$(subdir)/build-in.o; done; echo $$libs)

$(TARGET):
	$(AR) -r $(TARGET) $(OBJ) $(LIB)

$(OPath)/%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) -rf $(Opath)/*.o >& /dev/null;

	@for subdir in $(SUBDIRS);\
	do\
		make -C $$(subdir) clean;\
	done


