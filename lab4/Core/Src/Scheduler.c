

#include"Scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];

unsigned char SCH_Add_Task(void(*pFunction)(), unsigned int DELAY, unsigned int PERIOD) {
	unsigned char Index = 0;
	// First find a gap in the array (if there is one)
	while((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
		Index++;
	}

	// Have we reached the end of the list?
	if(Index == SCH_MAX_TASKS) {
		// Task list is full
		// Set the global error variable
		// Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		// Also return an error code
		return SCH_MAX_TASKS;
	}
	// If we ’re here, there is a space in the task array
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;

	// Return position of task (to allow later deletion)
	return Index;
}

void SCH_Dispatch_Tasks(void) {
	unsigned char Index;
	// Dispatches (runs) the next task (if one is ready)
	for(Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if(SCH_tasks_G[Index].RunMe > 0) {
			(*SCH_tasks_G[Index].pTask)(); // Run the task
			SCH_tasks_G[Index].RunMe -= 1; // Reset / reduce RunMe flag
			// Periodic tasks will automatically run again
			// if this is a ’one shot’ task, remove it from the array
			 if(SCH_tasks_G[Index].Period == 0) {
				 SCH_Delete_Task(Index);
			 }
		}
	}
	// Report system status
//	SCH_Report_Status();
	// The scheduler enters idle mode at this point
//	SCH_Go_To_Sleep();
}

unsigned char SCH_Delete_Task(const unsigned char index) {
	if(SCH_tasks_G[index].pTask == 0){
		return 0;
	} else {
		SCH_tasks_G[index].pTask = 0;
		SCH_tasks_G[index].Delay = 0;
		SCH_tasks_G[index].Period = 0;
		SCH_tasks_G[index].RunMe = 0;
		return 1;
	}
}

void SCH_Init(void) {
	unsigned char i ;
	for(i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
	// Reset the global error variable
	// − SCH_Delete_Task ( ) will generate an e r ro r code ,
	// ( because the task array i s empty)
	// Error_code_G = 0;
	// Timer_init();
	// Watchdog_init ( ) ;
}

void SCH_Update(void) {
	unsigned char Index;
	// NOTE: calculations are in *TICKS* (not milliseconds)
	for(Index = 0; Index < SCH_MAX_TASKS; Index++) {
		// Check if there is a task at this location
		if(SCH_tasks_G[Index].pTask) {
			if(SCH_tasks_G[Index].Delay == 0) {
				// The task is due to run
				// Inc . the ’RunMe’ flag
				SCH_tasks_G[Index].RunMe += 1;
				if(SCH_tasks_G[Index].Period) {
					// Schedule periodic tasks to run again
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			} else {
				// Not yet ready to run: just decrement the delay
				SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}
}
