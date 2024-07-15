#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int total = 0;
    int N;
    cin >> N;
    vector<int> nums(N);
    vector<int> count(8001, 0);  // ������ 4000�� ���� �ʱ� ������ ������ 8001

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        total += nums[i];
        count[4000 + nums[i]]++;
    }

    sort(nums.begin(), nums.end());

    // ������
    cout << round(static_cast<double>(total) / N) << endl;

    // �߾Ӱ�
    cout << nums[N / 2] << endl;

    // �ֺ� ���
    int max_freq = 0;
    vector<int> mode_candidates;

    for (int i = 0; i < 8001; i++) {
        if (count[i] > max_freq) {
            max_freq = count[i];
            mode_candidates = {i - 4000};
        } else if (count[i] == max_freq) {
            mode_candidates.push_back(i - 4000);
        }
    }

    int mode;
    if (mode_candidates.size() == 1) {
        mode = mode_candidates[0];
    } else {
        sort(mode_candidates.begin(), mode_candidates.end());
        mode = mode_candidates[1];  // �� ��°�� ���� ��
    }

    cout << mode << endl;

    // ����
    cout << nums.back() - nums.front() << endl;

    return 0;
}
