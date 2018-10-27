# Fibonacci Series Hard
Everyone knows about fibonacci series: 1, 1, 2, 3, 5, 8, 13, 21, 34,..... . All you have to do is print the Nth fibonacci number.

## Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line containing a single integer - N.

## Constraints

1. 10 points
   - 1 <= T <= 1000
   - 0 <= N <= 20

2. 30 points
   - 1 <= T <= 1000
   - 0 <= N <= 10<sup>3</sup>

3. 60 points
   - 1 <= T <= 1000
   - 0 <= N <= 10<sup>7</sup>

4. 100 points
   - 1 <= T <= 1000
   - 0 <= N <= 10<sup>18</sup>

## Output Format

For each test case, print the Nth Fibonacci number, separated by new line. Since the number can be very large, print result % 1000000007

## Sample Input 0
```
5
0
1
2
100
10
```
## Sample Output 0
```
1
1
2
782204094
89
```
## Explanation 0

Self Explanatory


## Solution 1

### main.cpp

This another O(log n) which relies on the fact that if we n times multiply the matrix M = {{1,1},{1,0}} to itself (in other words calculate power(M, n )), then we get the (n+1)th Fibonacci number as the element at row and column (0, 0) in the resultant matrix.

```
power(M,n)=power(M,n/2)*power(M,n/2);
if n/2 is odd:
    power(M,n)=power(M,n/2)*power(M,n/2)*M;
```

The matrix representation gives the following closed expression for the Fibonacci numbers:

<img src="https://www.geeksforgeeks.org/wp-content/uploads/fibonaccimatrix.png">
