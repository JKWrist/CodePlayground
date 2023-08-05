#if 1
#define debug(fmt, ...) ({\
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <debug>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})
#define info(fmt, ...) ({\
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <info>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})
#define notice(fmt, ...) ({\
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <notice>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})
#define warn(fmt, ...) ({\
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <warn>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})
#define error(fmt, ...) ({\
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <error>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})

#else

#define debug(...)  syslog(LOG_DEBUG, ##__VA_ARGS__)
#define info(...)   syslog(LOG_INFO, ##__VA_ARGS__)
#define notice(...) syslog(LOG_NOTICE, ##__VA_ARGS__)
#define warn(...)   syslog(LOG_WARNING, ##__VA_ARGS__)
#define error(...)  syslog(LOG_ERR, ##__VA_ARGS__)
#enfif


/*! \struct _option_t
 *  \brief Brief struct description
 *
 *  Detailed description
 */
typedef struct _option_t {
    const char *name;
    unsigned short id;
} option_t;


/*! \struct _section_t
 *  \brief Brief struct description
 *
 *  Detailed description
 */
typedef struct _section_t {
    const char *name;
    unsigned int cnt;
    const char **alias;
    option_t **option;
} section_t;

/*! \struct _package_t
 *  \brief Brief struct description
 *
 *  Detailed description
 */
typedef struct _package_t {
    const char *name;
    section_t **section;
} package_t;

#define OPTION(n, i) \
    &(option_t){ \
        .name = n, \
        .id = i, \
    }

#define ALIAS(...) (const char *[]) {__VA_ARGS__}

#define SECTION(x, c, a, ...) \
    &(section_t){ \
        .name = x, \
        .cnt = c, \
        .alias = a, \
        .option = (option_t*[]){ \
            __VA_ARGS__, \
            NULL, \
        } \
    }

#define PACKAGE(x, ...) \
    &(package_t){ \
        .name = x, \
        .section = (section_t*[]){ \
            __VA_ARGS__, \
            NULL, \
        }\
    }


static const package_t *const package[] = {
    PACKAGE("wireless",
            SECTION("wifi-iface", 8,
                ALIAS("host_5g", "guest_5g", NULL, NULL,
                    "host_2g", "guest_2g", NULL, NULL),
                OPTION("ssid",      MIB_WLAN_SSID),
                OPTION("hidden",    MIB_WLAN_HIDDEN_SSID))),

    PACKAGE("test",
            SECTION("hello", 1,
                ALIAS("123", "456"),
                OPTION("option",    MIB_WLAN_SSID))),

    NULL,
};