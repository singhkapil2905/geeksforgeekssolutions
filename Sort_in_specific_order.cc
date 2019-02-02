//https://practice.geeksforgeeks.org/problems/sort-in-specific-order/0

#include <iostream>
#include <vector>
#include <algorithm>

using li = long int;

void Sort(std::vector<li>& vec) {
    if (vec.size() < 2) {
        return;
    }
    
    auto pivot = std::partition(std::begin(vec),
                   std::end(vec),
                   [] (int x) {
                       return ((x&1) == 1);
                   });

    std::sort(std::begin(vec),
              pivot,
              std::greater<int>());
              
    std::sort(pivot,
              std::end(vec),
              std::less<int>());
}

int main() {
    li T, N;
    
    std::cin >> T;
    
    while (T--) {
        std::cin >> N;
        auto vec = std::vector<li>(N);
        
        for (auto idx = 0; idx < N; ++idx) {
            std::cin >> vec.at(idx);
        }
        
        Sort(vec);
        
        for (auto idx = 0; idx < N; ++idx) {
            std::cout << vec.at(idx) << " ";
        }
        
        std::cout << std::endl;
    }
}
