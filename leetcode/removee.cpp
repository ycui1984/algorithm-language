
Remove Element
Total Accepted: 18924 Total Submissions: 57491

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        for (int i = 0; i < n; i++) {
            while (A[i] == elem && i < n) {
                if (i != n-1) {
                    int tmp = A[n-1];
                    A[n-1] = A[i];
                    A[i] = tmp;
                }
                n--;
            }
        }
        
        return n;
    }
};
