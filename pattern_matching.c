#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char S[]= "NOBODY_NOTICEDHIM";
	char P[]= "HIM";
	
	int n= 17;
	int m= 3;
	int i, j;
	
	for (i = 0; i <= n - m; i++) {
	j = 0;
    while (j < m && S[i + j] == P[j]) {
        j++;
    }
    if (j == m) {
        printf("Found '%s' in S at index %d\n", P, i);
        return 0;  
    }
}

	
}
