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
            // �빮�ڰ� ������ ����ٸ� �߰��ϰ� �ҹ��ڷ� ��ȯ
            if (i > 0) result += '_';
            result += tolower(input[i]);
        } else {
            // �ҹ��ڴ� �״�� �߰�
            result += input[i];
        }
    }

    return result;
}
int main() {
    // �Է� �ޱ�
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
            // a�� ������ "_"�� ��ü�ϰ� �ҹ��ڷ� ��ȯ
            tb = b;

            replace(tb.begin(), tb.end(), ' ', '_');
            transform(tb.begin(), tb.end(), tb.begin(), ::tolower);
            // b�� ù ���ڸ� �빮�ڷ� ��ȯ
            //b[0] = toupper(b[0]);

            // ��� ���
            cout << "<string name=\"" << a << "." << tb << "\">" << b << "</string>" << std::endl;
        }
        cout << endl;
    }
    return 0;
}
