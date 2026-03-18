/*
 * Example 4: Deque Operations (Time and Space Complexity plus STL Algorithms)
 */
// Demonstrates fill, iota, generate, rotate, copy.
#include <bits/stdc++.h>
using namespace std;

int main() {
    // iota — fills with increasing values
    vector<int> v(10);
    iota(v.begin(), v.end(), 1);
    cout << "iota(1..10): "; for(int x:v) cout<<x<<" "; cout<<"\n";

    // fill — sets all elements to a value
    vector<int> zeros(5);
    fill(zeros.begin(), zeros.end(), 42);
    cout << "fill(42): "; for(int x:zeros) cout<<x<<" "; cout<<"\n";

    // generate — fill with function results
    int counter = 0;
    vector<int> gen(5);
    generate(gen.begin(), gen.end(), [&](){ return counter += 3; });
    cout << "generate(multiples of 3): "; for(int x:gen) cout<<x<<" "; cout<<"\n";

    // rotate — O(n), left rotate by k positions
    vector<int> r = {1,2,3,4,5,6,7};
    rotate(r.begin(), r.begin()+3, r.end());  // left rotate by 3
    cout << "rotate left by 3: "; for(int x:r) cout<<x<<" "; cout<<"\n";

    // copy, copy_if
    vector<int> src = {1,2,3,4,5,6,7,8}, dst;
    copy_if(src.begin(), src.end(), back_inserter(dst), [](int x){ return x%2==0; });
    cout << "copy_if (evens): "; for(int x:dst) cout<<x<<" "; cout<<"\n";

    // replace, replace_if
    vector<int> rep = {1,2,3,2,4,2,5};
    replace(rep.begin(), rep.end(), 2, 99);
    cout << "replace 2->99: "; for(int x:rep) cout<<x<<" "; cout<<"\n";

    return 0;
}
