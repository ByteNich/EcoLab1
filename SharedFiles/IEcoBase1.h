#ifndef __I_ECOBASE1_H__
#define __I_ECOBASE1_H__

#include <stdint.h>

#define ECOCALLMETHOD
#define ERR_ECO_SUCCESES 0
#define ERR_ECO_POINTER -1
#define ERR_ECO_NOINTERFACE -2
#define ERR_ECO_NOAGGREGATION -3

typedef void* voidptr_t;
typedef struct UGUID {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t Data4[8];
} UGUID;

static const UGUID IID_IEcoUnknown = {0x01, 0x10, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

typedef struct IEcoUnknown IEcoUnknown;
typedef struct IEcoUnknownVTbl {
    int16_t (ECOCALLMETHOD *QueryInterface)(IEcoUnknown* me, const UGUID* riid, void** ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(IEcoUnknown* me);
    uint32_t (ECOCALLMETHOD *Release)(IEcoUnknown* me);
} IEcoUnknownVTbl;

struct IEcoUnknown {
    IEcoUnknownVTbl* pVTbl;
};

int16_t IsEqualUGUID(const UGUID* rguid1, const UGUID* rguid2);

#endif /* __I_ECOBASE1_H__ */