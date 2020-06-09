//Library Definition

#include<stdio.h>
#include<stddef.h>

//Constant Definition

#define maxv 10

//Structure Definition
 
typedef struct adjacency_matrix
{
    int v;
    int mat[maxv][maxv];
}adj_mat;

//Function Definition

adj_mat* adj_matrix();
void display_adj_matrix(adj_mat* a);

//Main Function

int main()
{
    display_adj_matrix(adj_matrix());
}



adj_mat* adj_matrix()
{
    int i,j,v,e,x,y;
    adj_mat* a;
    a = (adj_mat*)malloc(sizeof(adj_mat));

    printf("Enter Number of Vertices in the graph : ");
    scanf("%d",&v);
    a->v = v;
    for( i = 0 ; i < v ; i++)
        for( j = 0 ; j < v ; j++) a->mat[i][j]=0;
    
    printf("Enter number of edges :");
    scanf("%d",&e);

    for( i = 0 ; i < e ; i++)
    {
        printf("Enter node pairs to initialize edges : ");
        scanf("%d %d",&x,&y);
        a->mat[x-1][y-1] = 1;
        a->mat[y-1][x-1] = 1;
    }
    
    return a;

}

void display_adj_matrix(adj_mat* a)
{
    int size = a->v , i,j;
    printf("Adjacency Matrix\n");
    if(a == NULL) 
    {
        printf("No Matrix Avaliable");
        return;
    }
        
    for(i=0;i<size;i++)
    {
        printf("|");
        for(j=0;j<size;j++)
        {
            printf("  %d  " , a->mat[i][j]);
        }
        printf("|\n");
    } 
    
}
