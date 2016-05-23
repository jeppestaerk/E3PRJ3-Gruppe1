/*******************************************************************************
* File Name: Clk.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Clk.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Clk_PC =   (Clk_PC & \
                                (uint32)(~(uint32)(Clk_DRIVE_MODE_IND_MASK << (Clk_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Clk_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Clk_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Clk_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Clk_DR & (uint8)(~Clk_MASK));
    drVal = (drVal | ((uint8)(value << Clk_SHIFT) & Clk_MASK));
    Clk_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Clk_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void Clk_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Clk__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Clk_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Clk_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Clk_Read(void) 
{
    return (uint8)((Clk_PS & Clk_MASK) >> Clk_SHIFT);
}


/*******************************************************************************
* Function Name: Clk_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Clk_ReadDataReg(void) 
{
    return (uint8)((Clk_DR & Clk_MASK) >> Clk_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Clk_INTSTAT) 

    /*******************************************************************************
    * Function Name: Clk_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Clk_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Clk_INTSTAT & Clk_MASK);
		Clk_INTSTAT = maskedStatus;
        return maskedStatus >> Clk_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
