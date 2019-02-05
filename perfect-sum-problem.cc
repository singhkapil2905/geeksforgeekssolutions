// https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0

#include <iostream>
#include <vector>

using li = long int;
using tab = std::vector<std::vector<li>>;

li SWS(li S, li N, const std::vector<li>& v, tab& t) {
    if (S < 0 || N < 0) {
        return 0;
    }
    
    if (S == 0) {
        return t[S][N] = 1;
    }
    
    if (S > 0 && N == 0) {
        return t[S][N] = 0;
    }
    
    if (t[S][N] != -1) {
        return t[S][N];
    }
    
    return t[S][N] = (SWS(S - v.at(N - 1), N - 1, v, t)
                     +SWS(S, N - 1, v, t));
}

int main() {
	auto T = li{0}, N = li{0}, S = li{0};
	
	std::cin >> T;
	
	while (T--) {
	    std::cin >> N;
	    auto v = std::vector<li>(N);
	    
	    for (auto idx = li{0}; idx < N; ++idx) {
	        std::cin >> v.at(idx);
	    }
	    
	    std::cin >> S;
	    
	    auto t = tab(S + 1, std::vector<li>(N + 1, -1));
	    
	    std::cout << SWS(S, N, v, t) << std::endl;
	}
	return 0;
}
