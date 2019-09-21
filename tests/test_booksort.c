#include <assert.h>
#include "booksort.h"


int TestIsIgnored() {
    assert(!IsIgnored('a'));
    assert(IsIgnored(' '));
    assert(!IsIgnored('A'));
    assert(IsIgnored('\n'));

    return 0;
}

int TestIsBigger() {
    assert(IsBigger("a", "b", CLASSIC));
    assert(IsBigger("9a", "10b", CLASSIC));

    return 0;
}

int TestSwap() {
    char* a = "abc";
    char* b = "def";

    Swap(&a, &b);

    assert(a == "def");
    assert(b == "abc");

    return 0;
}

int main() {
    TestIsIgnored();
    TestIsBigger();
    TestSwap();

    return 0;
}
