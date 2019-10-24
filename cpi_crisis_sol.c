#include <stdio.h>
 
int arr[1000];
int vis[1000];
 
int main(int argc, char const *argv[]) {
	int t;
	scanf("%d", &t);
	while(t-- ) {
		int i, j, k, n; scanf("%d%d", &n, &k);
		long long num = 0, den = 0;
		for (i = 0; i < n; vis[i] = 0, i++)
			scanf("%d", arr + i);
		while(k--) {
			double maxr = 0, temp;
			for (i = 0; i < n; i++)
				if (!vis[i]) {
					temp = 1.0 * (num + (i + 1) * arr[i]) / (den + i + 1);
					if (temp > maxr) j = i, maxr = temp;
				}
			num += (j + 1) * arr[j]; den += j + 1; vis[j] = 1;
		}
		printf("%.9f\n", 1.0 * num / den) ;
	}
	return 0;
} 
