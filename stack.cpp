#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    int num, input;
    string op = ""; // ���ڿ��� �� ���ڿ��� �ʱ�ȭ
    int tmp = 1;
    stack<int> i;

    cin >> num;
    

    for(int j = 0; j < num; j++){
        cin >> input;
        if(tmp <= input){
            while(tmp <= input){ // tmp�� input���� �۰ų� ���� ����
                i.push(tmp);
                op += '+';
                tmp++;
            }
            op += '-';
            i.pop();
        } else {
            if(i.empty() || i.top() != input){
                cout << "NO";
                return 0;
            }
            op += '-';
            i.pop();
        }
    }

    for (int j = 0; j < op.length(); j++)
    {
        cout << op[j] << "\n";
    }

    return 0;
}
