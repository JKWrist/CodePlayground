#include <stdio.h>

#define SETKEY_CONF "/tmp/setkey.conf"
#define RACOON_CONF "/tmp/racoon.conf"
#define RACOON_PID "/var/run/racoon.pid"
#define RACOON_LOG "/tmp/racoon.log"
#define PSK_FILE "/tmp/psk.txt"
#define CERT_FLOD "/var/config"
#define DHGROUP_INDEX(x)	((x >> 24) & 0xff)
#define ENCRYPT_INDEX(x)	((x >> 16) & 0xff)
#define AHAUTH_INDEX(x)	((x >> 8) & 0xff)
#define AUTH_INDEX(x)	(x & 0xff)
#define MAX_NAME_LEN	32
#define MAX_V6_IP_LEN	46

typedef struct ipsec_entry {
	unsigned char enable;	 //0-disable; 1-enable;
	unsigned char state;     //0 - not apply, 1 - applyed
#ifdef CONFIG_IPV6_VPN
	unsigned char IpProtocol; 		 // 1: IPv4, 2: IPv6
#endif
	unsigned char transportMode; //0-tunnel; 1-transport;
	unsigned char negotiationType;	 //0-IKE; 1-manual;
	unsigned char remoteTunnel[MAX_V6_IP_LEN];//depends on IpProtocol
	unsigned char remoteIP[MAX_V6_IP_LEN];//depends on IpProtocol
	unsigned char remoteMaskLen;//depends on IpProtocol: IPV4 (0<len<32);  IPV6(0l<en<128)
	unsigned char localTunnel[MAX_V6_IP_LEN];//depends on IpProtocol
	unsigned char localIP[MAX_V6_IP_LEN];//depends on IpProtocol
	unsigned char localMaskLen;//depends on IpProtocol: IPV4 (0<len<32);  IPV6(0l<en<128)
	unsigned char encapMode; //1-esp; 2-ah; 3-esp+ah;
	unsigned char filterProtocol;	//0-any; 1-TCP; 2-UDP; 3-ICMP;
	unsigned int filterPort;

	//for manual
	unsigned char espEncrypt; //esp encryption algorithm
	unsigned char espEncryptKey[60];  //esp encryption key
	unsigned char espAuth; //esp authentication algorithm
	unsigned char espAuthKey[60];  //esp authentication key
	unsigned char ahAuth; //ah authentication algorithm
	unsigned char ahAuthKey[60];  //ah authentication key
	unsigned int espINSPI;
	unsigned int espOUTSPI;
	unsigned int ahINSPI;
	unsigned int ahOUTSPI;

	//for ike
	unsigned char ikeMode;      //0-main; 1-aggressive;
	unsigned char auth_method;  //0-psk; 1-certificate
	unsigned char psk[130];
	unsigned char ikeProposal[4];
	unsigned int pfs_group;
	unsigned int encrypt_group;
	unsigned int auth_group;
	unsigned int ikeAliveTime;
	unsigned int saAliveTime;
	unsigned int saAliveByte;
} __PACK__ MIB_IPSEC_T, *MIB_IPSEC_Tp;

struct IPSEC_PROP_ST
{
    char valid;
    char name[MAX_NAME_LEN];
    unsigned int algorithm; //dhGroup|espEncryption|ahAuth|espAuth
};

void ipsec_take_effect(void);
void apply_nat_rule(MIB_IPSEC_T *pEntry);
extern struct IPSEC_PROP_ST ikeProps[];
extern char *curr_dhArray[];
extern char *curr_encryptAlgm[];
extern char *curr_authAlgm[];

struct IPSEC_PROP_ST ikeProps[] =
{
    {1, "------------------------", 0x00000000},
    {1, "des-md5-group1", 0x01010001},//dhGroup|Encryption|ahAuth|Auth
    {1, "des-sha1-group1", 0x01010002},
    {1, "3des-md5-group2", 0x02020001},
    {1, "3des-sha1-group2", 0x02020002},
    {0} //invalid should be the last one!!!!
};

char *curr_dhArray[] =
{
    "null",
    "modp768",
    "modp1024",
    NULL
};

