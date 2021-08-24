#include<iostream>
#include<cstring>
using namespace std;

//strtok()用来将字符串分割成一个个片段。参数s指向欲分割的字符串，参数delim则为分割字符串中包含的所有字符。当strtok()在参数s的字符串中发现参数delim中包含的分割字符时,则会将该字符改为\0 字符。在第一次调用时，strtok()必需给予参数s字符串，往后的调用则将参数s设置成NULL。每次调用成功则返回指向被分割出片段的指针。
int main()
{
    char sentence[]="This is a sentence with 7 tokens";
    cout << "The string to be tokenized is:\n" << sentence << "\n\nThe tokens are:\n\n";
    char *tokenPtr = strtok(sentence," ");
    while(tokenPtr!=NULL)
    {
        cout << tokenPtr << endl;
        tokenPtr = strtok(NULL," ");
    }
    //cout << "After strtok,sentence=" << tokenPtr<<endl;
    
    
    char input[16]="abc,d";
    char*p;
    /*strtok places a NULL terminator
    infront of the token,if found*/
    p=strtok(input,",");
    if(p)
    {
        printf("%s\n",p);
    }
    /*Asecond call to strtok using a NULL
    as the first parameter returns a pointer
    to the character following the token*/
    p = strtok(NULL,",");
    if(p)
    {
        printf("%s\n",p);
    }
    return 0;
}