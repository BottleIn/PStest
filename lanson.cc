#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long first = 1, last = 0;
    int num1, num2;
    long long result = 0;
    cin >> num1 >> num2;
    
    vector<int> nums(num1);

    for(int i = 0; i < num1; i++) {
        int tmp;
        cin >> tmp;
        nums[i] = tmp;
        if(tmp > last) {
            last = tmp;
        }
    }

    while(first <= last) {
        long long mid = (first + last) / 2;
        long long total = 0;

        for(int i = 0; i < num1; i++) {
            total += nums[i] / mid;
        }

        if(total >= num2) {
            result = mid;
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }
    
    cout << result;
    return 0;
}
