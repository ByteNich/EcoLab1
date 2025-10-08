#include "IEcoBase1.h"
#include <string.h>

int16_t IsEqualUGUID(const UGUID* rguid1, const UGUID* rguid2) {
    if (rguid1 == 0 || rguid2 == 0) return -1;
    if (rguid1->Data1 != rguid2->Data1 ||
        rguid1->Data2 != rguid2->Data2 ||
        rguid1->Data3 != rguid2->Data3) {
        return 0;
    }
    return memcmp(rguid1->Data4, rguid2->Data4, 8) == 0 ? 1 : 0;
}