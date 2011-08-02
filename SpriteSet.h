#ifndef __SPRITESET_H__
#define __SPRITESET_H__

#include "SDL.h"
#include "SDL_image.h"

#include "tinyxml.h"
#include "tinystr.h"

#include <vector>
#include <string>

extern "C"
{

#include "libgrbase.h"

}

using std::string;
using std::vector;

typedef struct {
    SDL_Surface* surf;
    GRAPH* graph;
} GraphSurf;

typedef vector<GraphSurf*> SpriteCollection;

class CSpriteset {
private :

	static Uint16 globalAuxiliar;
	//Inicializa Spriteset con los contenidos del fichero de tipo gráfico, cuyo nombre es obtenido por el constructor.
	void loadChipset(string& c,Uint8 mode,string* cPrev=NULL);

	string name;
	//Contenedor de Sprites.
	SpriteCollection m_veSDL_Surfaces ;

	Uint8 mode;

	SpriteCollection& getSpriteList ( ) ;


public:

	void add ( SDL_Surface* pspt ) ;

	CSpriteset();
	//constructor que inicializa la colección con un fichero externo.
	CSpriteset(string c,Uint8 mode);

	virtual ~CSpriteset();

	GraphSurf* get ( int n ) ;


};

typedef struct {
	Sint16 x, y,w, h;
} SDL_Rect_Signed;

typedef struct {
	bool relative ;
	vector<SDL_Rect_Signed> v;
} RectsInfo;



#endif
