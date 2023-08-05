#include $(ROOTDIR)/config/.config
SRCS = cmcc_sec2_router.c 
OBJS = $(SRCS:.c=.o) 
CFLAGS += -I$(ROOTDIR)/user/boa/src/LINUX/
RC_GREEN_NET = /etc/init.d/rc36

ifeq ($(CONFIG_USER_ADAPTER_API_ISP),y)
ISP_API_DIR = $(ROOTDIR)/user/adapter-api/rtk_isp_api
CFLAGS += -I$(ISP_API_DIR)
LDFLAGS += -L$(ISP_API_DIR)
LIBS += -l_rtk_isp_adapter
endif

LIBS += $(LIBMIB)

TGT = libsec2_router.so
TEST = test_main
VASDOCKER_TAR = vasdocker.tar.gz
VASDOCKER_SH = vasdocker_monitor.sh

all :$(TGT) $(TEST) 

$(TGT) : $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS)  -shared -s -o $@  $(OBJS) $(LIBS)

$(TEST) :
	$(CC) $(LDFLAGS) $(LIBS) $(CFLAGS) -o $(TEST) test_main.c  -L. -lsec2_router -I.  

.c.o:
	$(CC) $(CFLAGS) -c  -o $@ -fPIC $^ $(LDFLAGS)  $(LIBS) 

romfs :
	$(ROMFSINST) /bin/$(TEST)
	$(ROMFSINST) /lib/$(TGT)
	mkdir -p $(IMAGEDIR)/romfs/usr/bin
	#vasdocker
	$(ROMFSINST) /usr/bin/$(VASDOCKER_TAR)
	$(ROMFSINST) /usr/bin/$(VASDOCKER_SH)
	$(ROMFSINST) -s /var/app/cmcc_sec2Router /tmp/netmonitor
	$(ROMFSINST) -s /var/app/bvasPlug /tmp/bvasPlug
	#netmonitor
	$(ROMFSINST) netmonitor.tar.gz /etc/netmonitor.tar.gz
	#$(ROMFSINST) netmonitor /etc/netmonitor/
	#marknum
	$(ROMFSINST) marknum /etc/marknum

clean:
	rm -rf $(OBJS)  $(TEST) $(TGT)

rcX:
	$(ROMFSINST) -a "mkdir /var/app/cmcc_sec2Router" $(RC_GREEN_NET)
	$(ROMFSINST) -a "mkdir /var/app/bvasPlug" $(RC_GREEN_NET)
	$(ROMFSINST) -a "cp -ar /etc/netmonitor.tar.gz /tmp" $(RC_GREEN_NET)
	$(ROMFSINST) -a "tar xvzf /tmp/netmonitor.tar.gz -C /tmp/" $(RC_GREEN_NET)
	$(ROMFSINST) -a "ln -s /var/app/bvasPlug /tmp/bvasPlug" $(RC_GREEN_NET)
	$(ROMFSINST) -a "/usr/bin/vasdocker_monitor.sh &" $(RC_GREEN_NET)

.PHONY : all clean romfs rcX
