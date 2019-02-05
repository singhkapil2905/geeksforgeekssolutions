// https://practice.geeksforgeeks.org/problems/longest-even-length-substring/0

#include <iostream>

int GetLargestSubarray(const std::string& s) {
    const auto N = s.size();
    if (N < 2) {
        return 0;
    }
    
    auto max_len = int{0};
    auto centre = int{1};
    
    do {
        auto l = centre - 1;
        auto r = centre;
        auto lsum = 0;
        auto rsum = 0;
        
        while (l >= 0 && r < N) {
            lsum += s[l] - '0';
            rsum += s[r] - '0';
            if (lsum == rsum) {
                max_len = std::max(max_len, r - l + 1);
            }
            --l;
            ++r;
        }
        ++centre;
    } while (centre < N);
    return max_len;
}

int main() {
	auto T = int{0};
	
	std::cin >> T;
	
	while (T--) {
	    std::string s{};
	    
	    std::cin >> s;
	    
	    std::cout << GetLargestSubarray(s) << std::endl;
	}
	return 0;
}
