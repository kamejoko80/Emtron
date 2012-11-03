#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1904510940/SoftI2C.o ${OBJECTDIR}/_ext/1904510940/SoftSPI.o ${OBJECTDIR}/_ext/761631083/peripheral.o ${OBJECTDIR}/_ext/761631083/rtos.o ${OBJECTDIR}/_ext/761631083/task.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1543948142/EEPROM.o ${OBJECTDIR}/_ext/1543948142/HD44780.o ${OBJECTDIR}/_ext/1543948142/MCP23S17.o ${OBJECTDIR}/_ext/1543948142/MCP355X.o ${OBJECTDIR}/_ext/1543948142/MCP9800.o ${OBJECTDIR}/_ext/1174900389/circular_buffer.o ${OBJECTDIR}/_ext/1015565369/kernel.o ${OBJECTDIR}/_ext/1015565369/timer.o ${OBJECTDIR}/_ext/1015565369/uart.o ${OBJECTDIR}/_ext/1015565369/task_switch.o ${OBJECTDIR}/_ext/1015565369/PIC24.o ${OBJECTDIR}/_ext/761631083/taskQueue.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d ${OBJECTDIR}/_ext/761631083/peripheral.o.d ${OBJECTDIR}/_ext/761631083/rtos.o.d ${OBJECTDIR}/_ext/761631083/task.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1543948142/EEPROM.o.d ${OBJECTDIR}/_ext/1543948142/HD44780.o.d ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d ${OBJECTDIR}/_ext/1543948142/MCP355X.o.d ${OBJECTDIR}/_ext/1543948142/MCP9800.o.d ${OBJECTDIR}/_ext/1174900389/circular_buffer.o.d ${OBJECTDIR}/_ext/1015565369/kernel.o.d ${OBJECTDIR}/_ext/1015565369/timer.o.d ${OBJECTDIR}/_ext/1015565369/uart.o.d ${OBJECTDIR}/_ext/1015565369/task_switch.o.d ${OBJECTDIR}/_ext/1015565369/PIC24.o.d ${OBJECTDIR}/_ext/761631083/taskQueue.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1904510940/SoftI2C.o ${OBJECTDIR}/_ext/1904510940/SoftSPI.o ${OBJECTDIR}/_ext/761631083/peripheral.o ${OBJECTDIR}/_ext/761631083/rtos.o ${OBJECTDIR}/_ext/761631083/task.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1543948142/EEPROM.o ${OBJECTDIR}/_ext/1543948142/HD44780.o ${OBJECTDIR}/_ext/1543948142/MCP23S17.o ${OBJECTDIR}/_ext/1543948142/MCP355X.o ${OBJECTDIR}/_ext/1543948142/MCP9800.o ${OBJECTDIR}/_ext/1174900389/circular_buffer.o ${OBJECTDIR}/_ext/1015565369/kernel.o ${OBJECTDIR}/_ext/1015565369/timer.o ${OBJECTDIR}/_ext/1015565369/uart.o ${OBJECTDIR}/_ext/1015565369/task_switch.o ${OBJECTDIR}/_ext/1015565369/PIC24.o ${OBJECTDIR}/_ext/761631083/taskQueue.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA002
MP_LINKER_FILE_OPTION=,--script=p24FJ64GA002.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1904510940/SoftI2C.o: ../Drivers/SoftI2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1904510940 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Drivers/SoftI2C.c  -o ${OBJECTDIR}/_ext/1904510940/SoftI2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1904510940/SoftSPI.o: ../Drivers/SoftSPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1904510940 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Drivers/SoftSPI.c  -o ${OBJECTDIR}/_ext/1904510940/SoftSPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/peripheral.o: ../RTOS/peripheral.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/peripheral.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/peripheral.c  -o ${OBJECTDIR}/_ext/761631083/peripheral.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/peripheral.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/peripheral.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/rtos.o: ../RTOS/rtos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/rtos.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/rtos.c  -o ${OBJECTDIR}/_ext/761631083/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/rtos.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/rtos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/task.o: ../RTOS/task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/task.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/task.c  -o ${OBJECTDIR}/_ext/761631083/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/task.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/EEPROM.o: ../Devices/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/EEPROM.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/EEPROM.c  -o ${OBJECTDIR}/_ext/1543948142/EEPROM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/EEPROM.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/EEPROM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/HD44780.o: ../Devices/HD44780.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/HD44780.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/HD44780.c  -o ${OBJECTDIR}/_ext/1543948142/HD44780.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/HD44780.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/HD44780.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/MCP23S17.o: ../Devices/MCP23S17.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/MCP23S17.c  -o ${OBJECTDIR}/_ext/1543948142/MCP23S17.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/MCP355X.o: ../Devices/MCP355X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP355X.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/MCP355X.c  -o ${OBJECTDIR}/_ext/1543948142/MCP355X.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP355X.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP355X.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/MCP9800.o: ../Devices/MCP9800.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP9800.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/MCP9800.c  -o ${OBJECTDIR}/_ext/1543948142/MCP9800.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP9800.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP9800.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1174900389/circular_buffer.o: ../Utilities/circular_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1174900389 
	@${RM} ${OBJECTDIR}/_ext/1174900389/circular_buffer.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Utilities/circular_buffer.c  -o ${OBJECTDIR}/_ext/1174900389/circular_buffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1174900389/circular_buffer.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1174900389/circular_buffer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/kernel.o: ../Portable/PIC24/kernel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/kernel.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/kernel.c  -o ${OBJECTDIR}/_ext/1015565369/kernel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/kernel.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/kernel.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/timer.o: ../Portable/PIC24/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/timer.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/timer.c  -o ${OBJECTDIR}/_ext/1015565369/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/timer.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/uart.o: ../Portable/PIC24/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/uart.c  -o ${OBJECTDIR}/_ext/1015565369/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/uart.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/PIC24.o: ../Portable/PIC24/PIC24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/PIC24.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/PIC24.c  -o ${OBJECTDIR}/_ext/1015565369/PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/PIC24.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/PIC24.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/taskQueue.o: ../RTOS/taskQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/taskQueue.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/taskQueue.c  -o ${OBJECTDIR}/_ext/761631083/taskQueue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/taskQueue.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/taskQueue.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1904510940/SoftI2C.o: ../Drivers/SoftI2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1904510940 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Drivers/SoftI2C.c  -o ${OBJECTDIR}/_ext/1904510940/SoftI2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1904510940/SoftSPI.o: ../Drivers/SoftSPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1904510940 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Drivers/SoftSPI.c  -o ${OBJECTDIR}/_ext/1904510940/SoftSPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/peripheral.o: ../RTOS/peripheral.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/peripheral.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/peripheral.c  -o ${OBJECTDIR}/_ext/761631083/peripheral.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/peripheral.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/peripheral.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/rtos.o: ../RTOS/rtos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/rtos.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/rtos.c  -o ${OBJECTDIR}/_ext/761631083/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/rtos.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/rtos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/task.o: ../RTOS/task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/task.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/task.c  -o ${OBJECTDIR}/_ext/761631083/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/task.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/EEPROM.o: ../Devices/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/EEPROM.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/EEPROM.c  -o ${OBJECTDIR}/_ext/1543948142/EEPROM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/EEPROM.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/EEPROM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/HD44780.o: ../Devices/HD44780.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/HD44780.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/HD44780.c  -o ${OBJECTDIR}/_ext/1543948142/HD44780.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/HD44780.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/HD44780.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/MCP23S17.o: ../Devices/MCP23S17.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/MCP23S17.c  -o ${OBJECTDIR}/_ext/1543948142/MCP23S17.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/MCP355X.o: ../Devices/MCP355X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP355X.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/MCP355X.c  -o ${OBJECTDIR}/_ext/1543948142/MCP355X.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP355X.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP355X.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1543948142/MCP9800.o: ../Devices/MCP9800.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP9800.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/MCP9800.c  -o ${OBJECTDIR}/_ext/1543948142/MCP9800.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP9800.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP9800.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1174900389/circular_buffer.o: ../Utilities/circular_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1174900389 
	@${RM} ${OBJECTDIR}/_ext/1174900389/circular_buffer.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Utilities/circular_buffer.c  -o ${OBJECTDIR}/_ext/1174900389/circular_buffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1174900389/circular_buffer.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1174900389/circular_buffer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/kernel.o: ../Portable/PIC24/kernel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/kernel.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/kernel.c  -o ${OBJECTDIR}/_ext/1015565369/kernel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/kernel.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/kernel.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/timer.o: ../Portable/PIC24/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/timer.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/timer.c  -o ${OBJECTDIR}/_ext/1015565369/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/timer.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/uart.o: ../Portable/PIC24/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/uart.c  -o ${OBJECTDIR}/_ext/1015565369/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/uart.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/PIC24.o: ../Portable/PIC24/PIC24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/PIC24.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/PIC24.c  -o ${OBJECTDIR}/_ext/1015565369/PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/PIC24.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/PIC24.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/taskQueue.o: ../RTOS/taskQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/taskQueue.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/taskQueue.c  -o ${OBJECTDIR}/_ext/761631083/taskQueue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/taskQueue.o.d"        -g -omf=elf -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/taskQueue.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1015565369/task_switch.o: ../Portable/PIC24/task_switch.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/task_switch.o.d 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../Portable/PIC24/task_switch.s  -o ${OBJECTDIR}/_ext/1015565369/task_switch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -Wa,-MD,"${OBJECTDIR}/_ext/1015565369/task_switch.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/task_switch.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1015565369/task_switch.o: ../Portable/PIC24/task_switch.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/task_switch.o.d 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../Portable/PIC24/task_switch.s  -o ${OBJECTDIR}/_ext/1015565369/task_switch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -Wa,-MD,"${OBJECTDIR}/_ext/1015565369/task_switch.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/task_switch.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="C:/Users/Hans/Documents/GitHub/Emtron/Emtron.X/usage.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="C:/Users/Hans/Documents/GitHub/Emtron/Emtron.X/usage.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
