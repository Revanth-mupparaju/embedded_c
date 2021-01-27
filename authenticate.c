#include<reg51.h>
#include<string.h>

void invalid()
{
    int i;
    char text[7] = " INVALID ";
    for(i=0;n[i]!='\0';i++)
    {
        SBUF = text[i];
        while(TI==0);
        TI = 0;
    }
    while(1); 
}

void valid()
{
    int i;
    char text[6] = " VALID ";
    for(i=0;text[i]!='\0';i++)
    {
        SBUF = text[i];
        while(TI==0);
        TI = 0;
    }
    while(1);
}

void main()
{
    int i;
    char act_usr[10] = "username" , act_pass[10] = "auth8051" , usr[10] , pas[10] ;
    SCON = 0X50;
    TMOD = 0X20;
    TH1 = 0XFF;
    TR1 = 1;
    for(i=0; act_usr[i]!='\0'; i++)
    {
        while(RI==0);
        usr[i] = SBUF;
        RI = 0;
        SBUF = usr[i];
        while(TI==0);
        TI = 0;
    }
    usr[i] = '\0';
    if(strcmp(act_usr,usr)==0)
    {
        for(i=0; act_pass[i]!='\0'; i++)
        {
            while(RI==0);
            pas[i] = SBUF;
            RI = 0;
            SBUF = '*';
            while(TI==0);
            TI = 0;
        }
        pas[i] = '\0';
        if(strcmp(act_pass,pas)==0)
        {
            valid();
        }
        else
        {
            invalid();
        }
    }
    else
    {
        invalid();
    }
    while(1);
}