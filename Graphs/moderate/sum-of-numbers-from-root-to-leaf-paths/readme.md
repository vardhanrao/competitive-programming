## Sum of Numbers from Root to Leaf Paths
Given an array of unique elements, construct a Binary Search Tree and print the sum of all the numbers formed along the path from the root node to the leaf nodes.

## Input Format
First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

## Constraints
1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

## Output Format
For each test case, print the sum, separate each traversal by newline. Since the output can be very large, print output % 1000000007.

## Sample Input 0
```
3
5
1 2 3 4 5
5
3 2 4 1 5
7
4 5 15 2 1 7 17
```

## Sample Output 0
```
12345
666
497095
```

## Explanation 0
Test Case 1
Total Sum = 12345

Test Case 1
Total Sum = 321 + 345 = 666

Test Case 1
Total Sum = 421 + 45157 + 451517 = 497095
