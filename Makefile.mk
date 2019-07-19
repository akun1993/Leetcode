CC=gcc
RM=rm
MV=mv
CD=cd
CP=cp
AR=ar
STRIP=strip

INC=-I./include

DEBUG=DEBUG
CFLAGS   = -g
TARGET_DIR=./_install
TARGET   = p2p_core
LIBMUTLS = libmutls-debug.a
#LIBDNS = libdns-debug.a

CFLAGS += -Wall -DDEBUG $(INC)

LDFLAGS += -lpthread -L/usr/lib64/mysql -lmysqlclient_r -luuid -lrt -lssl -lidn

ifeq (,$(PRO_DIR))
PRO_DIR =$(shell pwd)
endif

#Out file path
OPath=$(PRO_DIR)/.obj

# all object files.
OBJ=$(OPath)/main.o $(OPath)/version.o $(OPath)/n_sys_init.o  \
	$(OPath)/n_rtmfp_peer.o $(OPath)/n_rtmfp_comm.o $(OPath)/n_rtmfp_session.o $(OPath)/n_rtmfp_packet.o $(OPath)/n_rtmfp_handshake.o \
	$(OPath)/n_rtmfp_encryption_layer.o $(OPath)/n_rtmfp_encryption_aes.o $(OPath)/n_rtmfp_chunk_user_data.o \
	$(OPath)/n_rtmfp_chunk_rikeying.o $(OPath)/n_rtmfp_chunk_iikeying.o $(OPath)/n_rtmfp_chunk_rhello_cookie_change.o \
	$(OPath)/n_rtmfp_chunk_rhello.o $(OPath)/n_rtmfp_chunk_redirect.o $(OPath)/n_rtmfp_chunk_ihello.o $(OPath)/n_rtmfp_key_compute.o \
	$(OPath)/n_rtmfp_chunk_fihello.o $(OPath)/n_rtmfp_chunk.o  $(OPath)/n_rtmfp_port.o $(OPath)/n_event_handler.o  $(OPath)/n_rtmfp_chient_handshake.o\
	$(OPath)/n_DNS.o $(OPath)/n_diffie_hellman.o $(OPath)/n_rtmfp_c2s_handshake.o  $(OPath)/n_rtmfp_redirect_request.o \
	$(OPath)/n_udp.o  $(OPath)/n_rtmfp_p2p_handshake.o $(OPath)/n_utils.o $(OPath)/n_rtmfp_flow.o $(OPath)/n_rtmfp_flow_writer.o $(OPath)/RTMFP_test.o \
	$(OPath)/n_rtmfp_interactive.o $(OPath)/n_rtmfp_flash_stream.o  $(OPath)/n_rtmfp_flash_stream_resp.o  $(OPath)/n_aiqiyi_stream_handler.o \
	$(OPath)/n_rtmfp_flash_writer.o $(OPath)/amf_writer.o $(OPath)/n_rtmfp_chunk_other.o

sub_dirs=
#sub_dirs=$(PRO_DIR)/dif



LIBS=
LIBS=$(shell libs=;for subdir in $(sub_dirs);do libs+="$$subdir/build-in.o ";done;echo $$libs;)

all:start $(TARGET_DIR) $(OPath) $(OBJ) sub-dirs end
	$(CC) -o $(TARGET) -Xlinker "-(" $(OBJ) $(LIBS) $(LIBMUTLS) $(LIBNETCORE) $(LIBDNS) -Xlinker "-)" $(LDFLAGS)

ifdef OEM_NAME
	$(CP) $(TARGET) $(TARGET_DIR)/$(TARGET)_$(OEM_NAME)
else
	$(CP) $(TARGET) $(TARGET_DIR)/$(TARGET)
endif

start:
	@echo -e "\033[44;37;5m Make start  \033[0m"

	make -f Makefile.mk clean_obj

end:
	@echo -e "\033[44;37;5m Make finish \033[0m"

$(TARGET_DIR):
	mkdir $(TARGET_DIR) 2> /dev/null

$(OPath):
	mkdir $(OPath) 2> /dev/null

$(OPath)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

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
	$(RM) -f $(OBJ) >& /dev/null

	@for subdir in $(sub_dirs);\
	do\
		make -C $$subdir clean >& /dev/null;\
	done


