#include <stdio.h>
#include <string.h>

// struct html_spec_char_t html_spec_sym[] =
//     {
//         {'"', "&quot;", 6},
//         {0x27, "&#39;", 5}, // '
//         {0x5c, "&#92;", 5}, // '\'
//         {'<', "&lt;", 4},
//         {'>', "&gt;", 4},
//         {0x21, "&#33;", 5},  // !
//         {0x26, "&amp;", 5},  // &
//         {0x5e, "&#94;", 5},  // ^
//         {0x7e, "&#126;", 6}, // ~
//         {0x2d, "&#45;", 5},  // -
//         {0x40, "&#64;", 5},  // @
//         {0x23, "&#35;", 5},  // #
//         {0x24, "&#36;", 5},  // $
//         {0x25, "&#37;", 5},  // %
//         {0x2b, "&#43;", 5},  // +
//         {0}};

//convert to html style
void translate_control_code(char *buffer)
{
    if (NULL == buffer)
    {
        return;
    }
    char tmpBuf[1024] = {0};
    char *p1 = buffer, *p2 = tmpBuf;

    while (*p1)
    {
        if (*p1 == '\"')
        {
            memcpy(p2, "&quot;", 6);
            p2 += 6;
        }
        else if (*p1 == '\'')
        {
            memcpy(p2, "&#39;", 5); //single quote
            p2 += 5;
        }
        else if (*p1 == '\\')
        {
            memcpy(p2, "&#92;", 5); //backslash
            p2 += 5;
        }
        else if (*p1 == '<')
        {
            memcpy(p2, "&lt;", 4);
            p2 += 4;
        }
        else if (*p1 == '>')
        {
            memcpy(p2, "&gt;", 4);
            p2 += 4;
        }
        else
            *p2++ = *p1;
        p1++;
    }
    *p2 = '\0';

    strcpy(buffer, tmpBuf);
}

//convert to js style
void translate_web_code(char *buffer)
{
    if (NULL == buffer)
    {
        return;
    }
    char tmpBuf[1024] = {0};
    char *p1 = buffer, *p2 = tmpBuf;

    while (*p1)
    {
        if (*p1 == '\"')
        {
            strcpy(p2, "\\\"");
            p2 += 2;
        }
        else if (*p1 == '\'')
        {
            strcpy(p2, "\\'");
            p2 += 2;
        }
        else if (*p1 == '\\')
        {
            strcpy(p2, "\\\\");
            p2 += 2;
        }
        else
            *p2++ = *p1;
        p1++;
    }
    *p2 = '\0';

    strcpy(buffer, tmpBuf);
}

int main()
{
    char str_original[1024] = "11111 wwww.html\'.baidu222222\", ! <> com333333";
    printf("original: %d \n %s\n\n", strlen(str_original), str_original);

    char str_html[1024]     = "11111 wwww.html\'.baidu222222\", ! <> com333333";
    translate_control_code(str_html);
    printf("html: %d\n %s\n\n", strlen(str_html), str_html);

    char str_js[1024]       = "11111 wwww.html\'.baidu222222\", ! <> com333333";
    translate_web_code(str_js);
    printf("js  :  %d\n %s\n\n", strlen(str_js), str_js);

    return 0;
}