char *curr_encryptAlgm[] =
{
    "null_enc",
    "des",
    "3des",
#ifdef CONFIG_CRYPTO_AES
    "aes",
#endif
    NULL
};
static char *setkey_encryptAlgm[] =
{
    "null_enc",
    "des-cbc",
    "3des-cbc",
#ifdef CONFIG_CRYPTO_AES
    "aes-cbc",
#endif
    NULL
};

char *curr_authAlgm[] =
{
    "non_auth",
    "md5",
    "sha1",
    NULL
};
static char *setkey_authAlgm[] =
{
    "non_auth",
    "hmac-md5",
    "hmac-sha1",
    NULL
};
static char *racoon_authAlgm[] =
{
    "non_auth",
    "hmac_md5",
    "hmac_sha1",
    NULL
};

/*
return
	0: failed
	1: succeed
*/
static int applyIPsec(FILE *fpSetKey, FILE *fpRacoon, FILE *fpPSK, MIB_IPSEC_T *pEntry)
{
    char *strVal;
    int intVal;
    char *saProtocol[2] = {"esp", "ah"};
    char *transportMode[2] = {"tunnel", "transport"};
    char *ikeMode[2] = {"main", "aggressive"};
    char *ikeauthmethod[2] = {"pre_shared_key", "rsasig"};
    char *filterProtocol[4] = {"any", "tcp", "udp", "icmp"};
    char filterPort[10];

    if ((fpPSK == NULL) || (fpSetKey == NULL) || (fpRacoon == NULL) || (pEntry == NULL))
    {
        printf("\n %s %d  Invaild arguments\n", __func__, __LINE__);
        return 0;
    }
    //psk mode
    if(0 == pEntry->auth_method)
    {
        fprintf(fpPSK, "%s %s\n", pEntry->remoteTunnel, pEntry->psk);
    }

    if(pEntry->filterPort != 0)
        snprintf(filterPort, 10, "%d", pEntry->filterPort);
    else
        snprintf(filterPort, 10, "%s", "any");

    if(pEntry->negotiationType == 1)
    {
        //manual mode
        if((pEntry->encapMode & 0x1) != 0x0)
        {
            fprintf(fpSetKey, "add %s %s esp 0x%x -m %s ", pEntry->localTunnel, pEntry->remoteTunnel,
                    pEntry->espOUTSPI, transportMode[pEntry->transportMode]);

            if(pEntry->espEncrypt != 0)
                fprintf(fpSetKey, "-E %s 0x%s ", setkey_encryptAlgm[pEntry->espEncrypt], pEntry->espEncryptKey);
            if(pEntry->espAuth != 0)
                fprintf(fpSetKey, "-A %s 0x%s ", setkey_authAlgm[pEntry->espAuth], pEntry->espAuthKey);

            fprintf(fpSetKey, ";\n\n");

            fprintf(fpSetKey, "add %s %s esp 0x%x -m %s ", pEntry->remoteTunnel, pEntry->localTunnel,
                    pEntry->espINSPI, transportMode[pEntry->transportMode]);

            if(pEntry->espEncrypt != 0)
                fprintf(fpSetKey, "-E %s 0x%s ", setkey_encryptAlgm[pEntry->espEncrypt], pEntry->espEncryptKey);
            if(pEntry->espAuth != 0)
                fprintf(fpSetKey, "-A %s 0x%s ", setkey_authAlgm[pEntry->espAuth], pEntry->espAuthKey);

            fprintf(fpSetKey, ";\n\n");
        }

        if((pEntry->encapMode & 0x2) != 0x0)
        {
            fprintf(fpSetKey, "add %s %s ah 0x%x -m %s -A %s 0x%s ;\n\n", pEntry->localTunnel, pEntry->remoteTunnel,
                    pEntry->ahOUTSPI, transportMode[pEntry->transportMode], setkey_authAlgm[pEntry->ahAuth], pEntry->ahAuthKey);

            fprintf(fpSetKey, "add %s %s ah 0x%x -m %s -A %s 0x%s ;\n\n", pEntry->remoteTunnel, pEntry->localTunnel,
                    pEntry->ahINSPI, transportMode[pEntry->transportMode], setkey_authAlgm[pEntry->ahAuth], pEntry->ahAuthKey);

        }
    }

    //direction: in
    if(pEntry->transportMode == 0)
    {
        fprintf(fpSetKey, "spdadd %s/%d[%s] %s/%d[%s] %s -P in ipsec", pEntry->remoteIP, pEntry->remoteMaskLen, filterPort,
                pEntry->localIP, pEntry->localMaskLen, filterPort, filterProtocol[pEntry->filterProtocol]);
        if((pEntry->encapMode & 0x1) != 0x0)
            fprintf(fpSetKey, " esp/tunnel/%s-%s/require", pEntry->remoteTunnel, pEntry->localTunnel);
        if((pEntry->encapMode & 0x2) != 0x0)
            fprintf(fpSetKey, " ah/tunnel/%s-%s/require", pEntry->remoteTunnel, pEntry->localTunnel);
    }
    else
    {
        fprintf(fpSetKey, "spdadd %s[%s] %s[%s] %s -P in ipsec", pEntry->remoteTunnel, filterPort,
                pEntry->localTunnel, filterPort, filterProtocol[pEntry->filterProtocol]);
        if((pEntry->encapMode & 0x1) != 0x0)
            fprintf(fpSetKey, " esp/transport//use");
        if((pEntry->encapMode & 0x2) != 0x0)
            fprintf(fpSetKey, " ah/transport//use");
    }

    fprintf(fpSetKey, ";\n\n");

    //direction: out
    if(pEntry->transportMode == 0)
    {
        fprintf(fpSetKey, "spdadd %s/%d[%s] %s/%d[%s] %s -P out ipsec", pEntry->localIP, pEntry->localMaskLen, filterPort,
                pEntry->remoteIP, pEntry->remoteMaskLen, filterPort, filterProtocol[pEntry->filterProtocol]);
        if((pEntry->encapMode & 0x1) != 0x0)
            fprintf(fpSetKey, " esp/tunnel/%s-%s/require", pEntry->localTunnel, pEntry->remoteTunnel);
        if((pEntry->encapMode & 0x2) != 0x0)
            fprintf(fpSetKey, " ah/tunnel/%s-%s/require", pEntry->localTunnel, pEntry->remoteTunnel);
    }
    else
    {
        fprintf(fpSetKey, "spdadd %s[%s] %s[%s] %s -P out ipsec", pEntry->localTunnel, filterPort,
                pEntry->remoteTunnel, filterPort, filterProtocol[pEntry->filterProtocol]);
        if((pEntry->encapMode & 0x1) != 0x0)
            fprintf(fpSetKey, " esp/transport//require");
        if((pEntry->encapMode & 0x2) != 0x0)
            fprintf(fpSetKey, " ah/transport//require");
    }
    fprintf(fpSetKey, ";\n\n");

    //ike mode
    if(pEntry->negotiationType == 0)
    {

        // Mason Yu.
#if 0
        //for NAT-Traversal
        fprintf(fpRacoon, "timer {\n");
        fprintf(fpRacoon, "\tnatt_keepalive 10sec ;\n");
        fprintf(fpRacoon, "\t}\n");

        fprintf(fpRacoon, "listen {\n");
        fprintf(fpRacoon, "\tisakmp %s [500] ;\n", homeAddr);
        fprintf(fpRacoon, "\tisakmp_natt %s [4500] ;\n", homeAddr);
        fprintf(fpRacoon, "\t}\n");
        //end
#endif
        fprintf(fpRacoon, "remote %s {\n", pEntry->remoteTunnel);
        fprintf(fpRacoon, "\texchange_mode %s ;\n", ikeMode[pEntry->ikeMode]);
        // Mason Yu.
        //fprintf(fpRacoon, "\tnat_traversal on ;\n");
        fprintf(fpRacoon, "\tlifetime time %d second ;\n", pEntry->ikeAliveTime);
        if(1 == pEntry->auth_method)
        {
            //certificate mode
            //ToDo:
            fprintf(fpRacoon, "\tcertificate_type x509 \"cert.pem\" \"privKey.pem\" ;\n");
            fprintf(fpRacoon, "\tverify_cert on ;\n");
            fprintf(fpRacoon, "\tmy_identifier asn1dn ;\n");
            fprintf(fpRacoon, "\tpeers_identifier asn1dn ;\n");
        }

        for(intVal = 0; intVal < 4; intVal++)
        {
            if(pEntry->ikeProposal[intVal] == 0)
                continue;
            fprintf(fpRacoon, "\tproposal {\n");
            fprintf(fpRacoon, "\t\tencryption_algorithm %s ;\n", curr_encryptAlgm[ENCRYPT_INDEX(ikeProps[pEntry->ikeProposal[intVal]].algorithm)]);
            fprintf(fpRacoon, "\t\thash_algorithm %s ;\n", curr_authAlgm[AUTH_INDEX(ikeProps[pEntry->ikeProposal[intVal]].algorithm)]);
            fprintf(fpRacoon, "\t\tauthentication_method %s ;\n", ikeauthmethod[pEntry->auth_method]);
            fprintf(fpRacoon, "\t\tdh_group %d ;\n", DHGROUP_INDEX(ikeProps[pEntry->ikeProposal[intVal]].algorithm));
            fprintf(fpRacoon, "\t}\n\n");
        }
        fprintf(fpRacoon, "}\n\n");

        for(intVal = 1; curr_dhArray[intVal] != NULL; intVal++)
        {
            int i, flag;

            if(0x0 == (pEntry->pfs_group & (1 << intVal)))
                continue;
            if (pEntry->transportMode == 0)
            {
                fprintf(fpRacoon, "sainfo address %s/%d[%s] %s address %s/%d[%s] %s{\n",
                        pEntry->localIP, pEntry->localMaskLen, filterPort, filterProtocol[pEntry->filterProtocol],
                        pEntry->remoteIP, pEntry->remoteMaskLen, filterPort, filterProtocol[pEntry->filterProtocol]);
            }
            else
            {
                fprintf(fpRacoon, "sainfo address %s[%s] %s address %s[%s] %s{\n",
                        pEntry->localTunnel, filterPort, filterProtocol[pEntry->filterProtocol],
                        pEntry->remoteTunnel,	filterPort, filterProtocol[pEntry->filterProtocol]);
            }
            fprintf(fpRacoon, "\tpfs_group %s ;\n", curr_dhArray[intVal]);
            fprintf(fpRacoon, "\tlifetime time %d second ;\n", pEntry->saAliveTime);
            fprintf(fpRacoon, "\tencryption_algorithm ");
            flag = 0;
            for(i = 0; curr_encryptAlgm[i] != NULL; i++)
            {
                if(pEntry->encrypt_group & (1 << i))
                {
                    if(0 == flag)
                    {
                        fprintf(fpRacoon, "%s", curr_encryptAlgm[i]);
                        flag = 1;
                    }
                    else
                    {
                        fprintf(fpRacoon, ", %s", curr_encryptAlgm[i]);
                    }
                }
            }
            fprintf(fpRacoon, " ;\n");
            fprintf(fpRacoon, "\tauthentication_algorithm ");
            flag = 0;
            for(i = 0; racoon_authAlgm[i] != NULL; i++)
            {
                if(pEntry->auth_group & (1 << i))
                {
                    if(0 == flag)
                    {
                        fprintf(fpRacoon, "%s", racoon_authAlgm[i]);
                        flag = 1;
                    }
                    else
                    {
                        fprintf(fpRacoon, ", %s", racoon_authAlgm[i]);
                    }
                }
            }
            fprintf(fpRacoon, " ;\n");
            fprintf(fpRacoon, "\tcompression_algorithm deflate ;\n");
            fprintf(fpRacoon, "}\n\n");
        }
    }
    return 1;
}

