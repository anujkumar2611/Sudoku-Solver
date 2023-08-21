#include <stdio.h>
int arr[9][9]={{0}};
void input()  //taking input 
{
    int i;
    printf("Enter each line with space and enter after every line , empty spaces are 0 \n");
    for(i=0;i<9;i++){
        scanf("%i%i%i%i%i%i%i%i%i",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3],&arr[i][4],&arr[i][5],&arr[i][6],&arr[i][7],&arr[i][8]);
    
        }
}


int isallowed(int r,int c,int n)         //function to check whether a element is allowed 
{
    int i,j,gr,gc;
    for(i=0;i<9;i++)         
    {
        if(arr[r][i]==n||arr[i][c]==n)  //checking rows and columns for the element 
        return 0;
    }
    
    gr=(r/3)*3;                         //checking grid for the element 
    gc=(c/3)*3;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[gr+i][gc+j]==n)
             return 0;
    
        }
    }
    return 1;
}
void solve(int r, int c)                 //algorithm that solves the puzzle 
{
    int i,j,nr=0,nc=0;                     //declaring next row nr , and next column nc
   if(r==9)                                /*chcecking the value of row , if it reaches out of bound , the program ends*/
   {
       printf("\n\n");
       for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            printf("%i ",arr[i][j]);
            printf("\n");
        }
        return ;
   }
    if(c==8)                         //upon reaching the last column , next column is zero while row increases
    {
        nr=r+1;
        nc=0;
    }
    else
    {
        nr=r;
        nc=c+1;
    }
    if(arr[r][c]!=0)
    {
        solve(nr,nc);
    }
    else
    {
        for(i=1;i<10;i++)
        {
            if(isallowed(r,c,i)==1)
            {
                arr[r][c]=i;            //backtracking
                solve(nr,nc);
                arr[r][c]=0;
            }
            
        }

        
    }

}
int main()
{
	int i,j;
    input();                //calling input function
   printf("INPUT:\n");
   	 for(i=0;i<9;i++)             //displaying user input 
        {
            for(j=0;j<9;j++)
            printf("%i ",arr[i][j]);
            printf("\n");
        }
    printf("Solved Sudoku Table:\n");    
        solve(0,0);        //solving 
        
        return 0;
}
