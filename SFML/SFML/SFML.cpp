// SFML.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "strzal.h"
#include "display.h"
#include "AllienArray.h"





int main()
{
	
	Display& obraz = Display::GetDisplay();
	obraz.print();
	while(1);
	
    return 0;
}

