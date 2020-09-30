#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decStrToHexStr(const char *s) {
    int flag=1;
    int count=0;
    int num[64];
    const char *pstr = s;
    if (pstr == NULL) {
        return NULL;
    }

    if ((*pstr) == '-') {
        flag = -1;
        pstr++;
    }

    int a = atoi(pstr);
    int len = (strlen(s) + 1);
    char *s2 = (char *) malloc(sizeof(char) * len);
    memset(s2, '\0', len);
//    if (flag == -1) {
//        s2[0] = '-';
//        sprintf(s2 + 1, "%#x", a);
//    } else {
//        sprintf(s2, "%#x", a);
//    }


    while (a>0){

        num[count++] =a%16;
        a=a/16;
    }

    int k =0;
    if (flag == -1){
        s2[k++] = '-';
        s2[k++] = '0';
        s2[k++] = 'X';
    } else{
        s2[k++] = '+';
        s2[k++] = '0';
        s2[k++] = 'X';
    }

    for (int i = count-1; i >=0; --i) {
        if(num[i] > 10)
        {
            s2[k++] = num[i] - 10 +'A';
        } else{
            s2[k++] = num[i]  +'0';
        }
    }
    printf("%s\n", s2);
    return s2;

}

void test() {
    char *str = "+20";
    decStrToHexStr(str);
}

int main() {
    test();
    return 0;
}
