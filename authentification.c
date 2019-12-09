#include <string.h>
#include <stdio.h>
#include "authentification.h"

int verifier(char use[20], char pwd[20])
{int tu;int tp; int te;char login[20];char password[20];int role;
FILE*f;
te=-1;
f=fopen("users.txt","r");
while(fscanf(f,"%s %s %d\n",login,password,&role)!=EOF){
tu=strcmp(use,login);
tp=strcmp(pwd,password);
if ((tu==0) && (tp==0))

te=role;

}
fclose(f);
return(te);
}
