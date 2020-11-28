#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Cameras{

    int s_cameraID;
    char s_RZ[1001];
    char s_month[4];
    int s_monthInt;
    int s_day;
    int s_hour;
    int s_min;
    int s_inMin;

}CAMERA;

int numOfDay(int month,int day)
{
    int numday=0;
    switch (month)
    {
        case 1:
        {
            numday=day;
            break;
        }
        case 2:
        {
            numday=day+31;
            break;
        }
        case 3:
        {
            numday=day+31+28;
            break;
        }
        case 4:
        {
            numday=day+31+28+31;
            break;
        }
        case 5:
        {
            numday=day+31+28+31+30;
            break;
        }
        case 6:
        {
            numday=day+31+28+31+30+31;
            break;
        }
        case 7:
        {
            numday=day+31+28+31+30+31+30;
            break;
        }
        case 8:
        {
            numday=day+31+28+31+30+31+30+31;
            break;
        }
        case 9:
        {
            numday=day+31+28+31+30+31+30+31+31;
            break;
        }
        case 10:
        {
            numday=day+31+28+31+30+31+30+31+31+30;
            break;
        }
        case 11:
        {
            numday=day+31+28+31+30+31+30+31+31+30+31;
            break;
        }
        case 12:
        {
            numday=day+31+28+31+30+31+30+31+31+30+31+30;
            break;
        }
    }
    return numday;
}



int months(char *month,int day)
{
    int monthInt=0;
    switch (month[0])
    {
        case 'A' :
        {
            if(month[1]=='p' && month[2]=='r' && month[3]=='\0')
            {
                if(day>30)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=4;
                return monthInt;   
            }
            else if(month[1]=='u'&& month[2]=='g' && month[3]=='\0')
            {
                if(day>31)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=8;
                return monthInt;   
            }
            else
            {
                monthInt=0;
                return monthInt; 
            }
            break;
        }
        case 'D' :
        {
            if(month[1]=='e')
            {
                if(month[2]=='c' && month[3]=='\0')
                {
                    if(day>31)
                    {
                        monthInt=0;
                        return monthInt;                     
                    }
                    monthInt=12;
                    return monthInt;                       
                }
            }
            else
            {
                monthInt=0;
                return monthInt;                
            }
            
        }
        case 'J' :
        {
            if(month[1]=='a'&& month[2]=='n' && month[3]=='\0')
            {
                if(day>31)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=1;
                return monthInt;                  
            }
            else if(month[1]=='u'&& month[2]=='n' && month[3]=='\0')
            {
                if(day>30)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=6;
                return monthInt;  
            }
            else if(month[1]=='u'&& month[2]=='l' && month[3]=='\0')
            {
                if(day>31)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=7;
                return monthInt;                  
            }
            else
            {
                monthInt=0;
                return monthInt;   
            }
            
        }
        case 'F' :
        {
            if(month[1]=='e'&& month[2]=='b' && month[3]=='\0')
            {
                if(day>28)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=2;
                return monthInt;                  
            }
            else
            {
                monthInt=0;
                return monthInt; 
            }
            
        }
        case 'M' :
        {
            if(month[1]=='a'&& month[2]=='r' && month[3]=='\0')
            {
                if(day>31)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=3;
                return monthInt;                  
            }
            else if(month[1]=='a'&& month[2]=='y' && month[3]=='\0')
            {
                if(day>31)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=5;
                return monthInt;    
            }
            else
            {
                monthInt=0;
                return monthInt; 
            }
        }
        case 'N' :
        {
            if(month[1]=='o'&& month[2]=='v' && month[3]=='\0')
            {
                if(day>30)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=11;
                return monthInt;                  
            }
            else
            {
                monthInt=0;
                return monthInt; 
            }
        }
        case 'O' :
        {
            if(month[1]=='c'&& month[2]=='t' && month[3]=='\0')
            {
                if(day>31)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=10;
                return monthInt;                  
            }
            else
            {
                monthInt=0;
                return monthInt; 
            }
        }      
        case 'S' :
        {
            if(month[1]=='e'&& month[2]=='p' && month[3]=='\0')
            {
                if(day>30)
                {
                    monthInt=0;
                    return monthInt;                     
                }
                monthInt=9;
                return monthInt;                  
            }
            else
            {
                monthInt=0;
                return monthInt; 
            }
        }                                  
        default:
        {
            monthInt=0;
            return monthInt;
        }
    }
    return monthInt;
}



