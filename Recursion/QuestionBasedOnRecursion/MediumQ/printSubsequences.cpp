#include <iostream>
#include <string>

void printSubseq(const std::string& str, int idx, const std::string& res) {
    if (idx == str.length()) {
        std::cout << res << std::endl;
        return;
    }

    // choose
    printSubseq(str, idx + 1, res + str[idx]);

    // don't choose
    printSubseq(str, idx + 1, res);
}

int main() {
    std::string str1 = "abc";

    printSubseq(str1, 0, ""); // last ak empty string bhi aayega

    return 0;
}
