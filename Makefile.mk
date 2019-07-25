CC=g++
RM=rm
MV=mv
CD=cd
CP=cp
AR=ar
STRIP=strip
INC=-I./Include -I./ModuleBase

TARGET_DIR =./_install
TARGET   = leet_main

CXXFLAGS += -Wall -std=c++11 -DDEBUG $(INC)

LDFLAGS += 

ifeq (,$(PRO_DIR))
PRO_DIR =$(shell pwd)
endif

#Out file path
OPATH=$(PRO_DIR)/.obj

# all object files.
OBJ=$(OPATH)/leet_main.o 
#$(OPath)/version.o 

sub_dirs=	$(PRO_DIR)/ModuleBase  \
			$(PRO_DIR)/StringTopics \
			$(PRO_DIR)/TreeTopics \
			$(PRO_DIR)/ListTopics \
			$(PRO_DIR)/DynamicPTopics \
			$(PRO_DIR)/ArrayTopics
#
#sub_dirs=$(PRO_DIR)
LIBS=
LIBS=$(shell libs=;for subdir in $(sub_dirs);do libs+="$$subdir/build-in.o ";done;echo $$libs;)

all:start $(TARGET_DIR) $(OPATH) $(OBJ) sub-dirs end
	$(CC) -o $(TARGET) -Xlinker "-(" $(OBJ) $(LIBS) -Xlinker "-)" $(LDFLAGS)

#
start:
	@echo -e "\033[44;37;5m Make start  \033[0m"

	make -f Makefile.mk clean_obj

end:
	@echo -e "\033[44;37;5m Make finish \033[0m"

$(TARGET_DIR):
	mkdir $(TARGET_DIR) 2> /dev/null

$(OPATH):
	mkdir $(OPATH) 2> /dev/null

$(OPATH)/%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

sub-dirs:
	@for subdir in $(sub_dirs);\
	do\
		make -C $$subdir DEBUG=$(DEBUG);\
		ret=$$?;\
		if [ ! $$ret -eq "0" ];then \
			echo -e "\033[44;37;5m Make Error [$$ret]  \033[0m";\
			exit;\
		fi \
	done

clean:
	$(RM) -rf $(OPATH) >& /dev/null
	$(RM) -f $(TARGET) >& /dev/null
	$(RM) -rf $(TARGET_DIR) >& /dev/null

	@for subdir in $(sub_dirs);\
	do\
		make -C $$subdir clean >& /dev/null;\
	done

clean_obj:
	@for subdir in $(sub_dirs);\
	do\
		make -C $$subdir clean >& /dev/null;\
	done
	$(RM) -f $(OBJ) >& /dev/null

export CC
export RM
export MV
export CD
export CP
export AR
export STRIP
