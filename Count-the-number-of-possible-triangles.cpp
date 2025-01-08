
/*Count the number of possible triangles
Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. 

A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.

Examples:

Input: arr[] = [4, 6, 3, 7]
Output: 3
Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. Note that [3, 4, 7] is not a possible triangle.  
Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
Output: 6
Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200] and [101, 200, 300]
Input: arr[] = [1, 2, 3]
Output: 0
Explanation: No triangles are possible.
Constraints:
3 <= arr.size() <= 103
0 <= arr[i] <= 105
*/

//-----------------------------------------------------Brute force---------------------------------
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& v) {
        // code here
        int n=v.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(k==i || k==j)continue;
                    
                    if(v[i]+v[j]>v[k] && v[j]+v[k]>v[i] && v[k]+v[i]>v[j]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

//--------------------------------------------optimal using two pointer------------------------------------------------

class Solution {
    // Function to count the number of possible triangles.
    // code for c++ and java is same so I am providing only java code.
    static int countTriangles(int arr[]) {
        // code here
        Arrays.sort(arr);
        int ans=0;
        for(int i=arr.length-1;i>=0;i--){
            int st=0, end=i-1;
            while(st<end){
                if(arr[st]+arr[end]>arr[i]){
                    ans+=end-st;
                    end--;
                }
                else {
                    st++;
                }
            }
        }
        return ans;
    }
}

