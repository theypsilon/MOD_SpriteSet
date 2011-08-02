// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the shared library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bgddl.h"


#include "spriteset.h"
//#include "debugfunc.h"


extern "C"
{

#include "xstrings.h"

}

    static int toLoadSpriteset(INSTANCE * my,int * params);
    static int toGetSprite(INSTANCE * my,int * params);
    static int toUnloadSpriteset(INSTANCE * my,int * params);

    #define FENIX_export(a,b,c,d) {a,b,c,(void*)d}

    DLLEXPORT DLSYSFUNCS __bgdexport(mod_spriteset,functions_exports)[] = {
        FENIX_export( "LOAD_SPRITESET", "SI", TYPE_DWORD, toLoadSpriteset ),
        FENIX_export( "GET_SPRITE", "II", TYPE_INT, toGetSprite ),
        FENIX_export( "UNLOAD_SPRITESET", "I", TYPE_INT, toUnloadSpriteset ),
        { 0 , 0 , 0 , 0 }
    };

    static int toLoadSpriteset(INSTANCE * my,int * params) {

        CSpriteset* set = new CSpriteset(string_get(params[0]),params[1]);
        string_discard(params[0]);

        return ((int)set);

    }

    static int toGetSprite(INSTANCE * my,int * params) {

        int code = -1;

        CSpriteset* set = reinterpret_cast<CSpriteset*>(params[0]);

        GraphSurf* gs = set->get(params[1]);

        if (gs != NULL && gs->graph != NULL)
            code = gs->graph->code;

        return code;

    }

    static int toUnloadSpriteset(INSTANCE * my,int * params) {

        CSpriteset* set = reinterpret_cast<CSpriteset*>(params[0]);

        delete set;

        return 0;

    }
