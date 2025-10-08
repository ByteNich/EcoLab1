#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "CEcoLab1.h"
#include "IEcoLab1.h"
#include "IEcoBase1.h"

int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    if (me == 0 || ppv == 0) return -1;
    if (IsEqualUGUID(riid, &IID_IEcoLab1)) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((struct IEcoLab1*)pCMe);
        return 0;
    }
    if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((struct IEcoLab1*)pCMe);
        return 0;
    }
    *ppv = 0;
    return -1;
}

uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    if (me == 0) return 0;
    pCMe->m_cRef++;
    return pCMe->m_cRef;
}

uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    if (me == 0) return 0;
    pCMe->m_cRef--;
    if (pCMe->m_cRef == 0) {
        deleteCEcoLab1((struct IEcoLab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

int32_t ECOCALLMETHOD CEcoLab1_linearSearchInt(/* in */ struct IEcoLab1* me, /* in */ int* arr, /* in */ uint32_t size, /* in */ int target) {
    uint32_t i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) return (int32_t)i;
    }
    return -1;
}

int32_t ECOCALLMETHOD CEcoLab1_linearSearchLong(/* in */ struct IEcoLab1* me, /* in */ int64_t* arr, /* in */ uint32_t size, /* in */ int64_t target) {
    uint32_t i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) return (int32_t)i;
    }
    return -1;
}

int32_t ECOCALLMETHOD CEcoLab1_linearSearchFloat(/* in */ struct IEcoLab1* me, /* in */ float* arr, /* in */ uint32_t size, /* in */ float target) {
    uint32_t i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) return (int32_t)i;
    }
    return -1;
}

int32_t ECOCALLMETHOD CEcoLab1_linearSearchDouble(/* in */ struct IEcoLab1* me, /* in */ double* arr, /* in */ uint32_t size, /* in */ double target) {
    uint32_t i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) return (int32_t)i;
    }
    return -1;
}

int32_t ECOCALLMETHOD CEcoLab1_linearSearchLongDouble(/* in */ struct IEcoLab1* me, /* in */ long double* arr, /* in */ uint32_t size, /* in */ long double target) {
    uint32_t i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) return (int32_t)i;
    }
    return -1;
}

IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
    CEcoLab1_QueryInterface,
    CEcoLab1_AddRef,
    CEcoLab1_Release,
    CEcoLab1_linearSearchInt,
    CEcoLab1_linearSearchLong,
    CEcoLab1_linearSearchFloat,
    CEcoLab1_linearSearchDouble,
    CEcoLab1_linearSearchLongDouble
};

int16_t ECOCALLMETHOD createCEcoLab1(/* in */ struct IEcoUnknown* pIUnkSystem, /* in */ struct IEcoUnknown* pIUnkOuter, /* out */ struct IEcoLab1** ppIEcoLab1) {
    CEcoLab1* pCMe = 0;
    if (ppIEcoLab1 == 0) return -1;
    pCMe = (CEcoLab1*)malloc(sizeof(CEcoLab1));
    if (pCMe == 0) return -1;
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;
    pCMe->m_cRef = 1;
    pCMe->m_Name = (char*)malloc(16);
    if (pCMe->m_Name != 0) {
        memset(pCMe->m_Name, 0, 16);
    }
    *ppIEcoLab1 = (struct IEcoLab1*)pCMe;
    return 0;
}

void ECOCALLMETHOD deleteCEcoLab1(/* in */ struct IEcoLab1* pIEcoLab1) {
    CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
    if (pIEcoLab1 != 0) {
        if (pCMe->m_Name != 0) {
            free(pCMe->m_Name);
            pCMe->m_Name = 0;
        }
        free(pCMe);
    }
}