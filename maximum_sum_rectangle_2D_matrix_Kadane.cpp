// Program to find maximum sum subarray
// in a given 2D array
#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

// Implementation of Kadane's algorithm for
// 1D array.
int kadane(int* arr, int* start, int* finish, int n)
{
	int sum = 0, maxSum = INT_MIN, i;
	*finish = -1;
	int local_start = 0;

	for (i = 0; i < n; ++i)
	{
		if (sum + arr[i] < arr[i])
		{
			sum = arr[i];
			local_start = i;
		}
		else sum+=arr[i];
		if (sum + arr[i] > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if (*finish != -1)
		return maxSum;

	maxSum = arr[0];
	*start = *finish = 0;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > maxSum)
		{
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

void findMaxSum(int M[][COL])
{
	int maxSum = INT_MIN,
				finalLeft,
				finalRight,
				finalTop,
				finalBottom;

	int left, right, i;
	int temp[ROW], sum, start, finish;

	for (left = 0; left < COL; ++left) {
		memset(temp, 0, sizeof(temp));

		for (right = left; right < COL; ++right) {

			for (i = 0; i < ROW; ++i)
				temp[i] += M[i][right];

			sum = kadane(temp, &start, &finish, ROW);

			if (sum > maxSum) {
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}
	cout << "(Top, Left) ("
		<< finalTop << ", "
		<< finalLeft
		<< ")" << endl;
	cout << "(Bottom, Right) ("
		<< finalBottom << ", "
		<< finalRight << ")" << endl;
	cout << "Max sum is: " << maxSum << endl;
}

// Driver Code
int main()
{
	int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
						{ -8, -3, 4, 2, 1 },
						{ 3, 8, 10, 1, 3 },
						{ -4, -1, 1, 7, -6 } };

	// Function call
	findMaxSum(M);

	return 0;
}

// This code is contributed by
// rathbhupendra
