#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int ElsieTypingMode;
    cin >> T >> ElsieTypingMode;

    while (T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        cout << "YES\n";

        if (ElsieTypingMode == 1) {
            string result;
            int flip = 0;

            for (int i = 0; i < N; i++) {
                char want = S[i];
                char producedByM = (flip == 0 ? 'M' : 'O');

                if (producedByM == want) {
                    result.push_back('M');
                } else {
                    result.push_back('O');
                    flip ^= 1;
                }
            }

            cout << result << "\n";
        }
    }

    return 0;
}
