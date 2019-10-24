/*
- - - - - - - - - - - - 
QUESTION (Zonal Computing Olympiad, 2016)
 
Uncle Shiva is an avid collector of books. In his study he has two shelves with N books in each of the shelves. He has invited Lavanya to decorate his study.
Lavanya feels that the arrangement of books in the two shelves is not aesthetic. She has come up with a measure for the elegance of the two shelves called "Skew". The skew of the two bookshelves is defined to be the sum of the heights of the tallest books in each of the shelves.
Lavanya recommends rearranging the books b/w the two shelves so that the Skew is as small as possible. On the other hand, Uncle Shiva prides himself as a balanced personality and always wants the two shelves to have an equal no of books, N in each.
 
Lavanya is an artist, she merely recommends what needs to be done, leaving the actual work to Uncle Shiva. Uncle Shiva on the other hand is lazy and and would like to do very little work. As a compromise, Uncle Shiva is willing to exchange books betwwen the two shelves K times and would like to do these exchanges cleverly so as to make the skew as small as possible (via K swaps).
For example, suppose each shelf contained  books, where the heights of the books on the first shelf are 3,5,2,7 and 1, and the heights of the books on the second shelf are 14,2,3,10 and 4.The skew of the arrangement is 7 + 14 = 21. If K = 1, i.e., Uncle Shiva is willing to exchange only one book b/w the two, he can swap the book with height 2 in the shelf 1 with the book with the height 14 in shelf 2 and this will increase the skew to 24! On the other hand if he swaps the book with height 7 in the first shell with the book with height 3 in the second shell then resulting arrangement has a skew of 5 + 14 = 19. You can verify that if K = 1 then this is the smallest Skew that can be acheived. So for this case the answer is 19.
 
Your task is to write a program that takes as input - N - the no of books in each shelf, K - the no of swaps that Uncle Shiva is willing to do, and the heights of the books on the two shelves, and computes the smallest Skew value that can be achieved through at most K swaps of books b/w the two shelves.
 
- - - - - - - - - - - - - - - 
INPUT FORMAT
 
(i) There is only one line, which contains ((2 x N) + 2) space seperated integers.
(ii) The first two integers are N and K.
(iii) The next N integers, give the heights of the N books in the first book shelf.
(iv) The last N integers, give the heights of the N books in the second book shelf.
 
- - - - - - - - - - - - - - - -
OUTPUT FORMAT 
A single line with a single integer giving the minimumSkew that can be achieved via at most K swaps b/w the two bookshelves.
 
- - - - - - - - - - - - - - - - 
TEST DATA
You may assume that the height of all the books lie in the range b/w 0 and 10^8, both inclusive and that 1 <= N <= 10^5. Note that there may be more than one book with the same height on a bookshelf.
 
- - - - - - - - - - - - - - - -
SUBTASK 1 (30 Marks)
You may assume that K = 1.
 
- - - - - - - - - - - - - - - - 
SUBTASK 2 (70 Marks)
0 <= K <= N
 
- - - - - - - - - - - - - - - - -
SAMPLE INPUT 
5 1 3 5 2 7 1 14 2 3 10 4
 
- - - - - - - - - - - - - - - - -
SAMPLE OUTPUT
19
 
- - - - - - - - - - - - - - - - - -
EXPLANATION 
N = 5, K = 1
The 1st book shelf contains books with heights {3,5,2,7,1}.
The 2nd book shelf contains bppks with heights {14,2,3,10,4}.
This is same as example explained above, and so the answer is 19.
- - - - - - - - - - - - - - - - - - -
COMPILATION TIME LIMIT
 
1s
*/
 
/*
|= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =|
|			Solution By h!m@nshu			          |
|	This works fine for G++ or CodeBlocks or any similar C++ 	  |		
|	compiler. However this will not work for TURBO C compilers.	  |
|	You need to do the necessary changes for such compilers.          |
|	This is solution for subtask2 only. Solution for subtask2	  |
|	can be found in the file "bookshelves_zco1". There are things     |
|	which could have been done in a better and more efficient way,    |
|	but I leave that job for you.					  |
|= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =|
*/
 
#include <iostream>
 
using namespace std;
 
