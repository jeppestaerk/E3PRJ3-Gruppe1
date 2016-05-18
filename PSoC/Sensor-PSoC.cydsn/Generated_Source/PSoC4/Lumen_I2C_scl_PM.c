/*******************************************************************************
* File Name: Lumen_I2C_scl.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Lumen_I2C_scl.h"

static Lumen_I2C_scl_BACKUP_STRUCT  Lumen_I2C_scl_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Lumen_I2C_scl_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Lumen_I2C_scl_SUT.c usage_Lumen_I2C_scl_Sleep_Wakeup
*******************************************************************************/
void Lumen_I2C_scl_Sleep(void)
{
    #if defined(Lumen_I2C_scl__PC)
        Lumen_I2C_scl_backup.pcState = Lumen_I2C_scl_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Lumen_I2C_scl_backup.usbState = Lumen_I2C_scl_CR1_REG;
            Lumen_I2C_scl_USB_POWER_REG |= Lumen_I2C_scl_USBIO_ENTER_SLEEP;
            Lumen_I2C_scl_CR1_REG &= Lumen_I2C_scl_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Lumen_I2C_scl__SIO)
        Lumen_I2C_scl_backup.sioState = Lumen_I2C_scl_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Lumen_I2C_scl_SIO_REG &= (uint32)(~Lumen_I2C_scl_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Lumen_I2C_scl_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Lumen_I2C_scl_Sleep() for an example usage.
*******************************************************************************/
void Lumen_I2C_scl_Wakeup(void)
{
    #if defined(Lumen_I2C_scl__PC)
        Lumen_I2C_scl_PC = Lumen_I2C_scl_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Lumen_I2C_scl_USB_POWER_REG &= Lumen_I2C_scl_USBIO_EXIT_SLEEP_PH1;
            Lumen_I2C_scl_CR1_REG = Lumen_I2C_scl_backup.usbState;
            Lumen_I2C_scl_USB_POWER_REG &= Lumen_I2C_scl_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Lumen_I2C_scl__SIO)
        Lumen_I2C_scl_SIO_REG = Lumen_I2C_scl_backup.sioState;
    #endif
}


/* [] END OF FILE */
