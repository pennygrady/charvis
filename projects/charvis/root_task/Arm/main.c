#include <stdio.h>

#include <vka/object.h>

#include <allocman/allocman.h>
#include <allocman/bootstrap.h>
#include <allocman/vka.h>
#include <sel4utils/sel4_zf_logif.h>
#include <sel4utils/thread.h>
#include <simple/simple.h>
#include <simple-default/simple-default.h>
#include <sel4platsupport/bootinfo.h>

#include<hypervisor.h>
#include<terminal.h>

seL4_BootInfo *info;

simple_t simple;
vka_t vka;
allocman_t *allocman;

seL4_CPtr cspace_cap;
seL4_CPtr pd_cap;
seL4_CPtr pd1_cap;

/* static memory for the allocator to bootstrap with */
#define ALLOCATOR_STATIC_POOL_SIZE (BIT(seL4_PageBits) * 10)
UNUSED static char allocator_mem_pool[ALLOCATOR_STATIC_POOL_SIZE];

#define HYPERVISOR_STACK_SIZE 512
static uint64_t hypervisor_stack[HYPERVISOR_STACK_SIZE]__attribute__ ((aligned (16)));

#define CONSOLE_STACK_SIZE 512
static uint64_t console_stack[CONSOLE_STACK_SIZE]__attribute__ ((aligned (16)));

int create_hypervisor()
{
    UNUSED int error = 0;
    vka_object_t tcb_object = {0};
    error = vka_alloc_tcb(&vka, &tcb_object);
    ZF_LOGF_IFERR(error, "Failed to allocate new TCB.\n");
    error = seL4_TCB_Configure(tcb_object.cptr, seL4_CapNull,  cspace_cap, seL4_NilData, pd_cap, seL4_NilData, 0, 0);
    ZF_LOGF_IFERR(error, "Failed to configure the new TCB object.\n");

    error = seL4_TCB_SetPriority(tcb_object.cptr, simple_get_tcb(&simple), 255);
    ZF_LOGF_IFERR(error, "Failed to set the priority for the new TCB object.\n");

    NAME_THREAD(tcb_object.cptr, "charvis hypervisor");

    UNUSED seL4_UserContext regs = {0};
    sel4utils_set_instruction_pointer(&regs, (seL4_Word)hypervisor_entry);
    const int stack_alignment_requirement = sizeof(seL4_Word) * 2;
    uintptr_t hypervisor_stack_top = (uintptr_t)hypervisor_stack + sizeof(hypervisor_stack);
    ZF_LOGF_IF(hypervisor_stack_top % (stack_alignment_requirement) != 0,
               "Stack top isn't aligned correctly to a %dB boundary.\n",
               stack_alignment_requirement);
    sel4utils_set_stack_pointer(&regs, hypervisor_stack_top);
    error = seL4_TCB_WriteRegisters(tcb_object.cptr, 0, 0, 2, &regs);
    ZF_LOGF_IFERR(error, "Failed to write the new thread's register set.\n");
    error = seL4_TCB_Resume(tcb_object.cptr);
    
    return 0;
}

int create_console()
{
     UNUSED int error = 0;
    vka_object_t tcb_object = {0};
    error = vka_alloc_tcb(&vka, &tcb_object);
    ZF_LOGF_IFERR(error, "Failed to allocate new TCB.\n");
    error = seL4_TCB_Configure(tcb_object.cptr, seL4_CapNull,  cspace_cap, seL4_NilData, pd_cap, seL4_NilData, 0, 0);
    ZF_LOGF_IFERR(error, "Failed to configure the new TCB object.\n");

    error = seL4_TCB_SetPriority(tcb_object.cptr, simple_get_tcb(&simple), 255);
    ZF_LOGF_IFERR(error, "Failed to set the priority for the new TCB object.\n");

    NAME_THREAD(tcb_object.cptr, "charvis console");

    UNUSED seL4_UserContext regs = {0};
    sel4utils_set_instruction_pointer(&regs, (seL4_Word)termianal_entry);
    const int stack_alignment_requirement = sizeof(seL4_Word) * 2;
    uintptr_t console_stack_top = (uintptr_t)console_stack + sizeof(console_stack);
    ZF_LOGF_IF(console_stack_top % (stack_alignment_requirement) != 0,
               "Stack top isn't aligned correctly to a %dB boundary.\n",
               stack_alignment_requirement);
    sel4utils_set_stack_pointer(&regs, console_stack_top);
    error = seL4_TCB_WriteRegisters(tcb_object.cptr, 0, 0, 2, &regs);
    ZF_LOGF_IFERR(error, "Failed to write the new thread's register set.\n");
    error = seL4_TCB_Resume(tcb_object.cptr);
    
    
    return 0;
}
int main(int argc, char *argv[]) {
    printf("Hello, I'm Charvis!\n");
    
    UNUSED int error = 0;
    info=platsupport_get_bootinfo();
    ZF_LOGF_IF(info == NULL, "Failed to get bootinfo.");

    simple_default_init_bootinfo(&simple,info);
    simple_print(&simple);
    allocman=bootstrap_use_current_simple(&simple,ALLOCATOR_STATIC_POOL_SIZE,allocator_mem_pool);
    ZF_LOGF_IF(allocman == NULL, "Failed to initialize alloc manager.\n");
    allocman_make_vka(&vka, allocman);
    cspace_cap=simple_get_cnode(&simple);
    pd_cap=simple_get_pd(&simple);

    
    printf("creating hypervisor task\n");
    error=create_hypervisor();
    printf("creating console task\n");
    error=create_console();
    while (1)
    {
        /* code */
    }
    
    return 0;
}