#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;
int getmax(int*arr,int n)//求一维数组的最大连续子 
{
	
}
int main() {
    int N;
    cin >> N;

    int arr[N][N];

    // Read the array
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }
	int temp[N+1];
    // Initialize variables to store the result
    int maxSum = INT_MIN;
    // Dynamic programming to find the sum of the maximal sub-rectangle
    for (int i = 0; i < N; ++i) {//对第i行到第j行求和，进行压缩 
        for (int j = i; j < N; ++j) {
        	memset(temp,0,sizeof(int)*N);
        	for(int l = 0; l < N; l++)//l为列数
			{
				for(int k = i; k <= j; k++)
            	{
            	temp[l]+=arr[k][l];
				}
			 } 
			 int max = temp[0]; 
			 for(int k = 1; k < N; k++)
			 {
			 	temp[k] += temp[k-1]>0?temp[k-1]:0;
			 	if(max < temp[k])
			 	max = temp[k];
			} 
			if(maxSum < max)
			maxSum = max;
        }
    }

    cout << maxSum;

    return 0;
}
