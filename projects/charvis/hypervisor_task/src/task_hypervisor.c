void hypervisor_entry()
{
    int *a;
    a=0x450000;
    *a=8;
    printf("hypervisor is running\n");
    while (1)
    {
        /* code */
    }
    
}