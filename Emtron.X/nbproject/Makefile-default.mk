#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
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
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/peripheral.o ${OBJECTDIR}/_ext/1472/rtos.o ${OBJECTDIR}/_ext/1472/task.o ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o ${OBJECTDIR}/_ext/1543948142/MCP23S17.o ${OBJECTDIR}/_ext/1015565369/kernel.o ${OBJECTDIR}/_ext/1015565369/timer.o ${OBJECTDIR}/_ext/1015565369/task_switch.o ${OBJECTDIR}/_ext/1543948142/HD44780.o ${OBJECTDIR}/_ext/1904510940/SoftSPI.o ${OBJECTDIR}/_ext/1543948142/MCP355X.o ${OBJECTDIR}/_ext/1904510940/SoftI2C.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/peripheral.o.d ${OBJECTDIR}/_ext/1472/rtos.o.d ${OBJECTDIR}/_ext/1472/task.o.d ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.d ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d ${OBJECTDIR}/_ext/1015565369/kernel.o.d ${OBJECTDIR}/_ext/1015565369/timer.o.d ${OBJECTDIR}/_ext/1015565369/task_switch.o.d ${OBJECTDIR}/_ext/1543948142/HD44780.o.d ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d ${OBJECTDIR}/_ext/1543948142/MCP355X.o.d ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/peripheral.o ${OBJECTDIR}/_ext/1472/rtos.o ${OBJECTDIR}/_ext/1472/task.o ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o ${OBJECTDIR}/_ext/1543948142/MCP23S17.o ${OBJECTDIR}/_ext/1015565369/kernel.o ${OBJECTDIR}/_ext/1015565369/timer.o ${OBJECTDIR}/_ext/1015565369/task_switch.o ${OBJECTDIR}/_ext/1543948142/HD44780.o ${OBJECTDIR}/_ext/1904510940/SoftSPI.o ${OBJECTDIR}/_ext/1543948142/MCP355X.o ${OBJECTDIR}/_ext/1904510940/SoftI2C.o


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ32GA002
MP_LINKER_FILE_OPTION=,-Tp24FJ32GA002.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1015565369/task_switch.o: ../Portable/PIC24/task_switch.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/task_switch.o.d 
	@${RM} ${OBJECTDIR}/_ext/1015565369/task_switch.o.ok ${OBJECTDIR}/_ext/1015565369/task_switch.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/task_switch.o.d" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE)  ../Portable/PIC24/task_switch.s -o ${OBJECTDIR}/_ext/1015565369/task_switch.o -omf=elf -p=$(MP_PROCESSOR_OPTION) --defsym=__MPLAB_BUILD=1 --defsym=__MPLAB_DEBUG=1 --defsym=__ICD2RAM=1 --defsym=__DEBUG=1  -g  -MD "${OBJECTDIR}/_ext/1015565369/task_switch.o.d"$(MP_EXTRA_AS_POST)
	
else
${OBJECTDIR}/_ext/1015565369/task_switch.o: ../Portable/PIC24/task_switch.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/task_switch.o.d 
	@${RM} ${OBJECTDIR}/_ext/1015565369/task_switch.o.ok ${OBJECTDIR}/_ext/1015565369/task_switch.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/task_switch.o.d" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE)  ../Portable/PIC24/task_switch.s -o ${OBJECTDIR}/_ext/1015565369/task_switch.o -omf=elf -p=$(MP_PROCESSOR_OPTION) --defsym=__MPLAB_BUILD=1 -g  -MD "${OBJECTDIR}/_ext/1015565369/task_switch.o.d"$(MP_EXTRA_AS_POST)
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/peripheral.o: ../peripheral.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/peripheral.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/peripheral.o.ok ${OBJECTDIR}/_ext/1472/peripheral.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/peripheral.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1472/peripheral.o.d" -o ${OBJECTDIR}/_ext/1472/peripheral.o ../peripheral.c    
	
${OBJECTDIR}/_ext/1472/rtos.o: ../rtos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/rtos.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/rtos.o.ok ${OBJECTDIR}/_ext/1472/rtos.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/rtos.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1472/rtos.o.d" -o ${OBJECTDIR}/_ext/1472/rtos.o ../rtos.c    
	
${OBJECTDIR}/_ext/1472/task.o: ../task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/task.o.ok ${OBJECTDIR}/_ext/1472/task.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/task.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1472/task.o.d" -o ${OBJECTDIR}/_ext/1472/task.o ../task.c    
	
