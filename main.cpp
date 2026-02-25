#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)
int dataVar1 = 100;
int dataVar2 = 200;

// TODO: Declare 2 uninitialized global variables (BSS segment)
int bssVar1; 
int bssVar2;

// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;

    // TODO: Print parentAddr value (points to main's local var - parent frame)
    cout << "parentAddr value: " << (void*)parentAddr << endl;
    // TODO: Print &parentAddr (parameter's own address - child frame)
    cout << "&parentAddr: " << (void*)&parentAddr << endl;
    // TODO: Print &childVar (local var address - child frame)
    cout << "&childVar: " << (void*)&childVar << endl;
    // TODO: Print "Stack grows: DOWN" or "UP" based on comparison
    cout << "Stack grows: " << ((parentAddr > &childVar)? "Down" : "UP" ) << endl;
    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)
    int localVar = 25;

    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction
    void* heap1 = malloc(1024);
    void* heap2 = malloc(1024);

    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack
    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    cout << "&main: " << (void*)&main << endl;
    cout << "functiodAdd: " << (void*)&checkStack << endl;
    cout << endl; 

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    cout << "&dataVar1: " << (void*)&dataVar1 << "Value = " << dataVar1 << endl;
    cout <<  "&dataVar2: " << (void*)&dataVar2 << "Value = " << dataVar2 << endl;
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    cout << "&bssVar1: " << (void*)&bssVar1 << "Value = " << bssVar1 << endl;
    cout << "&bssVar2: " << (void*)&bssVar2 << "Value = " << bssVar2 << endl;
    cout << endl;

    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);
    checkStack(&localVar);

    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"
    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    cout << "heap1: " << heap1 << endl;
    cout << "heap2: " << heap2 << endl;
    cout << "Heap grows: " << ((heap1 < heap2) ? "UP" : "DOWN") << endl;
    cout << endl;

    // TODO: Print relative position summary
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    cout << "TEXT near: " << (void*)&main << endl;
    cout << "DATA near: " << (void*)&dataVar1 << endl;
    cout << "BSS near: " << (void*)&bssVar1 << endl;
    cout << "HEAP near: " << heap1 << endl;
    cout << "LOCALS near: " << (void*)&localVar << endl;

    // TODO: Free all heap allocations
    free(heap1);
    free(heap2);

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses? Text, Data, Bss
 * - Which has the highest? Stack
 * - Does stack grow down? How did you verify this? parent add greater than child add
 * - Does heap grow up? How did you verify this? Heap grows up. heap2 greater than heap2
 * - What is the gap between HEAP and STACK? printed in byte code, can be alot  
 */
