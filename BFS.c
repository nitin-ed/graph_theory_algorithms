//Library Definitions

#include<stdio.h>
#include<conio.h>
#include<stddef.h>
#include<stdlib.h>

//Structures

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct Graph
{
    int vertices;
    int* visited;
    struct node **adjlist;
}Graph;

typedef struct qode
{
    int data;
    struct qode *next;
}qode;

//Function Declerations

Graph* create_graph(int v);
node* create_node(int data);
qode* create_qode(int data);
void enqueue(int data);
int dequeue();
int isEmpty();
void add_edge(Graph *graph);
Graph* create_adjlist();
void display_graph(Graph *graph);
void display_queue();
void BFS(Graph* graph ,int start);

//Global Variables

qode* front;
qode* rear;

//MAIN Function

void main()
{
    Graph *graph;
    int start;
    graph = create_adjlist();
    display_graph(graph);
    printf("Enter Starting Vertex for BFS : ");
    scanf("%d" , &start);
    BFS(graph,start);
}

//Functions Defintions count = 10

Graph* create_graph(int v)
{
    Graph *new;
    int i;
    new = (Graph*)malloc(v*sizeof(Graph));
    new->vertices = v;
    new->visited = (int*)malloc(v*sizeof(int));
    new->adjlist = (node**)malloc(v*sizeof(node*));
    i=0;
    for ( i = 0; i < v; i++)
    {
        new->visited[i] = 0;
        new->adjlist[i] = NULL; 
    }
    return new;
}

node* create_node(int data)
{
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

qode* create_qode(int data)
{
    qode *new;
    new = (qode*)malloc(sizeof(qode));
    new->data = data;
    new->next = NULL;
    return new;
}

void enqueue(int data)
{
    qode *new,*temp;
    new = create_qode(data);
    if (front == NULL)
    {
        front = new;
        rear = front;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
}

int dequeue()
{
    int value;
    if(isEmpty()) return 0;
    else if (front == rear)
    {
        value = front->data;
        front = NULL;
        return value;
    }
    else
    {
        value = front->data;
        front = front->next;
        return value;
    }
}

int isEmpty()
{
    return(front == NULL);
}

void add_edge(Graph *graph)
{
    int v1 , v2;
    node *newnode;
    printf("Enter the vertices connected to the edge : ");
    scanf("%d %d" , &v1 , &v2);
    v1--; v2--;

    //connecting v1 to v2
    newnode = create_node(v2);
    newnode->next = graph->adjlist[v1];
    graph->adjlist[v1] = newnode;

    //connecting v2 to v1
    newnode = create_node(v1);
    newnode->next = graph->adjlist[v2];
    graph->adjlist[v2] = newnode; 
}

Graph* create_adjlist()
{
    int v , e , i;
    printf("Enter total number of vertices in the graph : ");
    scanf("%d" ,&v);
    Graph *graph = create_graph(v);
    printf("Enter number of edges to initialize the graph : ");
    scanf("%d" , &e);
    for ( i = 0; i < e; i++)
    {
        add_edge(graph);
    }
    return graph;
}

void display_graph(Graph *graph)
{
    int i;
    for ( i = 0; i < graph->vertices; i++)
    {
        node *temp = graph->adjlist[i];
        printf("%d : " , i + 1);
        while (temp)
        {
            
            printf("-> %d " , temp->data + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

void display_queue()
{
    qode *temp = front;
    printf("\n[ ");
    while(temp != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf(" ]\n");
}

void BFS(Graph* graph ,int start)
{
    start--;
    graph->visited[start] = 1;
    enqueue(start);

    while( !isEmpty())
    {
        display_queue();
        int current = dequeue();
        printf("\nVisited : %d", current + 1);
        node *temp = graph->adjlist[current];

        while(temp)
        {
            int vertex = temp->data;
            if (graph->visited[vertex] == 0)
            {
                graph->visited[vertex] = 1;
                enqueue(vertex);
            }
            temp = temp->next;
        }
    }
}


