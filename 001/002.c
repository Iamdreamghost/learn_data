#include<stdio.h>
#include<stdlib.h>

int main()
{
	short A,B,C,D,T1,T2,T3,T4;
	for(A=0; A<2; A++)
		for(B=0; B<2; B++)
			for(C=0; C<2; C++)
				for(D=0; D<2; D++)
				{
					T1 = (B+C+D == 1);
					T2 = (!B&&C);
					T3 = (A+D == 1);
					T4 = T2;
					if( (A+B+C+D == 1) && (T1+T2+T3+T4 == 2) )
					{
						printf("%d  %d  %d  %d\n",A,B,C,D);
					}
				}
}
