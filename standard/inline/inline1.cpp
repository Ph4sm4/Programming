#pragma once
class Temp {
public:
	static const inline std::string txt{ "TREóè STAùA" };
};
inline Temp global_object;

/*
 Jeæeli ten plik b©dzie doà•czony w wielu plikach .cpp, i nie b©dzie zawieraà sàowa -inline-
 w¢wczas etap linkowania zako‰czyàby si© niepowodzeniem.
 
 O co chodzi?

 Normalnie program moæe mieÜ wiele plik¢w .cpp, kt¢re zazwyczaj kompilowane s• pojedy‰czo 
 do obiekt¢w (pliki .o). Potem wszystkie pliki moduà¢w/obiekt¢w s• linkowane w celu wygenerowania
 jednego pliku wykonywalnego lub biblioteki statycznej lub wsp¢àdzielonej.
 Gdy jest to linkowanie i definicja jakiegoò symbolu powt¢rzy si©, pojawia si© bà•d.
 (Np. gdy jest funkcja int f(); i co najmniej dwa obiekty/modyày definiuj• tak• sam• funkcj©.)
 Bà•d wynika z tego, iæ nie wiadomo, kt¢ra jest prawidàowa. Zàamana jest reguàa ODR (reguàa pojedy‰czej definicji).

Od C++17 z pomoc• przychodzi sàowo kluczowe inline.
Jeæeli linker znajdzie wiele symboli o takiej samej sygnaturze, ale zadeklarowanych jako osadzone (inline), w¢wczas wybierze pierwszy a pozostaàe nie zmieni• definicji. Programista musi jednak zadbaÜ, by ta niezmiennoòÜ definicji byàa faktycznie porz•dana !



*/