void apply_nat_rule(MIB_IPSEC_T *pEntry)
{
    char *strVal;
    char filterPort[10];
    char local[24], remote[24];
    char *argv[20];
    int i = 3;

    if(1 == pEntry->transportMode)
    {
        //transportMode do not need it.
        return;
    }

    strVal = inet_ntoa(*(struct in_addr *)pEntry->localIP);
    snprintf(local, 24, "%s/%d", strVal, pEntry->localMaskLen);
    strVal = inet_ntoa(*(struct in_addr *)pEntry->remoteIP);
    snprintf(remote, 24, "%s/%d", strVal, pEntry->remoteMaskLen);
    if(pEntry->filterPort != 0)
        snprintf(filterPort, 10, "%d", pEntry->filterPort);

    argv[1] = "-t";
    argv[2] = "nat";
    if(1 == pEntry->state)
    {
        //for tunnel mode, should disable NAT for SPD.
        argv[i++] = (char *)FW_INSERT;
    }
    else
    {
        argv[i++] = (char *)FW_DEL;
    }
    argv[i++] = (char *)FW_POSTROUTING;

    if(0 != pEntry->filterProtocol)
    {
        argv[i++] = "-p";
        if(1 == pEntry->filterProtocol)
            argv[i++] = (char *)ARG_TCP;
        else if(2 == pEntry->filterProtocol)
            argv[i++] = (char *)ARG_UDP;
        else
            argv[i++] = (char *)ARG_ICMP;
    }

    //src ip
    argv[i++] = "-s";
    argv[i++] = local;

    // src port
    if ((1 == pEntry->filterProtocol) || (2 == pEntry->filterProtocol))
    {
        if(0 != pEntry->filterPort)
        {
            argv[i++] = (char *)FW_SPORT;
            argv[i++] = filterPort;
        }
    }

    // dst ip
    argv[i++] = "-d";
    argv[i++] = remote;

    // dst port
    if ((1 == pEntry->filterProtocol) || (2 == pEntry->filterProtocol))
    {
        if(0 != pEntry->filterPort)
        {
            argv[i++] = (char *)FW_DPORT;
            argv[i++] = filterPort;
        }
    }

    argv[i++] = "-j";
    argv[i++] = (char *)FW_RETURN;
    argv[i++] = NULL;

    //printf("i=%d\n", i);
    TRACE(STA_SCRIPT, "%s %s %s %s %s %s %s ...\n", IPTABLES, argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
    do_cmd(IPTABLES, argv, 1);

    return;
}

void add_ipsec_mangle_rule(void)
{
    unsigned char vChar;
    int ori_wlan_idx;
    char tnlName[32], markStr[32];

    snprintf(markStr, 32, "0x%x/0x%x", BYPASS_FWDENGINE_MARK_MASK, BYPASS_FWDENGINE_MARK_MASK);
    va_cmd(IPTABLES, 4, 1, "-t", "mangle", "-F", "XFRM");

    //iptables -t mangle -A XFRM -p esp -j MARK --set-mark 0x8/0x8
    va_cmd(IPTABLES, 10, 1, "-t", "mangle", (char *)FW_ADD, "XFRM", "-p", "esp", "-j", "MARK",
           "--set-mark", markStr);
    //iptables -t mangle -A XFRM -p ah -j MARK --set-mark 0x8/0x8
    va_cmd(IPTABLES, 10, 1, "-t", "mangle", (char *)FW_ADD, "XFRM", "-p", "ah", "-j", "MARK",
           "--set-mark", markStr);
    //iptables -t mangle -A XFRM -p udp --dport 500 --sport 500 -j MARK --set-mark 0x8/0x8
    va_cmd(IPTABLES, 14, 1, "-t", "mangle", (char *)FW_ADD, "XFRM", "-p", (char *)ARG_UDP, "--dport", "500", "--sport",
           "500", "-j", "MARK", "--set-mark", markStr);
#ifdef CONFIG_IPV6_VPN
    va_cmd(IP6TABLES, 4, 1, "-t", "mangle", "-F", "XFRM");

    //ip6tables -t mangle -A XFRM -p esp -j MARK --set-mark 0x8/0x8
    va_cmd(IP6TABLES, 10, 1, "-t", "mangle", (char *)FW_ADD, "XFRM", "-p", "esp", "-j", "MARK",
           "--set-mark", markStr);
    //ip6tables -t mangle -A XFRM -p ah -j MARK --set-mark 0x8/0x8
    va_cmd(IP6TABLES, 10, 1, "-t", "mangle", (char *)FW_ADD, "XFRM", "-p", "ah", "-j", "MARK",
           "--set-mark", markStr);
    //ip6tables -t mangle -A XFRM -p udp --dport 500 --sport 500 -j MARK --set-mark 0x8/0x8
    va_cmd(IP6TABLES, 14, 1, "-t", "mangle", (char *)FW_ADD, "XFRM", "-p", (char *)ARG_UDP, "--dport", "500", "--sport",
           "500", "-j", "MARK", "--set-mark", markStr);
#endif
}

void del_ipsec_mangle_rule(void)
{
    va_cmd(IPTABLES, 4, 1, "-t", "mangle", "-F", "XFRM");
#ifdef CONFIG_IPV6_VPN
    va_cmd(IP6TABLES, 4, 1, "-t", "mangle", "-F", "XFRM");
#endif
}

void ipsec_take_effect(void)
{
    FILE *fp = NULL;
    char pid[10];
    FILE *fpPSK = NULL, *fpSetKey = NULL, *fpRacoon = NULL;
    int entryNum, i, newState;
    MIB_IPSEC_T Entry;

    va_cmd("/bin/setkey", 1, 1, "-F");
    va_cmd("/bin/setkey", 1, 1, "-FP");

    if(access(RACOON_PID, 0) == 0)
    {
        if ((fp = fopen(RACOON_PID, "r")) == NULL)
        {
            printf("ERROR: open file %s error!\n", RACOON_PID);
            return;
        }
        if(fscanf(fp, "%d\n", &i) != 1)
            printf("fscanf failed: %s %d\n", __func__, __LINE__);
        snprintf(pid, 10, "%d", i);
        va_cmd("/bin/kill", 1, 1,  pid);
        unlink(RACOON_PID);
        if(fp) fclose(fp);
    }

    if(access(PSK_FILE, 0) == 0)
    {
        unlink(PSK_FILE);
    }

    if(access(RACOON_LOG, 0) == 0)
    {
        unlink(RACOON_LOG);
    }

    if(access(SETKEY_CONF, 0) == 0)
    {
        unlink(SETKEY_CONF);
    }

    if(access(RACOON_CONF, 0) == 0)
    {
        unlink(RACOON_CONF);
    }

    del_ipsec_mangle_rule();

    //Setup basic conf for setkey.conf / racoon.conf / psk.txt
    va_cmd("/bin/mkdir", 2, 1, "-p", CERT_FLOD);

    if (((fpSetKey = fopen(SETKEY_CONF, "w+")) == NULL)
            || ((fpRacoon = fopen(RACOON_CONF, "w+")) == NULL)
            || ((fpPSK = fopen(PSK_FILE, "w+")) == NULL))
    {
        printf("ERROR: open file %s error!\n");
        if (fpSetKey)
            fclose(fpSetKey);
        if (fpPSK)
            fclose(fpPSK);
        if (fpRacoon)
            fclose(fpRacoon);
        return;
    }
    fprintf(fpSetKey, "flush;\n");
    fprintf(fpSetKey, "spdflush;\n\n");
    fprintf(fpRacoon, "path pre_shared_key \"%s\" ;\n\n", PSK_FILE);
    fprintf(fpRacoon, "path certificate \"%s\" ;\n\n", CERT_FLOD);

    entryNum = mib_chain_total(MIB_IPSEC_TBL);
    for(i = 0; i < entryNum; i++)
    {
        if(mib_chain_get(MIB_IPSEC_TBL, i, (void *)&Entry) == 0)
            printf("\n %s %d\n", __func__, __LINE__);
        if(Entry.enable == 1)
        {
            newState = applyIPsec(fpSetKey, fpRacoon, fpPSK, &Entry);
            if(newState != Entry.state)
            {
                Entry.state = newState;
                mib_chain_update(MIB_IPSEC_TBL, &Entry, i);
            }
        }
        else
        {
            if(0 != Entry.state)
            {
                Entry.state = 0;
                mib_chain_update(MIB_IPSEC_TBL, &Entry, i);
            }
        }
#ifdef CONFIG_IPV6_VPN
        if (Entry.IpProtocol == 1)
#endif
            apply_nat_rule(&Entry); //just for IPV4
    }

    if (fpSetKey)
        fclose(fpSetKey);
    if (fpPSK)
        fclose(fpPSK);
    if (fpRacoon)
        fclose(fpRacoon);

    if(access(PSK_FILE, 0) == 0)
    {
        va_cmd("/bin/chmod", 2, 1, "600", PSK_FILE);
    }

    if(access(SETKEY_CONF, 0) == 0)
    {
        va_cmd("/bin/setkey", 2, 1, "-f", SETKEY_CONF);
    }

    if(access(RACOON_CONF, 0) == 0)
    {
        va_cmd("/bin/racoon", 4, 1, "-f", RACOON_CONF, "-l", RACOON_LOG);
        add_ipsec_mangle_rule();
#ifdef CONFIG_GPON_FEATURE
        _routeInternetWanCheck();
#endif
    }

    return;
}
