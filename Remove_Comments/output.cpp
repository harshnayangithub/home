#include <iostream>
#include <unistd.h>  
#include <sys/types.h> 
using namespace std;

int main() {
    pid_t pid = fork();  

    if (pid < 0) {
        
        cout << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0) {
        
        cout << "Child Process: " << endl;
        cout << "Child PID: " << getpid() << endl;
        cout << "Parent PID (PPID) of Child: " << getppid() << endl;
    } else {
        
        cout << "Parent Process: " << endl;
        cout << "Parent PID: " << getpid() << endl;
        cout << "Parent of Parent Process: " << getppid() << endl;
    }

    return 0;
}
