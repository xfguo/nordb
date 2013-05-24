#include "dbg.h"
#include "test_cases.h"

#define TEST(tfunc, ttext) {\
    int ret;\
    DBG("TEST %s:%s\n", ttext, ((ret = tfunc()) == 0)?"PASS":"FAIL");\
    if(ret != 0) return ret;\
}

int main() {
    TEST(test_sim, "NOR Flash Simulation");
    return 0;
}
