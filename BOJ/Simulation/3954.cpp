#include <iostream>
#define MXSIZE 4097
using namespace std;
char oper[MXSIZE], input[MXSIZE];
int stack[MXSIZE], arr[100001], loop[MXSIZE];;
int Sm, Sc, Si;
void PairLoop() {
    int top = -1;
    for (int i = 0; i < Sc; i++) {
        if (oper[i] == '[') {
            stack[++top] = i;
        }
        else if(oper[i] == ']'){
            stack[++top] = i;
            loop[stack[top]] = stack[top - 1];
            loop[stack[top - 1]] = i;
            top -= 2;
        }
    }
}
int main(void) {
    int T;
    cin >> T;
    while (T--) {
        cin >> Sm >> Sc >> Si;
        for (int i = 0; i < Sm; i++) arr[i] = 0;
        for (int j = 0; j < Sc; j++) loop[j] = 0;
        cin >> oper;
        cin >> input;
        PairLoop();
        int idx = 0, oper_idx = 0, input_idx = 0, max_oper_idx = 0;
        bool flag = false;
        for (int i = 1; i <= 50000000; i++) {
            if (oper_idx >= Sc) {
                cout << "Terminates" << endl;
                flag = true;
                break;
            }
            if (oper[oper_idx] == '-') {
                arr[idx] = (arr[idx] - 1) < 0 ? 255 : arr[idx] - 1;
            }
            else if (oper[oper_idx] == '+') {
                arr[idx] = (arr[idx] + 1) % 256;
            }
            else if (oper[oper_idx] == '<') {
                idx = idx - 1 < 0 ? Sm - 1 : idx - 1;
            }
            else if (oper[oper_idx] == '>') {
                idx = (idx + 1) % Sm;
            }
            else if (oper[oper_idx] == '[') {
                if (arr[idx] == 0) {
                    oper_idx = loop[oper_idx];
                }
            }
            else if (oper[oper_idx] == ']') {
                if (arr[idx] != 0) {
                    oper_idx = loop[oper_idx];
                }
            }
            else if (oper[oper_idx] == ',') {
                int c = input_idx >= Si ? 255 : (int)input[input_idx];
                arr[idx] = c;
                input_idx = input_idx >= Si ? input_idx : input_idx + 1;
            }
            oper_idx++;
            max_oper_idx = oper_idx > max_oper_idx ? oper_idx : max_oper_idx;
        }
        if (!flag) {
            cout << "Loops " << loop[max_oper_idx] << " " << max_oper_idx << endl;
        }
    }
    
    return 0;
}
