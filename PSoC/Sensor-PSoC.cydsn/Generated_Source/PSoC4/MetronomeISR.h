/*******************************************************************************
* File Name: MetronomeISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_MetronomeISR_H)
#define CY_ISR_MetronomeISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void MetronomeISR_Start(void);
void MetronomeISR_StartEx(cyisraddress address);
void MetronomeISR_Stop(void);

CY_ISR_PROTO(MetronomeISR_Interrupt);

void MetronomeISR_SetVector(cyisraddress address);
cyisraddress MetronomeISR_GetVector(void);

void MetronomeISR_SetPriority(uint8 priority);
uint8 MetronomeISR_GetPriority(void);

void MetronomeISR_Enable(void);
uint8 MetronomeISR_GetState(void);
void MetronomeISR_Disable(void);

void MetronomeISR_SetPending(void);
void MetronomeISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the MetronomeISR ISR. */
#define MetronomeISR_INTC_VECTOR            ((reg32 *) MetronomeISR__INTC_VECT)

/* Address of the MetronomeISR ISR priority. */
#define MetronomeISR_INTC_PRIOR             ((reg32 *) MetronomeISR__INTC_PRIOR_REG)

/* Priority of the MetronomeISR interrupt. */
#define MetronomeISR_INTC_PRIOR_NUMBER      MetronomeISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable MetronomeISR interrupt. */
#define MetronomeISR_INTC_SET_EN            ((reg32 *) MetronomeISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the MetronomeISR interrupt. */
#define MetronomeISR_INTC_CLR_EN            ((reg32 *) MetronomeISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the MetronomeISR interrupt state to pending. */
#define MetronomeISR_INTC_SET_PD            ((reg32 *) MetronomeISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the MetronomeISR interrupt. */
#define MetronomeISR_INTC_CLR_PD            ((reg32 *) MetronomeISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_MetronomeISR_H */


/* [] END OF FILE */
