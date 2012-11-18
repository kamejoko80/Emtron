        MODULE context

        IMPORT  scramble
        IMPORT Task_CurrentStackLocation
        IMPORT Task_Change
        EXPORT  asmKernel_ContextRestore
        EXPORT  asmKernel_ContextSave
        EXPORT  asmKernel_StackPtrRead
        EXPORT  asmKernel_StackPtrWrite
        EXPORT  asmKernel_ContextSwitch
        SECTION .text:CODE:REORDER(2)
asmKernel_ContextSwitch
        MRS R0, msp
        STMDB r0!, {r4-r11, lr}
        LDR r1, =Task_CurrentStackLocation
        STR r0, [r1]
	STMDB sp!, {r3, r14}
        
        BL Task_Change ; call Task_Change of scheduler
	ldmia sp!, {r3, r14}
        
        LDR r0, =Task_CurrentStackLocation
        LDR r1, [r0]
        
        LDMIA r1!, {r4-r11, lr}
        MSR msp, r1
        BX lr ; return

        SECTION .text:CODE:REORDER(2)
asmKernel_ContextRestore
        MRS     R12, msp
        LDR r0, =Task_CurrentStackLocation
        LDR r12, [r0]
        
        LDMFD   R12!, {r4-r11, lr}
        MSR     msp, R12
        bx lr
        
        SECTION .text:CODE:REORDER(2)
asmKernel_ContextSave
        MRS R12, msp
        STMDB R12!, {r4-r11, lr}
        MSR msp, R12
        BX LR
        
        SECTION .text:CODE:REORDER(2)
asmKernel_StackPtrRead
        MRS R9, msp
        LDR R8, =Task_CurrentStackLocation
        STR R9, [R8]
        BX lr ; return
        
        SECTION .text:CODE:REORDER(2)
asmKernel_StackPtrWrite
        LDR R8, =Task_CurrentStackLocation
        LDR R9, [R8]
        MSR msp, R9
        BX lr ; return
        

        END
        