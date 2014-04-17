
#include "answer11.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void printPuzzle(const char * state)
{
    int row, col;
    for(row = 0; row < SIDELENGTH; ++row) {
	for(col = 0; col < SIDELENGTH; ++col) {
	    printf(" %c", state[row*SIDELENGTH + col]);
	}
	printf("\n");
    }
}

void MoveTree_print(MoveTree * node)
{
    if(node == NULL)
	return;
    printf("%s\n", node -> state);
    MoveTree_print(node -> left);
    MoveTree_print(node -> right);
}


void printPuzzle(const char * state)
{
    int indx,indy;
    for(indy=0;indy<4;indy++)
    {
        for(indx=0;indx<4;indx++)
        {
            printf("%c ",state[indy*4+indx]);
        }
        printf("\n");
    }
}

int charcmp(const void *a, const void *b)
{
    return *((char*)a)-*((char*)b);
}

int isValidState(const char * state)
{
    if(strlen(state)!=16) return FALSE;
    char buffer[17];
    strcpy(buffer,state);
    qsort(buffer,16,sizeof(char),charcmp);
    const char *valid="-123456789ABCDEF";
    if(strcmp(buffer,valid)==0) return TRUE;
    return FALSE;
}

int isValidMoveList(const char * movelist)
{
    int ind;
    const char *valid="RLUD";
    int len=strlen(movelist);
    for(ind=0;ind<len;ind++)
    {
        if(strchr(valid,movelist[ind])==NULL) return FALSE;
    }
    return TRUE;
}

void swap(char *a,char *b)
{
    char tmp=*a;
    *a=*b;
    *b=tmp;
}

int move(char * state, char m)
{
    int position;
    for(position=0; position<SIDELENGTH*SIDELENGTH;position++)
    {
        if(state[position]=='-') break;
    }
    int row=position/SIDELENGTH;
    int col=position % SIDELENGTH;
    int new_row=row,new_col=col;
    switch(m){
        case 'U':new_row=row-1;break;
        case 'D':new_row=row+1;break;
        case 'L':new_col=col-1;break;
        case 'R':new_col=col+1;break;
    }

    if(new_row<0 || new_row>=SIDELENGTH || new_col<0 || new_col>=SIDELENGTH) return FALSE;
    int target_position=new_row*SIDELENGTH+new_col;
    swap(state+position,state+target_position);
    return TRUE;
}

void processMoveList(char * state, const char * movelist)
{

}

MoveTree * MoveTree_create(const char * state, const char * moves)
{
    MoveTree *node=malloc(sizeof(MoveTree));
    node->state=strdup(state);
    node->left=NULL;
    node->right=NULL;
    return node;
}

void MoveTree_destroy(MoveTree * node)
{
    if(node==NULL) return;
    MoveTree_destroy(node->left);
    MoveTree_destroy(node->right);
    free(node->state);
    free(node->moves);
    free(node);
}

MoveTree * MoveTree_insert(MoveTree * node, 
               const char * state, 
               const char * moves)
{
    if(node==NULL) return MoveTree_create(state,moves);
    int cmp=strcmp(state,node->state);
    if(cmp==0){
        if(strlen(moves)<strlen(node->moves)){
            free(node->moves);
            node->moves=strdup(moves);
        }
    }
    else if(cmp<0) node->left=MoveTree_insert(node->left,state,moves);
    else if(cmp>0) node->right=MoveTree_insert(node->right,state,moves);
    return node;
}

MoveTree * MoveTree_find(MoveTree * node, const char * state)
{
    if(node==NULL) return NULL;
    int cmp=strcmp(state,node->state);
    if(cmp==0) return NULL;
    else if(cmp<0) return MoveTree_find(node->left,state);
    else if(cmp>0) return MoveTree_find(node->right,state);
    return node;
}

MoveTree * generateAll(char * state, int n_moves)
{

}

char * solve(char * state)
{

}