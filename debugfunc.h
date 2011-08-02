#ifndef DEBUGFUNC_H_INCLUDED
#define DEBUGFUNC_H_INCLUDED

void debugSay(const char* str) {
    printf( "%s\n", str );
    fflush( stdout );
};

#endif // DEBUGFUNC_H_INCLUDED
