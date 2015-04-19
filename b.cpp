#include <iostream>
//#include <fstream>
//#include <stdlib.h>
#include <stdio.h>
using namespace std;

static bool finished=false;/**found all solution yet?*/
static int MAX;

bool is_a_solution(int a[], int k, int n){
	return (k==n);
}

void construct_candidate(int a[], int k, int n, int c[], int *ncandidates){
	 int i;                       /* counter */
        bool in_perm[MAX];          /* who is in the permutation? */
        for (i=0; i<=MAX; i++) in_perm[i] = false;
        for (i=0; i<k; i++) in_perm[ a[i] ] = true;
        *ncandidates = 0;
        for (i=0; i<=n; i++){
                if (in_perm[i] == false) {
                        c[ *ncandidates] = i;
                        *ncandidates = *ncandidates + 1;
					}
		}
}

void process_solution(int a[], int k, int input){
	int i;                       /* counter */
	for (i=1; i<=k; i++) printf(" %d",a[i]);
	printf("\n");
}

void backtrack(int a[], int k, int input){
	int c[MAX];
	int ncandidates; /** next posistion candidate count */
	int i; /** counter */

	if(is_a_solution(a,k,input)){
		process_solution(a,k,input);
		
	}else{
		k=k+1;
		construct_candidate(a,k,input,c,&ncandidates);
		for (i=0; i<ncandidates; i++) {
			a[k] = c[i];
			backtrack(a,k,input);
			if (finished) return;
		}
	} 
}

void generate_permutations(int n)
{
        int a[MAX];
        backtrack(a,0,n);
}


int main(){
	FILE *pfile;
	pfile=fopen("2.txt","r+");
	if(pfile == NULL){
		printf("cannot open\n");
		return 1;
	}

	int N; int a,b; int W;

	fscanf(pfile, "%d\n%d", &MAX, &N);

	MAX=10;
	int matrix[MAX][MAX]; //** initailize matrix 
	int ary[MAX];
	for(int i=0;i<MAX;i++){
		ary[i]=0;
		for(int j=0;j<MAX;j++){
			matrix[i][j]=0;
		}
	}

	backtrack(ary,0,MAX);
	
		/** mark connected vertex */
	for(int i=0;i<N;i++){
		//process tree here..
		fscanf(pfile, "%d %d", &a, &b);
		a--;b--;

		if(a>b){
			matrix[a][b]=1;
		} else matrix[a][b]=1;
	}

	 //print matrix
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			cout<<matrix[i][j];
		}
		cout<<endl;
	}

	for(int i=0;i<MAX;i++){
		for(int j=i;j<MAX;j++){
			if(matrix[i][j]==1){
				//cout<<i<<" "<<j<<endl;
			}
		}
	}



	fclose(pfile);
	return 0;
}