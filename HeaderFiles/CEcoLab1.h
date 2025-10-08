#ifndef __C_ECOLAB1_H__
#define __C_ECOLAB1_H__

#include <stddef.h>
#include "IEcoLab1.h"

typedef struct CEcoLab1 {
    struct IEcoLab1VTbl* m_pVTblIEcoLab1;
    uint32_t m_cRef;
    char* m_Name;
} CEcoLab1;

int16_t ECOCALLMETHOD createCEcoLab1(/* in */ struct IEcoUnknown* pIUnkSystem, /* in */ struct IEcoUnknown* pIUnkOuter, /* out */ struct IEcoLab1** ppIEcoLab1);
void ECOCALLMETHOD deleteCEcoLab1(/* in */ struct IEcoLab1* pIEcoLab1);

#endif /* __C_ECOLAB1_H__ */