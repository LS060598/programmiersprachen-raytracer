#include "shape.hpp"
#include <cmath>
#include <iostream>

//5.3
//Konstruktoren
Shape::Shape():
	name_{""},
    color_{0.0,0.0,0.0,} {
		std::cout <<"default constructor erstellt" <<std::endl;
	}

Shape::Shape(std::string const&  name, Color const& color):
	name_{name},
    color_{color} {
		std::cout << "constructor erstellt" <<std::endl;
	}

Shape::~Shape(){
	std::cout<< "destructor erstellt" <<std::endl;
}



//getter
Color Shape::getColor() const{
	return color_;
}

std::string Shape::getName() const{
	return name_;
}


//5.4
//Ausgabe von Objekten des Typs Shape
std::ostream & Shape::print(std::ostream & os) const{
	os << name_ << std::endl << color_ ; 
	return os; //gibt Name & Farbe zurueck
}

// Überladen des Stream-Operators <<
std::ostream & operator <<(std::ostream & os, Shape const& s){
	return s.print(os);
}


//5.7
//linke Seite = statisch, rechte Seite dynamisch
//statisch-> zur Übersetzungszeit festgelegt oder gebunden, kann zur lLaufzeit nicht verändert werden
// stat. Typ -> Variablen werden mit Typversehen der zur Übersetzungszeit festgelegt wird
		   //-> erlaubt typabhängige Fehlererkennung zur Übersetzungszeit
		   //-> im Allgemeinen schnellere Ausführung als dynamisch typisierte Sprachen

//dynamisch-> nicht festgelegt bis zur Laufzeit, erlaubt Veränderungen während des Programmablaufs
//dyn. Typ -> bsp: Scheme/Javascript
		// -> Variablen sind nur Namen
		// -> Typen sind mit Werten verbunden, nicht mit Variablen
		// -> Variable kann zur Laufzeit mit verschiedenen Typen verbunden sein
		// -> Größere Flexibilität und einfacher zu schreiben -> keine Deklarationen


/*
//5.9
//Klassenhierachie -> 2 Arten
                // -> baumartige Struktur, bei der alle Klassen von einer einzigen übergeordneten Klasse abgeleitet sind (Java)
				// -> Klassen werden nur in eine Klassenhierachie eingefügt, falls es eine Beziehung zwischen ihnen gibt
				//    Daraus ergibt sich eine Art Wald von einzelnen Klassenhierachien (c++)

//Objekthierachie -> partielle Ordnung auf der menge der Objekte entsprechend der zwischen ihnen bestehenden Kompositionsbeziehungen
                //-> Komponente werden dabei als Nachfolger des Objektes, dem sie angehören, angeordnet
				//-> sind dynamisch, da sie zur Laufzeit dursch Zuweisen, Erzeugen und Löschen von Objekten verändert werden können



// Klassendiagramm -> statische/ logische Sicht
                // -> ein oder mehrere Klassendiagramme beschreiben die Klasse des Systems und ihre Beziehungen untereinander
				// -> Unterschiedliche Typen von Klassen : normale, parametrierte, instantiierte, abstrakte Klassen
				// -> wichtige methoden und Attribuete sollen in Klassendiagrammen dargestellt werden

// Objektdiagramme -> dynamische/ logische Sicht
                // -> Momentaufnahme des Systems
				// -> beziehungen aus Klassendiagrammen Spiegeln sich in Objektdiagrammen wieder

*/