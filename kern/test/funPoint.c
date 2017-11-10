/*
 * Michelle Bergin
 * Lab 4 Part III
 * Function Pointers in an array.
 */
#include <types.h>
#include <lib.h>
#include <thread.h>
#include <synch.h>
#include <test.h>

void cat(void){
	kprintf("  ____\n");
	kprintf(" (.   \\\n");
	kprintf("   \\  |\n");
	kprintf("    \\  |\n");
	kprintf("     \\ |___(\\--/)\n");
	kprintf("   __/    (  . . )\n");
	kprintf("  \"'._.    '-.O.'\n");
	kprintf("       '-.  \\ \"|\\\n");
	kprintf("          '.,,/'.,,\n");
	kprintf("\n");
}
void cupcake(void){
	kprintf("           )\n");
	kprintf("          (.)\n");
	kprintf("          .|.\n");
	kprintf("          l8J\n");
	kprintf("          | |\n");
	kprintf("      _.--| |--._\n");
	kprintf("   .-';  ;`-'& ; `&.\n");
	kprintf("  & &  ;  &   ; ;   \\\n");
	kprintf("  \\      ;    &   &_/\n");
	kprintf("   F\"\"\"---...---\"\"\"J\n");
	kprintf("   | | | | | | | | |\n");
	kprintf("   J | | | | | | | F\n");
	kprintf("    `---.|.|.|.---'\n");
	kprintf("\n");
}
int funPoint(int nargs, char **args){
	kprintf("Program name %s\n", args[0]);
	(void)nargs;

	char buf[64];
	void(*fun_Arr[])() = {cat, cupcake};
	int size = 2;
	int i = size;
	while(i > size - 1){ 
		kprintf("Enter 0 for cat or 1 for cupcake\n");
		kgets(buf, sizeof(buf));
		i = atoi (buf);
	}   

	(*fun_Arr[i])();
	return 0;
}

