#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int min, max;
    cin >> min >> max;

    vector<int> num(max + 1, 1);  // �ε����� 0���� max���� ����ϱ� ���� ũ�⸦ max + 1�� ����

    // 0�� 1�� �Ҽ��� �ƴ�
    num[0] = num[1] = 0;

    // �����佺�׳׽��� ü �˰��� ����
    for (int i = 2; i * i <= max; i++) {
        if (num[i]) {  // num[i]�� 1�̸� �Ҽ�
            for (int j = i; j*i <= max; j++) {
                num[j * i] = 0;  // i�� ������� �Ҽ��� �ƴ϶�� ǥ��
            }
        }
    }
    
    for(int k = min; k <=max; k++){
        if(num[k]) cout<<k<<'\n';
    }
    return 0;
}
