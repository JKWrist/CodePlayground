#include <stdio.h>
#include "ifdef.h"

#ifdef WLAN_QUICK_MESH
int is_internet_online()
{
    printf("is_internet_online\n");
}
#endif

int main ()
{
#ifdef WLAN_QUICK_MESH
    is_internet_online();
#endif
    char ifname[32] = {0};
    snprintf((char *)ifname, sizeof(ifname), "wlan1");
    printf("main %s\n", ifname);
}