int daysMinCompare(int *a, int *b)
{
    return (*b<*a)-(*a<*b);
}

int RZCompare(const CAMERA*a,const CAMERA*b)
{
    return (strcmp(a->s_RZ,b->s_RZ));
}

int lowerUppperBoundF(CAMERA*data,int low,int high,char RZ[],int flag)
{
    int mid;
    int result=-1;
    int compare=0;
    if(high==0 && low==0)
    {
        compare=strcmp(data[0].s_RZ,RZ);
        if(compare==0)
        {
            return 0;
        }
        return -1;
    }
    while (low<=high)
    {
        mid=(low+high)/2;
        compare=strcmp(data[mid].s_RZ,RZ);
        if (compare<0)
        {
            low=mid+1;
        }
        else if (compare>0)
        {
           high=mid-1; 
        }
        else
        {
            result=mid;
            if(flag)
            {
                high=mid-1; //Lower
            }
            else
            {
                low=mid+1; // Higher
            }   
        }
    }
    return result;
}

void findRZ(CAMERA*data,int n,char RZ[],char month[],int monthInt,int day, int hour, int min,int sum)
{
    int identicalE=0;
    int identicalL=0;
    int isEarlier=0;
    int isLater=0;
    int n1=0;
    int *arr1;
    int n2=0;
    int *arr2;
    int n3=0;
    int *arr3;
    int n4=0;
    int *arr4;
    int n5=0;
    int *arr5;
    int monthE=0;
    int monthL=0;
    int startPosition=0;
    int endPosition=0;
    int identical=0;
    int lowerBound=0;
    int upperBound=0;
    int result=0;
    arr1=(int*)calloc(100,sizeof(int));
    arr2=(int*)calloc(100,sizeof(int));
    arr3=(int*)calloc(100,sizeof(int));
    arr5=(int*)calloc(100,sizeof(int));
    arr4=(int*)calloc(100,sizeof(int));
    qsort(data,n,sizeof(*data),(int(*)(const void*, const void*))RZCompare);
    lowerBound=lowerUppperBoundF(data,0,n-1,RZ,1);
    upperBound=lowerUppperBoundF(data,0,n-1,RZ,0);
    if(lowerBound==-1 && upperBound==-1)
    {
        printf("> Automobil nenalezen.\n");
    }
    else if(lowerBound!=-1 && upperBound!=-1)
    {
       for (int i = lowerBound; i <= upperBound; i++)
        {
            result=strcmp(data[i].s_RZ,RZ);
            if(sum==data[i].s_inMin && result==0)
            {
                identical++;
                if(identical==100 || n1%100==1)
                {
                    arr1=(int*)realloc(arr1,100*sizeof(int));
                }
                arr1[n1]=data[i].s_cameraID;
                n1++;
                qsort(arr1,n1,sizeof(*arr1),(int(*)(const void *, const void *)) daysMinCompare);
            }
            else
            {
                if(data[i].s_inMin<sum)
                {
                    isEarlier++;
                    if(n2==100 || n2%100==1)
                    {
                        arr2=(int*)realloc(arr2,100*sizeof(int));
                    }
                    arr2[n2]=data[i].s_inMin;
                    n2++;
                }
                if(sum<data[i].s_inMin)
                {
                    isLater++;
                    if(n3==100 || n3%100==1)
                    {
                        arr3=(int*)realloc(arr3,100*sizeof(int));
                    }
                    arr3[n3]=data[i].s_inMin;
                    n3++;
                }
            }
        }
        qsort(arr1,n1,sizeof(*arr1),(int(*)(const void *, const void *)) daysMinCompare);
        qsort(arr2,n2,sizeof(*arr2),(int(*)(const void *, const void *)) daysMinCompare);
        qsort(arr3,n3,sizeof(*arr3),(int(*)(const void *, const void *)) daysMinCompare);
        if(identical>0)
        {
            if(lowerBound==upperBound)
            {
                if(hour<10)
                {
                    printf(">Presne: %s %02d %d:%02d, 1x ",month,day,hour,min);
                    printf("[");
                    printf("%d",data[lowerBound].s_cameraID);
                    printf("]\n");
                }
            }
            else
            {     
                printf("> Presne: %s %d %02d:%02d, %dx ",month,day,hour,min,identical);
                printf("[");
                startPosition=0;
                endPosition=n1-1;
                while (startPosition<=endPosition)
                {
                    printf("%d",arr1[startPosition]);
                    startPosition++;
                    if(arr1[startPosition]!='\0')
                    {
                        printf(", ");
                    }
                }
                printf("]\n");       
            }   
        }
        else if(identical==0)
        {
            n4=0;
            n5=0;
            for (int i = lowerBound; i <= upperBound; i++)
            {
                if(isEarlier!=0 && n2!=0)
                {
                    if(arr2[n2-1]==data[i].s_inMin)
                    {
                        if(n4==100 || n4%100==1)
                        {
                            arr4=(int*)realloc(arr4,100*sizeof(int));
                        }
                        arr4[n4]=data[i].s_cameraID;
                        n4++;
                        if(n4==1)
                        {
                            monthE=i;
                        }
                    }
                }
                if(isLater!=0 && n3!=0)
                {
                    if(arr3[0]==data[i].s_inMin)
                    {
                        if(n5==100 || n5%100==1)
                        {
                            arr5=(int*)realloc(arr5,100*sizeof(int));
                        }
                        arr5[n5]=data[i].s_cameraID;
                        n5++;
                        if(n5==1)
                        {
                            monthL=i;
                        }
                    }
                }
            }
            identicalE=0;
            identicalL=0;
            qsort(arr4,n4,sizeof(*arr4),(int(*)(const void *, const void *)) daysMinCompare); 
            qsort(arr5,n5,sizeof(*arr5),(int(*)(const void *, const void *)) daysMinCompare);                
            for (int i = 0; i <n4; i++)
            {
                identicalE++;
            }
            for (int i = 0; i <n5; i++)
            {
                identicalL++;
            }
            if(isEarlier==0)
            {
                printf("> Predchazejici: N/A\n");
                printf("> Pozdejsi: %s %d %02d:%02d, %dx ",data[monthL].s_month,data[monthL].s_day,data[monthL].s_hour,data[monthL].s_min,identicalL);
                printf("[");
                startPosition=0;
                endPosition=n5-1;
                while (startPosition<=endPosition)
                {
                    printf("%d",arr5[startPosition]);
                    startPosition++;
                    if(arr5[startPosition]!='\0')
                    {
                        printf(", ");
                    }
                }
                printf("]\n");
            }
            else if(isLater==0)
            {
                printf("> Predchazejici: %s %d %02d:%02d, %dx ",data[monthE].s_month,data[monthE].s_day,data[monthE].s_hour,data[monthE].s_min,identicalE);
                printf("[");
                startPosition=0;
                endPosition=n4-1;
                while (startPosition<=endPosition)
                {
                    printf("%d",arr4[startPosition]);
                    startPosition++;
                    if(arr4[startPosition]!='\0')
                    {
                        printf(", ");
                    }
                }
                printf("]\n");
                printf("> Pozdejsi: N/A\n");
            }
            else if(isEarlier!=0 && isLater!=0)
            {
                printf("> Predchazejici: %s %d %02d:%02d, %dx ",data[monthE].s_month,data[monthE].s_day,data[monthE].s_hour,data[monthE].s_min,identicalE);
                printf("[");
                startPosition=0;
                endPosition=n4-1;
                while (startPosition<=endPosition)
                {
                    printf("%d",arr4[startPosition]);
                    startPosition++;
                    if(arr4[startPosition]!='\0')
                    {
                        printf(", ");
                    }
                }
                printf("]\n");
                printf("> Pozdejsi: %s %d %02d:%02d, %dx ",data[monthL].s_month,data[monthL].s_day,data[monthL].s_hour,data[monthL].s_min,identicalL);
                printf("[");
                startPosition=0;
                endPosition=n5-1;
                while (startPosition<=endPosition)
                {
                    printf("%d",arr5[startPosition]);
                    startPosition++;
                    if(arr5[startPosition]!='\0')
                    {
                        printf(", ");
                    }
                }
                printf("]\n");
            }
        }   
    }
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
}
CAMERA *readRZ(int *n)
{
    int sum=0;
    CAMERA* data=NULL;
    char tmp='0';
    int max=0;
    /*--------------------*/
    int cameraID;
    char RZ[1001];
    char month[4];
    int monthInt;
    int day;
    int hour;
    int min;
    int input;
    char lastCharacter;
    /*--------------------*/
    *n=0;
    input=scanf(" { %d : %1000s %3s %d %2d : %2d %1c",&cameraID,RZ,month,&day,&hour,&min,&lastCharacter);
    if(input!=7 || (lastCharacter!='}' && lastCharacter!=','))
    {  
        free(data);          
        return NULL;
    }
    if(*n>=max)
    {
        if(max<10)
        {
            max=max+10;
        }
        else
        {
            max=max+5;
        }
        data=(CAMERA*)realloc(data,max*sizeof(*data));
    }
    //checking if the first literal is capital
    if(month[0]>='a' && month[0]<='z')
    {
        return NULL;
    }
    //Checking months
    monthInt=months(month,day);
    if(monthInt==0)
    {   
        return NULL;
    }
    //Checking hours and minutes
    if(hour>23 || hour<0 || min>59 || min<0)
    {
        return NULL;          
    }
    sum=(numOfDay(monthInt,day))*1440+hour*60+min;
    strncpy(data[*n].s_RZ,RZ,sizeof(data[*n].s_RZ));
    strncpy(data[*n].s_month,month,sizeof(data[*n].s_month));
    data[*n].s_cameraID=cameraID;
    data[*n].s_day=day;
    data[*n].s_hour=hour;
    data[*n].s_min=min;
    data[*n].s_monthInt=monthInt;
    data[*n].s_inMin=sum;
    ++*n;
    while (tmp!='}' && lastCharacter!='}')
    {
        input=scanf("%d : %1000s %3s %d %2d:%2d %1c",&cameraID,RZ,month,&day,&hour,&min,&lastCharacter);
        if((lastCharacter!=',' && lastCharacter!='}') || input!=7 ||tmp=='}')
        {
            free(data);
            return NULL;
        }
        if(*n>=max)
        {
            if(max<10)
            {
                max=max+10;
            }
            else
            {
                max=max+5;
            }
            data=(CAMERA*)realloc(data,max*sizeof(*data));
        }
        //checking if the first literal is capital
        if(month[0]>='a' && month[0]<='z')
        {
            return NULL;
        }
        //Checking months
        monthInt=months(month,day);
        if(monthInt==0)
        {   
            return NULL;
        }
        //Checking hours and minutes
        if(hour>23 || hour<0 || min>59 || min<0)
        {
            return NULL;          
        }
        sum=(numOfDay(monthInt,day))*1440+hour*60+min;
        strncpy(data[*n].s_RZ,RZ,sizeof(data[*n].s_RZ));
        strncpy(data[*n].s_month,month,sizeof(data[*n].s_month));
        data[*n].s_cameraID=cameraID;
        data[*n].s_day=day;
        data[*n].s_hour=hour;
        data[*n].s_min=min;
        data[*n].s_monthInt=monthInt;
        data[*n].s_inMin=sum;
        ++*n;
        tmp=lastCharacter;
    }
    return data;
}

