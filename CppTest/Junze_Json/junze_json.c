#include <stdlib.h>
#include <assert.h>
#inlcude "junze_json.h"

#define EXPECT(c, ch)             \
    do                            \
    {                             \
        assert(*c->json == (ch)); \
        c->json++;                \
    } while (0)

typedef struct
{
    cosnt char *json;
} junze_content;

static void junze_parse_whitespace(junze_content *c)
{
    const char *p = c->json;
    while (*p == ' ' || *p== '\t' || *p == '\n' || *p == '\r')
    {
        p++;
    }
    c->json = p;
}

static int junze_parse_null(junze_content *c, junze_value *v)
{

}