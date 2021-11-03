#ifndef __JUNZE_JSON_H__
#define __JUNZE_JSON_H__

typedef enum
{
    JUNZE_NULL,
    JUNZE_FALSE,
    JUNZE_TRUE,
    JUNZE_NUMBER,
    JUNZE_STRING,
    JUNZE_ARRAY,
    JUNZE_OBJECT
} junze_type;

typedef struct 
{
    junze_type types;
}junze_value;

enum
{
    JUNZE_PARSE_OK = 0,
    JUNZE_PARSE_EXECT_VALUE,
    JUNZE_PARSE_INVALID_CALUE,
    JUNZE_PARSE_ROOT_NOT_SINGULAR
};

int junze_parse(junze_valuse * v, const char *json);

junze_type junze_get_type(const junze_value *v);


#endif