//                              -*- Mode: C++ -*- 
// 
// uC++ Version 6.0.0, Copyright (C) Peter A. Buhr 1994
// 
// uContext.cc -- 
// 
// Author           : Peter A. Buhr
// Created On       : Thu Jul  7 13:08:01 1994
// Last Modified By : Peter A. Buhr
// Last Modified On : Fri Jul 15 08:13:16 2011
// Update Count     : 27
// 


// WARNING: Do not use cout/cerr/printf in save or restore as they cause a recursive context switch or deadlock.

class uCoProcessorCxt1 : public uContext {
    static int uUniqueKey;
#   define savemsg1 "uCoProcessorCxt1::save\n"
#   define restoremsg1 "uCoProcessorCxt1::restore\n"
  public:
    uCoProcessorCxt1() : uContext( &uUniqueKey ) {};
    void save() {
	write( 1, savemsg1, sizeof( savemsg1 ) - 1 );
    }
    void restore() {
	write( 1, restoremsg1, sizeof( restoremsg1 ) - 1 );
    }
}; // uCoProcessorCxt1
int uCoProcessorCxt1::uUniqueKey = 0;


class uCoProcessorCxt2 : public uContext {
#   define savemsg2 "uCoProcessorCxt2::save\n"
#   define restoremsg2 "uCoProcessorCxt2::restore\n"
  public:
    void save() {
	write( 1, savemsg2, sizeof( savemsg2 ) - 1 );
    }
    void restore() {
	write( 1, restoremsg2, sizeof( restoremsg2 ) - 1 );
    }
}; // uCoProcessorCxt2


void uMain::main() {
    uCoProcessorCxt1 cpCxt11, cpCxt12;
    uCoProcessorCxt2 cpCxt21, cpCxt22;

    for ( int i = 0; i < 5; i += 1 ) {
	yield();
    } // for
} // uMain::main
    
// Local Variables: //
// compile-command: "u++ -O uContext.cc" //
// End: //