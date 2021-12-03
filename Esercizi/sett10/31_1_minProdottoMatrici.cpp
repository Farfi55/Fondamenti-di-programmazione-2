#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

int minProdottoMatrici(const vector<int>& r, int n)
{
	assert(n>0 && r.size()==n+1);
	vector<vector<int>> m(n, vector<int>(n));
	
	// calcolo dei costi per valori crescenti di v=i-j
	for (int v=1; v<=n-1; v++)
	{
		for (int i=0; i<n-v; i++)
		{	
			int j=i+v;
			// calcolo di mij come minimo costo
			// inizializzo il minimo con k=i; N.B.: se k=i, m[i][i]=0
			int k=i;
			m[i][j]=m[i][k]+m[k+1][j]+r[i]*r[k+1]*r[j+1]; 
			cout<<"v:"<<v<<" i:"<<i<<" j:"<<j<<endl;
			for (k=i+1; k<j; k++)
			{ 	cout<<"v:"<<v<<" i:"<<i<<" j:"<<j<<" k:"<<k <<endl;
				int mTemp=m[i][k]+m[k+1][j]+r[i]*r[k+1]*r[j+1];
				m[i][j]=min(mTemp,m[i][j]);
			}
		}
	}
	return m[0][n-1];
}

int main(){
	vector<int> r={10,20,50,1,100};
	
	cout<<minProdottoMatrici(r,4); 

return 0;
}
