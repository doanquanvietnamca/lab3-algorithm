#include <bits/stdc++.h>
long long calculate(const int n, const int k)
{
	int seq[16] = {0};
	int add[16] = {0};
	seq[0] = k - 1;
	for (int i = 1; i < n; i++)
	{
		add[i] = seq[i-1];
		seq[i] = (add[i-1] + seq[i-1]) * (k-1);
	}
	return seq[n-1] + add[n-1];
}
int main()
{
  FILE* open('input.txt', 'r', stdin);
  FILE* open('output.txt','w',stdout);
  int n = 0, k = 0;
	cin>>n>>k;
	cout<<calculate(n, k)<<endl;
	return 0;
}