${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o: ../Portable/PIC24FJ32GA002.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/237321450 
	@${RM} ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.d 
	@${RM} ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.ok ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.d" -o ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o ../Portable/PIC24FJ32GA002.c    
	
${OBJECTDIR}/_ext/1543948142/MCP23S17.o: ../Devices/MCP23S17.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.ok ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d" -o ${OBJECTDIR}/_ext/1543948142/MCP23S17.o ../Devices/MCP23S17.c    
	
${OBJECTDIR}/_ext/1015565369/kernel.o: ../Portable/PIC24/kernel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/kernel.o.d 
	@${RM} ${OBJECTDIR}/_ext/1015565369/kernel.o.ok ${OBJECTDIR}/_ext/1015565369/kernel.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/kernel.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1015565369/kernel.o.d" -o ${OBJECTDIR}/_ext/1015565369/kernel.o ../Portable/PIC24/kernel.c    
	
${OBJECTDIR}/_ext/1015565369/timer.o: ../Portable/PIC24/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1015565369/timer.o.ok ${OBJECTDIR}/_ext/1015565369/timer.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/timer.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1015565369/timer.o.d" -o ${OBJECTDIR}/_ext/1015565369/timer.o ../Portable/PIC24/timer.c    
	
${OBJECTDIR}/_ext/1543948142/HD44780.o: ../Devices/HD44780.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/HD44780.o.d 
	@${RM} ${OBJECTDIR}/_ext/1543948142/HD44780.o.ok ${OBJECTDIR}/_ext/1543948142/HD44780.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/HD44780.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1543948142/HD44780.o.d" -o ${OBJECTDIR}/_ext/1543948142/HD44780.o ../Devices/HD44780.c    
	
${OBJECTDIR}/_ext/1904510940/SoftSPI.o: ../Drivers/SoftSPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1904510940 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.ok ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d" -o ${OBJECTDIR}/_ext/1904510940/SoftSPI.o ../Drivers/SoftSPI.c    
	
${OBJECTDIR}/_ext/1543948142/MCP355X.o: ../Devices/MCP355X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP355X.o.d 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP355X.o.ok ${OBJECTDIR}/_ext/1543948142/MCP355X.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP355X.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP355X.o.d" -o ${OBJECTDIR}/_ext/1543948142/MCP355X.o ../Devices/MCP355X.c    
	
${OBJECTDIR}/_ext/1904510940/SoftI2C.o: ../Drivers/SoftI2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1904510940 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.ok ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d" -o ${OBJECTDIR}/_ext/1904510940/SoftI2C.o ../Drivers/SoftI2C.c    
	
else
${OBJECTDIR}/_ext/1472/peripheral.o: ../peripheral.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/peripheral.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/peripheral.o.ok ${OBJECTDIR}/_ext/1472/peripheral.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/peripheral.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1472/peripheral.o.d" -o ${OBJECTDIR}/_ext/1472/peripheral.o ../peripheral.c    
	
${OBJECTDIR}/_ext/1472/rtos.o: ../rtos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/rtos.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/rtos.o.ok ${OBJECTDIR}/_ext/1472/rtos.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/rtos.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1472/rtos.o.d" -o ${OBJECTDIR}/_ext/1472/rtos.o ../rtos.c    
	
${OBJECTDIR}/_ext/1472/task.o: ../task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/task.o.ok ${OBJECTDIR}/_ext/1472/task.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/task.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1472/task.o.d" -o ${OBJECTDIR}/_ext/1472/task.o ../task.c    
	
${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o: ../Portable/PIC24FJ32GA002.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/237321450 
	@${RM} ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.d 
	@${RM} ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.ok ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o.d" -o ${OBJECTDIR}/_ext/237321450/PIC24FJ32GA002.o ../Portable/PIC24FJ32GA002.c    
	
${OBJECTDIR}/_ext/1543948142/MCP23S17.o: ../Devices/MCP23S17.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.ok ${OBJECTDIR}/_ext/1543948142/MCP23S17.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP23S17.o.d" -o ${OBJECTDIR}/_ext/1543948142/MCP23S17.o ../Devices/MCP23S17.c    
	
${OBJECTDIR}/_ext/1015565369/kernel.o: ../Portable/PIC24/kernel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/kernel.o.d 
	@${RM} ${OBJECTDIR}/_ext/1015565369/kernel.o.ok ${OBJECTDIR}/_ext/1015565369/kernel.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/kernel.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1015565369/kernel.o.d" -o ${OBJECTDIR}/_ext/1015565369/kernel.o ../Portable/PIC24/kernel.c    
	
${OBJECTDIR}/_ext/1015565369/timer.o: ../Portable/PIC24/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1015565369/timer.o.ok ${OBJECTDIR}/_ext/1015565369/timer.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/timer.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1015565369/timer.o.d" -o ${OBJECTDIR}/_ext/1015565369/timer.o ../Portable/PIC24/timer.c    
	
${OBJECTDIR}/_ext/1543948142/HD44780.o: ../Devices/HD44780.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/HD44780.o.d 
	@${RM} ${OBJECTDIR}/_ext/1543948142/HD44780.o.ok ${OBJECTDIR}/_ext/1543948142/HD44780.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/HD44780.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1543948142/HD44780.o.d" -o ${OBJECTDIR}/_ext/1543948142/HD44780.o ../Devices/HD44780.c    
	
${OBJECTDIR}/_ext/1904510940/SoftSPI.o: ../Drivers/SoftSPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1904510940 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.ok ${OBJECTDIR}/_ext/1904510940/SoftSPI.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1904510940/SoftSPI.o.d" -o ${OBJECTDIR}/_ext/1904510940/SoftSPI.o ../Drivers/SoftSPI.c    
	
${OBJECTDIR}/_ext/1543948142/MCP355X.o: ../Devices/MCP355X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP355X.o.d 
	@${RM} ${OBJECTDIR}/_ext/1543948142/MCP355X.o.ok ${OBJECTDIR}/_ext/1543948142/MCP355X.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/MCP355X.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1543948142/MCP355X.o.d" -o ${OBJECTDIR}/_ext/1543948142/MCP355X.o ../Devices/MCP355X.c    
	
${OBJECTDIR}/_ext/1904510940/SoftI2C.o: ../Drivers/SoftI2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1904510940 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d 
	@${RM} ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.ok ${OBJECTDIR}/_ext/1904510940/SoftI2C.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -I"C:/Users/Hans/Documents/Proteus/PIC24RTOS/PIC24RTOS.X" -I"C:/Users/Hans/Documents/Github/Emtron" -Os -MMD -MF "${OBJECTDIR}/_ext/1904510940/SoftI2C.o.d" -o ${OBJECTDIR}/_ext/1904510940/SoftI2C.o ../Drivers/SoftI2C.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} -omf=elf $(MP_EXTRA_AR_PRE) r dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
else
dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} -omf=elf $(MP_EXTRA_AR_PRE) r dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
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
