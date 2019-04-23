#include <iostream>
#include <vector>

using li = long int;

long int GetIdx(const std::vector<long int>& v, long int el) {
    long int N = v.size();
    
    if (N == 0) {
        return -1;
    }
    
    long int s = 0;
    long int e = v.size() - 1;
    
    while (s <= e) {
        if (s == e) {
            if (v.at(s) == el) {
                return s;
            } else {
                return -1;
            }
        }
        
        auto m = s + (e - s) / 2;
        
        if (v.at(m) == el) {
            return m;
        }
        
        if (v.at(s) < v.at(m)) {
            if (el >= v.at(s) && el < v.at(m)) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        } else {
            if (el > v.at(m) && el <= v.at(e)) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
    }
    
    return -1;
}

int main() {
    long int T = 0;
    std::cin >> T;
    
    while (T--) {
        long int N = 0;
        
        std::cin >> N;
        
        auto v = std::vector<long int>(N);
        
        for (auto& el : v) {
            std::cin >> el;
        }
        
        long int K = 0;
        std::cin >> K;
        
        std::cout << GetIdx(v, K) << std::endl;
    }
    
	return 0;
}
