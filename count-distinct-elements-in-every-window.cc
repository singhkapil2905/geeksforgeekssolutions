// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

{
#include <bits/stdc++.h>
using namespace std;
void countDistinct(int [], int , int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{
    auto constexpr mx = 101;
    const auto N = n;
    auto count = std::vector<int>(mx, 0);
    auto res = 0;
    auto idx = 0;
    
    while (idx < N && idx < k) {
        auto& cnt = count.at(A[idx]);
        if (cnt == 0) {
            ++res;
        }
        ++cnt;
        ++idx;
    }
    
    std::cout << res << " ";
    
    while (idx < N) {
        auto in = A[idx];
        auto out = A[idx - k];
        
        if (in != out) {
            if (count.at(in) > 0 && count.at(out) == 1) {
                --res;
            } else if (count.at(in) == 0 && count.at(out) > 1) {
                ++res;
            }
        }
        ++count.at(in);
        --count.at(out);
        ++idx;
        std::cout << res << " ";
    }
}
