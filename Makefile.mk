TARGET_DIR =./_install
TARGET   = leet

CXXFLAGS += -Wall -DDEBUG $(INC)

LDFLAGS += -luuid -lrt 

ifeq (,$(PRO_DIR))
PRO_DIR =$(shell pwd)
endif

#Out file path
OPath=$(PRO_DIR)/.obj

# all object files.
OBJ=$(OPath)/main.o $(OPath)/version.o 

sub_dirs=$(PRO_DIR)/ArrayClassify $(PRO_DIR)/DPClassify  $(PRO_DIR)/ListClassify   $(PRO_DIR)/StringClassify  $(PRO_DIR)/TreeClassify  
#sub_dirs=$(PRO_DIR)

LIBS=
LIBS=$(shell libs=;for subdir in $(sub_dirs);do libs+="$$subdir/build-in.o ";done;echo $$libs;)

all:start $(TARGET_DIR) $(OPath) $(OBJ) sub-dirs end
	$(CC) -o $(TARGET) -Xlinker "-(" $(OBJ) $(LIBS) -Xlinker "-)" $(LDFLAGS)

#
start:
	@echo -e "\033[44;37;5m Make start  \033[0m"

	make -f Makefile.mk clean_obj

end:
	@echo -e "\033[44;37;5m Make finish \033[0m"

$(TARGET_DIR):
	mkdir $(TARGET_DIR) 2> /dev/null

$(OPath):
	mkdir $(OPath) 2> /dev/null

$(OPath)/%.o: %.cpp
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
	$(RM) -rf $(OPath) >& /dev/null
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


