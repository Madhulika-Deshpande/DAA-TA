#include<stdio.h>
#include<string.h>
#define N 4
#define INF 9999
char fragments[4][4]={"AGT","GTC","TCA","CAT"};
int sequence[N];
int sequences[100][N];
int totallen[100];
int count=0;
int minlen=INF;
int bestsequence[100][N];
int bestcount=0;
int extraLength(int first,int second)
{
    int len1=strlen(fragments[first]);
    int len2=strlen(fragments[second]);
    int overlap=0;
    for(int i=1;i<len1 && i<len2;i++)
    {
        if(strncmp(fragments[first]+len1-i,fragments[second],i)==0)
        overlap=i;
    }
    return len2-overlap;
}
void shortestSequence(int current,int used[],int position,int total)
{
    if(position==N)
    {
        for(int i=0;i<N;i++)
        {
            sequences[count][i]=sequence[i];
        }
        totallen[count]=total;
        count++;
        if(total<minlen)
        {
            minlen=total;
            bestcount=0;
            for(int i=0;i<N;i++)
            {
                bestsequence[bestcount][i]=sequence[i];
            }
            bestcount=1;
        }
        else if(total==minlen)
        {
            for(int i=0;i<N;i++)
            {
                bestsequence[bestcount][i]=sequence[i];
            }
            bestcount++;
        }
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            sequence[position]=i;
            int add=(position==0)?strlen(fragments[i]):extraLength(current,i);
            shortestSequence(i,used,position+1,total+add);
            used[i]=0;
        }
    }
}
int main()
{
    int used[N]={0};
    sequence[0]=0;
    used[0]=1;
    shortestSequence(0,used,1,strlen(fragments[0]));
    printf("All possible sequence:\n");
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("F%d",sequences[i][j]+1);
            if(j<N-1)
            {
                printf("->");
            }
        }
        printf("\n");
    }
    printf("\nTotal length for each sequence:\n");
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("F%d",sequences[i][j]+1);
            if(j<N-1)
            {
                printf("->");
            }
        }
        printf(":%d\n",totallen[i]);
    }
    printf("\nShortest sequence:\n");
    printf("Shortest length:%d\n",minlen);
    for(int i=0;i<bestcount;i++)
    {
        printf("Sequence:");
        for(int j=0;j<N;j++)
        {
            printf("F%d",bestsequence[i][j]+1);
            if(j<N-1)
            {
                printf("->");
            }
        }
        printf("\n");
    }
    char result[100]="";
    strcat(result,fragments[bestsequence[0][0]]);
    for(int i=1;i<N;i++)
    {
        int p=bestsequence[0][i-1];
        int n=bestsequence[0][i];
        int lenp=strlen(fragments[p]);
        int lenn=strlen(fragments[n]);
        int overlap=0;
        for(int k=1;k<lenp && k<lenn;k++)
        {
            if(strncmp(fragments[p]+lenp-k,fragments[n],k)==0)
            overlap=k;
        }
        strncat(result,fragments[n]+overlap,lenn-overlap);
    }
    printf("\nDNA sequence:%s\n",result);
    return 0;
}
