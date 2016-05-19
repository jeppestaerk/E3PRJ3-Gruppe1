/*******************************************************************************
* File Name: PIR_Trig.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PIR_Trig_ALIASES_H) /* Pins PIR_Trig_ALIASES_H */
#define CY_PINS_PIR_Trig_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PIR_Trig_0			(PIR_Trig__0__PC)
#define PIR_Trig_0_PS		(PIR_Trig__0__PS)
#define PIR_Trig_0_PC		(PIR_Trig__0__PC)
#define PIR_Trig_0_DR		(PIR_Trig__0__DR)
#define PIR_Trig_0_SHIFT	(PIR_Trig__0__SHIFT)
#define PIR_Trig_0_INTR	((uint16)((uint16)0x0003u << (PIR_Trig__0__SHIFT*2u)))

#define PIR_Trig_INTR_ALL	 ((uint16)(PIR_Trig_0_INTR))


#endif /* End Pins PIR_Trig_ALIASES_H */


/* [] END OF FILE */