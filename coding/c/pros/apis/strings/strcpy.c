#include <stdio.h>
#include <string.h>

int main()
{
    printf("-------------\n");
    const char* sentence = "my name is smx";
    int length = strlen(sentence);
    char copy_sentence[length+1];
    printf("length of sentence is :%d\n", length);
    char* ret = strcpy(copy_sentence, sentence); 
    copy_sentence[0] = 'a';
    if (ret)
    {
        printf("the return value of strcpy is not null: %p %s\n", ret, ret); // 返回的是dest地址
    }
    printf("the copy sentence is:%s\n", copy_sentence);
    printf("-------------\n");
    printf("end of string_c.c\n");
    return 0;
}