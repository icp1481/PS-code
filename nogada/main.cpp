#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;


string convertCamelCaseToUnderscore(const string& input) {
    string result;
    int i;
    for (i = 0; i < input.size(); i++) {
        if (isupper(input[i])) {
            // 대문자가 나오면 언더바를 추가하고 소문자로 변환
            if (i > 0) result += '_';
            result += tolower(input[i]);
        } else {
            // 소문자는 그대로 추가
            result += input[i];
        }
    }

    return result;
}
int main() {
    // 입력 받기
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string a, b, tb;

   // cout << "<string name=" << app_name">K-Dual</string>" << endl << endl;
    while (1) {
        getline(cin, a);
        if (a == "!!!fin") break;
        cout << "<!-- " << a << ".kt" << "-->" << endl;
        //replace(a.begin(), a.end(), ' ', '_');
        //transform(a.begin(), a.end(), a.begin(), ::tolower);
        a = convertCamelCaseToUnderscore(a);
        while (1) {
            getline(cin, b);
            if (b == "!!!end1") break;
            // a의 공백을 "_"로 대체하고 소문자로 변환
            tb = b;

            replace(tb.begin(), tb.end(), ' ', '_');
            transform(tb.begin(), tb.end(), tb.begin(), ::tolower);
            // b의 첫 문자를 대문자로 변환
            //b[0] = toupper(b[0]);

            // 결과 출력
            cout << "<string name=\"" << a << "." << tb << "\">" << b << "</string>" << std::endl;
        }
        cout << endl;
    }
    return 0;
}