int main(void)
{
    int sum;
    int n;
    CAMERA *data;
    int nRz=0;
    char *RZ;
    int nMonth=0;
    char *month;
    int monthInt;
    int day;
    int hour;
    int min;
    int input;
    RZ=(char*)calloc(1001,sizeof(char));
    month=(char*)calloc(4,sizeof(char));
    printf("Data z kamer:\n");
    data=readRZ(&n);
    if(!data)
    {
        printf("Nespravny vstup.\n");
        free(data);
        return 0;
    }
    printf("Hledani:\n");
    while ((input=scanf(" %1000s %3s %d %2d:%2d",RZ,month,&day,&hour,&min))!=EOF)
    {
        if(input!=5)
        {
            printf("Nespravny vstup.\n");
            free(data);
            return 0;
        }
        //checking if the first literal is capital
        if(month[0]>='a' && month[0]<='z')
        {
            printf("Nespravny vstup.\n");
            free(data);
            return 0;
        }
        //Checking months
        monthInt=months(month,day);
        if(monthInt==0)
        { 
            printf("Nespravny vstup.\n");  
            free(data);
            return 0;
        }
        //Checking hours and minutes
        if(hour>23 || hour<0 || min>59 || min<0)
        {
            printf("Nespravny vstup.\n");
            free(data);
            return 0;        
        }
        nRz++;
        nMonth++;
        if(nRz>=1000)
        {
            RZ=(char*)realloc(RZ,1001*sizeof(char));
        }
        if(nMonth>=4)
        {
            month=(char*)realloc(month,4*sizeof(char));
        }
        sum=(numOfDay(monthInt,day))*1440+hour*60+min; 
        findRZ(data,n,RZ,month,monthInt,day,hour,min,sum);
        free(RZ);
        free(month);

    }
    free(data);
    return 0;
}