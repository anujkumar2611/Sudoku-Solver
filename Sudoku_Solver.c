#include <stdio.h>
int arr[9][9]={ {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
int main()
{
   int i,j,a=solve(0,0);
   if(a==1)
    {
    	 for( i=0;i<9;i++)
        {
            for( j=0;j<9;j++)
            printf("%i",arr[i][j]);
            printf("\n");
        }
    }
    if(a!=1)
    {
    	printf("imposssible");
    }
}
int isallowed(int r,int c,int n)         //function to check whether a elemenrt is allowed 
{
    int i,gr,gc;
    for( i=0;i<9;i++)         
    {
        if(arr[r][i]==n||arr[i][c]==n)  //checking rows and columns for the element 
        return 0;
    }
    return 1;
    gr=(r/3)*3;                         //checking grid for the element 
    gc=(c/3)*3;
    for(i=0;i<3;i++)
    if(arr[gr+i][gc+i]==n)
    return 0;
    return 1;
}
int solve(int r, int c)
{int nr,nc,i;
   if(r==9)
   return 1;
    if(c==8)
    {
        nr=r+1;
        nc=0;
    }else{
        nr=r;
        nc=c+1;
    }
    if(arr[r][c]!=0)
    {
        solve(nr,nc);
    }else
	{
        for( i=1;i<10;i++)
        {
            if(isallowed(r,c,i)==1)
            {
                arr[r][c]=i;
                solve(nr,nc);
                arr[r][c]=0;
            }
            
        }
        
    }
   return 0;
        
}

