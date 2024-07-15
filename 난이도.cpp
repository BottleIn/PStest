#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> opinions(n);
    for (int i = 0; i < n; ++i) {
        cin >> opinions[i];
    }

    // ���ĵ� ���¿��� 30% ��������� ���
    sort(opinions.begin(), opinions.end());

    // 15%�� �ݿø��Ͽ� ��, �Ʒ��� ������ ���� ���
    int exclude = round(n * 0.15);

    // ������ ������ �ǰ��� ���� ���
    int sum = 0;
    for (int i = exclude; i < n - exclude; ++i) {
        sum += opinions[i];
    }

    // ������ �ǰ��� ������ ����� ���
    int remaining = n - 2 * exclude;
    double trimmed_mean = static_cast<double>(sum) / remaining;

    // ����� �ݿø��Ͽ� ���
    cout << round(trimmed_mean) << endl;

    return 0;
}
