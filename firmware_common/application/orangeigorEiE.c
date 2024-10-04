/*!*********************************************************************************************************************
@file orangeigorEiE.c                                                                
@brief User's tasks / applications are written here.  This description
should be replaced by something specific to the task.

----------------------------------------------------------------------------------------------------------------------
To start a new task using this orangeigorEiE as a template:
 1. Copy both orangeigorEiE.c and orangeigorEiE.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "orangeigorEiE" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "OrangeIgorEiE" with "OrangeIgorEiE"
 6. Use ctrl-h to find and replace all instances of "ORANGE_IGOR_EIE" with "YOUR_NEW_TASK_NAME"
 7. Add a call to OrangeIgorEiEInitialize() in the init section of main
 8. Add a call to OrangeIgorEiERunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------------------------------
GLOBALS
- NONE

CONSTANTS
- NONE

TYPES
- NONE

PUBLIC FUNCTIONS
- NONE

PROTECTED FUNCTIONS
- void OrangeIgorEiEInitialize(void)
- void OrangeIgorEiERunActiveState(void)


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_<type>OrangeIgorEiE"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32OrangeIgorEiEFlags;                          /*!< @brief Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemTime1ms;                   /*!< @brief From main.c */
extern volatile u32 G_u32SystemTime1s;                    /*!< @brief From main.c */
extern volatile u32 G_u32SystemFlags;                     /*!< @brief From main.c */
extern volatile u32 G_u32ApplicationFlags;                /*!< @brief From main.c */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "OrangeIgorEiE_<type>" and be declared as static.
***********************************************************************************************************************/
static fnCode_type OrangeIgorEiE_pfStateMachine;               /*!< @brief The state machine function pointer */
//static u32 OrangeIgorEiE_u32Timeout;                           /*!< @brief Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------------------------------------------------
@fn void OrangeIgorEiEInitialize(void)

@brief
Initializes the State Machine and its variables.

Should only be called once in main init section.

Requires:
- NONE

Promises:
- NONE

*/
void OrangeIgorEiEInitialize(void)
{
  HEARTBEAT_OFF();
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    OrangeIgorEiE_pfStateMachine = OrangeIgorEiESM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    OrangeIgorEiE_pfStateMachine = OrangeIgorEiESM_Error;
  }

} /* end OrangeIgorEiEInitialize() */

  
/*!----------------------------------------------------------------------------------------------------------------------
@fn void OrangeIgorEiERunActiveState(void)

@brief Selects and runs one iteration of the current state in the state machine.

All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
- State machine function pointer points at current state

Promises:
- Calls the function to pointed by the state machine function pointer

*/
void OrangeIgorEiERunActiveState(void)
{
  OrangeIgorEiE_pfStateMachine();

} /* end OrangeIgorEiERunActiveState */


/*------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------------*/
/* What does this state do? */
static void OrangeIgorEiESM_Idle(void)
{
    if (heartbeat_timer_counter == HEARTBEAT_MS)
    {
      heartbeat_timer_counter = 0;

      if (heartbeat_toggle == 0)
      {
        HEARTBEAT_OFF();
        heartbeat_toggle = 1;}
      else
      {
        HEARTBEAT_ON();
        heartbeat_toggle = 0;}
    }

    heartbeat_timer_counter++;
} /* end OrangeIgorEiESM_Idle() */
     

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void OrangeIgorEiESM_Error(void)          
{
  
} /* end OrangeIgorEiESM_Error() */




/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