int main(){
	int assign(char [], long [], long);
	int addspace(char []);
	void bubsort(long [], long);
	long maxo(long [], long);
	long maxpos(long [], long);
	long minpos(long [], long);
	long i,l,m,j,flag=0;
	long size1=2000025;
	char ar[size1];
	long m1,m2,tmp;
	long num=0;	
	cin.getline(ar,size1);
	long * fin;
	for(i=0;ar[i]!=' ';i++){
		num=num*10+(ar[i]-'0');
	}
	long unsigned numz=num*2 + 2;
	fin=new (nothrow) long [numz];
	long sizex=num;
	long x[sizex];
	long y[sizex];
	addspace(ar);
	assign(ar,fin,size1);
	long K=fin[1];
	for(i=0;i!=sizex;i++){
		x[i]=fin[2+i];
		y[i]=fin[2+sizex+i];
	}
	bubsort(x,sizex);
	bubsort(y,sizex);
	m1 = maxo(x,sizex);
	m2 = maxo(y,sizex);
	long skew=m1+m2;
	if(m1>m2){
		for(i=0;i!=K;i++){
			m=maxpos(y,sizex);
			l=minpos(x,sizex);
			tmp=y[m];
			y[m]=x[l];
			x[l]=tmp;
			skew=maxo(x,sizex)+maxo(y,sizex);
			/*if(tmp<skew){
				skew=tmp;
			}*/
		}
	}
	else if(m1<m2){
		for(i=0;i!=K;i++){
			m=maxpos(x,sizex);
			l=minpos(y,sizex);
			tmp=x[m];
			x[m]=y[l];
			y[l]=tmp;
			skew=maxo(x,sizex)+maxo(y,sizex);
			/*if(tmp<skew){
				skew=tmp;
			}*/
		}
	}
	else{
		for(j=0;x[j]-y[j]==0 && j!=sizex;j++);
		if(j==sizex-1){
			for(i=0;i!=K;i++){
				m=maxpos(y,sizex);
				l=minpos(x,sizex);
				tmp=y[m];
				y[m]=x[l];
				x[l]=tmp;
				skew=maxo(x,sizex)+maxo(y,sizex);
				/*if(tmp<skew){
					skew=tmp;
				}*/
			}
		}
		else{
			if(x[j]-y[j]<0){
				for(i=0;i!=K;i++){
					m=maxpos(x,sizex);
					l=minpos(y,sizex);
					tmp=x[m];
					x[m]=y[l];
					y[l]=tmp;
					skew=maxo(x,sizex)+maxo(y,sizex);
					/*if(tmp<skew){
						skew=tmp;
					}*/
				}
			}
			else{
				for(i=0;i!=K;i++){
					m=maxpos(y,sizex);
					l=minpos(x,sizex);
					tmp=y[m];
					y[m]=x[l];
					x[l]=tmp;
					skew=maxo(x,sizex)+maxo(y,sizex);
					/*if(tmp<skew){
						skew=tmp;
					}*/
				}
			}
		}
	}
	cout<<skew<<endl;
	return 0;
}
 
int assign(char ar[],long fin[],long size){
	long i=0,ctr=0;
	long num=0;
	for(i=0;i!=size;i++){
		if(ar[i]!=' '){		
			num = num*10 + (ar[i] - '0');
		}
		else{
			fin[ctr]=num;
			num=0;
			ctr++;
		}
	}
	return 0;
}
 
int addspace(char a[]){
	long i;	
	for(i=0;a[i]!='\0';i++);
	a[i]=' ';
	return 0;
}
 
void bubsort(long x[], long s){
	long i,j;
	long tmp;
	for(i=1;i!=s;i++){
		for(j=i;x[j]<x[j-1] && j!=0;j--){
		    tmp=x[j];
		    x[j]=x[j-1];
		    x[j-1]=tmp;
		}
	}
}
 
long maxo(long a[], long size){
	long i;
	long maxi = a[0];
	for(i=0;i!=size;i++){
		if(a[i]>maxi){
			maxi=a[i];
		}
	}
	return maxi;
}
 
long maxpos(long a[], long s){
	long maxp=0,i;
	long maxi=a[0];
	for(i=1;i!=s;i++){
		if(a[i]>maxi){
			maxi=a[i];
			maxp=i;
		}
	}
	return maxp;
}
 
long minpos(long a[], long s){
	long maxp=0,i;
	long maxi=a[0];
	for(i=1;i!=s;i++){
		if(a[i]<maxi){
			maxi=a[i];
			maxp=i;
		}
	}
	return maxp;
}
