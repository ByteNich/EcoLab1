#ifndef __I_ECOLAB1_H__
#define __I_ECOLAB1_H__

#include "IEcoBase1.h"

typedef struct IEcoLab1 IEcoLab1;
typedef struct IEcoLab1VTbl {
    int16_t (ECOCALLMETHOD *QueryInterface)(IEcoLab1* me, const UGUID* riid, void** ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(IEcoLab1* me);
    uint32_t (ECOCALLMETHOD *Release)(IEcoLab1* me);
    int32_t (ECOCALLMETHOD *linearSearchInt)(IEcoLab1* me, int* arr, uint32_t size, int target);
    int32_t (ECOCALLMETHOD *linearSearchLong)(IEcoLab1* me, int64_t* arr, uint32_t size, int64_t target);
    int32_t (ECOCALLMETHOD *linearSearchFloat)(IEcoLab1* me, float* arr, uint32_t size, float target);
    int32_t (ECOCALLMETHOD *linearSearchDouble)(IEcoLab1* me, double* arr, uint32_t size, double target);
    int32_t (ECOCALLMETHOD *linearSearchLongDouble)(IEcoLab1* me, long double* arr, uint32_t size, long double target);
} IEcoLab1VTbl;

struct IEcoLab1 {
    IEcoLab1VTbl* pVTbl;
};

static const UGUID IID_IEcoLab1 = {0x01, 0x10, {0x27, 0x7F, 0xC0, 0x0C, 0x35, 0x62, 0x40, 0x96}};

#endif /* __I_ECOLAB1_H__ */