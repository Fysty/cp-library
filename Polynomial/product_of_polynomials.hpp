#pragma once

#include "Polynomial/convolution.hpp"

// returns prod_i polys[i]
template<typename T>
vector<T> product_of_polynomials(vector<vector<T>> polys) {
    if (polys.empty()) return vector<T>{1};
    for (int k = (int)polys.size(); k > 1; k = (k + 1) / 2) {
        for (int i = 0; i + 1 < k; i += 2)
            polys[i / 2] = convolution(polys[i], polys[i + 1]);
        if (k & 1) polys[k / 2] = move(polys[k - 1]);
    }
    return polys[0];
}
