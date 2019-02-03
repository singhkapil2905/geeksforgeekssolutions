// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

#include <iostream>
#include <vector>

using li = long int;

void Sort(std::vector<li>& v) {
    auto s = li{0}, m = li{0}, e = li{v.size() - 1};
    
    while (m <= e) {
        auto& element = v.at(m);
        if (element == 0) {
            std::swap(v.at(s), element);
            ++s;
            ++m;
        } else if (element == 1) {
            ++m;
        } else {
            std::swap(element, v.at(e));
            --e;
        }
    }
}

int main() {
	auto T = li{0}, N = li{0};
	
	std::cin >> T;
	
	while (T--) {
	    std::cin >> N;
	    
	    auto vec = std::vector<li>(N);
	    
	    for (auto idx = li{0}; idx < N; ++idx) {
	        std::cin >> vec.at(idx);
	    }
	    
	    Sort(vec);
	    
	    for (const auto& element : vec) {
	        std::cout << element << " ";
	    }
	    
	    std::cout << std::endl;
	}
	return 0;
}
