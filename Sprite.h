#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "SDL.h"
#include <string>
#include <vector>
using namespace std;

typedef vector<SDL_Rect*> RectArea;

//CSprite--abstracts Image+Control Point.
class CSprite
{
private:
	//Nombre
	string name;
	//Lista de Control points
	SDL_Rect* cpoint;
	vector<RectArea*> areas;

	//lo crea de una imagen fuente, añadiéndole el punto de control 0 si existe.
	CSprite ( SCanvas pSurface, SDL_Rect* zerocpSource = NULL) ;
	//destruye el sprite.
	virtual ~CSprite ( ) ;


	friend class CSpriteset;

public:
	//asigna nombre
	void setName(const char* newName);
	//devuelve nombre
	string getName();
	//devuelve la lista de puntos de control.
	vector<RectArea*>& getAllAreas () ;
	//devuelve el enésimo punto de control dentro del array de puntos de control.
	RectArea* getArea(int n);

	SDL_Rect* getRect(int n,int m);

	SDL_Rect* getCenter();

	void replaceCenter(SDL_Rect* c);
	//añade al final de la lista el punto cpSource
	int addArea(RectArea* area);

	int addRect(int area,SDL_Rect* rect);
	//substituye en el punto de control de la posición n, por cpSource
	void replaceArea(int n,RectArea* area);
	//devuelve el número de Control Points que posee el Sprite.
	void replaceRect(int area,int n,SDL_Rect* rect);

	int size();

};

#endif
